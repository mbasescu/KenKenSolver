#include <chrono>
#include <iostream>
#include <utility>
#include <vector>

#include "BoxConstraint.h"
#include "KenKenBoard.h"
#include "KenKenGameManager.h"
#include "KenKenSolver.h"
#include "KenKenTestBoards.h"

using KENKENSOLVER::BoxConstraint;
using KENKENSOLVER::KenKenBoard;
using KENKENSOLVER::KenKenGameManager;
using KENKENSOLVER::KenKenSolver;

int main(int argc, char *argv[])
{
  KenKenBoard board = KENKENSOLVER::KENKENSOLVERTEST::board4();
  KenKenGameManager game(board);

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