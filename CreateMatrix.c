#include <stdio.h>
#include <stdlib.h>
float** CreateMatrix(int rows, int columns)
{
	int i;
	float** mat;	

	mat = malloc(sizeof(float*) * rows);			
	for (i = 0; i < rows; i++)
	{
		mat[i] = malloc(sizeof(float) * columns);	
	}

	return mat;
}