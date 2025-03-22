#include <type_traits>
#include <iostream>
#include <sstream>

template <class T, class = std::enable_if_t<std::is_arithmetic_v<T>>>
class BST;

template <class T, class U>
std::ostream &operator<<(std::ostream&, const BST<T, U>&);

template <class T, class U>
class BST {
public:
  BST() : root{ nullptr } {}
  
  BST &insert(T val) {
    root = insert(root, val);
    return *this;
  }

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

template <class T, class U> void
BST<T, U>::inorder(Node *node, std::ostream &os)
{
  if (!node) return;
  inorder(node->left, os);
  os << node->data << ' ';
  inorder(node->right, os);
}

template <class T, class U>
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


template <class T, class U> std::ostream &
operator<<(std::ostream &out, const BST<T, U> &tree)
{
  std::ostringstream ss;
  BST<T, U>::inorder(tree.root, ss);
  std::string contents = ss.str();
  if (!contents.empty())
    contents.pop_back();
  return out << "[ " << contents << " ]";
}

int
main(void)
{
  BST<int> tree{};
  tree.insert(10).insert(5).insert(0);
  std::cout << tree << '\n';
}
