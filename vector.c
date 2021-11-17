#include <stdlib.h>
#include <stdio.h>
#include <math.h>
 

void matrix_show(double** matrix, int n)
{
    printf("\n");
    for (int i = 0; i < n; i++) {
        printf("\n");
        for (int j = 0; j < n; j++)
            printf("  %.5f ", matrix[i][j]);
    }
}

 void new_matrix(double**& matrix, int n)
 {
     matrix = new double* [n];
     for (int i = 0; i < n; i++)
         matrix[i] = new double[n];
 }

 void pr_matrix(double** A, double** B, double** C, int n)
 {
     for (int i = 0; i < n; i++)
         for (int j = 0; j < n; j++)
         {
             C[i][j] = 0;
             for (int k = 0; k < n; k++)
                 C[i][j] += A[i][k] * B[k][j];
         }
 }

 void calc_U(double** A, double** B, int n)
 {
     double max_elem = A[0][1];
     int h = 1;
     int k = 0;
     for (int i = 0; i < n; i++)
     {
         for (int j = i + 1; j < n; j++)
             if (fabs(A[i][j]) > max_elem)
             {
                 max_elem = fabs(A[i][j]);
                 k = i;
                 h = j;
             }
     }
     double fi = 0.5 * atan((2 * max_elem) / (A[k][k] - A[h][h]));

     if (A[k][k] == A[h][h]) {
         fi = 0.785;
     }

     for (int i = 0; i < n; i++)
         for (int j = 0; j < n; j++)
         {
             if (i == j)
             {
                 B[i][j] = 1;
             }
             else
                 B[i][j] = 0;

             B[k][h] = -sin(fi);
             B[h][k] = sin(fi);
             B[h][h] = cos(fi);
             B[k][k] = cos(fi);

         }

 }
 
 double elem_sum(double** A, int n)
 {
     double sum = 0;
     for (int i = 0; i < n; i++)
         for (int j = i + 1; j < n; j++)
             sum += (A[i][j]) * (A[i][j]);

     return sum;
 }
 void trans_matrix(double** A, double** B, double** T, int n)
 {
     for (int i = 0; i < n; i++)
         for (int j = 0; j < n; j++) {
             T[i][j] = A[j][i];
             B[i][j] = A[j][i];
             B[i][j] = T[i][j];
         }

 }

 void prir_matrix(double** A, double** B, double** T, int n)
 {
     for (int i = 0; i < n; i++)
         for (int j = 0; j < n; j++) {
             T[i][j] = A[i][j];
             B[i][j] = A[i][j];
             B[i][j] = T[i][j];
         }

 }

void calc_max_elem(double** A, int n)
{
    double max_elem = A[0][1];
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++)
            if (A[i][j] > max_elem)
            {
                max_elem = A[i][j];
            }
    }
    printf("%f", max_elem);
}

int control(double** A, int n)
{
   double s = 0;
    s = elem_sum(A, n);
    if (s == 0)
        printf("\nPreobrazovanie zavercheno \n");
    else
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                if (A[i][j] != A[j][i]) {
                    printf("\nMatrix is not symmetric \n");
                    return 0;
                }
    return 0;
}

int main()
{

    char file_name[100];
    FILE* file1;
    int check = 1;
    int dimension1, rows1, columns1;
    float value1;

    while (check == 1) {
        printf("Enter filename: ");
        scanf("%s", file_name);

        file1 = fopen(file_name, "r");

        if (!file1)
            puts("File with this name doesn't exist. Try again!");
        else
            check = 0;
    }


    fscanf(file1, "%d\n%d %d\n", &dimension1, &rows1, &columns1);

    if (rows1 != columns1) {
        printf("It's not square matrix. Tre again!\n");
        return 0;
    }
   double** A;
    A = CreateMatrix(rows1, columns1);


    for (int i = 0; i < rows1; i++)
    {
        for (int j = 0; j < columns1; j++)
        {
            fscanf(file1, "%f", &value1);
            A[i][j] = value1;
        }
        fscanf(file1, "\n");
    }

    int n = rows1;

    float Eps;
    printf("Enter the  Epsilon: \n");
    scanf("%f", &Eps);

    if (Eps < 0.00001)
    {
        Eps = 0.00001;
    }
    double** A;
    double** U;
    double** UT;
    double** E;
    double** C;
    double** T1;
    double** T2;
    new_matrix(A, n);
    new_matrix(U, n);
    new_matrix(UT, n);
    new_matrix(E, n);
    new_matrix(C, n);
    new_matrix(T1, n);
    new_matrix(T2, n);
    control(A, n);

    double s = elem_sum(A, n);

    printf("\n please waiting... \n");
    for (int i = 0; sqrt(s) > Eps; i++) {
        calc_U(A, U, n);
        trans_matrix(U, UT, T1, n);
        pr_matrix(UT, A, E, n);
        pr_matrix(E, U, C, n);
        prir_matrix(C, A, T2, n);

        s = elem_sum(A, n);
    }
    matrix_show(A, n);

    return 0;
}

