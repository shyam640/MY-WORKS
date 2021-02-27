#include <iostream>
using namespace std;

// int CountingFlipBits(int a,int b){
//     int count=0;
//     while(a!=0 or b!=0){
//         if((a%2) != (b%2))
//             count++;
//         a/=2;
//         b/=2;
//     }
//     return count;
// }

int CountingFlipBits(int a,int b){
    return __builtin_popcount(a^b);
}

// int CountingFlipBits(int a,int b){
//     int count=0;
//     int temp=a^b;
//     while(temp){
//         temp&=(temp-1);
//         count++;
//     }
//     return count;
// }

// int CountingFlipBits(int a,int b){
//     int count=0;
//     while(a or b){
//         if((a&1)!=(b&1))
//             count++;
//         a>>=1;
//         b>>=1;
//     }
// }

int main() {
	int a,b;
	cin>>a>>b;
	cout<<CountingFlipBits(a,b)<<endl;
	return 0;
}
