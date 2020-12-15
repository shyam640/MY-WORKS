//              ------------------------
//              | SUCCESSFULLY EXECUTED|
//              ------------------------

// N --> Total People with ages a1,a2,a3,.......an
// D --> No. of people given vaccine per day
// If age >= 80 or <=9 is considered to be at risk
/*
Constraints
1≤T≤10
1≤N≤104
1≤D≤105
1≤ai≤100 for each valid i
*/

#include <iostream>

using namespace std;
int main()
{

   int t; //No. of test cases
   cin >> t;
   for (int test_case = 1; test_case <= t; test_case++)
   {
      int N, D;
      cin >> N >> D;
      int age[N];
      for (int i = 0; i < N; i++)
      {
         cin >> age[i];
      }
      int risk_count = 0, safe_count = 0;
      int total_days = 0;
      for (int i = 0; i < N; i++)
      {
         if (age[i] <= 9 || age[i] >= 80)
         {
            risk_count += 1;
         }
         else
         {
            safe_count += 1;
         }
      }   
         if (risk_count % D == 0 && safe_count % D == 0)
         {
            total_days = ((risk_count / D) + (safe_count / D));
            
         }
         else if ((risk_count % D != 0 && safe_count % D == 0) || (risk_count % D == 0 && safe_count % D != 0))
         {
            total_days = ((risk_count / D) + (safe_count / D) + 1);
            
         }
         else
         {
            total_days = ((risk_count / D) + (safe_count / D) + 2);
            
         }
      
      cout<<total_days<<endl;
   }   
      return 0;
}