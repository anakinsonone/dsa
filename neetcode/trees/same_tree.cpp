/*Given the roots of two binary trees p and q, return true if the trees are
 * equivalent, otherwise return false.

 * Two binary trees are considered equivalent if they share the exact same
 * structure and the nodes have the same values.

 * Example 1:
 * Input: p = [1,2,3], q = [1,2,3]
 * Output: true

 * Example 2:
 * Input: p = [4,7], q = [4,null,7]
 * Output: false

 * Example 3:
 * Input: p = [1,2,3], q = [1,3,2]
 * Output: false

 * Constraints:
 * - 0 <= The number of nodes in both trees <= 100.
 * - -100 <= Node.val <= 100
 */

#include <iostream>
#include <optional>
#include <vector>

#include "BinaryTree.h"

bool areSame(BinaryTree::TreeNode<int>* p, BinaryTree::TreeNode<int>* q) {
  if (!p && !q) return true;

  if (p && q && p->value == q->value) {
    return areSame(p->left, q->left) && areSame(p->right, q->right);
  } else {
    return false;
  }
}

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

  BinaryTree::TreeNode<int>* p = BinaryTree::createBinaryTree(mNums);
  BinaryTree::TreeNode<int>* q = BinaryTree::createBinaryTree(nNums);

  std::cout << (areSame(p, q) ? "true" : "false");

  return 0;
}
