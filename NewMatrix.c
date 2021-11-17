// ������� ������ ���������� , ���1-31, 10.11.2020
// �������� ������� 1. ����� 1
// �������� 16.11.2020
#include <stdio.h>
//#include <conio.h>
#include <stdlib.h>

/*#include "PrintMatrix.c"
#include "FillMatrix.c"
#include "CreateMatrix.c"*/

// ������� �������� ��������� �������
float** CreateMatrix(int rows, int columns);

// ������� ���������� ������� 
void FillMatrix(float** mat, int rows, int columns);

// ������� ������ �������
void PrintMatrix(float** mat, int rows, int columns);

int NewMatrix()
{
	int dimension;					// ������� �������
	int rows;						// ���������� ����� ������
	int columns;					// ���������� �������� �������
	float** Matrix;					// �������
	char filename[100];				// ��� �����
	int i;
	int j;
	FILE* file;                     //�������� ����������

	// ���������� ��� �������� 
	int dimension_t;                //����������, � ������� �� �� ����� ������� ������� ������� ��� �������� � ��������� ����
	int rows_t;
	int columns_t;
	float value_t;
	const float eps = 0.0001f;		// ����������� �������� 
	

	// ���� ������� � �������� �� ��������� 2 
	printf("Enter matrix dimension: ");
	scanf("%d", &dimension);
	if (dimension != 2)
	{
		printf("Wrong dimension! { %d } \n", dimension);
		return 0;
	}

	// ���� ����������� �������
	printf("Enter matrix rows and columns: ");
	scanf("%d %d", &rows, &columns);

	Matrix = CreateMatrix(rows, columns);		// �������� ������������ ������� �������� rowsXcolumns 
	FillMatrix(Matrix, rows, columns);			// ���������� �������
	PrintMatrix(Matrix, rows, columns);			// ����� ��������� �������

	// ���� ��� ����� ��� ������ �������
	printf("Enter filename: ");
	scanf("%s", filename);

	// ��������� ���� ��� ������ 
	file = fopen(filename, "w");
	if (file == NULL)							// ���������, ��� ���� �������� ���������
	{
		printf("Can\'t open file to write \n");
		return 0;
	}

	// ������ ������� � ����
	fprintf(file, "%d\n%d %d\n", dimension, rows, columns);
	for (i = 0; i < rows; i++)
	{
		for (j = 0; j < columns; j++)
		{
			fprintf(file, "%f ", Matrix[i][j]);
		}
		fprintf(file, "\n");   
	}

	fclose(file);			// �������� ����� 

	printf("\n-------------------------------------------------------------\n");
	printf("Testing file...\n");

	// ��������� ���� ��� ������ 
	file = fopen(filename, "r");
	if (file == NULL)							// ���������, ��� ���� �������� ���������
	{
		printf("Can\'t open file to read \n");
		return 0;
	}

	fscanf(file, "%d\n%d %d\n", &dimension_t, &rows_t, &columns_t);			// ��������� �������� �� �����
	printf("%d\n%d %d\n", dimension_t, rows_t, columns_t);
	if (dimension != dimension_t)
	{
		printf("Wrong dimension reading \n");
		return 0;
	}
	if (rows != rows_t)
	{
		printf("Wrong rows reading \n");
		return 0;
	}
	if (columns != columns_t)
	{
		printf("Wrong columns reading \n");
		return 0;
	}

	// ���������� � �������� �������� ������
	for (i = 0; i < rows; i++)
	{
		for (j = 0; j < columns; j++)
		{
			fscanf(file, "%f", &value_t);
			printf("%8.3f ", value_t);
			if (abs(value_t - Matrix[i][j]) > eps)  
			{
				printf("\n Wrong file reading of value: %8.3f  at row: %d, column: %d \n", value_t, i, j);
				return 0;
			}
		}
		printf("\n");
	}

	fclose(file);			// �������� ����� 

	// ������������� ������
	for (i = 0; i < rows; i++)
	{
		free(Matrix[i]);
	}
	free(Matrix);
	printf("\n-------------------------------------------------------------\n");
	printf("Program executed correctly!\n");

	return 0;
}