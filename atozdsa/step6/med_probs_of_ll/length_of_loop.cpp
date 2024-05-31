#include "LinkedList.h"
#include <algorithm>
#include <unordered_map>
using namespace std;

void loopHere(Node *head, Node *tail, int pos) {
  if (pos == 0)
    return;

  Node *walk = head;
  for (int i = 1; i < pos; i++) {
    walk = walk->next;
  }

  tail->next = walk;
}

int main() {
  int n, num, pos;
  cin >> n >> num;

  Node *head, *tail;
  head = tail = new Node(num);

  for (int i = 0; i < n - 1; i++) {
    cin >> num;
    tail->next = new Node(num);
    tail = tail->next;
  }

  cin >> pos;
  loopHere(head, tail, pos);

  unordered_map<Node *, int> nodemap;
  Node *temp = head;
  int count = 1, length;
  while (temp->next != NULL) {
    if (nodemap.find(temp) != nodemap.end()) {
      int val = nodemap[temp];
      length = count - val;
      break;
    }
    nodemap[temp] = count;
    count++;
    temp = temp->next;
  }

  cout << length;

  return 0;
}
