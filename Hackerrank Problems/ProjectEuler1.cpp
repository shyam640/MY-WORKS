#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <string>
#include <bitset>
#include <cstdio>
#include <limits>
#include <vector>
#include <climits>
#include <cstring>
#include <cstdlib>
#include <fstream>
#include <numeric>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <unordered_map>

using namespace std;

int m_sum(int num){
   int sum=0;
   for(int i=3;i<num;i+=3){
      sum+=i;
   }
   for(int i=5;i<num;i+=5){
      sum+=i;
   }
   for(int i=15;i<num;i+=15){
      sum-=i;
   }
   return sum;
}

int main(){
    int t;
    cin >> t;
    for(int a0 = 0; a0 < t; a0++){
        int n;
        cin >> n;
        cout<<m_sum(n)<<endl;
    }
    return 0;
}