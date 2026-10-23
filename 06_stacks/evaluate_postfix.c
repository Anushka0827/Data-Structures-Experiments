#include <stdio.h>
#include <ctype.h>

#define MAX 100

int stack[MAX];
int top = -1;

void pushval(int val) {
    stack[++top] = val;
}

int popval() {
    if (top == -1) return -1;
    return stack[top--];
}

int calc(int a, int b, char op) {
    switch(op) {
        case '+': return a + b;
        case '-': return a - b;
        case '*': return a * b;
        case '/': return a / b;
    }
    return 0;
}

void eval(char post[]) {
    int op1, op2, ans, z;
    for (int i = 0; post[i] != '\0'; i++) {
        if (isalpha(post[i])) {
            printf("Enter value of %c: ", post[i]);
            scanf("%d", &z);
            pushval(z);
        } else if (isdigit(post[i])) {
            pushval(post[i] - '0');
        } else {
            op2 = popval();
            op1 = popval();
            ans = calc(op1, op2, post[i]);
            pushval(ans);
        }
    }
    printf("Evaluation is: %d\n", stack[top]);
}

int main() {
    char post[MAX];

    printf("Enter Postfix expression: ");
    scanf("%s", post);

    eval(post);

    return 0;
}
