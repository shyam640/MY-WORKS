/*
Array is said to be beautiful if:-
1. The array consists of unique elements.
2. The array elements are not sorted in ascending order.
3. All the array elements should have a value between 1 to n inclusive, i.e.,1<=Ai<=n , where,0<=i<=n .
*/

#include <iostream>
#include <stdlib.h>

using namespace std;
int main()
{
   system("CLS");
   int q; //No. of queries
   cin >> q;
   for (int query = 1; query <= q; query++)
   {
      int n; //size of array
      cin >> n;
      int arr[n];
      for (int i = 0; i < n; i++)
      {
         cin >> arr[i];
      }
      int flag = 0;
      int i = 0;
      while (i < n - 1)
      {
         for (int j = i + 1; j < n; j++)
         {
            if (arr[i] == arr[j])
            {
               flag = 1;
            }
         }
         i++;
      }

      int flag1=0;
      for(int i=0;i<n;i++){
         if(arr[i]>n){
            flag1=1;
            break;
         }
      }

      int flag2=0;
      for(int i=0;i<n-1;i++){
         if(arr[i]>arr[i+1]){
            flag2=0;
            break;
         }else{
            flag2=1;
         }
      }


      if (flag == 1 || flag1==1 || flag2==1)
         cout << "Ugly" << endl;
      else
         cout << "Beautiful" << endl;
   }
   return 0;
}