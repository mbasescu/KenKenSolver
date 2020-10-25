#include "KenKenGameManager.h"

#include <iostream>
#include <utility>

namespace KENKENSOLVER
{

void
KenKenGameManager::display()
{
  for (std::size_t i = 0; i < board.size(); i++)
  {
    for (std::size_t j = 0; j < board.size(); j++)
    {
      int val = board.at(i, j);
      if (val == 0)
      {
        std::cout << null_entry;
      }
      else
      {
        std::cout << val;
      }

      // Handle end of line wrapping
      if (j == board.size()-1)
      {
        std::cout << std::endl;
      }
      else
      {
        std::cout << " ";
      }
    }
  }
}
  
} // namespace KENKENSOLVER