#ifndef KENKENGAMEMANAGER_H
#define KENKENGAMEMANAGER_H

#include "KenKenBoard.h"

namespace KenKenSolver
{

class KenKenGameManager
{
  private:
  const KenKenBoard& board;
  char null_entry = '@';

  public:
  KenKenGameManager(KenKenBoard& _board): board(_board)
  {}

  void display();
};

} // namespace KenKenSolver

#endif