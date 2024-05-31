#include <iostream>
#include <map>
#include <unordered_map>
int
main ()
{
  int n;
  std::cin >> n;
  int arr[n];
  for (int i = 0; i < n; i++)
    {
      std::cin >> arr[i];
    }

  // pre-fetch

  // this is an ordered map
  // time complexity in best, average and worst is O(log n);
  std::map<int, int> ordered_map;
  for (int i = 0; i < n; i++)
    {
      ordered_map[arr[i]]++;
    }

  // this is an unordered map
  // time complexity in best & average cases is O(1), but worst case is O(n)
  std::unordered_map<int, int> unordered_map;
  for (int i = 0; i < n; i++)
    {
      unordered_map[arr[i]]++;
    }

  // this is how we can iterate through a map
  // for (auto it : hashmap)
  //   {
  //     std::cout << it.first << " --> " << it.second << std::endl;
  //   }

  int q;
  std::cin >> q;
  while (q--)
    {
      int number;
      std::cin >> number;
      std::cout << unordered_map[number] << std::endl;
    }
  return 0;
}
