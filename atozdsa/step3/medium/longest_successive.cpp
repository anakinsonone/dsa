#include <bits/stdc++.h>
#include <unordered_set>
using namespace std;

void
merge (vector<int> &arr, int low, int mid, int high)
{
  int left = low;
  int right = mid + 1;
  vector<int> temp;
  while (left <= mid && right <= high)
    {
      if (arr[left] < arr[right])
        {
          temp.push_back (arr[left]);
          left++;
        }
      else
        {
          temp.push_back (arr[right]);
          right++;
        }
    }
  while (left <= mid)
    {
      temp.push_back (arr[left]);
      left++;
    }
  while (right <= high)
    {
      temp.push_back (arr[right]);
      right++;
    }
  for (int i = low; i <= high; i++)
    {
      arr[i] = temp[i - low];
    }
}

void
mergeSort (vector<int> &arr, int low, int high)
{
  if (low == high)
    return;
  int mid = (low + high) / 2;
  mergeSort (arr, low, mid);
  mergeSort (arr, mid + 1, high);
  merge (arr, low, mid, high);
}

int
main ()
{
  int n;
  cin >> n;
  vector<int> arr;
  for (int i = 0; i < n; i++)
    {
      int num;
      cin >> num;
      arr.push_back (num);
    }

  // mergeSort (arr, 0, n - 1);
  // int count = 1, maxCount = 0;
  // for (int i = 1; i < n; i++)
  //   {
  //     if (arr[i] - arr[i - 1] == 1)
  //       {
  //         count++;
  //       }
  //     else if (arr[i] == arr[i - 1])
  //       continue;
  //     else
  //       {
  //         count = 1;
  //       }
  //     maxCount = max (maxCount, count);
  //   }
  // for (int i = 0; i < n; i++)
  //   cout << arr[i] << ' ';
  // cout << endl << maxCount;
  // optimal solution
  if (n == 0)
    return 0;
  int longest = 1;
  unordered_set<int> st;
  for (int i = 0; i < n; i++)
    st.insert (arr[i]);

  for (auto it : st)
    {
      if (st.find (it - 1) == st.end ())
        {
          int count = 1;
          int x = it;
          while (st.find (x + 1) != st.end ())
            {
              x++;
              count++;
            }
          longest = max (longest, count);
        }
    }

  cout << longest;
  return 0;
}
