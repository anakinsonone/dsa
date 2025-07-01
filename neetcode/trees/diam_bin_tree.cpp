/*The diameter of a binary tree is defined as the length of the longest path
 * between any two nodes within the tree. The path does not necessarily have to
 * pass through the root.

 * The length of a path between two nodes in a binary tree is the number of
edges
 * between the nodes.

 * Given the root of a binary tree root, return the diameter of the tree.

 * Example 1:
 * Input: root = [1,null,2,3,4,5]
 * Output: 3
 * Explanation: 3 is the length of the path [1,2,3,5] or [5,3,2,4].

 * Example 2:
 * Input: root = [1,2,3]
 * Output: 2

 * Constraints:
 * 1 <= number of nodes in the tree <= 100
 * -100 <= Node.val <= 100
 */
#include "BinaryTree.h"
#include <algorithm>
#include <iostream>
#include <optional>
#include <vector>

int diameter(BinaryTree::TreeNode<int> *root, int &res) {
  if (!root)
    return 0;

  int left = diameter(root->left, res);
  int right = diameter(root->right, res);
  res = std::max(res, left + right);
  return 1 + std::max(left, right);
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

  int res = 0;
  diameter(root, res);

  std::cout << res;

  return 0;
}
