#include <bits/stdc++.h>

using namespace std;

/*
 * Complete the timeConversion function below.
 */
string timeConversion(string s) {
        if(s[8]=='A' && s[9]=='M'){
            // s.erase(8,9);
            if(s[0]=='1' && s[1]=='2'){
            s[0]='0';
            s[1]='0';
            }
        }
        else{
            if(s[0]=='1' && s[1]=='2'){
            int n=stoi(s);
            s.erase(0,2);
            s=to_string(n)+s;
            }else{
            int n=stoi(s);
            n+=12;
            s.erase(0,2);
            s=to_string(n)+s;
            }
        }
        
        s.erase(8,9);
        return s;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string s;
    getline(cin, s);

    string result = timeConversion(s);
    cout<<result<<endl;
    // fout << result << "\n";

    // fout.close();

    return 0;
}
