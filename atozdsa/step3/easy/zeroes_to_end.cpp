#include <bits/stdc++.h>
#include <utility>
using namespace std;

void
left_rotate (int arr[], int n, int k)
{
  reverse (arr, arr + k);
  reverse (arr + k, arr + n);
  reverse (arr, arr + n);
}

int
main ()
{
  int n;
  cin >> n;
  int arr[n];
  for (int i = 0; i < n; i++)
    cin >> arr[i];

  // int i = 0, j = n;
  // while (i < j) {
  //   if (arr[i] == 0) {
  //     left_rotate(arr, j, 1);
  //     j--;
  //   } else
  //     i++;
  // }
  // another method
  int j = -1;
  for (int i = 0; i < n; i++)
    {
      if (arr[i] == 0)
        {
          j = i;
          break;
        }
    }

  for (int i = j + 1; i < n; i++)
    {
      if (arr[i] != 0)
        {
          swap (arr[i], arr[j]);
          j++;
        }
    }

  for (int i = 0; i < n; i++)
    cout << arr[i] << ' ';
}
