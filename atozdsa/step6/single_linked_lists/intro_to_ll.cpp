#include "LinkedList.h"
#include <bits/stdc++.h>
using namespace std;

Node *createLL(vector<int> arr) {
  Node *head = new Node(arr[0]);
  Node *mover = head;
  for (int i = 1; i < arr.size(); i++) {
    Node *temp = new Node(arr[i]);
    mover->next = temp;
    mover = temp;
  }
  return head;
}

void traverseLL(Node *head) {
  Node *temp = head;
  while (temp) {
    cout << temp->data << ' ';
    temp = temp->next;
  }
}

int lengthLL(Node *head) {
  int count = 0;
  Node *temp = head;
  while (temp) {
    temp = temp->next;
    count++;
  }
  return count;
}

bool searchLL(Node *head, int val) {
  Node *temp = head;
  while (temp) {
    if (temp->data == val)
      return true;
    temp = temp->next;
  }
  return false;
}

int main() {
  int n;
  cin >> n;
  vector<int> arr(n, 0);
  for (int i = 0; i < n; i++)
    cin >> arr[i];

  Node *head = createLL(arr);
  cout << head->data << '\n';
  traverseLL(head);
  cout << '\n';
  cout << lengthLL(head) << '\n';
  cout << searchLL(head, 13);

  return 0;
}
