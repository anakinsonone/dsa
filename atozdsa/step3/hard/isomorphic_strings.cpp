#include <bits/stdc++.h>
using namespace std;

int
main ()
{

  string str1, str2;
  cin >> str1 >> str2;

  map<char, int> str1map;
  map<char, int> str2map;
  for (int i = 0; i < str1.length (); i++)
    {
      str1map[str1[i]]++;
      str2map[str2[i]]++;
    }

  bool res = true;
  for (int i = 0; i < str1.length (); i++)
    {
      if (str1map[str1[i]] != str2map[str2[i]])
        {
          res = false;
          break;
        }
    }

  cout << (res ? "true" : "false");

  return 0;
}
