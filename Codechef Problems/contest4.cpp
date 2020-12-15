#include<iostream>
#include<stdlib.h>
#include<math.h>

using namespace std;
int main(){
   system("CLS");
   int n;       //No. of Rounds
   cin>>n;
   int lead[n] , win_player[n] , max_lead=INT32_MIN , winner;
   for(int round=1;round<=n;round++){
      int score_player1 , score_player2;
      cin>>score_player1>>score_player2;
      if(score_player1>score_player2){
      win_player[round-1]=1;
      }else{
         win_player[round-1]=2;
      }
      lead[round-1]=score_player1-score_player2;
      if(lead[round-1]<0){
         lead[round-1]*=(-1);
      }
      
   }
   for(int i=0;i<n;i++){
      if(lead[i]>max_lead){
         max_lead=max(lead[i],max_lead);
         }
         if(lead[i]==max_lead){
         winner=win_player[i];
      }
       
   } 
   cout<<winner<<" "<<max_lead;
   return 0;
}