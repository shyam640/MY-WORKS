//                  ------------------------
//                 | SUCCESSFULLLY EXECUTED |
//                  ------------------------
#include <bits/stdc++.h>
using namespace std;

bool isItSafe(vector<vector<int>> &grid, int i, int j, int n, vector<vector<bool>> &visited)
{
   return (i >= 0 and j >= 0 and i < n and j < n and visited[i][j] == false);
}

   int arran=1;

void display(vector<vector<int>> &grid, int n)
{
   cout<<"Arrangement No. : "<<arran<<endl;
   for (int i = 0; i < n; i++)
   {
      for (int j = 0; j < n; j++)
      {
         cout << grid[i][j] << " ";
      }
      cout << endl;
   }
   arran++;
}

void KnightsTour(vector<vector<int>> &grid, int i, int j, int count, vector<vector<bool>> &visited, int n)
{
   if (count == (n * n - 1))
   {
      grid[i][j] = count;
      display(grid, n);
      cout<<endl<<endl;
      return;
   }
   if(count>=(n*n)){
      return;
   }
   int xdir[8] = {-2, -2, -1, -1, 1, 1, 2, 2};
   int ydir[8] = {-1, 1, -2, 2, -2, 2, -1, 1};
   visited[i][j] = true;
   grid[i][j] = count;
   for (int k = 0; k < 8; k++)
   {
      if (isItSafe(grid, i + xdir[k], j + ydir[k], n, visited))
      {
         KnightsTour(grid, i + xdir[k], j + ydir[k], count + 1, visited, n);
      }
   }

   grid[i][j] = -1;
   visited[i][j] = false;
}

int main()
{
   int n; //size of grid
   cin >> n;
   vector<vector<int>> grid(n, vector<int>(n, -1));
   vector<vector<bool>> visited(n, vector<bool>(n, false));
   KnightsTour(grid, 0, 0, 0, visited, n);
   return 0;
}