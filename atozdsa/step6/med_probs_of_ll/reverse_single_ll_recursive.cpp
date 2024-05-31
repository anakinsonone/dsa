#include "LinkedList.h"
using namespace std;

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

int main() {
  vector<int> arr = getInputsForLL();
  Node *head = createLL(arr);

  head = reverseLLRecursively(head);
  printLL(head);

  return 0;
}
