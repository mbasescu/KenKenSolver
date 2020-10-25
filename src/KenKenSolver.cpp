#include "KenKenSolver.h"

#include <vector>

namespace KENKENSOLVER
{

CellEntry
KenKenSolver::maximumInformationCell()
{
  for (std::size_t i = 0; i < board.size(); i++)
  {
    for (std::size_t j = 0; j < board.size(); j++)
    {
      // Pick first non-zero cell for now, change implementation later
      if (board.at(i, j) == 0)
      {
        return CellEntry(i, j, 0);
      }
    }
  }
  std::cout << "Didn't find maximum information cell!" << std::endl;

  // Just return invalid cell index if all cells are filled in
  return CellEntry(-1, -1, 0);
}

bool
KenKenSolver::solve(CellEntry entry)
{
  // Make entry
  board.at(entry.index) = entry.val;

  // Return false if board is invalid or if board is filled 
  if (!board.valid())
  {
    board.at(entry.index) = 0;
    return false;
  }
  else if (board.filled())
  {
    return true;
  }

  // This is guaranteed to return a valid cell if the board is not filled and is valid
  CellEntry new_entry = maximumInformationCell();

  // Try to solve with the maximum information entry until we run out of options
  for (std::size_t num = 1; num <= board.size(); num++)
  {
    new_entry.val = num;
    bool solved = solve(new_entry);
    if (solved)
    {
      return true;
    }
  }

  // Reset this value and return false if there are no more options
  board.at(entry.index) = 0;
  return false;
}

} // namespace KENKENSOLVER