#include <stdio.h>
void PrintMatrix(float** mat, int rows, int columns)
{
	int i;
	int j;
	for (i = 0; i < rows; i++)
	{
		for (j = 0; j < columns; j++)
		{
			printf("%8.3f ", mat[i][j]);
		}
		printf("\n");
	}
	
}