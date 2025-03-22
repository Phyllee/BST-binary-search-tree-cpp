// bst.cpp

#include "bst.hpp"
#include <sstream>

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

template class BST<int, void>;
template std::ostream &operator<<<int, void>(std::ostream&,  const BST<int, void>&);

template class BST<unsigned, void>;
template std::ostream &operator<<<unsigned, void>(std::ostream&,  const BST<unsigned, void>&);

template class BST<short, void>;
template std::ostream &operator<<<short, void>(std::ostream&,  const BST<short, void>&);

template class BST<unsigned short, void>;
template std::ostream &operator<<<unsigned short, void>(std::ostream&,  const BST<unsigned short, void>&);

template class BST<long, void>;
template std::ostream &operator<<<long, void>(std::ostream&,  const BST<long, void>&);

template class BST<unsigned long , void>;
template std::ostream &operator<<<unsigned long, void>(std::ostream&,  const BST<unsigned long, void>&);

template class BST<long long, void>;
template std::ostream &operator<<<long long, void>(std::ostream&,  const BST<long long, void>&);

template class BST<unsigned long long, void>;
template std::ostream &operator<<<unsigned long long, void>(std::ostream&,  const BST<unsigned long long, void>&);

template class BST<char, void>;
template std::ostream &operator<<<char, void>(std::ostream&,  const BST<char, void>&);

template class BST<signed char, void>;
template std::ostream &operator<<<signed char, void>(std::ostream&,  const BST<signed char, void>&);

template class BST<unsigned char, void>;
template std::ostream &operator<<<unsigned char, void>(std::ostream&,  const BST<unsigned char, void>&);

template class BST<bool, void>;
template std::ostream &operator<<<bool, void>(std::ostream&,  const BST<bool, void>&);

template class BST<float, void>;
template std::ostream &operator<<<float, void>(std::ostream&,  const BST<float, void>&);

template class BST<double, void>;
template std::ostream &operator<<<double, void>(std::ostream&,  const BST<double, void>&);

template class BST<long double, void>;
template std::ostream &operator<<<long double, void>(std::ostream&,  const BST<long double, void>&);
