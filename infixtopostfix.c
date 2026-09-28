#include <stdio.h>
#include <ctype.h>

#define MAX 100

// Stack definition and functions
char stk[MAX];
int top = -1;

void push(char item) {
    if (top < MAX - 1) {
        stk[++top] = item;
    }
}

char pop() {
    if (top >= 0) {
        return stk[top--];
    }
    return '\0';
}

int stack_not_empty() {
    return top != -1;
}

// In-Stack Precedence (isp)
int isp(char op) {
    switch (op) {
        case '^': return 3;
        case '*':
        case '/':
        case '%': return 2;
        case '+':
        case '-': return 1;
        case '(': return 0;
        default:  return -1;
    }
}

// In-Coming Precedence (icp)
int icp(char op) {
    switch (op) {
        case '^': return 4;
        case '*':
        case '/':
        case '%': return 2;
        case '+':
        case '-': return 1;
        case '(': return 4;
        default:  return -1;
    }
}

// Algorithm in_post(inexp[ ])
void in_post(char inexp[], char postexp[]) {
    int k = 0; //[cite: 6]
    int i = 0; //[cite: 6]
    char tkn = inexp[i]; //[cite: 6]

    while (tkn != '\0') { //[cite: 6]
        if (isalnum(tkn)) { // if tkn is an operand[cite: 6]
            postexp[k] = inexp[i]; //[cite: 6]
            k++; //[cite: 6]
        }
        else { // 1st[cite: 6]
            if (tkn == '(') { // open parenthesis[cite: 6]
                push('('); //[cite: 6]
            }
            else { // 2nd[cite: 6]
                if (tkn == ')') { // close parenthesis[cite: 6]
                    while ((tkn = pop()) != '(') { //[cite: 6]
                        postexp[k] = tkn; //[cite: 6]
                        k++; //[cite: 6]
                    }
                }
                else { // 3rd[cite: 6]
                    while (stack_not_empty() && isp(stk[top]) >= icp(tkn)) { //[cite: 6]
                        postexp[k] = pop(); //[cite: 6]
                        k++; //[cite: 6]
                    }
                    push(tkn); //[cite: 6]
                } // end of 3rd else[cite: 6]
            } // end of 2nd else[cite: 6]
        } // end of 1st else[cite: 6]

        // read next token[cite: 6]
        i++; //[cite: 6]
        tkn = inexp[i]; //[cite: 6]
    } // end of outer while[cite: 6]

    while (stack_not_empty()) { // while stack not empty[cite: 6]
        postexp[k] = pop(); //[cite: 6]
        k++; //[cite: 6]
    }
    postexp[k] = '\0';
}

int main() {
    char inexp[] = "(A+B)*(C-D)";
    char postexp[MAX];

    in_post(inexp, postexp);

    printf("Infix Expression:   %s\n", inexp);
    printf("Postfix Expression: %s\n", postexp);

    return 0;
}
