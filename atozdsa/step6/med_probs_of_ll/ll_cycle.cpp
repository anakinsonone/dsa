#include "LinkedList.h"
#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

bool hasCycle(Node *head) {
  unordered_map<Node *, int> llMap;
  Node *temp = head;
  while (temp != NULL) {
    if (llMap.find(temp) != llMap.end()) {
      return true;
    }
    llMap[temp] = 1;
  }
  return false;
}

int main() {
  Node *head = new Node(0);
  Node *second = new Node(2);
  Node *third = new Node(3);
  Node *fourth = new Node(4);
  Node *fifth = new Node(5);

  head->next = second;
  second->next = third;
  third->next = fourth;
  fourth->next = fifth;
  // fifth->next = second;

  string ans = hasCycle(head) ? "true" : "false";

  cout << ans;

  return 0;
}
