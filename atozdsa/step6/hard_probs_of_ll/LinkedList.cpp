#include "LinkedList.h"
using namespace std;

vector<int> getInputsForLL() {
  int n;
  cin >> n;
  vector<int> arr(n, 0);
  for (int i = 0; i < n; i++) {
    cin >> arr[i];
  }
  return arr;
}

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
    cout << temp->data << " -> ";
    temp = temp->next;
  }
  cout << '\n';
}

int getSizeOfLL(Node *head) {
  int count = 0;
  Node *temp = head;
  while (temp) {
    temp = temp->next;
    count++;
  }
  return count;
}

Node *reverseLLRecursively(Node *head) {
  if (head == NULL || head->next == NULL) {
    return head;
  }

  Node *newHead = reverseLLRecursively(head->next);

  Node *nextNode = head->next;

  nextNode->next = head;
  head->next = NULL;

  return newHead;
}
