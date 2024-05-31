#include "LinkedList.h"
using namespace std;

Node *removeMidNode(Node *head) {
  if (head == nullptr || head->next == nullptr) {
    return head;
  }
  Node *slow = head, *fast = head, *prevSlow = nullptr;
  while (fast && fast->next) {
    prevSlow = slow;
    slow = slow->next;
    fast = fast->next->next;
  }
  prevSlow->next = prevSlow->next->next;
  return head;
}

int main() {
  Node *head = createLL(getInputsForLL());

  printLL(head);
  head = removeMidNode(head);
  printLL(head);

  return 0;
}
