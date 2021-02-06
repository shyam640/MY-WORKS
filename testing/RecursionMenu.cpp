#include<bits/stdc++.h>

using namespace std;

class variables{
   public:
       int num1 ;
       int num2;
       int size ;
       int ch;
};

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
   variables v;
   
   cout<<"================= Recursion Menu ================="<<endl<<endl;
   cout<<"1. Sum of numbers less than n"<<endl;
   cout<<"2. Printing sum of Fibonaci series upto n digits"<<endl;
   cout<<"3. Euclid's Method of finding GCD of two numbers"<<endl;
   cout<<"4. Factorial of a number"<<endl;
   cout<<"5. Sort an array"<<endl;
   

   cout<<endl;
  
   cout<<"Enter your choice between : ";cin>>v.ch;
      cout<<endl;

   int arr[v.size];

   switch(v.ch)
   {
   case 1:
      cout<<endl<<endl;
      cout<<"Enter a number to find sum till the number : ";cin>>v.num1;
      cout<<"Sum of numbers from 1 to "<<v.num1<<" is : "<<SumOfLNums(v.num1)<<endl;
      cout<<endl;
      cout<<endl;
      break;
   case 2:
      cout<<endl<<endl;
      cout<<"Enter a number to find sum of fibonacci series till it "<<" : ";cin>>v.num1;
      cout<<"Sum of fibonacci series of "<<v.num1<<" is :-"<<endl;
      cout<<fib(v.num1)<<endl;
      cout<<endl;
      cout<<endl;
      break;
   case 3:
      cout<<endl<<endl;
      cout<<"Enter two numbers to find GCD of : ";cin>>v.num1>>v.num2;
      cout<<"GCD of numbers "<<v.num1<<" and "<<v.num2<<" is : "<<G_C_D(v.num1,v.num2)<<endl;
      cout<<endl;
      cout<<endl;
      break;
   case 4:
      cout<<endl<<endl;
      cout<<"Enter a number to find factorial of : ";cin>>v.num1;
      cout<<"Factorial of "<<v.num1<<" is : "<<fact(v.num1)<<endl;
      cout<<endl;
      break;
   case 5:
      cout<<"Enter size of array : ";cin>>v.size;
      cout<<"Enter Unsorted array of "<<v.size<<" elements : ";
      for(int i=0;i<v.size;i++)
         cin>>arr[i];
       SortedArray(arr,v.size);
      cout<<"Sorted array is :- ";
      for(int i=0;i<v.size;i++)
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

