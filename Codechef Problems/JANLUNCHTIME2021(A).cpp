//                         ------------------------
//                        | SUCCESSFULLY EXECUTED |
//                        ------------------------
#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;
    int x,y,z;
    while(t>0){
        cin>>x>>y>>z;
        if((x+y)==z ||((x+z)==y) || ((y+z)==x))
            cout<<"YES"<<endl;
        else
            cout<<"NO"<<endl;
        t--;
    }
    return 0;
}