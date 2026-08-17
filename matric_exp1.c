#include <stdio.h>

void inputMatrix(int a[10][10], int r, int c)
{
    int i, j;

    for(i=0;i<r;i++)
        for(j=0;j<c;j++)
            scanf("%d",&a[i][j]);
}

void add(int a[10][10], int b[10][10], int r, int c)
{
    int i, j, sum[10][10];

    for(i=0;i<r;i++)
        for(j=0;j<c;j++)
            sum[i][j]=a[i][j]+b[i][j];

    printf("\nAddition of Matrix:\n");

    for(i=0;i<r;i++)
    {
        for(j=0;j<c;j++)
            printf("%d ",sum[i][j]);
        printf("\n");
    }
}

void subtract(int a[10][10], int b[10][10], int r, int c)
{
    int i, j, sub[10][10];

    for(i=0;i<r;i++)
        for(j=0;j<c;j++)
            sub[i][j]=a[i][j]-b[i][j];

    printf("\nSubtraction of Matrix:\n");

    for(i=0;i<r;i++)
    {
        for(j=0;j<c;j++)
            printf("%d ",sub[i][j]);
        printf("\n");
    }
}

void multiply(int a[10][10], int b[10][10], int r, int c)
{
    int i, j, k, mul[10][10];

    for(i=0;i<r;i++)
    {
        for(j=0;j<c;j++)
        {
            mul[i][j]=0;

            for(k=0;k<c;k++)
                mul[i][j]+=a[i][k]*b[k][j];
        }
    }

    printf("\nMultiplication of Matrix:\n");

    for(i=0;i<r;i++)
    {
        for(j=0;j<c;j++)
            printf("%d ",mul[i][j]);
        printf("\n");
    }
}

void transpose(int a[10][10], int r, int c)
{
    int i, j, t[10][10];

    for(i=0;i<r;i++)
        for(j=0;j<c;j++)
            t[j][i]=a[i][j];

    printf("\nTranspose Matrix:\n");

    for(i=0;i<c;i++)
    {
        for(j=0;j<r;j++)
            printf("%d ",t[i][j]);
        printf("\n");
    }
}

int main()
{
    int a[10][10], b[10][10];
    int r, c, choice;

    printf("Enter rows and columns: ");
    scanf("%d%d",&r,&c);

    printf("Enter First Matrix:\n");
    inputMatrix(a,r,c);

    printf("Enter Second Matrix:\n");
    inputMatrix(b,r,c);

    while(1)
    {
    
        printf("1. Addition\n");
        printf("2. Subtraction\n");
        printf("3. Multiplication\n");
        printf("4. Transpose of First Matrix\n");
        printf("5. Transpose of Second Matrix\n");
        printf("6. Exit\n");

        printf("Enter your choice: ");
        scanf("%d",&choice);

        switch(choice)
        {
            case 1:
                add(a,b,r,c);
                break;

            case 2:
                subtract(a,b,r,c);
                break;

            case 3:
                multiply(a,b,r,c);
                break;

            case 4:
                printf("\nTranspose of First Matrix:\n");
                transpose(a,r,c);
                break;

            case 5:
                printf("\nTranspose of Second Matrix:\n");
                transpose(b,r,c);
                break;

            case 6:
                printf("Program Ended.\n");
                return 0;

            default:
                printf("Invalid Choice.\n");
        }
    }

    return 0;
}
