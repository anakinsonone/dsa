#include "LinkedList.h"
#include <bits/stdc++.h>
using namespace std;

int main() {
  Node *head1 = new Node(4);
  head1->next = new Node(1);
  head1->next->next = new Node(8);
  head1->next->next->next = new Node(4);
  head1->next->next->next->next = new Node(5);

  Node *head2 = new Node(5);
  head2->next = new Node(6);
  head2->next->next = new Node(1);
  head2->next->next->next = head1->next->next;

  // Brute force
  // Node *temp1 = head1, *temp2 = head2;
  // set<Node *> st;
  // while (temp1) {
  //   st.insert(temp1);
  //   temp1 = temp1->next;
  // }
  //
  // while (temp2) {
  //   if (st.find(temp2) != st.end()) {
  //     cout << "lists intersect at: " << temp2->data;
  //     break;
  //   }
  //   st.insert(temp2);
  //   temp2 = temp2->next;
  // }

  // Optimal

  int l1 = getSizeOfLL(head1);
  int l2 = getSizeOfLL(head2);
  Node *temp1 = head1, *temp2 = head2;
  int offset = 0;
  if (l1 > l2) {
    offset = l1 - l2;
    while (offset) {
      temp1 = temp1->next;
      offset--;
    }
  } else {
    offset = l2 - l1;
    while (offset) {
      temp2 = temp2->next;
      offset--;
    }
  }

  while (temp1->next != NULL && temp2->next != NULL) {
    if (temp1 == temp2) {
      cout << "lists intersect at: " << temp1->data;
      break;
    }
    temp1 = temp1->next;
    temp2 = temp2->next;
  }

  return 0;
}
