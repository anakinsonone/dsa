/*Given the root of a binary tree, return the level order traversal of its
 * nodes' values. (i.e., from left to right, level by level).

 * Example 1:
 * Input : root = [3, 9, 20, null, null, 15, 7]
 * Output : [ [3] , [9, 20] , [15, 7] ]

 * Example 2:
 * Input : root = [1, 4, null, 4 2]
 * Output : [ [1] , [4] , [4, 2] ]
 */
#include "BinaryTree.h"
#include <deque>
#include <iostream>
#include <optional>
#include <vector>

std::vector<std::vector<int>> levelOrder(BinaryTree::TreeNode<int> *root) {
  std::vector<std::vector<int>> res;

  std::deque<BinaryTree::TreeNode<int> *> dq;
  dq.push_back(root);
  res.push_back({root->value});

  while (!dq.empty()) {
    BinaryTree::TreeNode<int> *current = dq.front();
    dq.pop_front();

    std::vector<int> v;
    if (current->left) {
      dq.push_back(current->left);
      v.push_back(current->left->value);
    }
    if (current->right) {
      dq.push_back(current->right);
      v.push_back(current->right->value);
    }
    if (v.size()) {
      res.push_back(v);
    }
  }

  return res;
}

int main() {
  int n;
  std::cin >> n;
  std::vector<std::optional<int>> nums(n);
  for (int i = 0; i < n; i++) {
    int num;
    std::cin >> num;
    if (num == -1) {
      nums[i] = std::nullopt;
    } else {
      nums[i] = num;
    }
  }

  BinaryTree::TreeNode<int> *root = BinaryTree::createBinaryTree(nums);
  BinaryTree::printBinaryTree(root);

  std::vector<std::vector<int>> res = levelOrder(root);

  for (std::vector<int> v : res) {
    for (int n : v) {
      std::cout << n << ' ';
    }
    std::cout << '\n';
  }

  return 0;
}
