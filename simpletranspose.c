#include<stdio.h>
void accept_matrix(int arr[10][10], int n, int m);
void display(int arr[10][10], int n, int m);
void compact(int arr[10][10],int sp[10][3], int r, int c);
void display_compact(int sp[10][3]);
void simple_tran(int sp[10][3], int tp[10][3]);

void accept_matrix(int arr[10][10], int n, int m ){
printf("Enter the elemnets of the sparse matrix:\n");
for(int i=0;i<n;i++){
for(int j=0;j<m;j++){
scanf("%d",&arr[i][j]);
    }
  }
}

void display(int arr[10][10], int n, int m){
printf("The elemnets of the sparse matrix:\n");
for(int i=0;i<n;i++){
for(int j=0;j<m;j++){
printf("%d ",arr[i][j]);
    }
    printf("\n");
  }
}


void compact(int arr[10][10],int sp[10][3], int r, int c){
int k ;
int n;
sp[0][0]=r;
sp[0][1]=c;
//sp[0][2]=n;
k=1;
for(int i=0;i<r;i++){
for(int j=0;j<c;j++){
if(arr[i][j]!=0){
 sp[k][0]=i;
 sp[k][1]=j;
 sp[k][2]=arr[i][j];
 k++;
        }
     }
  }
  sp[0][2]=k-1;
}

 void display_compact(int sp[10][3]){
 int row=sp[0][2]+1;
 for(int i=0;i<row;i++){
 printf("%d %d %d\n",sp[i][0],sp[i][1],sp[i][2]);
  }
}

void simple_tran(int sp[10][3], int tp[10][3]) {
    int t = sp[0][2]; // Number of non-zero elements

    // Transpose metadata: rows become cols, cols become rows
    tp[0][0] = sp[0][1];
    tp[0][1] = sp[0][0];
    tp[0][2] = t;

    if (t <= 0) {
        return;
    }

    int q = 1; // Tracks current entry index in transpose matrix 'tp'

    // Loop through columns of original matrix (sp[0][1]) 
    // to keep transpose row-sorted
    for (int i = 0; i < sp[0][1]; i++) { 
        for (int j = 1; j <= t; j++) {
            // Check if element belongs to current column
            if (sp[j][1] == i) {
                tp[q][0] = sp[j][1]; // Original Column becomes New Row
                tp[q][1] = sp[j][0]; // Original Row becomes New Column
                tp[q][2] = sp[j][2]; // Value remains identical
                q++;
            }
        }
    }
}







int main(){
 int m, n;
    int arr[10][10], sp[10][3], tp[10][3];

    printf("Enter number of rows: ");
    scanf("%d", &m);

    printf("Enter number of columns: ");
    scanf("%d", &n);

    accept_matrix(arr,m,n);

    printf("\nMatrix:\n");
    display(arr,m,n);

    compact(arr, sp, m, n);

    printf("\nCompact Form:\n");
    display_compact(sp);
    
    simple_tran(sp, tp);

    printf("\nTransposed Compact Form:\n");
    display_compact(tp);

    return 0;
}
