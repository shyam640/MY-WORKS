//                   -----------------------
//                   |SUCCESSFULLY EXECUTED|
//                   -----------------------
#include <bits/stdc++.h>

using namespace std;

int main()
{
   system("CLS");
   int t; //No. of test cases
   cin >> t;
   for (int test_case = 1; test_case <= t; test_case++)
   {
      int n; //size of matrix
      cin >> n;
      int arr[n][n];
      for (int i = 0; i < n; i++)
      {
         for (int j = 0; j < n; j++)
         {
            cin >> arr[i][j];
         }
      }
      int t = 0; //trace  of matrix

      int new_arr1[n][n];
      for (int i = 0; i < n; i++)
      {
         for (int j = 0; j < n; j++)
         {
            new_arr1[i][j] = arr[i][j];
         }
      }

      int new_arr2[n][n];
      for (int i = 0; i < n; i++)
      {
         for (int j = 0; j < n; j++)
         {
            new_arr2[i][j] = arr[i][j];
         }
      }

      for (int i = 0; i < n; i++)
      {
         for (int j = 0; j < n; j++)
         {
            if (i == j)
            {
               t += arr[i][j];
            }
         }
      }

      int r = 0; //No. of rows with repeated element
      int k = 0;
      while (k < n)
      {
         for (int i = 0; i < n - 1; i++)
         {
            for (int j = i + 1; j < n; j++)
            {
               if (new_arr1[k][j] < new_arr1[k][i])
               {
                  int temp = new_arr1[k][i];
                  new_arr1[k][i] = new_arr1[k][j];
                  new_arr1[k][j] = temp;
               }
            }
         }
         k++;
      }

     int a=0;
      while(a<n){
         for(int i=0;i<n-1;i++){
            if(new_arr1[a][i]==new_arr1[a][i+1]){
               r++;
               break;
            }
         }
         a++;
      }
      int c = 0; //No. of column with repeated element
      int z = 0;
      while (z < n)
      {
         for (int i = 0; i < n - 1; i++)
         {
            for (int j = i + 1; j < n; j++)
            {
               if (new_arr2[j][z] < new_arr2[i][z])
               {
                  int temp = new_arr2[i][z];
                  new_arr2[i][z] = new_arr2[j][z];
                  new_arr2[j][z] = temp;
               }
            }
         }
         z++;
      }

      int b=0;
      while(b<n){
         for(int i=0;i<n-1;i++){
            if(new_arr2[i][b]==new_arr2[i+1][b]){
               c++;
               break;
            }
         }
         b++;
      }

      cout << "Case #" << test_case << ": " << t << " " << r << " " << c << endl;
   }
   return 0;
}