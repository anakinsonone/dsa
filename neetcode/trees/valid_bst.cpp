/*
 * Given the root of a binary tree, return true if it is a valid binary search
 * tree, otherwise return false.

 * A valid binary search tree satisfies the following constraints:

 * The left subtree of every node contains only nodes with keys less than the
 * node's key. The right subtree of every node contains only nodes with keys
 * greater than the node's key. Both the left and right subtrees are also binary
 * search trees. Example 1:

 * Input: root = [2,1,3]
 * Output: true

 * Example 2:
 * Input: root = [1,2,3]
 * Output: false
 * Explanation: The root node's value is 1 but its left child's value is 2 which
 * is greater than 1.

 * Constraints:
 * 1 <= The number of nodes in the tree <= 1000.
 * -1000 <= Node.val <= 1000
 */

#include <climits>
#include <deque>
#include <iostream>
#include <optional>
#include <vector>

#include "BinaryTree.h"

bool isValidBST(BinaryTree::TreeNode<int>* root, long left, long right) {
  if (!root) return true;

  if (!(left < root->value && right > root->value)) return false;

  return isValidBST(root->left, left, root->value) &&
         isValidBST(root->right, root->value, right);
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

  bool isValid = isValidBST(root, LONG_MIN, LONG_MAX);
  std::cout << (isValid ? "true" : "false");

  return 0;
}
