#include <iostream>
#include <vector>

void
fibonacci (std::vector<int> &series, int init, int limit)
{
  if (init >= limit)
    {
      return;
    }
  else if (init <= 1)
    {
      series.push_back (init);
    }
  else
    {
      series.push_back (series[init - 1] + series[init - 2]);
    }
  fibonacci (series, init + 1, limit);
}

int
main ()
{
  int limit;
  std::cin >> limit;
  int init = 0;
  std::vector<int> series;
  fibonacci (series, init, limit);
  for (int i = 0; i < series.size (); i++)
    {
      std::cout << series[i] << " ";
    }
  return 0;
}
