/*
 * Given root of binary tree, return the preorder traversal of the binary
 * tree.
 * */
#include <iostream>
#include <optional>
#include <vector>

#include "BinaryTree.h"

void preorderTraversal(BinaryTree::TreeNode<int> *root,
                       std::vector<int> &nums) {
  if (!root) return;

  nums.push_back(root->value);
  preorderTraversal(root->left, nums);
  preorderTraversal(root->right, nums);
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
  preorderTraversal(root, res);

  std::cout << "preorder: ";
  for (int r : res) {
    std::cout << r << ' ';
  }
  std::cout << '\n';

  return 0;
}
