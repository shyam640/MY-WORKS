#include <iostream>
#include <iomanip>
#include <limits>
#include<stdlib.h>

using namespace std;

int main() {
    system("CLS");
    int i = 4;
    double d = 4.0;
    string s = "HackerRank ";
    int a ; double b ; string s2;
    
    cin>>a;
    scanf("%lf \n",&b);
    getline(cin, s2);
    int sum1=a+i;
    double sum2=b+d;
    cout<<sum1<<endl;
    cout<<sum2<<setprecision(1)<<endl;
    cout<<s<<s2<<endl;

    return 0;
}