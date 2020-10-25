#ifndef SRC_KENKENSOLVER_H
#define SRC_KENKENSOLVER_H

#include <iostream>
#include <utility>

#include "KenKenBoard.h"

namespace KENKENSOLVER
{

struct CellEntry
{ 
  private:
  bool _valid;

  public:
  std::pair<int, int> index;
  int val;

  CellEntry(int i, int j, int _val)
  {
    index = std::make_pair(i, j);
    val = _val;

    if (i < 0 || j < 0)
    {
      _valid = false;
    }
    else
    {
      _valid = true;
    }
  }

  bool
  valid()
  {
    return _valid;
  }
};

class KenKenSolver
{
  private:

  KenKenBoard board;

  bool
  solve(CellEntry entry);

  public:
  
  KenKenSolver()
  {}

  CellEntry
  maximumInformationCell();

  bool
  solve(KenKenBoard _board)
  {
    board = _board;

    if (board.valid() && board.filled())
    {
      return true;
    }

    CellEntry entry = maximumInformationCell();
    for (std::size_t i = 1; i <= board.size(); i++)
    {
      entry.val = i;
      bool solved = solve(entry);
      if (solved)
      {
        return true;
      }
    }
    return false;
  }

  KenKenBoard
  getSolution()
  {
    return board;
  }
};

} // namespace KENKENSOLVER

#endif