#include <iostream>

int
main ()
{
  int array_size;
  std::cin >> array_size;
  int arr[array_size];
  for (int i = 0; i < array_size; i++)
    {
      std::cin >> arr[i];
    }

  int hash[13] = { 0 };
  for (int i = 0; i < array_size; i++)
    {
      hash[arr[i]] += 1;
    }

  int queries;
  std::cin >> queries;
  while (queries--)
    {
      int number;
      std::cin >> number;
      std::cout << hash[number] << std::endl;
    }
  return 0;
}
