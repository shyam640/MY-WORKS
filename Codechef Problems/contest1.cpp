/*You need to calculate the total number of points gained by each player 
and find maximum of these values*/

#include<iostream>
#include<stdlib.h>
#include<math.h>
#include<climits>

using namespace std;
int main(){
   system("CLS");
   int t;            //NO. of testcases
   cin>>t;
   for(int test_case=1;test_case<=t;test_case++){
   int n;           //size of array
   cin>>n;
   /*You are given two sequences A1,A2,…,AN and B1,B2,…,BN. For each valid i, player i scored Ai goals and 
   committed Bi fouls. For each goal, the player that scored it gets 20 points, and for each foul, 10 
   points are deducted from the player that committed it.*/
    int arr2[n] , arr1[n];
       for(int i=0;i<n;i++){
       cin>>arr1[i];               //first array input
       }
       for(int i=0;i<n;i++){
       cin>>arr2[i];                //second array input
      }
   int arr_max[n];
   int max_score=INT32_MIN;          //INT32_MIN used to assign minimum possible value of int 
      for(int i=0;i<n;i++){
      arr_max[i]=20*arr1[i]-10*arr2[i];
      if(arr_max[i]<0)
   arr_max[i]=0;
      
      max_score=max(max_score,arr_max[i]);         //max function used to find maximum of two
      } 
      cout<<max_score<<endl;
   }
   return 0;
}


/*constraints
1≤T≤100 

1≤N≤150
0≤Ai≤50 for each valid i
0≤Bi≤50 for each valid i*/