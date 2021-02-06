#include<bits/stdc++.h>
using namespace std;

#define MAX 500          // Macro defining size of ans_arr (max factorial of 236 possible with this macro)

/*
              *** Multiplication Function Explanation ***
                ans_arr[]==>          39759985                BASIC CHILDHOOD MULTIPLICATION CALCULATION
                number i ==>          x     12
                                   --------------
                                      477119820  ==> Ans

      ** 12 is multiplied each time with digits of above number and 1,2 or 3 digit carry is stored in carry variable

         ** This is the basic idea behind these funtions...

*/

int multiply(int t,int ans_arr[],int ans_arr_size){                                // Funtion to calculate multiplication
      int carry=0;                                                            // variable to store carry
      for(int i=0;i<ans_arr_size;i++){                                        
         int prod=ans_arr[i]*t+carry;                                         // variable to store product
         ans_arr[i]=prod%10;                                                  // storing last digit
         carry=prod/10;                                                       // storing carry (1,2,or 3 digit)
      }
      while(carry){                                                           
         ans_arr[ans_arr_size]=carry%10;                                      // Updating digits in ans_arr
         carry/=10;                                                           // Reducing carry 
         ans_arr_size++;                                                      // Increasing size of array
      }
      return ans_arr_size;                                        //returning the size and updated ans_arr in reverse order
}

void factorialmethod1(int n){                                               // Factorial Function
   int ans_arr[MAX];                                                    // Array of size 500
   ans_arr[0]=1;                                          // Putting first digit of ans_arr as 1 as n==1 in factorial calc.
   int ans_arr_size=1;                                                 // Assuming array size to be 1
   for(int i=2;i<=n;i++)                                          // Loop to calculate multiply
      ans_arr_size=multiply(i,ans_arr,ans_arr_size);
   for(int i=ans_arr_size-1;i>=0;i--)                                // Printing ans_arr in reverse order
      cout<<ans_arr[i];
}

/* 
                           ** Logarithmic identity define ** 
                           1.   logA + logB = logAB
                           2.   e^(logN!) = N!
                           3.   E(i=1 to i<=n) i = N!                 means product of i from 1 to N is equal to N!

*/

void factorialmethod2(int n){
    // Using logarithm funtion and identity
    // Ans may very some digits because of log funtion 

         if(n>MAX){
            cout<<"Increase Size of macro to find factorial"<<endl;
            return;
         }
         long long counter;                                             // Keeping 
         long double sum=0;
         for(counter=1;counter<n;counter++)
            sum+=log(counter);
         string ans=to_string(round(exp(sum)));
         cout<<ans<<endl;
}

/*
                                 ** Time Complexity Analysis (1st) **
          Observing 1st loop of multiply funtion gives complexity of logN
         Observing both loops of factorial function gives complexity of 2N

                  Hence Overall Complexity is O(NlogN) or O(2NlogN)


                                 ** Time Complexity Analysis (2nd) **
            Observing loop in funtion Factorialmethod2()  we get that loop moves logN times

                  Hence Overall Complexity is O(logN)

*/

int main(){
   int n;                                                                  // No. to find factorial of 
   cin>>n;
   factorialmethod1(n);                                                                 // Calling of Funtions
   cout<<endl<<endl<<endl<<endl<<endl<<endl;
   factorialmethod2(n);
   return 0;
}

/*  Extra: 
          Total digits in factorial of 100 are 158 
          By just simple funtion of factorial you can not find factorial more than 25-30
*/