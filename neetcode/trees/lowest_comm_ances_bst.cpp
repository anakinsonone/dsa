/*Given a binary search tree (BST) where all node values are unique, and two
 * nodes from the tree p and q, return the lowest common ancestor (LCA) of the
 *  two nodes.

 * The lowest common ancestor between two nodes p and q is the lowest node in a
 * tree T such that both p and q as descendants. The ancestor is allowed to be a
 * descendant of itself.

 * Example 1:
 * Input: root = [5,3,8,1,4,7,9,null,2], p = 3, q = 8
 * Output: 5

 * Example 2:
 * Input: root = [5,3,8,1,4,7,9,null,2], p = 3, q = 4
 * Output: 3
 * Explanation: The LCA of nodes 3 and 4 is 3, since a node can be a descendant
 * of itself.

 * Constraints:
 * 2 <= The number of nodes in the tree <= 100.
 * -100 <= Node.val <= 100
 * p != q
 * p and q will both exist in the BST.
 */
#include <algorithm>
#include <iostream>
#include <optional>
#include <vector>

#include "BinaryTree.h"

BinaryTree::TreeNode<int>* findLowestCommonAnc(BinaryTree::TreeNode<int>* root,
                                               BinaryTree::TreeNode<int>* p,
                                               BinaryTree::TreeNode<int>* q) {
  if (!root || !p || !q) return nullptr;

  if (std::min(p->value, q->value) > root->value) {
    return findLowestCommonAnc(root->right, p, q);
  } else if (std::max(p->value, q->value) < root->value) {
    return findLowestCommonAnc(root->left, p, q);
  } else {
    return root;
  }
}

int main() {
  int n, r1, r2;
  std::cin >> n >> r1 >> r2;
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

  BinaryTree::TreeNode<int>* p = new BinaryTree::TreeNode<int>(r1);
  BinaryTree::TreeNode<int>* q = new BinaryTree::TreeNode<int>(r2);

  BinaryTree::TreeNode<int>* curr = root;
  BinaryTree::TreeNode<int>* lca;

  while (curr) {
    if (p->value > curr->value && q->value > curr->value) {
      curr = curr->right;
    } else if (p->value < curr->value && q->value < curr->value) {
      curr = curr->left;
    } else {
      lca = curr;
      break;
    }
  }

  // lca = findLowestCommonAnc(root, p, q);

  std::cout << lca->value;

  return 0;
}
