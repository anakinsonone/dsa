#include <iostream>

using namespace std;

long
factorial (long &factResult, long num)
{
  if (num < 1)
    return 1;
  factResult = num * factorial (factResult, num - 1);
  return factResult;
}

int
main ()
{
  int number;
  cout << "Enter a number: ";
  cin >> number;
  long factResult = 1;
  factorial (factResult, number);
  cout << factResult << ' ';
  return 0;
}
