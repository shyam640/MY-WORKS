#include<bits/stdc++.h>
#include<string>
using namespace std;

bool  compare(char arr1[],char arr2[]){
   for(int i=0;i<MAX;i++)
      if(arr1[i]!=arr2[i])
         return false;
   return true;
}

bool checkString()

int mani(){
   int n;        //size of array
   cin>>n;
   vector<string> arr;
   for(int i=0;i<n-1;i++)
      cin>>arr[i];
   for(int i=0;i<n;i++){
      string temp=arr[i];
      for(int j=i+1;j<n;j++){
         if(temp.find(arr[j])){
            cout<<temp<<" ";
         }
      }
   }
   return 0;
}