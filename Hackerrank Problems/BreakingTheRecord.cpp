//                     -------------------------
//                     | SUCCESSFULLY EXECUTED |
//                     -------------------------

#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);

// Complete the breakingRecords function below.
vector<int> breakingRecords(vector<int> scores) {
      int Highest_scores[scores.size()],Lowest_scores[scores.size()];
      Highest_scores[0]=scores[0];
      Lowest_scores[0]=scores[0];
      
      int H_count=0 , L_count=0;
         for(int i=1;i<scores.size();i++){
            Highest_scores[i]=max(Highest_scores[i-1],scores[i]);
            Lowest_scores[i]=min(Lowest_scores[i-1],scores[i]);
            if(Highest_scores[i-1]<Highest_scores[i])
               H_count++;
            if(Lowest_scores[i-1]>Lowest_scores[i])
               L_count++;
         }
         // for(int i=0;i<scores.size();i++){
         //     cout<<Highest_scores[i]<<" "<<Lowest_scores[i]<<endl;
         // }
         // cout<<H_count<<" "<<L_count<<endl;
         vector<int> ans={H_count,L_count};
         return ans;
     
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    string scores_temp_temp;
    getline(cin, scores_temp_temp);

    vector<string> scores_temp = split_string(scores_temp_temp);

    vector<int> scores(n);

    for (int i = 0; i < n; i++) {
        int scores_item = stoi(scores_temp[i]);

        scores[i] = scores_item;
    }
   
    vector<int> result = breakingRecords(scores);

    for (int i = 0; i < result.size(); i++) {
      //   fout << result[i];
         cout << result[i];
        if (i != result.size() - 1) {
   //          // fout << " ";
            cout << " ";
        }
    }

   //  fout << "\n";

   //  fout.close();

    return 0;
}

vector<string> split_string(string input_string) {
    string::iterator new_end = unique(input_string.begin(), input_string.end(), [] (const char &x, const char &y) {
        return x == y and x == ' ';
    });

    input_string.erase(new_end, input_string.end());

    while (input_string[input_string.length() - 1] == ' ') {
        input_string.pop_back();
    }

    vector<string> splits;
    char delimiter = ' ';

    size_t i = 0;
    size_t pos = input_string.find(delimiter);

    while (pos != string::npos) {
        splits.push_back(input_string.substr(i, pos - i));

        i = pos + 1;
        pos = input_string.find(delimiter, i);
    }

    splits.push_back(input_string.substr(i, min(pos, input_string.length()) - i + 1));

    return splits;
}
