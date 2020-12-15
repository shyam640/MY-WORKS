//transpose of square matrix

#include <stdio.h>
using namespace std;
int main()
{
   int n,m;
   scanf("%d %d",&n,&m);
   int mat[n][m];
   printf("Enter a Matrix :\n");
   for (int i = 0; i < n; i++)
   {
      for (int j = 0; j < m; j++)
      {
         scanf("%d", &mat[i][j]);
      }
      printf("\n");
   }

   for (int i = 0; i < n; i++)
   {
      for (int j = 0; j < m; j++)
      {
         if (i < j)
         {
            int temp = mat[i][j];
            mat[i][j] = mat[j][i];
            mat[j][i] = temp;
         }
         else
         
            continue;
         }
      }
   }

   for (int i = 0; i < n; i++)
   {
      for (int j = 0; j < m; j++)
      {
         printf("%d ", mat[i][j]);
      }
      printf("\n");
   }
   return 0;
}