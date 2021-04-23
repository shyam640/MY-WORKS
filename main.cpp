// Method-1    using DS

#include<bits/stdc++.h>
using namespace std;
int main(){
	int n;						// size of array
	cin>>n;
	vector<int> arr(n);
	for(int i=0;i<n;i++)	cin>>arr[i];
	stable_sort(arr.begin(),arr.end());
	int fst_pstv=0,zro_cnt=0;
	while(!arr[fst_pstv]>0)
		fst_pstv++;
	// cout<<fst_pstv<<endl;
	int temp1=fst_pstv;
	vector<int> ans(n);
	int temp=n-fst_pstv;
	for(int i=0;i<n;i+=2){
		if(temp>=(n/2) and zro_cnt<temp1){
			ans[i]=arr[fst_pstv];
			ans[i+1]=arr[zro_cnt];
		}
		else if(zro_cnt<temp1){
			ans[i]=arr[zro_cnt];
			ans[i+1]=arr[fst_pstv];
		}
		else{
			ans[i]=arr[i];
			ans[i+1]=arr[i+1];
		}
		// cout<<ans[i]<<" "<<ans[i+1]<<endl;
		fst_pstv++;zro_cnt++;
	}
	arr=ans;
	for(int i=0;i<n;i++)
		cout<<arr[i]<<" ";
}


