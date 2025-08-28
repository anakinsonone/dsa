/*
 * You are given the root of a binary tree. Return only the values of the nodes
 * that are visible from the right side of the tree, ordered from top to bottom.

 * Example 1:
 * Input: root = [1,2,3]
 * Output: [1,3]

 * Example 2:
 * Input: root = [1,2,3,4,5,6,7]
 * Output: [1,3,7]
*/
#include <deque>
#include <iostream>
#include <optional>
#include <vector>

#include "BinaryTree.h"

std::vector<int> rightSideView(BinaryTree::TreeNode<int>* root) {
  std::vector<int> res;
  if (!root) return res;

  std::deque<BinaryTree::TreeNode<int>*> dq;
  dq.push_back(root);

  while (!dq.empty()) {
    int s = dq.size();
    res.push_back(dq.back()->value);
    for (int i = 0; i < s; i++) {
      BinaryTree::TreeNode<int>* curr = dq.front();
      dq.pop_front();

      if (curr->left) {
        dq.push_back(curr->left);
      }
      if (curr->right) {
        dq.push_back(curr->right);
      }
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

  BinaryTree::TreeNode<int>* root = BinaryTree::createBinaryTree(nums);
  BinaryTree::printBinaryTree(root);

  std::vector<int> res = rightSideView(root);
  for (int i : res) {
    std::cout << i << ' ';
  }
  std::cout << '\n';

  return 0;
}
