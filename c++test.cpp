// Method - 2      Without Using DS
#include<bits/stdc++.h>
using namespace std;
void Sort(int *arr,int n){
    for(int i=0;i<n-1;i++){
        for(int j=i+1;j<n;j++){
            if(arr[j]<arr[i]){
                int temp=arr[i];
                arr[i]=arr[j];
                arr[j]=temp;
            }
        }
    }
}
void Rearrange(int *arr,int n){
    int fst_pstv=0,zro_cnt=0;
	while(!arr[fst_pstv]>0) fst_pstv++;
    int ans[n];
	int temp1=fst_pstv;
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
		fst_pstv++;zro_cnt++;
	}
	for(int i=0;i<n;i++)    arr[i]=ans[i];
}
int main(){
	int n;						// size of array
	cin>>n;
	int arr[n];
	for(int i=0;i<n;i++)	cin>>arr[i];
	Sort(arr,n);
	Rearrange(arr,n);
	for(int i=0;i<n;i++)    cout<<arr[i]<<" ";
}

