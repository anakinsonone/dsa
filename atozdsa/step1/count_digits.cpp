#include <vector>

std::vector<int> digits;
void getDigits(int n) {
  if (n > 10) {
    getDigits(n / 10);
  }
  int digit = n % 10;
  digits.push_back(digit);
}
int main(int num) {
  int count = 0;
  int originalNum = num;
  getDigits(originalNum);
  for (int i = 0; i < digits.size(); i++) {
    if (num % digits[i] == 0)
      count++;
  }
  return count;
}
