#ifndef SRC_KENKENBOARD_H
#define SRC_KENKENBOARD_H

//#include <cstdint>

#include <utility>
#include <vector>

#include "BoxConstraint.h"

namespace KENKENSOLVER
{

class KenKenBoard
{
  private:
  int _size;
  std::vector<std::vector<int> > _cells;
  std::vector<BoxConstraint> constraints;

  public:

  KenKenBoard(int _size = 1);

  KenKenBoard(const KenKenBoard& _board)
  {
    _size = _board.size();
    _cells = _board.cells();
    constraints = _board.constraints;
  }

  bool 
  valid() const;

  void
  addConstraint(BoxConstraint constraint)
  {
    constraints.push_back(constraint);
  }

  const int&
  at(const std::pair<int, int>& ind) const
  {
    return _cells.at(ind.first).at(ind.second);
  }

  // non-const version of accessor for setting the cell value
  int&
  at(const std::pair<int, int>& ind)
  {
    return const_cast<int &>(const_cast<const KenKenBoard* >(this)->at(ind));
  }

  const int&
  at(int i, int j) const
  {
    return at(std::make_pair(i, j));
  }

  // non-const version of accessor for setting the cell value
  int &
  at(int i, int j)
  {
    return const_cast<int &>(const_cast<const KenKenBoard* >(this)->at(i, j));
  }

  int 
  size() const
  {
    return _size;
  }

  const std::vector<std::vector<int> >& 
  cells() const
  {
    return _cells;
  }

  bool
  filled() const
  {
    for (std::size_t i = 0; i < size(); i++)
    {
      for (std::size_t j = 0; j < size(); j++)
      {
        if (this->at(i, j) == 0)
        {
          return false;
        }
      }
    }

    return true;
  }
};

} // namespace KENKENSOLVER

#endif