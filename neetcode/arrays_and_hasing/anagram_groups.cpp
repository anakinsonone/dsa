/*
 * Anagram Groups

 * Given an array of strings strs, group all anagrams together into sublists.
 You may return the output in any order.

 * An anagram is a string that contains the exact same characters as another
 string, but the order of the characters can be different.

 * Example 1:
 * Input: strs = ["act","pots","tops","cat","stop","hat"]
 * Output: [["hat"],["act", "cat"],["stop", "pots", "tops"]]

 * Example 2:
 * Input: strs = ["x"]
 * Output: [["x"]]

 * Example 3:
 * Input: strs = [""]
 * Output: [[""]]
*/

#include <bits/stdc++.h>
#include <iostream>

int main() {
  int n;
  std::cin >> n;

  std::vector<std::string> anagrams;
  for (int i = 0; i < n; i++) {
    std::string s;
    std::cin >> s;
    anagrams.push_back(s);
  }

  std::unordered_map<std::string, std::vector<std::string>> ans;

  for (auto &s : anagrams) {
    std::vector<int> count(26, 0);

    for (auto c : s) {
      count[c - 'a']++;
    }

    std::string key;
    for (auto i : count) {
      key += std::to_string(i);
    }

    ans[key].push_back(s);
  }

  std::vector<std::vector<std::string>> result;
  for (auto it : ans) {
    result.push_back(it.second);
  }

  std::cout << '[';
  for (auto it : result) {
    std::cout << '[';
    for (auto s : it) {
      std::cout << s << " ";
    }
    std::cout << "]";
  }
  std::cout << ']';

  return 0;
}
