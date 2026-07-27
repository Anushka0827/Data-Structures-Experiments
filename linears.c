#include<stdio.h>
struct student{
int roll_no;
char name[50];
};
void accept(struct student s[10], int n){
   for(int i=0;i<n;i++){
   printf("Enter the details of the student:%d\n",i+1);
   printf("\nEnter the roll_no:\n");
    scanf("%d\n",&s[i].roll_no);
    printf("Enter  name of the student:\n");
    scanf(" %[^\n]s", s[i].name);
    printf("\n");
  }
}
void display(struct student s[10], int n){
for(int i=0;i<n;i++){
printf("The details of the student are:%d\n",i+1);
printf("\nThe roll number is:%d\n",s[i].roll_no);
printf("\nThe name is:%s\n",s[i].name);
printf("\n");
 }
}

int main(){
int n;
struct student s[10];
printf("Enter the number of the student(max 10):\n");
scanf("%d",&n);
accept(s,n);
display(s,n);
}
