#include <stdio.h>
void FillMatrix(float** mat, int rows, int columns)
{
	int i;
	int j;

	for (i = 0; i < rows; i++)
	{
		for (j = 0; j < columns; j++)
		{
			printf("a[%d][%d]: ", i, j);
		   scanf("%f", &mat[i][j]); 
        }
	}
 }
