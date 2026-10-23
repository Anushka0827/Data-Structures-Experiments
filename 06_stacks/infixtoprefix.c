#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX 100

char stk[MAX];
int top = -1;
char pre_exp[MAX];

void push(char ch) {
    stk[++top] = ch;
}

char pop() {
    if (top == -1) return -1;
    return stk[top--];
}

int isEmpty() {
    return top == -1;
}

int icp(char ch) {
    if (ch == '+' || ch == '-') return 1;
    if (ch == '*' || ch == '/') return 2;
    if (ch == '^') return 4;
    if (ch == ')') return 5;
    return 0;
}

int isp(char ch) {
    if (ch == '+' || ch == '-') return 1;
    if (ch == '*' || ch == '/') return 2;
    if (ch == '^') return 3;
    if (ch == ')') return 0;
    return 0;
}

void reverse(char *str) {
    int len = strlen(str);
    for (int i = 0; i < len / 2; i++) {
        char temp = str[i];
        str[i] = str[len - 1 - i];
        str[len - 1 - i] = temp;
    }
}

void in_pre(char inexp[]) {
    int k = 0;
    int i = strlen(inexp) - 1;
    char tkn = inexp[i];

    while (i >= 0) {
        if (isalnum(tkn)) {
            pre_exp[k++] = tkn;
        } else if (tkn == ')') {
            push(')');
        } else if (tkn == '(') {
            while ((tkn = pop()) != ')') {
                pre_exp[k++] = tkn;
            }
        } else {
            while (!isEmpty() && isp(stk[top]) > icp(tkn)) {
                pre_exp[k++] = pop();
            }
            push(tkn);
        }
        i--;
        if (i >= 0) tkn = inexp[i];
    }
    while (!isEmpty()) {
        pre_exp[k++] = pop();
    }
    pre_exp[k] = '\0';

    reverse(pre_exp);
}

int main() {
    char inexp[MAX];

    printf("Enter Infix expression: ");
    scanf("%s", inexp);

    in_pre(inexp);

    printf("Prefix expression: %s\n", pre_exp);

    return 0;
}
