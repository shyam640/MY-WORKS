#include <bits/stdc++.h>

using namespace std;

int binaryForm(int n){
   int rem;
   int sum=0;
   while(n!=0){
      int rem=n%2;
      sum=sum*10+rem;
      n/=2;
   }
   return sum;
}
int Num_of_cons_ones(int num){
   string s=to_string(binaryForm(num));
   cout<<s<<endl;
   int max_ones_count=INT_MIN;
   int ones_count=0;
   for(int i=0;i<s.length();i++){
      for(int j=0;j<s.length();j++){
         if(s[j]=='1' && s[j+1]=='1'){
               ones_count+=2;
               continue;
         }else if(s[j]=='1'){
            ones_count++;
            continue;
         }else{
            break;
         }
      }
     max_ones_count=max(max_ones_count,ones_count);
   }
   return max_ones_count;  
}


int main()
{
    int n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cout<<Num_of_cons_ones(n)<<endl;

    return 0;
}
