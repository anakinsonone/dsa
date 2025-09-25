/*
 * A path in a binary tree is a sequence of nodes where each pair of adjacent
 * nodes in the sequence has an edge connecting them. A node can only appear in
 * the sequence at most once. Note that the path does not need to pass through
 * the root.
*  The path sum of a path is the sum of the node's values in the path.
*  Given the root of a binary tree, return the maximum path sum of any non-empty
*  path.

*  Example 1:
*  Input: root = [1,2,3]
*  Output: 6
*  Explanation: The optimal path is 2 -> 1 -> 3 with a path sum of 2 + 1 + 3
= 6.

*  Example 2:
*  Input: root = [-10,9,20,null,null,15,7]
*  Output: 42
*  Explanation: The optimal path is 15 -> 20 -> 7 with a path sum of 15 + 20 + 7
= 42.

 *  Constraints:
 *  The number of nodes in the tree is in the range [1, 3 * 104].
 *  -1000 <= Node.val <= 1000
 */
#include <algorithm>
#include <climits>
#include <iostream>
#include <optional>
#include <vector>

#include "BinaryTree.h"

int dfs(BinaryTree::TreeNode<int>* root, int& res) {
  if (!root) {
    return 0;
  }

  int maxL = std::max(dfs(root->left, res), 0);
  int maxR = std::max(dfs(root->right, res), 0);

  res = std::max(res, maxL + maxR + root->value);

  return root->value + std::max(maxL, maxR);
}

int main() {
  int n;
  std::cin >> n;
  std::vector<std::optional<int>> nums(n);
  for (int i = 0; i < n; i++) {
    int num;
    std::cin >> num;
    if (num == -99) {
      nums[i] = std::nullopt;
    } else {
      nums[i] = num;
    }
  }

  BinaryTree::TreeNode<int>* root = BinaryTree::createBinaryTree(nums);
  BinaryTree::printPretty(root);
  // BinaryTree::printBinaryTree(root);
  //
  int res = root->value;
  dfs(root, res);
  //
  std::cout << res;

  return 0;
}
