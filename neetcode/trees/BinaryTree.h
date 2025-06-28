#ifndef BINARY_TREE_H
#define BINARY_TREE_H

#include <iostream>
#include <queue>
#include <vector>

namespace BinaryTree {
template <typename T> struct TreeNode {
  T value;
  TreeNode *left;
  TreeNode *right;

  // Constructors
  TreeNode() : value(T(0)), left(nullptr), right(nullptr) {};
  TreeNode(T x) : value(x), left(nullptr), right(nullptr) {};
  TreeNode(T x, TreeNode *left, TreeNode *right)
      : value(x), left(left), right(right) {};
};

template <typename T>
TreeNode<T> *createBinaryTree(const std::vector<T> &values) {
  if (values.empty()) {
    return nullptr;
  }

  TreeNode<T> *root = new TreeNode<T>(values[0]);
  std::queue<TreeNode<T> *> q;
  q.push(root);

  int i = 1;
  while (i < values.size()) {
    TreeNode<T> *current = q.front();
    q.pop();

    if (i < values.size()) {
      current->left = new TreeNode<T>(values[i]);
      q.push(current->left);
      i++;
    }

    if (i < values.size()) {
      current->right = new TreeNode<T>(values[i]);
      q.push(current->right);
      i++;
    }
  }

  return root;
}

template <typename T> void printBinaryTree(TreeNode<T> *root) {
  if (!root) {
    return;
  }

  std::queue<TreeNode<T> *> q;
  q.push(root);

  while (!q.empty()) {
    TreeNode<T> *current = q.front();
    q.pop();

    std::cout << current->value << ' ';

    if (current->left) {
      q.push(current->left);
    }

    if (current->right) {
      q.push(current->right);
    }
  }

  std::cout << '\n';
}

} // namespace BinaryTree

#endif // !BINARY_TREE_H
