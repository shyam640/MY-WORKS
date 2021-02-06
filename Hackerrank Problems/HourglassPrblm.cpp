#include <bits/stdc++.h>

using namespace std;

int calculateSum(vector<vector<int>> arr,int i,int j){
        int sum=0;
        for(int a=i;a<i+3;a++){
            for(int b=j;b<j+3;b++){
                if((a==i+1 && b==j)||(a==i+1 && b==j+2))
                    continue;
                else
                    sum+=arr[a][b];
            }
        }
        return sum;
}

// Complete the hourglassSum function below.
int hourglassSum(vector<vector<int>> arr) {
    int max_hourglass_sum=INT_MIN;
        for(int i=0;i<arr.size()-2;i++){
            for(int j=0;j<arr.size()-2;j++){
                int result=calculateSum(arr,i,j);
                max_hourglass_sum=max(max_hourglass_sum,result);
                // cout<<result<<" ";
            }//cout<<endl;
        }
        return max_hourglass_sum;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    vector<vector<int>> arr(6);
    for (int i = 0; i < 6; i++) {
        arr[i].resize(6);

        for (int j = 0; j < 6; j++) {
            cin >> arr[i][j];
        }

        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    int result = hourglassSum(arr);
      cout<<result<<"\n";
   //  fout << result << "\n";

   //  fout.close();

    return 0;
}
