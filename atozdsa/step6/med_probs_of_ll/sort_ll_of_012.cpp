#include "LinkedList.h"
using namespace std;

int main() {
  Node *head = createLL(getInputsForLL());

  printLL(head);

  Node *zeroHead = new Node(-1), *zero = zeroHead;
  Node *oneHead = new Node(-1), *one = oneHead;
  Node *twoHead = new Node(-1), *two = twoHead;

  Node *temp = head;

  while (temp) {
    if (temp->data == 0) {
      zero->next = temp;
      zero = zero->next;
    } else if (temp->data == 1) {
      one->next = temp;
      one = one->next;
    } else if (temp->data == 2) {
      two->next = temp;
      two = two->next;
    }
    temp = temp->next;
  }

  zero->next = (oneHead->next) ? oneHead->next : twoHead->next;
  one->next = twoHead->next;
  two->next = nullptr;
  Node *newHead = zeroHead->next;

  printLL(newHead);

  return 0;
}
