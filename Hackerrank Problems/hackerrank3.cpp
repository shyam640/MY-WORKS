#include<iostream>
using namespace std;
int main()
{
    string num[10]={"Greater than 9" , "one" , "two" , "three" , "four" , "five" , "six" , "seven" , "eight" , "nine"};
    int a,b;
    cin >>a>>b;
    for (int n = a; n<=b ; ++n)
    {
        if (n > 9) {
            if (n % 2 == 0) {
                cout << "even" << endl;
            } else {
                cout << "odd" << endl;
            }
        } else {
            cout << num[n]<<endl;
        }
    }
    return 0;
}
