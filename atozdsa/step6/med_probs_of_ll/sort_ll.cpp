#include "LinkedList.h"
#include <bits/stdc++.h>
using namespace std;

int main() {
  Node *head = createLL(getInputsForLL());

  printLL(head);

  vector<int> arr;

  Node *temp = head;
  while (temp) {
    arr.push_back(temp->data);
    temp = temp->next;
  }

  sort(arr.begin(), arr.end());

  temp = head;
  int i = 0;
  while (temp) {
    temp->data = arr[i];
    temp = temp->next;
    i++;
  }

  printLL(head);

  return 0;
}
