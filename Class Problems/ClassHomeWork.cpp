#include<bits/stdc++.h>
using namespace std;

void CelciusToFerenheit(float deg_c){
   float deg_f=(deg_c*1.8+32);
   cout<<"Tempereature in Fereinheit is : "<<deg_f<<endl;
}

void PrimeNo(long long signed int n){
   long long signed int arr[n]={0};
   for(int i=2;i<=n;i++){
      if(arr[i]==0){
         for(int j=i*i;j<=n;j+=i){
            arr[j]=1;
         }
      }
   }
   cout<<"All Prime Numbers between 1 to "<<n<<" are : ";
   for(int i=2;i<=n;i++){
      if(arr[i]==0)
         cout<<i<<" ";
   }
}

long long signed int factorial(long long signed int n){
   if(n==1)
      return 1;
   return n*factorial(n-1);
}

void LCM(long long signed int a,long long signed int b){
   long long signed int max=(a>b)?a:b;
   while(1){
      if(max%a==0 and max%b==0){
         cout<<"LCM of two given numbers "<<a<<" and "<<b<<" is : "<<max<<endl;
         break;
      }
      ++max;
   }
}

long long signed int GCD(long long signed int a,long long signed int b){
   if(b==0)
      return a;
   return GCD(b,a%b);
}

int main(){
   cout<<"<==================== Make a Choice ====================>"<<endl;
   cout<<"1. Convert Celcius to Ferenheit"<<endl;
   cout<<"2. Find Prime No. in between 1 to input N"<<endl;
   cout<<"3. Find Factorial of a number"<<endl;
   cout<<"4. Find Least Common Multiple (LCM) of given numbers"<<endl;
   cout<<"5. Find Greatest Common Divisor (GCD) of two Numbers"<<endl;
   cout<<endl<<endl;
   int x;
   cout<<"Enter Choice between 1 to 5 only : ";
   cin>>x;
   cout<<endl<<endl;
      long long signed int ans;

   switch (x)
   {
   case 1:
      float temp;
      cout<<"Enter Temperature in Degree Celcius : ";
      cin>>temp;
      CelciusToFerenheit(temp);
      break;
   case 2:
      long long signed int num;
      cout<<"Enter Number to Find Prime Number to : ";
      cin>>num;
      PrimeNo(num);
      cout<<endl<<endl;
      break;
   case 3:
      long long signed int no;
      cout<<"Enter Number to find Factorial of : ";
      cin>>no;
      ans=factorial(no);
      cout<<"Factorial of number "<<no<<" is : "<<ans;
      cout<<endl<<endl;
      break;
   case 4:
      long long signed int a,b;
      cout<<"Enter two digits to find LCM of : ";
      cin>>a>>b;
      LCM(a,b);
      cout<<endl<<endl;
      break;
   case 5:
      long long signed int num1,num2;
      cout<<"Enter two numbers to find GCD of : ";
      cin>>num1>>num2;
      cout<<endl;
      ans=GCD(num1,num2);
      cout<<"GCD of two numbers "<<num1<<" and "<<num2<<" is : "<<ans<<endl;
      cout<<endl<<endl;
      break;
   default:
      break;
   }
   return 0;
}