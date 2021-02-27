#include<bits/stdc++.h>
using namespace std;

class Test{
    private:
        int x,y;
    public:
        getData(){
            cin>>x;
            cin>>y;
        }
        friend void task1(x){
             for(int i=1;i<=x;i++)
                cout<<i*i<<" ";
        }
        friend void tast2(y){
            int sum=0;
            for(int i=1;i<=y;i++) 
                sum+=i;
                cout<<sum<<endl;
        }
};

int main(){
    Test t;
    t.getData();
}