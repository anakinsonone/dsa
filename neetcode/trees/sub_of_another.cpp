/*Given the roots of two binary trees root and subRoot, return true if there is
 * a subtree of root with the same structure and node values of subRoot and
 * false otherwise.

 * A subtree of a binary tree tree is a tree that consists of a node in tree and
 * all of this node's descendants. The tree tree could also be considered as a
 * subtree of itself.

 * Example 1:
 * Input: root = [1,2,3,4,5], subRoot = [2,4,5]
 * Output: true

 * Example 2:
 * Input: root = [1,2,3,4,5,null,null,6], subRoot = [2,4,5]
 * Output: false

 * Constraints:
 * 0 <= The number of nodes in both trees <= 100.
 * -100 <= root.val, subRoot.val <= 100
 */
#include <iostream>
#include <optional>
#include <vector>

#include "BinaryTree.h"

int main() {
  int m, n;
  std::cin >> m >> n;
  std::vector<std::optional<int>> mNums(m), nNums(n);

  for (int i = 0; i < m; i++) {
    int num;
    std::cin >> num;
    if (num == -1) {
      mNums[i] = std::nullopt;
    } else {
      mNums[i] = num;
    }
  }
  for (int i = 0; i < n; i++) {
    int num;
    std::cin >> num;
    if (num == -1) {
      nNums[i] = std::nullopt;
    } else {
      nNums[i] = num;
    }
  }

  BinaryTree::TreeNode<int>* root = BinaryTree::createBinaryTree(mNums);
  BinaryTree::TreeNode<int>* subroot = BinaryTree::createBinaryTree(nNums);

  return 0;
}
