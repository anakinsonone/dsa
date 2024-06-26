#include "DoublyLinkedList.h"
#include <bits/stdc++.h>
using namespace std;

int main() {
  Node *head = createDLL(getInputsForDLL());
  int target;
  cin >> target;

  Node *left = head, *right = head;
  while (right->next) {
    right = right->next;
  }

  vector<pair<int, int>> ans;
  while (left->data < right->data) {
    if (left->data + right->data == target) {
      ans.push_back({left->data, right->data});
      left = left->next;
      right = right->previous;
    } else if (left->data + right->data > target) {
      right = right->previous;
    } else {
      left = left->next;
    }
  }

  for (int i = 0; i < ans.size(); i++) {
    cout << ans[i].first << ", " << ans[i].second << '\n';
  }

  return 0;
}
