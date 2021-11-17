#include <stdio.h>
#include <stdlib.h>

float det(float** a, int n);
float** matr(float** a, int n, int x);

int DetMatrix()
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
    float** matrix;
    matrix = CreateMatrix(rows1, columns1);


    for (int i = 0; i < rows1; i++)
    {
        for (int j = 0; j < columns1; j++)
        {
            fscanf(file1, "%f", &value1);
            matrix[i][j] = value1;
        }
        fscanf(file1, "\n");
    }

    
    printf("Determinant of matrix: %f\n", det(matrix, rows1));

    for (int i = 0; i < rows1; i++)
    {
        free(matrix[i]);
    }
    free(matrix);

    fclose(file1);
    return 0;
}



float** matr(float** a, int n, int x) {
    float** res = (float**)malloc((n - 1) * sizeof(float*));
    for (int i = 0; i < n - 1; ++i)
        res[i] = (float*)malloc((n - 1) * sizeof(float));
    for (int i = 1; i < n; ++i)
        for (int j = 0, k = 0; j < n; ++j, ++k) {
            if (j == x) {
                --k;
                continue;
            }
            res[i - 1][k] = a[i][j];
        }
    return res;
}

float det(float** a, int n) {
    if (n == 1)
        return a[0][0];
    if (n == 2)
        return (a[1][1] * a[0][0]) - (a[0][1] * a[1][0]);
    int ans = 0, sig = 1;
    for (int i = 0; i < n; ++i) {
        ans += (sig * a[0][i] * det(matr(a, n, i), n - 1));
        sig *= -1;
    }
    return ans;
}