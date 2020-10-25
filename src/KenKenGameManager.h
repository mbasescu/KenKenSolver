#ifndef SRC_KENKENGAMEMANAGER_H
#define SRC_KENKENGAMEMANAGER_H

#include "KenKenBoard.h"

namespace KENKENSOLVER
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

} // namespace KENKENSOLVER

#endif