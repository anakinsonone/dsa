/*Within a binary tree, a node x is considered good if the path from the root of
 * the tree to the node x contains no nodes with a value greater than the value
 * of node x

 * Given the root of a binary tree root, return the number of good nodes within
 * the tree.

 * Example 1:
 * Input: root = [2,1,1,3,null,1,5]
 * Output: 3

 * Example 2:
 * Input: root = [1,2,-1,3,4]
 * Output: 4

 * Constraints:
 * 1 <= number of nodes in the tree <= 100
 * -100 <= Node.val <= 100
*/

#include <algorithm>
#include <iostream>
#include <optional>
#include <stack>
#include <utility>
#include <vector>

#include "BinaryTree.h"

int goodNodes(BinaryTree::TreeNode<int>* root) {
  int c = 0;
  if (!root) return c;

  std::stack<std::pair<BinaryTree::TreeNode<int>*, int>> st;
  st.push({root, root->value});

  while (!st.empty()) {
    std::pair<BinaryTree::TreeNode<int>*, int> curr = st.top();
    st.pop();

    if (curr.first->value >= curr.second) c++;

    if (curr.first->left) {
      st.push({curr.first->left, std::max(curr.first->value, curr.second)});
    }

    if (curr.first->right) {
      st.push({curr.first->right, std::max(curr.first->value, curr.second)});
    }
  }

  return c;
}

#include "BinaryTree.h"
int main() {
  int n;
  std::cin >> n;
  std::vector<std::optional<int>> nums(n);
  for (int i = 0; i < n; i++) {
    int num;
    std::cin >> num;
    if (num == -999) {
      nums[i] = std::nullopt;
    } else {
      nums[i] = num;
    }
  }

  BinaryTree::TreeNode<int>* root = BinaryTree::createBinaryTree(nums);
  BinaryTree::printBinaryTree(root);

  int res = goodNodes(root);
  std::cout << res;

  return 0;
}
