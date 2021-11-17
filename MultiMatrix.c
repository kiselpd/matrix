#include <stdio.h>
#include <stdlib.h>

int MultiMat()
{
    char file_name[100];
    FILE* file1;
    FILE* file2;
    FILE* file3;
    int check = 1;
    int dimension1, rows1, columns1, dimension2, rows2, columns2;
    float value1, value2;

    while (check == 1) {
        printf("Enter filename of first file: ");
        scanf("%s", file_name);

        file1 = fopen(file_name, "r");

        if (!file1)
            puts("File with this name doesn't exist. Try again!");
        else
            check = 0;
    }

    check = 1;

    while (check == 1) {
        printf("Enter filename of second file: ");
        scanf("%s", file_name);

        file2 = fopen(file_name, "r");

        if (!file2)
            puts("File with this name doesn't exist. Try again!");
        else
            check = 0;
    }

    fscanf(file1, "%d\n%d %d\n", &dimension1, &rows1, &columns1);
    fscanf(file2, "%d\n%d %d\n", &dimension2, &rows2, &columns2);
    if (rows2 != columns1) {
        printf("These matrixes cannot be multiply. Tre again!\n");
        return 0;
    }

    float** matrix1;
    matrix1 = CreateMatrix(rows1, columns1);

    float** matrix2;
    matrix2 = CreateMatrix(rows2, columns2);

    for (int i = 0; i < rows1; i++)
    {
        for (int j = 0; j < columns1; j++)
        {
            fscanf(file1, "%f", &value1);
            matrix1[i][j] = value1;
        }
        fscanf(file1, "\n");
    }

    for (int i = 0; i < rows2; i++)
    {
        for (int j = 0; j < columns2; j++)
        {
            fscanf(file2, "%f", &value2);
            matrix2[i][j] = value2;
        }
        fscanf(file2, "\n");
    }

    float** matrix3;
    matrix3 = CreateMatrix(rows1, columns2);


    for (int i = 0; i < rows1; i++) {
        for (int j = 0; j < columns2; j++)
        {
            matrix3[i][j] = 0;
            for (int k = 0; k < rows2; k++)
                matrix3[i][j] += matrix1[i][k] * matrix2[k][j];
        }
    }

    printf("\nMultiplication of matrix:\n");
    for (int i = 0; i < rows1; i++) {
        for (int j = 0; j < columns2; j++) {
            printf("%f ", matrix3[i][j]);
        }
        printf("\n");
    }

    printf("\nEnter filename with result: ");
    scanf("%s", file_name);
    file3 = fopen(file_name, "w");

    fprintf(file3, "%d\n%d %d\n", dimension1, rows1, columns2);
    for (int i = 0; i < rows1; i++)
    {
        for (int j = 0; j < columns2; j++)
        {
            fprintf(file3, "%f ", matrix3[i][j]);
        }
        fprintf(file3, "\n");
    }

    for (int i = 0; i < rows1; i++)
    {
        free(matrix1[i]);
    }
    free(matrix1);

    for (int i = 0; i < rows2; i++)
    {
        free(matrix2[i]);
    }
    free(matrix2);

    for (int i = 0; i < rows1; i++)
    {
        free(matrix3[i]);
    }
    free(matrix3);

    fclose(file1);
    fclose(file2);
    fclose(file3);
    return 0;
}

