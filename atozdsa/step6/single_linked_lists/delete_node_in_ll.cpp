#include "LinkedList.h"
#include <cstddef>
#include <iostream>
using namespace std;

void deleteNode(Node *head, int target) {
  Node *temp = head;
  Node *prev = NULL;
  while (temp) {
    if (temp->data == target) {
      prev->next = temp->next;
      break;
    }
    prev = temp;
    temp = temp->next;
  }
}

int main() {
  int n;
  cin >> n;
  vector<int> arr(n, 0);
  for (int i = 0; i < arr.size(); i++)
    cin >> arr[i];

  Node *head = createLL(arr);
  printLL(head);
  deleteNode(head, 1);
  cout << '\n';
  printLL(head);

  return 0;
}
