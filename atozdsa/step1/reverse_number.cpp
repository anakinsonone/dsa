#include <iostream>

int main() {
  int num;
  int reverse = 0;

  std::cout << "Enter a number: ";
  std::cin >> num;

  while (num != 0) {
    int digit = num % 10;
    reverse = reverse * 10 + digit;
    num = num / 10;
  }
  std::cout << reverse;
  return 0;
}
