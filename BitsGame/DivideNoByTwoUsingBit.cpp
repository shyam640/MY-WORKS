#include <iostream>
using namespace std;

int DivideBytwoPowerM1(int N,int k){
    return N/(1<<k);
}

int DivideBytwoPowerM2(int N,int k){
    return N>>k;
}

int main() {
    int N;
    cin>>N;
    int k;
    cin>>k;
	cout<<DivideBytwoPowerM1(N,k)<<endl;
	cout<<DivideBytwoPowerM2(N,k)<<endl;
	return 0;
}
