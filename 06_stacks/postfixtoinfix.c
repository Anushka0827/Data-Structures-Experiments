#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define SIZE 100

char stack[SIZE][SIZE];
int top = -1;

void push(char *str) {
    strcpy(stack[++top], str);
}

void pop(char *str) {
    strcpy(str, stack[top--]);
}

void postinfx(char post[]) {
    char s1[SIZE], s2[SIZE], s3[SIZE], inf[SIZE];

    for (int i = 0; post[i] != '\0'; i++) {
        s1[0] = post[i];
        s1[1] = '\0';

        if (isalnum(post[i]) != 0) {
            push(s1);
        } else {
            pop(s2);
            pop(s3);

            strcpy(inf, "(");
            strcat(inf, s3);
            strcat(inf, s1);
            strcat(inf, s2);
            strcat(inf, ")");

            push(inf);
        }
    }
    pop(inf);
    printf("The Infix expression is: %s\n", inf);
}

int main() {
    char post[SIZE];

    printf("Enter Postfix expression: ");
    scanf("%s", post);

    postinfx(post);

    return 0;
}
