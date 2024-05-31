#include "LinkedList.h"
#include <cstdlib>
using namespace std;

Node *removeNthFromEnd(Node *head, int pos) {
  int llsize = getSizeOfLL(head);
  if (pos == llsize) {
    Node *prevHead = head;
    head = head->next;
    free(prevHead);
    return head;
  }
  if (pos == 1) {
    Node *tail = head;
    Node *prev = nullptr;
    while (tail->next) {
      prev = tail;
      tail = tail->next;
    }
    prev->next = nullptr;
    free(tail);
    return head;
  }
  int n = llsize - pos - 1;
  Node *temp = head;
  while (n) {
    n--;
    temp = temp->next;
  }
  Node *nextNode = temp->next;
  temp->next = temp->next->next;
  free(nextNode);
  return head;
}

int main() {
  Node *head = createLL(getInputsForLL());

  int n;
  cin >> n;

  head = removeNthFromEnd(head, n);
  printLL(head);

  return 0;
}
