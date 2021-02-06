#include <bits/stdc++.h>
#include <string>
using namespace std;

int GCD(int a, int b)
{
   if (b == 0)
      return a;
   return GCD(b, a % b);
}

void Sort(vector<int> &arr,int &n){
   for(int i=0;i<n-1;i++){
      for(int j=i+1;j<n;j++){
         if(arr[i]>arr[j]){
            int temp=arr[i];
            arr[i]=arr[j];
            arr[j]=temp;
         }
      }
   }
}

// vector<int> height_arrgn(vector<int> arr,int n){

// }

int main()
{
   int t; //No. of test cases
   cin >> t;
   for (int test_cases = 1; test_cases <= t; test_cases++)
   {
      int n; //size of array
      cin >> n;
      vector<int> arr(n);
      for (int i = 0; i < n; i++)
         cin >> arr[i];
      if(n==1 || n==2){
         Sort(arr,n);
         for (int i = 0; i < n; i++)
            cout<<arr[i]<<" ";}
      else{
         Sort(arr,n);

      }
      // for (int i = 0; i < n; i++)
      //    cout<<arr[i]<<" ";
      cout<<endl;
   }
   return 0;
}