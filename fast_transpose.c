#include <stdio.h>

void accept_matrix(int r, int c, int a[10][10])
{
    int i, j;

    for (i = 0; i < r; i++)
    {
        for (j = 0; j < c; j++)
        {
            printf("Matrix[%d][%d] : ", i, j);
            scanf("%d", &a[i][j]);
        }
    }
}

void compact_matrix(int r, int c, int a[10][10], int b[20][3])
{
    int i, j;
    int k = 1;

    b[0][0] = r;
    b[0][1] = c;

    for (i = 0; i < r; i++)
    {
        for (j = 0; j < c; j++)
        {
            if (a[i][j] != 0)
            {
                b[k][0] = i;
                b[k][1] = j;
                b[k][2] = a[i][j];
                k++;
            }
        }
    }

    b[0][2] = k - 1;
}

void display_compact(int b[20][3])
{
    int i;
    int rows = b[0][2] + 1;

    printf("\nRow\tCol\tValue\n");
    printf("---------------------\n");

    for (i = 0; i < rows; i++)
    {
        printf("%d\t%d\t%d\n", b[i][0], b[i][1], b[i][2]);
    }
}

void fast_transpose(int a[20][3], int b[20][3])
{
    int m = a[0][0]; // Original rows
    int n = a[0][1]; // Original columns
    int t = a[0][2]; // Total non-zero elements

    // Set metadata for transposed matrix
    b[0][0] = n;
    b[0][1] = m;
    b[0][2] = t;

    int total[n];     // Count of elements in each column of 'a'
    int index[n];     // Starting position of each column in 'b'

    if (t > 0)
    {
        for (int i = 0; i < n; i++)
        {
            total[i] = 0;
        }

        // Count occurrences of each column index
        for (int i = 1; i <= t; i++)
        {
            total[a[i][1]]++;
        }

        // Compute starting index for each column in transposed matrix
        index[0] = 1;
        for (int i = 1; i < n; i++)
        {
            index[i] = index[i - 1] + total[i - 1];
        }

        // Place elements in correct transposed positions
        for (int i = 1; i <= t; i++)
        {
            int col = a[i][1];
            int pos = index[col];

            b[pos][0] = a[i][1];
            b[pos][1] = a[i][0];
            b[pos][2] = a[i][2];

            index[col]++;
        }
    }
}

int main()
{
    int a[10][10];
    int compact[20][3];
    int transpose[20][3];
    int r, c;

    printf("Enter rows and columns of the sparse matrix: ");
    scanf("%d %d", &r, &c);

    printf("Enter the sparse matrix elements:\n");
    accept_matrix(r, c, a);

    compact_matrix(r, c, a, compact);

    printf("\nCompact Matrix Representation:");
    display_compact(compact);

    fast_transpose(compact, transpose);

    printf("\nFast Transpose of Compact Matrix:");
    display_compact(transpose);

    return 0;
}
