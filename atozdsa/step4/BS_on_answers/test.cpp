#include <iostream>
#include <string>
using namespace std;

string addLargeNumbers(const std::string& num1, const std::string& num2) {
  string result;
  int carry = 0;

  for (int i = num1.size() - 1, j = num2.size() - 1; i >= 0 || j >= 0 || carry;
       i--, j--) {
    int digit1 = (i >= 0) ? (num1[i] - '0') : 0;
    int digit2 = (j >= 0) ? (num2[j] - '0') : 0;

    int sum = digit1 + digit2 + carry;

    carry = sum / 10;
    result.insert(0, 1, '0' + (sum % 10));
  }

  return result;
}

int main() {
  string num1 = "1555555555555555555500";
  string num2 = "20";

  string sum = addLargeNumbers(num1, num2);

  cout << "Sum: " << sum << std::endl;

  return 0;
}
