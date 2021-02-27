#include <iostream>
using namespace std;

// Time Complexity -> O(1)

// int UnSetBit(long long int n){
//     long long int x=n;
//     n|=n>>1;
//     n|=n>>2;
//     n|=n>>4;
//     n|=n>>8;
//     n|=n>>16;
//     return __builtin_popcount(x^n);
// }

// Time Complexity -> O(logn)

    int UnSetBit(long long int n){
        int count=0;
        for(int i=1;i<=n;i=i<<1){
            if((i&n)==0)
                count++;
        }
        return count;
    }

int main() {
    long long int n;
    cin>>n;
    cout<<UnSetBit(n)<<endl;
	return 0;
}
