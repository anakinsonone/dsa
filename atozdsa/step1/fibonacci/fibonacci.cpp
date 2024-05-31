#include <iostream>
#include <vector>

int
main ()
{
  std::cout << "Enter a number: ";
  int limit;
  std::cin >> limit;
  int init = 0;
  std::vector<int> series;
  while (init < limit)
    {
      if (init <= 1)
        {
          series.push_back (init);
        }
      else
        {
          series.push_back (series[init - 1] + series[init - 2]);
        }
      init += 1;
    }
  for (int i = 0; i < series.size (); i++)
    {
      std::cout << series[i] << " ";
    }
  return 0;
}
