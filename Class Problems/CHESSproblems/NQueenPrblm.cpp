#include <bits/stdc++.h>

using namespace std;

bool isItSafe(vector<vector<bool>> &grid, int &row, int &col, int &n)
{
   for (int i = row - 1; i >= 0; i--)
   {
      if (grid[i][col])
         return false;
   }
   for (int i = row - 1, j = col - 1; i >= 0 and j >= 0; i--, j--)
   {
      if (grid[i][j])
         return false;
   }
   for (int i = row - 1, j = col + 1; i >= 0 and j < n; i--, j++)
   {
      if (grid[i][j])
         return false;
   }
   return true;
}

void display(vector<vector<bool>> &grid, int &n)
{
   for (int i = 0; i < n; i++)
   {
      for (int j = 0; j < n; j++)
      {
         if (grid[i][j])
            cout << "Q  ";
         else
            cout << "_  ";
      }
      cout << endl;
   }
   cout<<endl;
}

int queenCount = 0;
void NQueenCount(vector<vector<bool>> &grid, int curr_row, int n)
{
   // for (int i = 0; i < n; i++)
   // {
   //    for (int j = 0; j < n; j++)
   //    {
   //       if (grid[i][j])
   //          cout << "Q ";
   //       else
   //          cout << "_ ";
   //    }
   //    cout << endl; 
   // }

   if (curr_row == n)
   {
      queenCount++;
      cout << "Arrangement No. " << queenCount << " :" << endl;
      display(grid, n);
      return;
   }
   for (int i = 0; i < n; i++)
   {
      if (isItSafe(grid, curr_row, i, n))
      {
         grid[curr_row][i] = true;
         NQueenCount(grid, curr_row + 1, n);
         grid[curr_row][i] = false;
      }
   }
}
int main()
{
   int n; //size of grid
   cin >> n;
   vector<vector<bool>> grid(n,vector<bool>(n,false));
   NQueenCount(grid, 0, n);

   return 0;
}