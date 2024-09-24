/*
 * Is Palindrome

 * Given a string s, return true if it is a palindrome, otherwise return false.

 * A palindrome is a string that reads the same forward and backward. It is also
 case-insensitive and ignores all non-alphanumeric characters.
*
 * Example 1:
 * Input: s = "Was it a car or a cat I saw?"
 * Output: true
 * Explanation: After considering only alphanumerical characters we have
 "wasitacaroracatisaw", which is a palindrome.
*
 * Example 2:
 * Input: s = "tab a cat"
 * Output: false
 * Explanation: "tabacat" is not a palindrome.
*/
#include <bits/stdc++.h>

std::string processString(std::string s) {
  std::string sanitizedS;
  for (int i = 0; i < s.length(); i++) {
    if (!(s[i] < 'A' || s[i] > 'Z' && s[i] < 'a' || s[i] > 'z')) {
      char c = std::tolower(s[i]);
      sanitizedS += c;
    }
  }

  std::cout << sanitizedS << '\n';
  return sanitizedS;
}

bool isPalindrome(std::string s) {
  s = processString(s);

  int i = 0, j = s.length() - 1;
  while (i <= j) {
    if (s[i] != s[j])
      return false;
    i++;
    j--;
  }

  return true;
}

int main() {
  std::string s;
  std::getline(std::cin, s);

  bool res = isPalindrome(s);

  std::cout << (res ? "true" : "false");

  return 0;
}
