/*Given a binary tree, return true if it is height-balanced and false otherwise.

 * A height-balanced binary tree is defined as a binary tree in which the left
 * and right subtrees of every node differ in height by no more than 1.

 * Example 1:
 * Input: root = [1,2,3,null,null,4]
 * Output: true
 * Example 2:

 * Input: root = [1,2,3,null,null,4,null,5]
 * Output: false
 * Example 3:

 * Input: root = []
 * Output: true
 * Constraints:

 * The number of nodes in the tree is in the range [0, 1000].
 * -1000 <= Node.val <= 1000
*/
#include "BinaryTree.h"
#include <algorithm>
#include <cstdlib>
#include <iostream>
#include <optional>
#include <utility>
#include <vector>

std::pair<bool, int> dfs(BinaryTree::TreeNode<int> *root) {
  if (!root)
    return {true, 0};

  std::pair<bool, int> left = dfs(root->left);
  std::pair<bool, int> right = dfs(root->right);
  bool balanced = (left.first && right.first) &&
                  (std::abs(left.second - right.second) <= 1);

  return {balanced, 1 + std::max(left.second, right.second)};
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

  std::pair<bool, int> res = dfs(root);
  std::cout << (res.first ? "true" : "false");

  return 0;
}
