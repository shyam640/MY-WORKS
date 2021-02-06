// N --> Packs of votes of john
// M --> Packs of votes of jack

#include<bits/stdc++.h>
#include<string.h>
using namespace std;

void swap(int &a,int &b){
   int temp=a;
   a=b;
   b=temp;
}
void Sort(vector<int> arr,int n){
   for(int i=0;i<n;i++){
      for(int j=0;j<n;j++){
         if(arr[i]>arr[j]){
            int temp=arr[i];
            arr[i]=arr[j];
            arr[j]=temp;
         }
      }
   }
}

int sum1(vector<int> arr,int size){
     int sum=0;
     for(int i=0;i<size;i++)
         sum+=arr[i];
      return sum;
}

int main(){
   int t;        //No. of test cases
   cin>>t;
   for(int test_cases=1;test_cases<=t;test_cases++){
      int N , M;
      cin>>N>>M;
      vector<int> A , B;
      for(int i=0;i<N;i++)
         cin>>A[i];
      for(int i=0;i<M;i++)
         cin>>B[i];
      int total_John_votes=sum1(A,N);
      int total_Jack_votes=sum1(B,M);
      // cout<<total_John_votes<<endl;
      // cout<<total_Jack_votes<<endl;
      int count=0;
      int i=0;
      if(total_John_votes>total_Jack_votes)
         cout<<"0"<<endl;
      else
         Sort(A,N);
         Sort(B,N);
         for(int i=0;i<N;i++)
            cout<<A[i]<<" ";
         for(int i=0;i<M;i++)
            cout<<B[i]<<" ";
         for(i=(min(N,M)-1);i>=0;i--){
            swap(A[i],B[i]);
            count++;
            total_John_votes=sum1(A,N);
            total_Jack_votes=sum1(B,M);
            // cout<<total_John_votes<<endl;
            // cout<<total_Jack_votes<<endl;
            if(total_Jack_votes>total_John_votes && i>=0)
               continue;
            else
               break;
         }
         if(total_Jack_votes>total_John_votes)
            cout<<"-1"<<endl;
         else
            cout<<count<<endl;
   }
   return 0;
}