#include <iostream>
#include <string>

int
main ()
{
  std::string input;
  std::cin >> input;

  // prefilling
  int hash[26] = { 0 };
  for (int i = 0; i < input.length (); i++)
    {
      hash[input[i] - 'a'] += 1;
    }

  int queries;
  std::cin >> queries;
  while (queries--)
    {
      // fetch
      char character;
      std::cin >> character;
      std::cout << hash[character - 'a'] << std::endl;
    }
  return 0;
}
