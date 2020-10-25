#ifndef BOXCONSTRAINT_H
#define BOXCONSTRAINT_H

#include <utility>
#include <vector>

namespace KenKenSolver
{

enum class BoxOperator
{
  ADD, SUBTRACT, MULTIPLY, DIVIDE
};

class KenKenBoard;

class BoxConstraint
{
  private:
    std::vector<std::pair<int, int> > cells;
    int n_cells;
    BoxOperator op;
    int constraint_val;

  public:

    BoxConstraint(std::vector<std::pair<int, int> > _box_cells, BoxOperator _op, int _constraint_val)
    {
      cells = _box_cells;
      n_cells = cells.size();
      op = _op;
      constraint_val = _constraint_val;
    }

    bool
    passes(const KenKenBoard& board) const;

    int
    applyOp(int val1, int val2) const;
};

} // namespace KenKenSolver

#endif