#include "LinkedList.h"
#include "bits/stdc++.h"
using namespace std;

int main() {
  Node *head = createLL(getInputsForLL());

  // vector<int> nums;
  // Node *temp = head;
  // while (temp != nullptr && temp->next != nullptr) {
  //   nums.push_back(temp->data);
  //   temp = temp->next->next;
  // }
  // if (temp)
  //   nums.push_back(temp->data);
  //
  // temp = head->next;
  // while (temp != nullptr && temp->next != nullptr) {
  //   nums.push_back(temp->data);
  //   temp = temp->next->next;
  // }
  // if (temp)
  //   nums.push_back(temp->data);
  //
  // temp = head;
  // int i = 0;
  // while (temp) {
  //   temp->data = nums[i];
  //   i++;
  //   temp = temp->next;
  // }

  Node *odd = head;
  Node *even = head->next;
  Node *evenHead = head->next;
  while (even != nullptr && even->next != nullptr) {
    odd->next = odd->next->next;
    odd = odd->next;
    even->next = even->next->next;
    even = even->next;
  }
  odd->next = evenHead;

  printLL(head);

  return 0;
}
