//                         ------------------------
//                        | SUCCESSFULLY EXECUTED |
//                        ------------------------
#include<bits/stdc++.h>
using namespace std;
void bitmanipulationAns(vector<int> arr){
   int i,j;
   long long int res = 0;
	for (j = 31; j >= 0; j--)
	{
		vector<int> temp;

		for (i = 0; i < arr.size(); i++)
		{
			if (arr[i] & (1 << j))
			{
				temp.push_back(arr[i]);
			}
		
		}
			if (temp.size() >= 2)
			{
				res += (1 << j);
				arr = temp;
				//we now transfer the ar in temp
			}
	}

	cout << res;
}

void simplyAns(vector<int> arr){
      int n=arr.size();
      int ans_arr[n*(n-1)/2];
   int t=0;
   for(int i=0;i<n-1;i++){
      for(int j=i+1;j<n;j++){
         ans_arr[t]=(arr[i]&arr[j]);
         t++;
      }
   }
   int max_and=INT_MIN;
   for(int i=0;i<n*(n-1)/2;i++)
      max_and=max(max_and,ans_arr[i]);
   cout<<max_and<<endl;
}
int main(){
   int n;
   cin>>n;
   vector<int> arr(n);
   for(int i=0;i<n;i++)
      cin>>arr[i];
   bitmanipulationAns(arr);
   cout<<endl;
   simplyAns(arr);
   return 0;
}