//              ------------------------
//              | SUCCESSFULLY EXECUTED |
//				    -------------------------
#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);

// Complete the miniMaxSum function below.

void miniMaxSum(int arr[])
{
	  long long int max_sum = INT64_MIN ;
	   long long int min_sum = INT64_MAX;
   int temp=0;
	int i=0;
	while(temp<5 ){
		long long int sum1=0;
			for(int i=0;i<5;i++){
				if(i==temp){
					continue;
				}else{
             sum1+=arr[i];
				}
		}
		min_sum=min(min_sum,sum1);
		max_sum=max(max_sum,sum1);
		temp++;
	}
	cout << min_sum << " " << max_sum << endl;
}

int main()
{
	string arr_temp_temp;
	getline(cin, arr_temp_temp);

	vector<string> arr_temp = split_string(arr_temp_temp);

	int arr[5];

	for (int i = 0; i < 5; i++)
	{
		int arr_item = stoi(arr_temp[i]);

		arr[i] = arr_item;
	}

	miniMaxSum(arr);

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
