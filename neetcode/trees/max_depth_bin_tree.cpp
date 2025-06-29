/*Given the root of a binary tree, return its depth.
 * The depth of a binary tree is defined as the number of nodes along the
 * longest path from the root node down to the farthest leaf node.
 * Example 1:
 * Input: root = [1,2,3,null,null,4]
 * Output: 3

 * Example 2:
 * Input: root = []
 * Output: 0
 */
#include "BinaryTree.h"
#include <algorithm>
#include <deque>
#include <iostream>
#include <optional>
#include <vector>

int treeDepth(BinaryTree::TreeNode<int> *root) {
  if (!root)
    return 0;
  // recursion
  // return 1 + std::max(treeDepth(root->left), treeDepth(root->right));

  // BFS
  std::deque<BinaryTree::TreeNode<int> *> dq;
  dq.push_back(root);

  int level = 0;
  while (!dq.empty()) {
    for (int i = 0; i < dq.size(); i++) {
      BinaryTree::TreeNode<int> *current = dq.front();
      dq.pop_front();

      if (current->left)
        dq.push_back(current->left);
      if (current->right)
        dq.push_back(current->right);
    }
    level++;
  }

  return level;
}

int main() {
  int n;
  std::cin >> n;
  std::vector<std::optional<int>> nums(n);
  for (int i = 0; i < n; i++) {
    int val;
    std::cin >> val;
    if (val == -1) {
      nums[i] = std::nullopt;
    } else {
      nums[i] = val;
    }
  }

  BinaryTree::TreeNode<int> *root = BinaryTree::createBinaryTree(nums);
  BinaryTree::printBinaryTree(root);

  std::cout << treeDepth(root);

  return 0;
}
