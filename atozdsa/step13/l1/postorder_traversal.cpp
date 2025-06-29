/*
 * Given root of binary tree, return the postorder traversal of the binary
 * tree.
 * */
#include "BinaryTree.h"
#include <iostream>
#include <optional>
#include <vector>

void postorder(BinaryTree::TreeNode<int> *root, std::vector<int> &res) {
  if (!root)
    return;

  postorder(root->left, res);
  postorder(root->right, res);
  res.push_back(root->value);
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
  postorder(root, res);
  std::cout << "postorder: ";
  for (int r : res) {
    std::cout << r << ' ';
  }
  std::cout << '\n';

  return 0;
}
