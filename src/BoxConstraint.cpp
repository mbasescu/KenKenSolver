#include "BoxConstraint.h"
#include "KenKenBoard.h"

namespace KENKENSOLVER
{

bool
BoxConstraint::passes(const KenKenBoard& board) const
{
  // First loop through and return true if the cells are not completely filled in
  for (int i = 0; i < n_cells; i++)
  {
    if (board.at(cells.at(i)) == 0)
    {
      return true;
    }
  }

  int res = board.at(cells.at(0));
  // Apply constraint operator to each cell to obtain the net result
  for (int i = 1; i < n_cells; i++)
  {
    res = applyOp(res, board.at(cells.at(i)));
  }

  return (res == constraint_val);
}

int
BoxConstraint::applyOp(int val1, int val2) const
{
  int ret_val = -1;
  // Subtract and divide must always use the greater number first
  switch (op)
  {
    case BoxOperator::ADD:
      ret_val = val1 + val2;
      break;
    case BoxOperator::SUBTRACT:
      ret_val = std::max(val1, val2) - std::min(val1, val2);
      break;
    case BoxOperator::MULTIPLY:
      ret_val = val1 * val2;
      break;
    case BoxOperator::DIVIDE:
      ret_val = std::max(val1, val2) / std::min(val1, val2);
      break;
  }

  return ret_val;
}

} // namespace KENKENSOLVER