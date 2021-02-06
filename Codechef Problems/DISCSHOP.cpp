#include <bits/stdc++.h>
#include <string>

using namespace std;
int main()
{
   int t; //No. of testcases
   cin >> t;
   for (int test_cases = 1; test_cases <= t; test_cases++)
   {
      int n; //Rupees
      cin >> n;

      string s = to_string(n);
      int l = s.length();
      int i=0;
      sort(s.begin(),s.end());
      while(s[i]=='0'){
         i++;
      }
      if(s[0]=='0')
         s.erase(i,i+1);
      else
         s.erase(l-1,l);
      cout<<s<<endl;
   }
}