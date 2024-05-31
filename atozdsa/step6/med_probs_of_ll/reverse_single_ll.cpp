#include "LinkedList.h"
using namespace std;

Node *reverseLL(Node *head) {
  Node *prevNode = NULL;
  Node *currNode = head;
  while (currNode != NULL) {
    Node *nextNode = currNode->next;
    currNode->next = prevNode;
    prevNode = currNode;
    currNode = nextNode;
  }
  return prevNode;
}

int main() {
  vector<int> arr = getInputsForLL();
  Node *head = createLL(arr);

  head = reverseLL(head);
  printLL(head);

  return 0;
}
