#include "FillMatrix.c"
#include "CreateMatrix.c"
#include "PrintMatrix.c"
#include "DetMatrix.c"
#include "MultiMatrix.c"
#include "NewMatrix.c"
#include "RangMatrix.c"
#include "SumMatrix.c"
#ifndef _FUNCTIONS_H_
#define _FUNCTIONS_H_
float** CreateMatrix(int rows, int columns);
void FillMatrix(float** mat, int rows, int columns);
void PrintMatrix(float** mat, int rows, int columns);
int Rang_mat(float** A, int i, int j);
float det(float** a, int n);
float** matr(float** a, int n, int x);
int DetMatrix();
int MultiMat();
int NewMatrix();
int RangMatrix();
int SumMatrix();

#endif