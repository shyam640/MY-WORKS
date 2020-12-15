// If any player has empty pile then he looses the game
// Cards are drawn from top of pile
// If one player pile is empty then he looses the game
// If both players draw same no. of cards then they draw card from bottom 
// Player whose card has higher value wins and  then keeps that card at bottom 
// and takes card from looser player and places it also at bottom
// card taken from looser player looses its value by 1
// there is no transfer of cards between players during 10^100 rounds
// they counts sum of values of cards and who higher sum , wins.

// N --> No. of cards (numbered 1 to n)
// C-i is the value of the i-th card

#include<iostream>
#include<stdlib.h>

using namespace std;
int main(){
   system("CLS");
   int t;           //No. of test cases
   cin>>t;
   for(int test_case=1;test_case<=t;test_case++){
      int n;        // No. of cards
      cin>>n;
      int C[n];
      for(int i=0;i<n;i++){
          cin>>C[i];
      }

   }
   return 0;
}


/*      Chef                  Chefu
       [6,1]                 [2,2]
1st=>  6 no. drawn          <-- 2 no. card         chef wins
       [1,6,1]               [2]                   2 no. card value decreased by 1

2nd=>  1 no. drawn           2 no. drawn            chefu wins
       1 -->goes            0 value card recieved
       [6,1]                  [2]

3rd=>  6 no. card drawn      <-- 2 no. card         chef wins
        [1,6,1]                 empty
     
*/