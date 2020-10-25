#include <chrono>
#include <iostream>
#include <utility>
#include <vector>

#include "BoxConstraint.h"
#include "KenKenBoard.h"
#include "KenKenGameManager.h"

using KenKenSolver::BoxConstraint;
using KenKenSolver::KenKenBoard;
using KenKenSolver::KenKenGameManager;

int main(int argc, char *argv[])
{
  KenKenBoard board(4);
  KenKenGameManager game(board);

  // Test Board:
  // 1 2 3 4
  // 2 3 4 1
  // 3 4 1 2
  // 4 1 2 3

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
  BoxConstraint c1(c1_cells, KenKenSolver::BoxOperator::MULTIPLY, 6);

  std::vector<std::pair<int, int> > c2_cells;
  c2_cells.push_back(std::make_pair(0, 2));
  c2_cells.push_back(std::make_pair(0, 3));

  BoxConstraint c2(c2_cells, KenKenSolver::BoxOperator::ADD, 7);

  board.addConstraint(c1);
  board.addConstraint(c2);

  game.display();
  auto start = std::chrono::high_resolution_clock::now();

  std::cout << "Board is valid: " << board.valid() << std::endl;
  
  auto stop = std::chrono::high_resolution_clock::now();
  auto duration = std::chrono::duration_cast<std::chrono::microseconds>(stop - start);
  std::cout << "Time used to check validity: " << duration.count()/1e6 << std::endl;

  return 0;
}