#include <iostream>
#include <vector>

using namespace std;

vector<int> answer;

void
appendNumbers (int current, int limit)
{
  if (current > limit)
    return;
  answer.push_back (current);
  appendNumbers (current + 1, limit);
}

int
main ()
{
  appendNumbers (1, 5);
  for (int i = 0; i < answer.size (); i++)
    {
      cout << answer[i] << " ";
    }
}
