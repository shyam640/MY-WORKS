 //                 ------------------------
 //                 | SUCCESSFULLY EXECUTED |
 //                 ------------------------
#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);

/*
 * Complete the 'gradingStudents' function below.
 *
 * The function is expected to return an INTEGER_ARRAY.
 * The function accepts INTEGER_ARRAY grades as parameter.
 */

vector<int> gradingStudents(vector<int> grades) {
         vector<int> ans(grades.size());
      for(int i=0;i<grades.size();i++){
         if(grades[i]<38){
            ans[i]=grades[i];
         }else{
            int temp=0;
            temp=grades[i];
            int next_m_5=0;
            for(int i=temp;i<=temp+5;i++)
            if(i%5==0){
               next_m_5=i;
            }
            if((next_m_5-temp)<3){
               ans[i]=next_m_5;
            }else{
               ans[i]=temp;
            }
         }
      }
      // for(int i=0;i<grades.size();i++)
      // cout<<ans[i]<<" ";
      return ans;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string grades_count_temp;
    getline(cin, grades_count_temp);

    int grades_count = stoi(ltrim(rtrim(grades_count_temp)));

    vector<int> grades(grades_count);

    for (int i = 0; i < grades_count; i++) {
        string grades_item_temp;
        getline(cin, grades_item_temp);

        int grades_item = stoi(ltrim(rtrim(grades_item_temp)));

        grades[i] = grades_item;
    }

    vector<int> result = gradingStudents(grades);

    for (int i = 0; i < result.size(); i++) {
        cout<<result[i];
      //   fout << result[i];

        if (i != result.size() - 1) {
      //       fout << "\n";
      cout<<"\n";
        }
    }

   //  fout << "\n";

   //  fout.close();

    return 0;
}

string ltrim(const string &str) {
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))
    );

    return s;
}

string rtrim(const string &str) {
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        s.end()
    );

    return s;
}
