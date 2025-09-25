/*
 * Given two integer arrays preorder and inorder where preorder is the preorder
 * traversal of a binary tree and inorder is the inorder traversal of the same
 * tree, construct and return the binary tree.

 * Example 1:
 * Input: preorder = [3,9,20,15,7], inorder = [9,3,15,20,7]
 * Output: [3,9,20,null,null,15,7]

 * Example 2:
 * Input: preorder = [-1], inorder = [-1]
 * Output: [-1]


 * Constraints:
 * 1 <= preorder.length <= 3000
 * inorder.length == preorder.length
 * -3000 <= preorder[i], inorder[i] <= 3000
 * preorder and inorder consist of unique values.
 * Each value of inorder also appears in preorder.
 * preorder is guaranteed to be the preorder traversal of the tree.
 * inorder is guaranteed to be the inorder traversal of the tree.
 */
#include <algorithm>
#include <climits>
#include <iostream>
#include <vector>

#include "BinaryTree.h"

BinaryTree::TreeNode<int>* createBTree(std::vector<int> pre,
                                       std::vector<int> in) {
  if (!pre.size() || !in.size()) return nullptr;

  BinaryTree::TreeNode<int>* root = new BinaryTree::TreeNode<int>(pre[0]);

  int mid = std::find(in.begin(), in.end(), pre[0]) - in.begin();
  std::vector<int> leftPre(pre.begin() + 1, pre.begin() + mid + 1);
  std::vector<int> rightPre(pre.begin() + mid + 1, pre.end());
  std::vector<int> leftIn(in.begin(), in.begin() + mid);
  std::vector<int> rightIn(in.begin() + mid + 1, in.end());

  root->left = createBTree(leftPre, leftIn);
  root->right = createBTree(rightPre, rightIn);

  return root;
}

int preIdx = 0, inIdx = 0;
BinaryTree::TreeNode<int>* dfs(std::vector<int> preorder,
                               std::vector<int> inorder, int limit) {
  if (preIdx >= preorder.size()) return nullptr;
  if (inorder[inIdx] == limit) {
    inIdx++;
    return nullptr;
  }

  BinaryTree::TreeNode<int>* root =
      new BinaryTree::TreeNode<int>(preorder[preIdx++]);
  root->left = dfs(preorder, inorder, root->value);
  root->right = dfs(preorder, inorder, limit);

  return root;
}

int main() {
  int n;
  std::cin >> n;
  std::vector<int> preorder(n), inorder(n);
  for (int i = 0; i < n; i++) {
    std::cin >> preorder[i];
  }
  for (int i = 0; i < n; i++) {
    std::cin >> inorder[i];
  }

  // BinaryTree::TreeNode<int>* root = createBTree(preorder, inorder);
  BinaryTree::TreeNode<int>* root = dfs(preorder, inorder, INT_MAX);
  BinaryTree::printBinaryTree(root);

  return 0;
}
