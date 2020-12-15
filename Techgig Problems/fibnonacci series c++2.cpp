/*Printing fibonacci series*/
#include <iostream>
using namespace std;

int main()
{   
   system("CLS");
	int n;
	cin>>n;
	int t1=0;
   int t2=1;
   cout<<t1<<" "<<t2;
   for(int i=2;i<n;i++){
   int next_term=t1+t2;
   cout<<" "<<next_term;
   t1=t2;
   t2=next_term;
   }
   
	return 0;
}
