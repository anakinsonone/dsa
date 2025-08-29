/*
 * Given root of binary tree, return the inorder traversal of the binary
 * tree.
 */
#include <iostream>
#include <optional>
#include <stack>
#include <vector>

#include "BinaryTree.h"

void inorderTraversal(BinaryTree::TreeNode<int> *root, std::vector<int> &arr) {
  if (!root) return;

  inorderTraversal(root->left, arr);
  arr.push_back(root->value);
  inorderTraversal(root->right, arr);
}

void iterativeInorder(BinaryTree::TreeNode<int> *root, std::vector<int> &arr) {
  if (!root) return;

  std::stack<BinaryTree::TreeNode<int> *> st;
  BinaryTree::TreeNode<int> *curr = root;

  while (!st.empty() || curr != nullptr) {
    while (curr != nullptr) {
      st.push(curr);
      curr = curr->left;
    }
    curr = st.top();
    st.pop();

    arr.push_back(curr->value);
    curr = curr->right;
  }
}

int main() {
  int n;
  std::cin >> n;
  std::vector<std::optional<int>> nums(n);

  for (int i = 0; i < n; i++) {
    int num;
    std::cin >> num;
    if (num == -101) {
      nums[i] = std::nullopt;
    } else {
      nums[i] = num;
    }
  }

  BinaryTree::TreeNode<int> *root = BinaryTree::createBinaryTree(nums);
  BinaryTree::printBinaryTree(root);

  std::vector<int> res;

  // inorderTraversal(root, res);
  iterativeInorder(root, res);
  std::cout << "inorder: ";
  for (int r : res) {
    std::cout << r << ' ';
  }

  return 0;
}
