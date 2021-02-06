#include<bits/stdc++.h>

using namespace std;

int SumOfLNums(int n){
   if(n==1)
   return 1;
   return n+SumOfLNums(n-1);
}

int fib(int n){
   if(n==0 || n==1)
   return n;
   else
   return (fib(n-1)+fib(n-2));
}

int G_C_D(int a , int b){
      if(b==0)
      return a;
      else
      return G_C_D(b,a%b);
}

int fact(int n){
   if(n==1)
   return 1;
   else
   return (n*fact(n-1));
}

void SortedArray(int arr[], int n){
    for(int i=0;i<n-1;i++){
      for(int j=i;j<n;j++){
         if(arr[i]>arr[j]){
            int temp=arr[i];
            arr[i]=arr[j];
            arr[j]=temp;
         }
      }
    }
}



int main(){
   system("CLS");
   
   cout<<"================= Recursion Menu ================="<<endl<<endl;
   cout<<"1. Sum of numbers less than n"<<endl;
   cout<<"2. Printing sum of Fibonaci series upto n digits"<<endl;
   cout<<"3. Euclid's Method of finding GCD of two numbers"<<endl;
   cout<<"4. Factorial of a number"<<endl;
   cout<<"5. Sort an array"<<endl;
   cout<<"6. "<<endl;
   cout<<"7. "<<endl;
   cout<<"8. "<<endl;
   cout<<"9. "<<endl;

   cout<<endl;
   int ch;
   cout<<"Enter your choice between : ";cin>>ch;
      cout<<endl;

   int num1 , num2 , size , arr[size];

   switch(ch)
   {
   case 1:
      cout<<endl<<endl;
      cout<<"Enter a number to find sum till the number : ";cin>>num1;
      cout<<"Sum of numbers from 1 to "<<num1<<" is : "<<SumOfLNums(num1)<<endl;
      cout<<endl;
      cout<<endl;
      break;
   case 2:
      cout<<endl<<endl;
      cout<<"Enter a number to find sum of fibonacci series till it "<<" : ";cin>>num1;
      cout<<"Sum of fibonacci series of "<<num1<<" is :-"<<endl;
      cout<<fib(num1)<<endl;
      cout<<endl;
      cout<<endl;
      break;
   case 3:
      cout<<endl<<endl;
      cout<<"Enter two numbers to find GCD of : ";cin>>num1>>num2;
      cout<<"GCD of numbers "<<num1<<" and "<<num2<<" is : "<<G_C_D(num1,num2)<<endl;
      cout<<endl;
      cout<<endl;
      break;
   case 4:
      cout<<endl<<endl;
      cout<<"Enter a number to find factorial of : ";cin>>num1;
      cout<<"Factorial of "<<num1<<" is : "<<fact(num1)<<endl;
      cout<<endl;
      break;
   case 5:
      cout<<"Enter size of array : ";cin>>size;
      cout<<"Enter Unsorted array of "<<size<<" elements : ";
      for(int i=0;i<size;i++)
         cin>>arr[i];
       SortedArray(arr,size);
      cout<<"Sorted array is :- ";
      for(int i=0;i<size;i++)
         cout<<arr[i]<<" ";
      cout<<endl<<endl;
      break;
   
   default:
      cout<<endl;
      cout<<"Enter a valid choic between 1 to only....."<<endl;
      cout<<"Exiting...."<<endl;
      break;
   }
   
   
}

