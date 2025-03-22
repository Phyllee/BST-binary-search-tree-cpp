// main.cpp

#include <iostream>
#include "bst.hpp"

int
main(void)
{
  using V = int;
  BST<V> tree{};
  
  std::cout << "How many insertion you want to add: ";
  V count{};
  std::cin >> count;
  
  for (V i = 0; i < count; ++i) {
    V temp{};
    std::cin >> temp;
    tree.insert(temp);
  }
       
  std::cout << tree << '\n';
}
