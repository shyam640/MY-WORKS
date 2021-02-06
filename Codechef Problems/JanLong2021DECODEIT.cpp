                  //  -------------------------
                  //  | SUCCESSFULLY EXECUTED |
                  //  -------------------------

// firsts bit :-
//         0 if letters lies among first 8 letters (a,b,c,d,e,f,g,h)
//         else 1 which means it lies between last 8 letters (i,j,k,l,m,n,o,p)
// second bit :-
//          0 if letters lies among first 4 letter of those 8 letter of first bit (depends on first bit)
//          else 1 which means it lies among last 4 letters of those 8 letter of first bit
// third bit & fourth bit :- similarly dividing letters

#include <bits/stdc++.h>
#include <string.h>
using namespace std;
int main()
{
   int t; //No. of test cases
   cin >> t;
   for (int test_cases = 1; test_cases <= t; test_cases++) //  10
   {
      int n; //Length of encoded string
      cin >> n;
      string s; //encoded string
      cin >> s;
      string s1 = "abcdefghijklmnop";
      // cout<<s1[0]<<" "<<s1[15]<<endl;
      string ans;

      int t = 4;
      int temp = 0;
      int i=0;
      
      while (t <= s.length()) //10^5
      {
         int left = 0, right = (s1.length() - 1);
         // cout<<i<<endl;
         // cout<<temp<<" "<<t<<endl;
         for (i = temp; i < t; i++)
         {
            // cout<<left<<" "<<right<<endl;
            int mid = (left + right) / 2;
            if (s[i] == '0')
            {
               right = mid;
            }
            else if (s[i] == '1')
            {
               left = mid + 1;
            }
            else if (left == right){
            // cout<<left<<" "<<right<<endl;
               break;
            }
         }
         ans.push_back(s1[right]);
         t += 4;
         temp += 4;
         
      }
      cout << ans << endl;
   }
   return 0;
}