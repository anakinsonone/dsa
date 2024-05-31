#include "LinkedList.h"
#include <cmath>
using namespace std;

// Node *findMidNode(Node *head, int k) {
//   int count = 0;
//   Node *temp = head;
//   while (head->next) {
//     count++;
//     if (count == k)
//       return temp;
//     temp = temp->next;
//   }
//   return temp;
// }

Node *findMidNode(Node *head) {
  Node *slow = head, *fast = head;
  while (fast != NULL && fast->next != NULL) {
    slow = slow->next;
    fast = fast->next->next;
  }
  return slow;
}

int main() {
  int n;
  cin >> n;
  vector<int> arr(n, 0);
  for (int i = 0; i < n; i++)
    cin >> arr[i];

  Node *head = createLL(arr);
  int llLength = getSizeOfLL(head);
  int mid = ceil(llLength / 2);
  // Node *midNode = findMidNode(head, mid + 1);
  Node *midNode = findMidNode(head);
  cout << midNode->data;

  return 0;
}
