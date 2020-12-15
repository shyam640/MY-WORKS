#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);

// Complete the plusMinus function below.
void plusMinus(vector<int> arr) {
   double p_c=0 , n_c=0 , z_c=0;      // No. of Positive count , negative count , zero count
   for(int i=0;i<arr.size();i++){
      if(arr[i]==0){
         z_c++;
      }else if(arr[i]>0){
         p_c++;
      }else{
         n_c++;
      }
   }
   // cout<<p_c<<" "<<n_c<<" "<<z_c<<endl;
   double n =arr.size();    //Total Elements in array
   // cout<<n<<endl;
   double o1=(p_c/n);
   double o2=(n_c/n);
   double o3=(z_c/n);
   cout<<fixed<<setfill('0')<<setw(8)<<o1<<endl;
   cout<<fixed<<setfill('0')<<setw(8)<<o2<<endl;
   cout<<fixed<<setfill('0')<<setw(8)<<o3<<endl;
}

int main()
{
    int n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    string arr_temp_temp;
    getline(cin, arr_temp_temp);

    vector<string> arr_temp = split_string(arr_temp_temp);

    vector<int> arr(n);

    for (int i = 0; i < n; i++) {
        int arr_item = stoi(arr_temp[i]);

        arr[i] = arr_item;
    }

    plusMinus(arr);

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
