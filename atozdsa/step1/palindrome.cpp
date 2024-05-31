#include <iostream>
#include <string>

using namespace std;

bool
is_palindrome (int init, string &input)
{
  if (init >= input.length () / 2)
    return true;

  if (input[init] != input[input.length () - init - 1])
    return false;

  return is_palindrome (init + 1, input);
}

int
main ()
{
  string input;
  std::cin >> input;
  bool isPalin = is_palindrome (0, input);
  cout << (isPalin ? "true" : "false");
  return 0;
}
