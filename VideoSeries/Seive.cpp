/* Finding the Prime Numbers between 1 and given no. N */
/* Seive of Eratosthenes */

/*

   Basic Idea : We will iterate over numbers from one to N and we will mark the multiples of numbers and if no. is repeated we will leave it then mark next multiples . 
   In this way we will remove all multiples and get prime numbers

   So lets begin with the coding part.....

*/

#include<bits/stdc++.h>            //Header file for all small headerfiles like iostream math etc.
using namespace std;
//Writing funtion to find primes
void primeSeive(int n){                   // Here value came 50
   bool prime[n+1];                //boolean array to keep track of multiples
   memset(prime,1,sizeof(prime));            //setting all values of array prime to 1.
   for(int i=2;i*i<=n;i++){                     //Loop to iterate over all elements from 2 to N i.e. 50               

   // this loop moves over all elements so N times program runs

      if(prime[i]==1){                                   //checking value of prime array if it is not marked before.
         for(int j=i*i;j<=n;j+=i){                                //loop to iterate over all multiples

         // This loop also runs for N times but leaves some integer multiples so it only runs log(logN) times

            prime[j]=0;                        //marking multiples (4,6,8,10..... ,6,9,12,15,18.....)
         }
      }
   }
   //After the loops are over we get prime numbers
   for(int i=2;i<=n;i++){                                //Loop to print elements

   //this loop runs n times 

      if(prime[i]==1)                                       // if element in prime array is not marked as multiple then       printing element

         cout<<i<<" ";               //Printing prime numbers
   }
}

int main(){
   int n;             //Digit to which we need to find prime no's
   cin>>n;           // value passed 50
   primeSeive(n);        //primeSeive(50);
}

/*

      NOW lets Run our Program.

      Now lets try to dry run the program....

      Now lets analyse the time complexity of program......

      So final time complexity of program is 

      N + N*log(logN)

      i.e.   N*log(logN)

      Thanks for watching video and please like share and subscribe......

*/
