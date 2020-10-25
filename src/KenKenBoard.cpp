#include "KenKenBoard.h"

#include <iostream>

namespace KENKENSOLVER
{

KenKenBoard::KenKenBoard(int __size)
{
  _size = __size;

  // Initialize column vector and row vector
  std::vector<int> null_col(_size, 0);
  _cells = std::vector<std::vector<int>>(_size);
  for (std::size_t i = 0; i < _size; i++)
  {
    _cells.at(i) = null_col;
  }
}

bool
KenKenBoard::valid() const
{
  // Evaluate row/col constraints since they are more likely to fail
  for (std::size_t i = 0; i < _size; i++)
  {
    std::vector<int> observed_vals_col(_size, 0);
    std::vector<int> observed_vals_row(_size, 0);
    for (std::size_t j = 0; j < _size; j++)
    {
      // Only check filled cells for validity (row first)
      if (_cells.at(i).at(j) != 0)
      {
        // Check if the index in the i'th row and j'th col is already populated, if so the constraint is violated
        if (observed_vals_row.at(_cells.at(i).at(j)-1) != 0)
        {
          return false;
        }
        else
        {
          observed_vals_row.at(_cells.at(i).at(j)-1) = 1;
        }
      }
      // Now check the column-wise interpretation of the index
      if (_cells.at(j).at(i) != 0)
      {
        // Same check but for the j'th row and i'th column
        if (observed_vals_col.at(_cells.at(j).at(i)-1) != 0)
        {
          return false;
        }
        else
        {
          observed_vals_col.at(_cells.at(j).at(i)-1) = 1;
        }
      }
    }
  }

  // Evaluate box constraints now
  for (std::vector<int>::size_type i = 0; i < constraints.size(); i++)
  {
    if (!constraints.at(i).passes(*this))
    {
      return false;
    }
  }

  return true;
}

} // namespace KENKENSOLVER