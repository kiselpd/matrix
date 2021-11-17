#include <stdio.h>
#include <stdlib.h>

int SumMatrix()
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
    if ((columns1 != columns2) || (rows1 != rows2)) {
        printf("These matrixes cannot be folded. Tre again!\n");
        return 0;
    }
    float** matrix;
    matrix = CreateMatrix(rows1, columns1);


    for (int i = 0; i < rows1; i++)
    {
        for (int j = 0; j < columns1; j++)
        {
            fscanf(file1, "%f", &value1);
            fscanf(file2, "%f", &value2);
            matrix[i][j] = value1 + value2;
        }
        fscanf(file2, "\n");
        fscanf(file1, "\n");
    }

    printf("\nSum of matrixes:\n");
    for (int i = 0; i < rows1; i++) {
        for (int j = 0; j < columns1; j++) {
            printf("%f ", matrix[i][j]);
        }
        printf("\n");
    }
    printf("\nEnter filename with result: ");
    scanf("%s", file_name);
    file3 = fopen(file_name, "w");

    fprintf(file3, "%d\n%d %d\n", dimension1, rows1, columns1);
    for (int i = 0; i < rows1; i++)
    {
        for (int j = 0; j < columns1; j++)
        {
            fprintf(file3, "%f ", matrix[i][j]);
        }
        fprintf(file3, "\n");
    }

    for (int i = 0; i < rows1; i++)
    {
        free(matrix[i]);
    }
    free(matrix);


    fclose(file1);
    fclose(file2);
    fclose(file3);
    return 0;
}