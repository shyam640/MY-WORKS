
#include<iostream>

using namespace std;
int main()
{
   int n;
   cin>>n;
   string name[n];int phone[n];string search[n];
   for(int i=0;i<n;i++){
      cin>>name[i]>>phone[i];
   }
   for(int i=0;i<n;i++){
      cin>>search[i];
   }
   int i=0;
   new_search:
   if(i<n){
   
      for(int j=0;j<n;j++){
         if(search[i]==name[j]){
            cout<<name[j]<<"="<<phone[j]<<endl;
            i++;
            goto new_search;                       
         }
        
      } 
      cout<<"Not found"<<endl;
            i++;
            goto new_search;
      
   }

      return 0;
}