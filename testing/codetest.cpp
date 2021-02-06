#include <bits/stdc++.h>
using namespace std;
int main()
{
   long long int n; //Positive integer n
   cin >> n;
   long long int bin_form = 0;
   while (n > 0)
   {
      int rem = n % 2;
      bin_form = bin_form * 10 + rem;
      n /= 2;
   }
   string s = to_string(bin_form);
   int t = 0;
   int max_count = INT_MIN;
   int flag = 0;
   while (t < s.length())
   {
      int i=0;
      int count = 0;
      int one_came_btw=0;
      if (s[t] == '1')
      {
         flag = 1;
         for (i = t + 1; i < s.length(); i++)
         {
            if (s[i] == '1'){
               one_came_btw=1;
               break;
            }
            else
               count++;
         }
         if(one_came_btw!=1)
           count=0;
      }
      max_count = max(max_count, count);
      t+=i;
   }
   if (flag == 1)
      cout << max_count << endl;
   else
      return 0;
}
