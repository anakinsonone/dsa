#include <bits/stdc++.h>
using namespace std;

int
partition_index (int arr[], int low, int high)
{
  int pivot = arr[low];
  int left = low;
  int right = high;
  while (left < right)
    {
      while (arr[left] <= pivot && left < high)
        {
          left++;
        }
      while (arr[right] > pivot && right > low)
        {
          right--;
        }
      if (left < right)
        swap (arr[left], arr[right]);
    }
  swap (arr[low], arr[right]);
  return right;
}

void
quick_sort (int arr[], int low, int high)
{
  if (low < high)
    {
      int pIndex = partition_index (arr, low, high);
      quick_sort (arr, low, pIndex - 1);
      quick_sort (arr, pIndex + 1, high);
    }
}

int
main ()
{
  int n;
  cin >> n;
  int arr[n];
  for (int i = 0; i < n; i++)
    cin >> arr[i];

  quick_sort (arr, 0, n - 1);

  for (int i = 0; i < n; i++)
    cout << arr[i] << ' ';
  return 0;
}
