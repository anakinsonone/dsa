#include <bits/stdc++.h>
#include <vector>
using namespace std;

struct Node {
public:
  int data;
  Node *next;
  Node(int d, Node *n) {
    data = d;
    next = n;
  }
  Node(int d) {
    data = d;
    next = nullptr;
  }
};

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

void printLL(Node *head) {
  Node *temp = head;
  while (temp) {
    cout << temp->data << ' ';
    temp = temp->next;
  }
}

Node *insertInitially(Node *head, int newValue) {
  Node *newHead = new Node(newValue, head);
  head = newHead;
  return newHead;
}

int main() {
  int n, k;
  cin >> n >> k;
  vector<int> arr(n, 0);
  for (int i = 0; i < arr.size(); i++)
    cin >> arr[i];

  Node *head = createLL(arr);
  printLL(head);
  cout << '\n';
  Node *newHead = insertInitially(head, k);
  printLL(newHead);

  return 0;
}
