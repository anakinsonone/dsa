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
#include <iostream>

bool isAlphaNum(char c) {
  if ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z') ||
      (c >= '0' && c <= '9'))
    return true;
  else
    return false;
}

bool isPalindrome(std::string s) {
  int l = 0, r = s.length() - 1;

  while (l <= r) {
    while (!isAlphaNum(s[l]) && l < r)
      l++;
    while (!isAlphaNum(s[r]) && r > l)
      r--;

    char lowL = tolower(s[l]);
    char lowR = tolower(s[r]);
    if (lowL != lowR)
      return false;

    l++;
    r--;
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
