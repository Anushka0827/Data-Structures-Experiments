#include <stdio.h>
#define MAX_TERMS 100

typedef struct {
    int row;
    int col;
    int val;
} Term;

void compact(int A[][10], int m, int n, Term B[]) {
    B[0].row = m;
    B[0].col = n;
    int k = 1;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (A[i][j] != 0) {
                B[k].row = i;
                B[k].col = j;
                B[k].val = A[i][j];
                k++;
            }
        }
    }
    B[0].val = k - 1;
}

void printSparse(Term sparse[]) {
    int t = sparse[0].val;
    printf("Row\tCol\tValue\n");
    for (int i = 0; i <= t; i++) {
        printf("%d\t%d\t%d\n", sparse[i].row, sparse[i].col, sparse[i].val);
    }
}

void simpleTranspose(Term A[], Term B[]) {
    int m = A[0].row;
    int n = A[0].col;
    int t = A[0].val;

    B[0].row = n;
    B[0].col = m;
    B[0].val = t;

    if (t <= 0) return;

    int q = 1;
    for (int col = 0; col < n; col++) {
        for (int p = 1; p <= t; p++) {
            if (A[p].col == col) {
                B[q].row = A[p].col;
                B[q].col = A[p].row;
                B[q].val = A[p].val;
                q++;
            }
        }
    }
}

void fastTranspose(Term A[], Term B[]) {
    int m = A[0].row;
    int n = A[0].col;
    int t = A[0].val;

    B[0].row = n;
    B[0].col = m;
    B[0].val = t;

    if (t <= 0) return;

    int S[MAX_TERMS] = {0};
    int T[MAX_TERMS] = {0};

    for (int i = 0; i < n; i++) {
        S[i] = 0;
    }

    for (int i = 1; i <= t; i++) {
        S[A[i].col]++;
    }

    T[0] = 1;
    for (int i = 1; i < n; i++) {
        T[i] = T[i - 1] + S[i - 1];
    }

    for (int i = 1; i <= t; i++) {
        int j = A[i].col;
        B[T[j]].row = A[i].col;
        B[T[j]].col = A[i].row;
        B[T[j]].val = A[i].val;
        T[j]++;
    }
}

void addSparse(Term a[], Term b[], Term sum[]) {
    if (a[0].row != b[0].row || a[0].col != b[0].col) {
        printf("Matrices dimensions must match for addition.\n");
        sum[0].val = 0;
        return;
    }

    sum[0].row = a[0].row;
    sum[0].col = a[0].col;

    int i = 1, j = 1, k = 1;
    int t1 = a[0].val;
    int t2 = b[0].val;

    while (i <= t1 && j <= t2) {
        if (a[i].row < b[j].row || (a[i].row == b[j].row && a[i].col < b[j].col)) {
            sum[k++] = a[i++];
        } else if (b[j].row < a[i].row || (b[j].row == a[i].row && b[j].col < a[i].col)) {
            sum[k++] = b[j++];
        } else {
            int added_val = a[i].val + b[j].val;
            if (added_val != 0) {
                sum[k].row = a[i].row;
                sum[k].col = a[i].col;
                sum[k].val = added_val;
                k++;
            }
            i++;
            j++;
        }
    }

    while (i <= t1) {
        sum[k++] = a[i++];
    }

    while (j <= t2) {
        sum[k++] = b[j++];
    }

    sum[0].val = k - 1;
}

int main() {
    Term A[MAX_TERMS], B[MAX_TERMS], result[MAX_TERMS];
    int mat[10][10];
    int rows = 0, cols = 0;
    int choice;
    int hasA = 0, hasB = 0;

    while (1) {
        printf("\n1. Create Sparse Matrix A\n");
        printf("2. Create Sparse Matrix B\n");
        printf("3. Display Matrices\n");
        printf("4. Simple Transpose of A\n");
        printf("5. Fast Transpose of A\n");
        printf("6. Add Sparse Matrices (A + B)\n");
        printf("7. Exit\n");
        printf("Enter your choice: ");
        if (scanf("%d", &choice) != 1) break;

        switch (choice) {
            case 1:
                printf("Enter number of rows and columns for A: ");
                scanf("%d %d", &rows, &cols);
                printf("Enter matrix elements (%d x %d):\n", rows, cols);
                for (int i = 0; i < rows; i++) {
                    for (int j = 0; j < cols; j++) {
                        scanf("%d", &mat[i][j]);
                    }
                }
                compact(mat, rows, cols, A);
                hasA = 1;
                break;

            case 2:
                printf("Enter number of rows and columns for B: ");
                scanf("%d %d", &rows, &cols);
                printf("Enter matrix elements (%d x %d):\n", rows, cols);
                for (int i = 0; i < rows; i++) {
                    for (int j = 0; j < cols; j++) {
                        scanf("%d", &mat[i][j]);
                    }
                }
                compact(mat, rows, cols, B);
                hasB = 1;
                break;

            case 3:
                if (hasA) {
                    printf("\nMatrix A (Triplet):\n");
                    printSparse(A);
                } else {
                    printf("Matrix A is empty.\n");
                }
                if (hasB) {
                    printf("\nMatrix B (Triplet):\n");
                    printSparse(B);
                } else {
                    printf("Matrix B is empty.\n");
                }
                break;

            case 4:
                if (!hasA) {
                    printf("Create Matrix A first.\n");
                } else {
                    simpleTranspose(A, result);
                    printf("\nSimple Transpose of A:\n");
                    printSparse(result);
                }
                break;

            case 5:
                if (!hasA) {
                    printf("Create Matrix A first.\n");
                } else {
                    fastTranspose(A, result);
                    printf("\nFast Transpose of A:\n");
                    printSparse(result);
                }
                break;

            case 6:
                if (!hasA || !hasB) {
                    printf("Create both matrices A and B first.\n");
                } else {
                    addSparse(A, B, result);
                    if (result[0].val > 0) {
                        printf("\nSum of Sparse Matrices:\n");
                        printSparse(result);
                    }
                }
                break;

            case 7:
                return 0;

            default:
                printf("Invalid choice.\n");
        }
    }
    return 0;
}
