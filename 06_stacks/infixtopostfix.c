#include <stdio.h>
#include <ctype.h>

#define MAX 100

char stk[MAX];
int top = -1;
char postexp[MAX];

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
    if (ch == '(') return 5;
    return 0;
}

int isp(char ch) {
    if (ch == '+' || ch == '-') return 1;
    if (ch == '*' || ch == '/') return 2;
    if (ch == '^') return 3;
    if (ch == '(') return 0;
    return 0;
}

void in_post(char inexp[]) {
    int k = 0, i = 0;
    char tkn = inexp[i];
    while (tkn != '\0') {
        if (isalnum(tkn)) {
            postexp[k++] = tkn;
        } else if (tkn == '(') {
            push('(');
        } else if (tkn == ')') {
            while ((tkn = pop()) != '(') {
                postexp[k++] = tkn;
            }
        } else {
            while (!isEmpty() && isp(stk[top]) >= icp(tkn)) {
                postexp[k++] = pop();
            }
            push(tkn);
        }
        i++;
        tkn = inexp[i];
    }
    while (!isEmpty()) {
        postexp[k++] = pop();
    }
    postexp[k] = '\0';
}

int main() {
    char inexp[MAX];

    printf("Enter Infix expression: ");
    scanf("%s", inexp);

    in_post(inexp);

    printf("Postfix expression: %s\n", postexp);

    return 0;
}
