#ifndef BINARY_TREE_H
#define BINARY_TREE_H

#include <algorithm>
#include <iostream>
#include <optional>
#include <queue>
#include <string>
#include <vector>

namespace BinaryTree {
template <typename T>
struct TreeNode {
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
TreeNode<T> *createBinaryTree(const std::vector<std::optional<T>> &values) {
  if (values.empty() || !values[0]) {
    return nullptr;
  }

  TreeNode<T> *root = new TreeNode<T>(values[0].value());
  std::queue<TreeNode<T> *> q;
  q.push(root);

  int i = 1;
  while (i < values.size()) {
    TreeNode<T> *current = q.front();
    q.pop();

    // Add left child
    if (i < values.size() && values[i].has_value()) {
      current->left = new TreeNode<T>(values[i].value());
      q.push(current->left);
    }
    i++;

    // Add right child
    if (i < values.size() && values[i].has_value()) {
      current->right = new TreeNode<T>(values[i].value());
      q.push(current->right);
    }
    i++;
  }

  return root;
}

template <typename T>
void printPretty(TreeNode<T> *root) {
  if (!root) {
    std::cout << "Empty tree" << std::endl;
    return;
  }
  std::cout << root->value << std::endl;
  if (root->left && root->right) {
    printPrettyHelper(root->left, "", false);
    printPrettyHelper(root->right, "", true);
  } else if (root->left) {
    printPrettyHelper(root->left, "", true);
  } else if (root->right) {
    printPrettyHelper(root->right, "", true);
  }
}

template <typename T>
void printPrettyHelper(TreeNode<T> *root, std::string prefix, bool isLast) {
  if (root) {
    std::cout << prefix;
    std::cout << (isLast ? "└── " : "├── ");
    std::cout << root->value << std::endl;
    std::string newPrefix = prefix + (isLast ? "    " : "│   ");
    if (root->left && root->right) {
      printPrettyHelper(root->left, newPrefix, false);
      printPrettyHelper(root->right, newPrefix, true);
    } else if (root->left) {
      printPrettyHelper(root->left, newPrefix, true);
    } else if (root->right) {
      printPrettyHelper(root->right, newPrefix, true);
    }
  }
}

}  // namespace BinaryTree

#endif  // !BINARY_TREE_H
