/*Enter your code here. Read input from STDIN. Print your output to STDOUT*/
#include <iostream>
#include<string>
using namespace std;
int main()
{
	string s;
	getline(cin , s);
   int a , b;
	cin>>a;
	cin>>b;
	cout<<s.substr(a,b)<<endl;
	

   return 0;
	
}
