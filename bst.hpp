// bst.hpp

#ifndef BST_H
#define BST_H

#include <ostream>
#include <type_traits>

template <class T, typename = std::enable_if_t<std::is_arithmetic_v<T>>>
class BST;

template <class T, typename U>
std::ostream &operator<<(std::ostream &out, const BST<T, U>&);

template <class T, typename U>
class BST {
public:
  BST(void);
  
  BST &insert(T);

  friend std::ostream &operator<<<T, U>(std::ostream &out, const BST<T, U>&);

private:
  struct Node {
    T data;
    struct Node *left, *right;
    Node(T val) : data{ val }, left{ nullptr }, right{ nullptr } {}
  } *root;

  static void inorder(Node*, std::ostream&);
  Node *insert(Node*, T);
};

#endif
