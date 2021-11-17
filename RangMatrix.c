#include <stdio.h>
#include <stdlib.h>

#define MIN(a, b) ((a<=b)?a:b)

float det(float** a, int n);
int Rang_mat(float** A, int i, int j);

int RangMatrix()
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


    printf("Determinant of matrix: %d\n", Rang_mat(matrix, rows1, columns1));

    for (int i = 0; i < rows1; i++)
    {
        free(matrix[i]);
    }
    free(matrix);

    fclose(file1);
    return 0;
}


int Rang_mat(float** A, int i, int j)

{
    float r = 0;
    float q = 1;

    while (q <= MIN(i, j)) {

        float** B;
        B = CreateMatrix(q, q);

        for (int a = 0; a < (i - (q - 1)); a++) {
            for (int b = 0; b < (j - (q - 1)); b++) {
                for (int c = 0; c < q; c++) {
                    for (int d = 0; d < q; d++) {
                        B[c][d] = A[a + c][b + d];
                    }
                }
                if (!(det(B, q) == 0)) {
                    r = q;
                }
            }
        }
        q++; 
    }

    return r;
}