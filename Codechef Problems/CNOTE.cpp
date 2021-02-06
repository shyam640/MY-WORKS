                        //   --------------------------
                        //   | SUCCCESSFULLY EXECUTED |
                        //   --------------------------

//  X --> No. of pages long poetry
//  Y --> No. of pages in notebook
//  Pi --> Pages in new notebook
//  Ci --> Price of new notebook (in rubles)
//  K --> Rubles left on chef

#include <bits/stdc++.h>
using namespace std;
int main()
{
   int t; //No. of test cases
   cin >> t;
   for (int i = 1; i <= t; i++)
   {
      int X, Y, K, N;
      cin >> X >> Y >> K >> N;
      int P[N], C[N];
      for (int i = 0; i < N; i++)
         cin >> P[i] >> C[i];
      int flag = 0;
      for (int i = 0; i < N; i++)
      {
         if (C[i] <= K)
         {
            int temp = 0;
            temp = Y + P[i];
            // cout<<temp<<endl;
            if (temp >= X)
            {
               flag = 1;
            }
         }
      }
      if (flag == 1)
            cout << "LuckyChef" << endl;
      else 
            cout << "UnluckyChef" << endl;
   }
   return 0;
}   