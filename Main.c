#include <stdio.h>

#include "functions.h"


int main() {
	int exit = 0, item = 0;

	while (!exit) {
		printf("1. Sum A+B\n2.Multiplication AxB\n3.Determinant A\n4.Create new matrix\n5.Rank A\n6.Exit\nSelect a menu item: ");
		scanf("%d", &item);
		switch (item) {
		case 1:
			printf("\n-------------------------------------------------------------\n");
			SumMatrix();
			printf("\n-------------------------------------------------------------\n");
			break;
		case 2:
			printf("\n-------------------------------------------------------------\n");
			MultiMat();
			printf("\n-------------------------------------------------------------\n");
			break;
		case 3:
			printf("\n-------------------------------------------------------------\n");
			DetMatrix();
			printf("\n-------------------------------------------------------------\n");
			break;
		case 4:
			printf("\n-------------------------------------------------------------\n");
			NewMatrix();
			printf("\n-------------------------------------------------------------\n");
			break;
		case 5:
			printf("\n-------------------------------------------------------------\n");
			RangMatrix();
			printf("\n-------------------------------------------------------------\n");
			break;
		case 6:
			exit = 1;
			break;
		default:
			exit = 1;
			break;
		}
	}

	return 0;
}