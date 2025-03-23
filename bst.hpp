// bst.hpp

#ifndef BST_HPP
#define BST_HPP

#include <sstream>
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

template <class T, typename U>
BST<T, U>::BST(void) : root{ nullptr } {}

template <class T, typename U>
BST<T, U> &BST<T, U>::insert(T val)
{
  root = insert(root, val);
  return *this;
}

template <class T, typename U> void
BST<T, U>::inorder(Node *node, std::ostream &os)
{
  if (!node) return;
  inorder(node->left, os);
  os << node->data << ' ';
  inorder(node->right, os);
}

template <class T, typename U>
typename BST<T, U>::Node *
BST<T, U>::insert(Node *node, T val)
{
  if (!node)
    return new Node{ val };
  
  if (val < node->data)
    node->left = insert(node->left, val);
  else
    node->right = insert(node->right, val);
  
  return node;
}


template <class T, typename U> std::ostream &
operator<<(std::ostream &out, const BST<T, U> &tree)
{
  std::ostringstream ss;
  BST<T>::inorder(tree.root, ss);
  std::string contents = ss.str();
  if (!contents.empty())
    contents.pop_back();
  return out << "[ " << contents << " ]";
}

#endif
