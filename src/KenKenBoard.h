#ifndef KENKENBOARD_H
#define KENKENBOARD_H

#include <utility>
#include <vector>

#include "BoxConstraint.h"

namespace KenKenSolver
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
};

} // namespace KenKenSolver

#endif