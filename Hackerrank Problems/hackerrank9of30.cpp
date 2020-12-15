#include <bits/stdc++.h>

using namespace std;

// Complete the factorial function below.
int factorial(int n) {
    int fact=1;
    for(int i=2;i<=n;i++){
    fact*=i;}
    return fact;

}

int main()
{   system("CLS");
    

    int n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    int result = factorial(n);

    cout << result << "\n";

    
    return 0;
}
