#include <chrono>
#include <iostream>
#include <utility>
#include <vector>

#include "BoxConstraint.h"
#include "KenKenBoard.h"
#include "KenKenGameManager.h"
#include "KenKenSolver.h"

using KENKENSOLVER::BoxConstraint;
using KENKENSOLVER::KenKenBoard;
using KENKENSOLVER::KenKenGameManager;
using KENKENSOLVER::KenKenSolver;

int main(int argc, char *argv[])
{
  KenKenBoard board(4);
  KenKenGameManager game(board);

  // Test Board:
  // 1 2 3 4
  // 2 3 4 1
  // 3 4 1 2
  // 4 1 2 3
  /*
  // Row 1
  board.at(0, 0) = 1;
  board.at(0, 1) = 2;
  board.at(0, 2) = 3;
  board.at(0, 3) = 4;

  // Row 2
  board.at(1, 0) = 2;
  board.at(1, 1) = 3;
  board.at(1, 2) = 4;
  board.at(1, 3) = 1;

  // Row 3
  board.at(2, 0) = 3;
  board.at(2, 1) = 4;
  board.at(2, 2) = 1;
  board.at(2, 3) = 2;

  // Row 4
  board.at(3, 0) = 4;
  board.at(3, 1) = 1;
  board.at(3, 2) = 2;
  board.at(3, 3) = 3;

  // Add constraints
  std::vector<std::pair<int, int> > c1_cells;
  c1_cells.push_back(std::make_pair(0, 0));
  c1_cells.push_back(std::make_pair(0, 1));
  c1_cells.push_back(std::make_pair(1, 1));
  BoxConstraint c1(c1_cells, KENKENSOLVER::BoxOperator::MULTIPLY, 6);

  std::vector<std::pair<int, int> > c2_cells;
  c2_cells.push_back(std::make_pair(0, 2));
  c2_cells.push_back(std::make_pair(0, 3));

  BoxConstraint c2(c2_cells, KENKENSOLVER::BoxOperator::ADD, 7);

  board.addConstraint(c1);
  board.addConstraint(c2);
  */

  // Add constraints
  board.at(0, 3) = 1;

  std::vector<std::pair<int, int> > c1_cells;
  c1_cells.push_back(std::make_pair(0, 0));
  c1_cells.push_back(std::make_pair(1, 0));
  BoxConstraint c1(c1_cells, KENKENSOLVER::BoxOperator::ADD, 5);

  std::vector<std::pair<int, int> > c2_cells;
  c2_cells.push_back(std::make_pair(2, 0));
  c2_cells.push_back(std::make_pair(3, 0));
  BoxConstraint c2(c2_cells, KENKENSOLVER::BoxOperator::ADD, 5);

  std::vector<std::pair<int, int> > c3_cells;
  c3_cells.push_back(std::make_pair(0, 1));
  c3_cells.push_back(std::make_pair(0, 2));
  BoxConstraint c3(c3_cells, KENKENSOLVER::BoxOperator::ADD, 7);

  std::vector<std::pair<int, int> > c4_cells;
  c4_cells.push_back(std::make_pair(1, 1));
  c4_cells.push_back(std::make_pair(2, 1));
  c4_cells.push_back(std::make_pair(3, 1));
  BoxConstraint c4(c4_cells, KENKENSOLVER::BoxOperator::ADD, 6);

  std::vector<std::pair<int, int> > c5_cells;
  c5_cells.push_back(std::make_pair(1, 2));
  c5_cells.push_back(std::make_pair(1, 3));
  c5_cells.push_back(std::make_pair(2, 2));
  c5_cells.push_back(std::make_pair(2, 3));
  BoxConstraint c5(c5_cells, KENKENSOLVER::BoxOperator::ADD, 11);

  std::vector<std::pair<int, int> > c6_cells;
  c6_cells.push_back(std::make_pair(3, 2));
  c6_cells.push_back(std::make_pair(3, 3));
  BoxConstraint c6(c6_cells, KENKENSOLVER::BoxOperator::ADD, 5);

  board.addConstraint(c1);
  board.addConstraint(c2);
  board.addConstraint(c3);
  board.addConstraint(c4);
  board.addConstraint(c5);
  board.addConstraint(c6);

  game.display();
  auto start = std::chrono::high_resolution_clock::now();

  std::cout << "Board is valid: " << board.valid() << std::endl;
  
  auto stop = std::chrono::high_resolution_clock::now();
  auto duration = std::chrono::duration_cast<std::chrono::microseconds>(stop - start);
  std::cout << "Time used to check validity: " << duration.count()/1e6 << std::endl;

  // Test the solver
  KenKenSolver solver;
  start = std::chrono::high_resolution_clock::now();
  
  bool solution_exists = solver.solve(board);
  std::cout << "Solution exists: " << solution_exists << std::endl;
  KenKenBoard solved_board = solver.getSolution();

  stop = std::chrono::high_resolution_clock::now();

  duration = std::chrono::duration_cast<std::chrono::microseconds>(stop - start);
  std::cout << "Time used to solve problem: " << duration.count()/1e6 << std::endl;

  KenKenGameManager solution_manager(solved_board);
  std::cout << "Solved board: " << std::endl;
  solution_manager.display();

  return 0;
}