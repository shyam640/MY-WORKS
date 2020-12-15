//       -------------------------- 
//      | SUCCESFULLY EXECUTED    |
//       --------------------------
//
//N --> students(numbered 1 to N)
//K --> Lectures(numbered 1 to K)

/* For each student i and each lecture j i-th student watched the j-th lecture for T-ij minutes*/

//Q-i times student i asked question
//M --> Minutes of lectures 

//Criteria for certificate is that the student must watch lectures for atleast M minutes and 
//asked question not more than 10 times.

/*Constraints
1 ≤ N,K ≤ 1,000        
1 ≤ M ≤ 10^6
1 ≤ Qi ≤ 10^6 for each valid i
1 ≤ Ti,j ≤ 1,000 for each valid i and j */

#include<iostream>
#include<stdlib.h>

using namespace std;
int main(){
   system("CLS");
   int N , M , K;    //no. of students , min. minutes and lectures respectively
   cin>>N>>M>>K;
   int t_watch[N][K] , que[N];
   for(int i=0;i<N;i++){
      for(int j=0;j<K;j++){
         cin>>t_watch[i][j];
      }cin>>que[i];
   }
   int total_time=0;
   int total_certificate=0;
   int i=0;
   while(i<N && i>=0)
  { 
     for(int j=0;j<K;j++){
       total_time+=t_watch[i][j];
       
      }
      if(total_time>=M && que[i]<=10){
          total_certificate+=1;
      }
      total_time=0;
      i+=1;
   }
     cout<<total_certificate<<endl;
     return 0;

}


/* Time complexity is O(N*K) */