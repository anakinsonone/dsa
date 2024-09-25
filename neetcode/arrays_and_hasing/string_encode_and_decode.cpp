/*
 * String Encode and Decode

 * Design an algorithm to encode a list of strings to a single string. The
 encoded string is then decoded back to the original list of strings.

 * Please implement encode and decode

 * Example 1:
 * Input: ["neet","code","love","you"]
 * Output:["neet","code","love","you"]

 * Example 2:
 * Input: ["we","say",":","yes"]
 * Output: ["we","say",":","yes"]

*/
#include <iostream>
#include <string>
#include <vector>

std::string encode(std::vector<std::string> strs) {
  std::string encodedString;
  for (auto &s : strs) {
    encodedString += std::to_string(s.length()) + "#" + s;
  }

  return encodedString;
}

std::vector<std::string> decode(std::string s) {
  std::vector<std::string> answer;

  int i = 0;
  while (i < s.length()) {
    int j = i;
    while (s[j] != '#') {
      j++;
    }

    int length = std::stoi(s.substr(i, j - i));
    std::string str = s.substr(j + 1, length);
    answer.push_back(str);
    i = j + 1 + length;
  }

  return answer;
}

int main() {
  int n;
  std::cin >> n;
  std::vector<std::string> words(n);
  for (int i = 0; i < n; i++) {
    std::cin >> words[i];
  }

  std::string en = encode(words);
  std::cout << en << '\n';
  std::vector<std::string> de = decode(en);
  for (auto &s : de) {
    std::cout << s << ' ';
  }

  return 0;
}
