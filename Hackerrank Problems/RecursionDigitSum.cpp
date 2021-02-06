#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);

// Complete the superDigit function below.
int superDigit(string n, int k)
{
        // cout<<n<<endl;
        if (n.length() == 1)
        {
            int ans = stoi(n);
            return ans;
        }
        long long signed int sum = 0;
        int num[n.length()];
        for(int i=0;i<n.length();i++){
            num[i]=n[i]-'0';
        }
        // for(int i=0;i<n.length();i++)
        //     cout<<num[i]<<" ";
        for(int i=0;i<n.length();i++){
            sum+=num[i];
        }
        // cout<<sum<<endl;
        // cout<<endl<<endl;
        string next = to_string(sum);
        return superDigit(next, k);  
        
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string nk_temp;
    getline(cin, nk_temp);

    vector<string> nk = split_string(nk_temp);

    string n = nk[0];

    int k = stoi(nk[1]);
    string new_string = n;
    for (int i = 0; i < k - 1; i++)
        new_string += n;
    cout << superDigit(new_string, k) << endl;
    // int result = superDigit(n, k);

    // fout << result << "\n";

    // fout.close();

    return 0;
}

vector<string> split_string(string input_string)
{
    string::iterator new_end = unique(input_string.begin(), input_string.end(), [](const char &x, const char &y) {
        return x == y and x == ' ';
    });

    input_string.erase(new_end, input_string.end());

    while (input_string[input_string.length() - 1] == ' ')
    {
        input_string.pop_back();
    }

    vector<string> splits;
    char delimiter = ' ';

    size_t i = 0;
    size_t pos = input_string.find(delimiter);

    while (pos != string::npos)
    {
        splits.push_back(input_string.substr(i, pos - i));

        i = pos + 1;
        pos = input_string.find(delimiter, i);
    }

    splits.push_back(input_string.substr(i, min(pos, input_string.length()) - i + 1));

    return splits;
}
