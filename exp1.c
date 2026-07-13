#include<stdio.h>

void accept_matrice(int m, int n, int a[10][10]);
void display(int m, int n, int a[10][10]);
void compact(int sp[10][3], int a[10][10], int m, int n);
void display_compact(int sp[10][3]);


void accept_matrice(int m, int n, int a[10][10]){
//printf("Enter number of rows:");
//scanf("%d",&m);
//printf("Enter number of columns:");
//scanf("%d",&n);
printf("Enter elements of sparse matrix:");
for(int i=0;i<m;i++){
for (int j=0;j<n;j++)
  scanf("%d",&a[i][j]);
  }
}

void display(int m, int n, int a[10][10]){
for(int i=0;i<m;i++){
for (int j=0;j<n;j++){
  printf("%d ",a[i][j]);
  }
  printf("\n");
  }
}

void compact(int sp[10][3], int a[10][10], int m, int n){
int k;
sp[0][0]=m;
sp[0][1]=n;
k=1;
for(int i=0;i<m;i++){
for (int j=0;j<n;j++){
  if(a[i][j]!=0){
      sp[k][0]=i;
      sp[k][1]=j;
      sp[k][2]=a[i][j];
      k++;
    }
  }
 }
 sp[0][2]=k-1;
}

void display_compact(int sp[10][3]){
int rows = sp[0][2] + 1;
for(int i=0;i<rows;i++){
printf("%d %d %d\n",sp[i][0],sp[i][1],sp[i][2]);
 }
}


int main(){

    int m, n;
    int a[10][10], sp[10][3];

    printf("Enter number of rows: ");
    scanf("%d", &m);

    printf("Enter number of columns: ");
    scanf("%d", &n);

    accept_matrice(m, n, a);

    printf("\nMatrix:\n");
    display(m, n, a);

    compact(sp, a, m, n);

    printf("\nCompact Form:\n");
    display_compact(sp);

    return 0;
}






