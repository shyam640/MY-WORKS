#include <bits/stdc++.h>

using namespace std;



int main() {
    int N;
    cin >> N;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    if (N % 2 == 0) {
        if (N >= 2 && N <= 5 || N > 20) {
            cout << "Not Weird" << endl;
        } else {
            cout << "Weird" << endl;
        }
    }else{
        cout << "Weird" << endl;
    }
        return 0;

}