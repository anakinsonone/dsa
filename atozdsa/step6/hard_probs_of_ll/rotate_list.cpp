#include "LinkedList.h"
using namespace std;

int main() {
  Node *head = createLL(getInputsForLL());
  Node *tail = head;
  while (tail->next) {
    tail = tail->next;
  }
  int k;
  cin >> k;
  int totLength = getSizeOfLL(head);

  k = totLength - k % totLength;
  Node *temp = head;
  Node *prev = nullptr;
  while (k > 0 && temp != NULL) {
    k--;
    prev = temp;
    temp = temp->next;
  }

  tail->next = head;
  prev->next = nullptr;
  head = temp;
  printLL(head);

  return 0;
}
