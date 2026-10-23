#include <stdio.h>
#define MAX 10

void readMatrix(int matrix[MAX][MAX], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("Element [%d][%d]: ", i, j);
            scanf("%d", &matrix[i][j]);
        }
    }
}

void printMatrix(int matrix[MAX][MAX], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%d\t", matrix[i][j]);
        }
        printf("\n");
    }
}

void addMatrices(int a[MAX][MAX], int b[MAX][MAX], int res[MAX][MAX], int r, int c) {
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            res[i][j] = a[i][j] + b[i][j];
        }
    }
}

void subtractMatrices(int a[MAX][MAX], int b[MAX][MAX], int res[MAX][MAX], int r, int c) {
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            res[i][j] = a[i][j] - b[i][j];
        }
    }
}

void multiplyMatrices(int a[MAX][MAX], int b[MAX][MAX], int res[MAX][MAX], int r1, int c1, int c2) {
    for (int i = 0; i < r1; i++) {
        for (int j = 0; j < c2; j++) {
            res[i][j] = 0;
            for (int k = 0; k < c1; k++) {
                res[i][j] += a[i][k] * b[k][j];
            }
        }
    }
}

void transposeMatrix(int a[MAX][MAX], int res[MAX][MAX], int r, int c) {
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            res[j][i] = a[i][j];
        }
    }
}

int main() {
    int A[MAX][MAX], B[MAX][MAX], result[MAX][MAX];
    int r1 = 0, c1 = 0, r2 = 0, c2 = 0;
    int choice;

    while (1) {
        printf("\n1. Enter Matrix A\n");
        printf("2. Enter Matrix B\n");
        printf("3. Display Matrices\n");
        printf("4. Addition\n");
        printf("5. Subtraction\n");
        printf("6. Multiplication\n");
        printf("7. Transpose of Matrix A\n");
        printf("8. Exit\n");
        printf("Enter your choice: ");
        if (scanf("%d", &choice) != 1) break;

        switch (choice) {
            case 1:
                printf("Enter rows and columns for Matrix A: ");
                scanf("%d %d", &r1, &c1);
                printf("Enter elements of Matrix A:\n");
                readMatrix(A, r1, c1);
                break;

            case 2:
                printf("Enter rows and columns for Matrix B: ");
                scanf("%d %d", &r2, &c2);
                printf("Enter elements of Matrix B:\n");
                readMatrix(B, r2, c2);
                break;

            case 3:
                if (r1 > 0 && c1 > 0) {
                    printf("\nMatrix A:\n");
                    printMatrix(A, r1, c1);
                } else {
                    printf("Matrix A is empty.\n");
                }
                if (r2 > 0 && c2 > 0) {
                    printf("\nMatrix B:\n");
                    printMatrix(B, r2, c2);
                } else {
                    printf("Matrix B is empty.\n");
                }
                break;

            case 4:
                if (r1 == 0 || r2 == 0) {
                    printf("Enter both matrices first.\n");
                } else if (r1 != r2 || c1 != c2) {
                    printf("Matrices dimensions must match for addition.\n");
                } else {
                    addMatrices(A, B, result, r1, c1);
                    printf("Result of Addition:\n");
                    printMatrix(result, r1, c1);
                }
                break;

            case 5:
                if (r1 == 0 || r2 == 0) {
                    printf("Enter both matrices first.\n");
                } else if (r1 != r2 || c1 != c2) {
                    printf("Matrices dimensions must match for subtraction.\n");
                } else {
                    subtractMatrices(A, B, result, r1, c1);
                    printf("Result of Subtraction:\n");
                    printMatrix(result, r1, c1);
                }
                break;

            case 6:
                if (r1 == 0 || r2 == 0) {
                    printf("Enter both matrices first.\n");
                } else if (c1 != r2) {
                    printf("Columns of A must equal rows of B for multiplication.\n");
                } else {
                    multiplyMatrices(A, B, result, r1, c1, c2);
                    printf("Result of Multiplication:\n");
                    printMatrix(result, r1, c2);
                }
                break;

            case 7:
                if (r1 == 0) {
                    printf("Enter Matrix A first.\n");
                } else {
                    transposeMatrix(A, result, r1, c1);
                    printf("Transpose of Matrix A:\n");
                    printMatrix(result, c1, r1);
                }
                break;

            case 8:
                return 0;

            default:
                printf("Invalid choice.\n");
        }
    }
    return 0;
}
