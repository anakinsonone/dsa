/**/
#include "BinaryTree.h"
#include <iostream>
#include <optional>
#include <vector>

BinaryTree::TreeNode<int> *invertBinaryTree(BinaryTree::TreeNode<int> *root) {
  if (!root) {
    return nullptr;
  }

  BinaryTree::TreeNode<int> *temp = root->left;
  root->left = root->right;
  root->right = temp;

  invertBinaryTree(root->left);
  invertBinaryTree(root->right);

  return root;
}

int main() {
  int n;
  std::cin >> n;
  std::vector<std::optional<int>> values(n, 0);
  for (int i = 0; i < n; i++) {
    int val;
    std::cin >> val;
    if (val == -1) {
      values[i] = std::nullopt;
    } else {
      values[i] = val;
    }
  }

  BinaryTree::TreeNode<int> *root = BinaryTree::createBinaryTree(values);
  BinaryTree::printBinaryTree(root);

  root = invertBinaryTree(root);
  BinaryTree::printBinaryTree(root);

  return 0;
}
