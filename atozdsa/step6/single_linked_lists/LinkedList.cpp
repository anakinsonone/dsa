#include "LinkedList.h"
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

void printLL(Node *head) {
  Node *temp = head;
  while (temp) {
    cout << temp->data << ' ';
    temp = temp->next;
  }
}

int printSizeOfLL(Node *head) {
  int count = 0;
  Node *temp = head;
  while (temp) {
    temp = temp->next;
    count++;
  }
  return count;
}
