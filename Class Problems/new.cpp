#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main()
{
   int i = 0;
   vector<int> ans;
   while (i < 5)
   {
      int n;
      cin >> n;
      ans.push_back(n);
      i++;
   }
   for (int i = 0; i < 5; i++)
   {
      if (ans[i] == 42)
         break;
      else
         cout << ans[i] << endl;
   }
   return 0;
}