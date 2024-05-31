#include <iostream>
#include <vector>

using namespace std;

long
factorial (long &factResult, long num)
{
  if (num < 1)
    return 1;
  factResult = num * factorial (factResult, num - 1);
  return factResult;
}

void
getFactorialNumbers (vector<long> &factNumbers, long limit, long &init)
{
  long factResult = 1;
  long factAnswer = factorial (factResult, init);
  if (factAnswer > limit)
    return;
  factNumbers.push_back (factAnswer);
  init = init + 1;
  getFactorialNumbers (factNumbers, limit, init);
}

int
main ()
{
  int limit;
  cin >> limit;
  vector<long> factNumbers;
  long factResult;
  long init = 1;
  getFactorialNumbers (factNumbers, limit, init);
  for (int i = 0; i < factNumbers.size (); i++)
    {
      cout << factNumbers[i] << " ";
    }
  return 0;
}
