#include "LinkedList.h"
#include <bits/stdc++.h>
using namespace std;

int main() {
  Node *head = createLL(getInputsForLL());

  // Brute force
  // stack<int> st;
  //
  // Node *temp = head;
  // while (temp) {
  //   st.push(temp->data);
  //   temp = temp->next;
  // }
  //
  // bool isPalindrome = true;
  // temp = head;
  // while (temp) {
  //   int val = st.top();
  //   if (val != temp->data) {
  //     isPalindrome = false;
  //     break;
  //   }
  //   st.pop();
  //   temp = temp->next;
  // }
  // cout << isPalindrome;

  Node *slow = head;
  Node *fast = head;

  while (fast->next->next != NULL && fast->next != NULL) {
    slow = slow->next;
    fast = fast->next->next;
  }

  Node *newHead = reverseLLRecursively(slow->next);

  Node *first = head;
  Node *second = newHead;
  bool isPalindrome = true;

  while (second) {
    if (first->data != second->data) {
      reverseLLRecursively(newHead);
      isPalindrome = false;
      break;
    }
    first = first->next;
    second = second->next;
  }
  cout << isPalindrome;

  return 0;
}
