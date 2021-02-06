//                  -------------------------
//                  | SUCCESSFULLY EXECUTED |
//                  --------------------------
#include<bits/stdc++.h>

using namespace std;

int main()
{
   system("CLS");
   int n; //NO. of Rounds
   cin >> n;
   int S1[n], T1[n]; //Score of player 1 and 2
   for (int i = 0; i < n; i++)
   {
      cin >> S1[i] >> T1[i];
   }
   int lead[n] = {0};
   int leader[n] = {0};
   for (int i = 1; i < n; i++)
   {
      S1[i] += S1[i - 1];
      T1[i] += T1[i - 1];
   }
   for (int i = 0; i < n; i++)
   {
      if (S1[i] > T1[i])
      {
         lead[i] = (S1[i] - T1[i]);
         leader[i] = 1;
      }
      else if (S1[i] < T1[i])
      {
         lead[i] = (T1[i] - S1[i]);
         leader[i] = 2;
      }
      else if (S1[i] == T1[i])
         continue;
   }
   // for (int i = 0; i < n; i++)
   //    cout << S1[i] << " " << T1[i] << " " << lead[i] <<" "<<leader[i]<<endl;
   int max_lead=INT8_MIN;
   for(int i=0;i<n;i++){
      max_lead=max(max_lead,lead[i]);
   }
   for(int i=0;i<n;i++){
      if(lead[i]==max_lead){
         cout<<leader[i]<<" "<<max_lead<<endl;
      }
   }
   return 0;
}