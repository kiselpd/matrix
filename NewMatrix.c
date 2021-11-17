// Мечкина Ксения Адексеевна , РКТ1-31, 10.11.2020
// Домашнее задание 1. Часть 1
// Поправки 16.11.2020
#include <stdio.h>
//#include <conio.h>
#include <stdlib.h>

/*#include "PrintMatrix.c"
#include "FillMatrix.c"
#include "CreateMatrix.c"*/

// Функция создания двумерной матрицы
float** CreateMatrix(int rows, int columns);

// Функция заполнения матрицы 
void FillMatrix(float** mat, int rows, int columns);

// Функция вывода матрицы
void PrintMatrix(float** mat, int rows, int columns);

int NewMatrix()
{
	int dimension;					// Порядок матрицы
	int rows;						// Количество строк матрцы
	int columns;					// Количество столбцов матрицы
	float** Matrix;					// Матрица
	char filename[100];				// Имя файла
	int i;
	int j;
	FILE* file;                     //Файловая переменная

	// Переменные для проверки 
	int dimension_t;                //Переменная, в которую мы из файла считаем порядок матрицы для проверки с введенной нами
	int rows_t;
	int columns_t;
	float value_t;
	const float eps = 0.0001f;		// Погрешность значения 
	

	// Ввод порядка и проверка на равенство 2 
	printf("Enter matrix dimension: ");
	scanf("%d", &dimension);
	if (dimension != 2)
	{
		printf("Wrong dimension! { %d } \n", dimension);
		return 0;
	}

	// Ввод размерности матрицы
	printf("Enter matrix rows and columns: ");
	scanf("%d %d", &rows, &columns);

	Matrix = CreateMatrix(rows, columns);		// Создание динамической матрицы размером rowsXcolumns 
	FillMatrix(Matrix, rows, columns);			// Заполнение матрицы
	PrintMatrix(Matrix, rows, columns);			// Вывод полученой матрицы

	// Ввод имя файла для записи матрицы
	printf("Enter filename: ");
	scanf("%s", filename);

	// Открываем файл для записи 
	file = fopen(filename, "w");
	if (file == NULL)							// Проверяем, что файл открылся правильно
	{
		printf("Can\'t open file to write \n");
		return 0;
	}

	// Запись матрицы в файл
	fprintf(file, "%d\n%d %d\n", dimension, rows, columns);
	for (i = 0; i < rows; i++)
	{
		for (j = 0; j < columns; j++)
		{
			fprintf(file, "%f ", Matrix[i][j]);
		}
		fprintf(file, "\n");   
	}

	fclose(file);			// Закрытие файла 

	printf("\n-------------------------------------------------------------\n");
	printf("Testing file...\n");

	// Открываем файл для чтения 
	file = fopen(filename, "r");
	if (file == NULL)							// Проверяем, что файл открылся правильно
	{
		printf("Can\'t open file to read \n");
		return 0;
	}

	fscanf(file, "%d\n%d %d\n", &dimension_t, &rows_t, &columns_t);			// Считываем значения из файла
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

	// Считывание и проверка значений матрцы
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

	fclose(file);			// Закрытие файла 

	// Высвобождение памяти
	for (i = 0; i < rows; i++)
	{
		free(Matrix[i]);
	}
	free(Matrix);
	printf("\n-------------------------------------------------------------\n");
	printf("Program executed correctly!\n");

	return 0;
}