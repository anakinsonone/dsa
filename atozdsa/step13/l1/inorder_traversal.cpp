/*
 * Given root of binary tree, return the preorder traversal of the binary
 * tree.
 */
#include "BinaryTree.h"
#include <iostream>
#include <optional>
#include <vector>

void inorderTraversal(BinaryTree::TreeNode<int> *root, std::vector<int> &arr) {
  if (!root)
    return;

  inorderTraversal(root->left, arr);
  arr.push_back(root->value);
  inorderTraversal(root->right, arr);
}

int main() {
  int n;
  std::cin >> n;
  std::vector<std::optional<int>> nums(n);

  for (int i = 0; i < n; i++) {
    int num;
    std::cin >> num;
    if (num == -101) {
      nums[i] = std::nullopt;
    } else {
      nums[i] = num;
    }
  }

  BinaryTree::TreeNode<int> *root = BinaryTree::createBinaryTree(nums);
  BinaryTree::printBinaryTree(root);

  std::vector<int> res;

  inorderTraversal(root, res);
  std::cout << "inorder: ";
  for (int r : res) {
    std::cout << r << ' ';
  }

  return 0;
}
