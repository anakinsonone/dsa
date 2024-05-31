#include "LinkedList.h"
using namespace std;

int main() {
  Node *head1 = createLL(getInputsForLL());
  Node *head2 = createLL(getInputsForLL());
  int carry = 0;

  Node *newHead = new Node(0), *temp = newHead;
  Node *t1 = head1, *t2 = head2;
  while (t1 != NULL || t2 != NULL || carry) {
    int sum = 0;

    if (t1 != NULL) {
      sum += t1->data;
      t1 = t1->next;
    }
    if (t2 != NULL) {
      sum += t2->data;
      t2 = t2->next;
    }

    sum += carry;
    carry = sum / 10;
    Node *newNode = new Node(sum % 10);
    temp->next = newNode;
    temp = newNode;
  }

  printLL(newHead->next);

  return 0;
}
