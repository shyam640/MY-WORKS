#include <bits/stdc++.h>
using namespace std;

int SwapBits(int n,int pos1,int pos2,int digits){
    int shift1,shift2,value1,value2;
    while(n--){
        shift1=(n<<pos1);
        shift2=(n<<pos2);
        value1=(n&shift1);
        value2=(n&shift2);
        if(value1 and !value2 || value1 and !value2){
            if(value1){
                n=(n&(~shift1));
                n|=shift2;
            }else{
                n=(n&(~shift2));
                n|=shift1;
            }
        }
    }
    return n;
}

int main() {
	int n;
	cin>>n;
	int pos1,pos2,digits;
	cin>>pos1>>pos2>>digits;
	SwapBits(n,pos1,pos2,digits);
	return 0;
}
