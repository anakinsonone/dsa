#include <bits/stdc++.h>

#include <string>
using namespace std;

int main() {
  string s;
  getline(cin, s);

  string word = "";
  string answer = "";
  for (int i = 0; i < s.length(); i++) {
    if (s[i] == ' ') {
      if (word.length() != 0) {
        answer.insert(0, word + " ");
        word = "";
      }
    } else {
      word += s[i];
    }
  }
  if (word.length() != 0) answer.insert(0, word + " ");
  cout << answer;
  return 0;
}
