#include "DoublyLinkedList.h"
using namespace std;

Node *reverseDLL(Node *head) {
  if (head == NULL || head->next == NULL) {
    return head;
  }
  Node *prevNode = NULL;
  Node *currNode = head;
  while (currNode != NULL) {
    prevNode = currNode->previous;

    currNode->previous = currNode->next;
    currNode->next = prevNode;

    currNode = currNode->previous;
  }
  return prevNode->previous;
}

int main() {
  int n;
  cin >> n;
  vector<int> arr(n, 0);
  for (int i = 0; i < n; i++)
    cin >> arr[i];

  Node *head = createDLL(arr);
  head = reverseDLL(head);
  printDLL(head);

  return 0;
}
