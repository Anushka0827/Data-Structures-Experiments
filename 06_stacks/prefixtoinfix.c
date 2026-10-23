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

void preinfx(char prefix[]) {
    char s1[SIZE], op1[SIZE], op2[SIZE], inf[SIZE];
    int l = strlen(prefix);

    for (int i = l - 1; i >= 0; i--) {
        s1[0] = prefix[i];
        s1[1] = '\0';

        if (isalnum(prefix[i])) {
            push(s1);
        } else {
            pop(op1);
            pop(op2);

            strcpy(inf, "(");
            strcat(inf, op1);
            strcat(inf, s1);
            strcat(inf, op2);
            strcat(inf, ")");

            push(inf);
        }
    }
    pop(inf);
    printf("The Infix expression is: %s\n", inf);
}

int main() {
    char prefix[SIZE];

    printf("Enter Prefix expression: ");
    scanf("%s", prefix);

    preinfx(prefix);

    return 0;
}
