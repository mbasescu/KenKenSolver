#ifndef TEST_KENKENTESTBOARDS_H
#define TEST_KENKENTESTBOARDS_H

#include <vector>

#include "BoxConstraint.h"
#include "KenKenBoard.h"

namespace KENKENSOLVER
{
namespace KENKENSOLVERTEST
{

  KenKenBoard board1()
  {
    // Test Board:
    // 1 2 3 4
    // 2 3 4 1
    // 3 4 1 2
    // 4 1 2 3
    
    KenKenBoard board(4);
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
    std::vector<std::pair<int, int> > cells;
    cells.push_back(std::make_pair(0, 0));
    cells.push_back(std::make_pair(0, 1));
    cells.push_back(std::make_pair(1, 1));
    BoxConstraint c(cells, KENKENSOLVER::BoxOperator::MULTIPLY, 6);
    board.addConstraint(c);
    cells.clear();

    cells.push_back(std::make_pair(0, 2));
    cells.push_back(std::make_pair(0, 3));
    c = BoxConstraint(cells, KENKENSOLVER::BoxOperator::ADD, 7);
    board.addConstraint(c);
    cells.clear();

    return board;
  }

  KenKenBoard board2()
  {
    // Unknown solution board (4x4)
    KenKenBoard board(4);

    // Add constraints
    board.at(0, 3) = 1;

    std::vector<std::pair<int, int> > cells;
    cells.push_back(std::make_pair(0, 0));
    cells.push_back(std::make_pair(1, 0));
    BoxConstraint c(cells, KENKENSOLVER::BoxOperator::ADD, 5);
    board.addConstraint(c);
    cells.clear();

    cells.push_back(std::make_pair(2, 0));
    cells.push_back(std::make_pair(3, 0));
    c = BoxConstraint(cells, KENKENSOLVER::BoxOperator::ADD, 5);
    board.addConstraint(c);
    cells.clear();

    cells.push_back(std::make_pair(0, 1));
    cells.push_back(std::make_pair(0, 2));
    c = BoxConstraint(cells, KENKENSOLVER::BoxOperator::ADD, 7);
    board.addConstraint(c);
    cells.clear();

    cells.push_back(std::make_pair(1, 1));
    cells.push_back(std::make_pair(2, 1));
    cells.push_back(std::make_pair(3, 1));
    c = BoxConstraint(cells, KENKENSOLVER::BoxOperator::ADD, 6);
    board.addConstraint(c);
    cells.clear();

    cells.push_back(std::make_pair(1, 2));
    cells.push_back(std::make_pair(1, 3));
    cells.push_back(std::make_pair(2, 2));
    cells.push_back(std::make_pair(2, 3));
    c = BoxConstraint(cells, KENKENSOLVER::BoxOperator::ADD, 11);
    board.addConstraint(c);
    cells.clear();

    cells.push_back(std::make_pair(3, 2));
    cells.push_back(std::make_pair(3, 3));
    c = BoxConstraint(cells, KENKENSOLVER::BoxOperator::ADD, 5);
    board.addConstraint(c);
    cells.clear();
    
    return board;
  }

  KenKenBoard board3()
  {
    // Unknown solution board (6x6)
    KenKenBoard board(6);

    // Add constraints
    board.at(2, 3) = 5;
    std::vector<std::pair<int, int> > cells;
    
    // Constraint 1
    cells.push_back(std::make_pair(0, 0));
    cells.push_back(std::make_pair(1, 0));
    cells.push_back(std::make_pair(1, 1));
    cells.push_back(std::make_pair(2, 0));
    BoxConstraint c(cells, KENKENSOLVER::BoxOperator::ADD, 12);
    board.addConstraint(c);
    cells.clear();

    // Constraint 2
    cells.push_back(std::make_pair(0, 1));
    cells.push_back(std::make_pair(0, 2));
    c = BoxConstraint(cells, KENKENSOLVER::BoxOperator::DIVIDE, 3);
    board.addConstraint(c);
    cells.clear();

    // Constraint 3
    cells.push_back(std::make_pair(0, 3));
    cells.push_back(std::make_pair(0, 4));
    cells.push_back(std::make_pair(0, 5));
    c = BoxConstraint(cells, KENKENSOLVER::BoxOperator::MULTIPLY, 15);
    board.addConstraint(c);
    cells.clear();

    // Constraint 4
    cells.push_back(std::make_pair(1, 2));
    cells.push_back(std::make_pair(1, 3));
    c = BoxConstraint(cells, KENKENSOLVER::BoxOperator::SUBTRACT, 3);
    board.addConstraint(c);
    cells.clear();

    // Constraint 5
    cells.push_back(std::make_pair(1, 4));
    cells.push_back(std::make_pair(1, 5));
    c = BoxConstraint(cells, KENKENSOLVER::BoxOperator::DIVIDE, 2);
    board.addConstraint(c);
    cells.clear();

    // Constraint 6
    cells.push_back(std::make_pair(2, 1));
    cells.push_back(std::make_pair(2, 2));
    c = BoxConstraint(cells, KENKENSOLVER::BoxOperator::ADD, 5);
    board.addConstraint(c);
    cells.clear();

    // Constraint 7
    cells.push_back(std::make_pair(2, 4));
    cells.push_back(std::make_pair(3, 4));
    c = BoxConstraint(cells, KENKENSOLVER::BoxOperator::MULTIPLY, 6);
    board.addConstraint(c);
    cells.clear();

    // Constraint 8
    cells.push_back(std::make_pair(2, 5));
    cells.push_back(std::make_pair(3, 5));
    cells.push_back(std::make_pair(4, 5));
    c = BoxConstraint(cells, KENKENSOLVER::BoxOperator::ADD, 11);
    board.addConstraint(c);
    cells.clear();

    // Constraint 9
    cells.push_back(std::make_pair(3, 0));
    cells.push_back(std::make_pair(3, 1));
    c = BoxConstraint(cells, KENKENSOLVER::BoxOperator::SUBTRACT, 2);
    board.addConstraint(c);
    cells.clear();

    // Constraint 10
    cells.push_back(std::make_pair(3, 2));
    cells.push_back(std::make_pair(3, 3));
    c = BoxConstraint(cells, KENKENSOLVER::BoxOperator::SUBTRACT, 1);
    board.addConstraint(c);
    cells.clear();

    // Constraint 11
    cells.push_back(std::make_pair(4, 0));
    cells.push_back(std::make_pair(4, 1));
    c = BoxConstraint(cells, KENKENSOLVER::BoxOperator::DIVIDE, 3);
    board.addConstraint(c);
    cells.clear();

    // Constraint 12
    cells.push_back(std::make_pair(4, 2));
    cells.push_back(std::make_pair(5, 2));
    c = BoxConstraint(cells, KENKENSOLVER::BoxOperator::SUBTRACT, 1);
    board.addConstraint(c);
    cells.clear();

    // Constraint 13
    cells.push_back(std::make_pair(4, 3));
    cells.push_back(std::make_pair(5, 3));
    c = BoxConstraint(cells, KENKENSOLVER::BoxOperator::SUBTRACT, 5);
    board.addConstraint(c);
    cells.clear();

    // Constraint 14
    cells.push_back(std::make_pair(4, 4));
    cells.push_back(std::make_pair(5, 4));
    cells.push_back(std::make_pair(5, 5));
    c = BoxConstraint(cells, KENKENSOLVER::BoxOperator::MULTIPLY, 24);
    board.addConstraint(c);
    cells.clear();

    // Constraint 15
    cells.push_back(std::make_pair(5, 0));
    cells.push_back(std::make_pair(5, 1));
    c = BoxConstraint(cells, KENKENSOLVER::BoxOperator::MULTIPLY, 30);
    board.addConstraint(c);
    cells.clear();
    
    return board;
  }

  KenKenBoard board4()
  {
    // Unknown solution board (7x7)
    KenKenBoard board(7);

    // Add constraints
    board.at(6, 2) = 1;
    board.at(2, 1) = 5;
    board.at(3, 6) = 6;

    std::vector<std::pair<int, int> > cells;
    
    cells.push_back(std::make_pair(0, 0));
    cells.push_back(std::make_pair(0, 1));
    cells.push_back(std::make_pair(1, 1));
    cells.push_back(std::make_pair(1, 2));
    BoxConstraint c(cells, KENKENSOLVER::BoxOperator::ADD, 18);
    board.addConstraint(c);
    cells.clear();

    cells.push_back(std::make_pair(0, 2));
    cells.push_back(std::make_pair(0, 3));
    cells.push_back(std::make_pair(1, 3));
    c = BoxConstraint(cells, KENKENSOLVER::BoxOperator::ADD, 15);
    board.addConstraint(c);
    cells.clear();

    cells.push_back(std::make_pair(0, 4));
    cells.push_back(std::make_pair(0, 5));
    cells.push_back(std::make_pair(0, 6));
    c = BoxConstraint(cells, KENKENSOLVER::BoxOperator::MULTIPLY, 60);
    board.addConstraint(c);
    cells.clear();

    cells.push_back(std::make_pair(1, 0));
    cells.push_back(std::make_pair(2, 0));
    cells.push_back(std::make_pair(3, 0));
    c = BoxConstraint(cells, KENKENSOLVER::BoxOperator::ADD, 16);
    board.addConstraint(c);
    cells.clear();

    cells.push_back(std::make_pair(1, 4));
    cells.push_back(std::make_pair(1, 5));
    c = BoxConstraint(cells, KENKENSOLVER::BoxOperator::SUBTRACT, 3);
    board.addConstraint(c);
    cells.clear();

    cells.push_back(std::make_pair(1, 6));
    cells.push_back(std::make_pair(2, 6));
    c = BoxConstraint(cells, KENKENSOLVER::BoxOperator::MULTIPLY, 6);
    board.addConstraint(c);
    cells.clear();

    cells.push_back(std::make_pair(2, 2));
    cells.push_back(std::make_pair(2, 3));
    c = BoxConstraint(cells, KENKENSOLVER::BoxOperator::SUBTRACT, 2);
    board.addConstraint(c);
    cells.clear();

    cells.push_back(std::make_pair(2, 4));
    cells.push_back(std::make_pair(2, 5));
    c = BoxConstraint(cells, KENKENSOLVER::BoxOperator::SUBTRACT, 6);
    board.addConstraint(c);
    cells.clear();

    cells.push_back(std::make_pair(3, 1));
    cells.push_back(std::make_pair(3, 2));
    c = BoxConstraint(cells, KENKENSOLVER::BoxOperator::MULTIPLY, 10);
    board.addConstraint(c);
    cells.clear();

    cells.push_back(std::make_pair(3, 3));
    cells.push_back(std::make_pair(4, 3));
    c = BoxConstraint(cells, KENKENSOLVER::BoxOperator::ADD, 7);
    board.addConstraint(c);
    cells.clear();

    cells.push_back(std::make_pair(3, 4));
    cells.push_back(std::make_pair(4, 4));
    c = BoxConstraint(cells, KENKENSOLVER::BoxOperator::ADD, 9);
    board.addConstraint(c);
    cells.clear();

    cells.push_back(std::make_pair(3, 5));
    cells.push_back(std::make_pair(4, 5));
    cells.push_back(std::make_pair(5, 5));
    c = BoxConstraint(cells, KENKENSOLVER::BoxOperator::ADD, 15);
    board.addConstraint(c);
    cells.clear();

    cells.push_back(std::make_pair(4, 0));
    cells.push_back(std::make_pair(5, 0));
    c = BoxConstraint(cells, KENKENSOLVER::BoxOperator::DIVIDE, 2);
    board.addConstraint(c);
    cells.clear();

    cells.push_back(std::make_pair(4, 1));
    cells.push_back(std::make_pair(4, 2));
    c = BoxConstraint(cells, KENKENSOLVER::BoxOperator::SUBTRACT, 1);
    board.addConstraint(c);
    cells.clear();

    cells.push_back(std::make_pair(4, 6));
    cells.push_back(std::make_pair(5, 6));
    c = BoxConstraint(cells, KENKENSOLVER::BoxOperator::ADD, 8);
    board.addConstraint(c);
    cells.clear();

    cells.push_back(std::make_pair(5, 1));
    cells.push_back(std::make_pair(6, 1));
    cells.push_back(std::make_pair(6, 0));
    c = BoxConstraint(cells, KENKENSOLVER::BoxOperator::ADD, 13);
    board.addConstraint(c);
    cells.clear();

    cells.push_back(std::make_pair(5, 2));
    cells.push_back(std::make_pair(5, 3));
    cells.push_back(std::make_pair(5, 4));
    c = BoxConstraint(cells, KENKENSOLVER::BoxOperator::ADD, 11);
    board.addConstraint(c);
    cells.clear();

    cells.push_back(std::make_pair(6, 3));
    cells.push_back(std::make_pair(6, 4));
    c = BoxConstraint(cells, KENKENSOLVER::BoxOperator::DIVIDE, 2);
    board.addConstraint(c);
    cells.clear();

    cells.push_back(std::make_pair(6, 5));
    cells.push_back(std::make_pair(6, 6));
    c = BoxConstraint(cells, KENKENSOLVER::BoxOperator::SUBTRACT, 2);
    board.addConstraint(c);
    cells.clear();

    return board;
  }

  // Get a vector containing all boards
  std::vector<KenKenBoard> initializeTestBoards()
  {
    std::vector<KenKenBoard> boards;
    boards.push_back(board1());
    boards.push_back(board2());
    boards.push_back(board3());
    boards.push_back(board4());

    return boards;
  }

} // namespace KENKENSOLVERTEST
} // namespace KENKENSOLVER

#endif