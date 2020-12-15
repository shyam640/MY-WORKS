/*Printing inverted pyramid*/
#include<iostream>
#include<stdlib.h>

using namespace std;
int main()
{   system("CLS");
    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
       for(int j=n;j>0;j--){
          if(j>n-i+1){
             cout<<" ";
          }else 
          cout<<"* ";
       }cout<<endl;
    }
    return 0;
}