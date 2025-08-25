/*
 * Given a binary tree root, return the level order traversal of it as a nested
 * list, where each sublist contains the values of nodes at a particular level
 * in the tree, from left to right.

 * Example 1:
 * Input: root = [1,2,3,4,5,6,7]
 * Output: [[1],[2,3],[4,5,6,7]]

 * Example 2:
 * Input: root = [1]
 * Output: [[1]]

 * Example 3:
 * Input: root = []
 * Output: []
 */
#include <deque>
#include <iostream>
#include <optional>
#include <vector>

#include "BinaryTree.h"

std::vector<std::vector<int>> levelOrder(BinaryTree::TreeNode<int>* root) {
  std::vector<std::vector<int>> res;
  if (!root) return res;

  std::deque<BinaryTree::TreeNode<int>*> dq;
  dq.push_back(root);

  while (!dq.empty()) {
    int size = dq.size();
    std::vector<int> level;
    for (int i = 0; i < size; i++) {
      BinaryTree::TreeNode<int>* curr = dq.front();
      dq.pop_front();
      level.push_back(curr->value);

      if (curr->left) {
        dq.push_back(curr->left);
      }
      if (curr->right) {
        dq.push_back(curr->right);
      }
    }
    if (level.size()) res.push_back(level);
  }

  return res;
}

int main() {
  int n;
  std::cin >> n;
  std::vector<std::optional<int>> nums(n, 0);
  for (int i = 0; i < n; i++) {
    int num;
    std::cin >> num;
    nums[i] = num;
  }

  BinaryTree::TreeNode<int>* root = BinaryTree::createBinaryTree(nums);
  BinaryTree::printBinaryTree(root);

  std::vector<std::vector<int>> res = levelOrder(root);

  for (auto it : res) {
    for (int i : it) {
      std::cout << i << ' ';
    }
    std::cout << '\n';
  }

  return 0;
}
