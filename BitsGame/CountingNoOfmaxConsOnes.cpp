#include <iostream>
using namespace std;

// int CountMaxConsOnes(int n){
//     int max_one=-1;
// 	int count=0;
// 	while(n){
// 	    if((n&1)!=0)
// 	        count++;
// 	    else
// 	        count=0;
// 	    max_one=max(max_one,count);
// 	    n>>=1;
// 	}
// 	return max_one;
// }

int CountMaxConsOnes(int n){
    int count=0;
    while(n){
        n&=(n<<1);
        count++;
    }
    return count;
}

// int CountMaxConsOnes(int n){
//     int max_one=-1;
// 	int count=0;
// 	int temp;
// 	while(n){
// 	    temp=n%2;
// 	    if(temp==1)
// 	        count++;
//         else
//             count=0;
//         max_one=max(max_one,count);
//         n/=2;
// 	}
// 	return max_one;
// }

int main() {
	int n;
	cin>>n;
	
	cout<<CountMaxConsOnes(n)<<endl;
	return 0;
}
