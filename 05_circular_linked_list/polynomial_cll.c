#include <stdio.h>
#include <stdlib.h>
#include <math.h>

struct node {
    int coeff;
    int exp;
    struct node *next;
};

struct node* initNode() {
    struct node *head = (struct node *)malloc(sizeof(struct node));
    head->exp = -1;
    head->coeff = 0;
    head->next = head;
    return head;
}

void create(struct node *H) {
    struct node *temp = H;
    struct node *curr;
    char choice = 'y';

    while (choice == 'y' || choice == 'Y') {
        curr = (struct node *)malloc(sizeof(struct node));
        printf("Enter coeff and exp (e.g. 3 2 for 3x^2): ");
        scanf("%d %d", &curr->coeff, &curr->exp);
        curr->next = H;
        temp->next = curr;
        temp = curr;

        printf("Add more terms? (y/n): ");
        scanf(" %c", &choice);
    }
}

void display(struct node *H) {
    if (H->next == H) {
        printf("0\n");
        return;
    }
    struct node *cur = H->next;
    while (cur->exp != -1) {
        if (cur->exp == 0) {
            printf("%d ", cur->coeff);
        } else if (cur->exp == 1) {
            printf("%dx ", cur->coeff);
        } else {
            printf("%dx^%d ", cur->coeff, cur->exp);
        }
        cur = cur->next;
        if (cur->exp != -1 && cur->coeff > 0) {
            printf("+ ");
        }
    }
    printf("\n");
}

struct node* add(struct node *H1, struct node *H2) {
    struct node *H3 = initNode();
    struct node *t3 = H3;
    struct node *t1 = H1->next;
    struct node *t2 = H2->next;
    struct node *temp;

    while (t1->exp != -1 || t2->exp != -1) {
        if (t1->exp == t2->exp) {
            int sum = t1->coeff + t2->coeff;
            if (sum != 0) {
                temp = (struct node *)malloc(sizeof(struct node));
                temp->coeff = sum;
                temp->exp = t1->exp;
                temp->next = H3;
                t3->next = temp;
                t3 = temp;
            }
            t1 = t1->next;
            t2 = t2->next;
        } else if (t1->exp < t2->exp) {
            temp = (struct node *)malloc(sizeof(struct node));
            temp->coeff = t2->coeff;
            temp->exp = t2->exp;
            temp->next = H3;
            t3->next = temp;
            t3 = temp;
            t2 = t2->next;
        } else {
            temp = (struct node *)malloc(sizeof(struct node));
            temp->coeff = t1->coeff;
            temp->exp = t1->exp;
            temp->next = H3;
            t3->next = temp;
            t3 = temp;
            t1 = t1->next;
        }
    }
    return H3;
}

void eval(struct node *H, double x) {
    struct node *cur = H->next;
    double sum = 0;
    while (cur->exp != -1) {
        sum += cur->coeff * pow(x, cur->exp);
        cur = cur->next;
    }
    printf("Evaluated sum for x = %.2f: %.2f\n", x, sum);
}

int main() {
    struct node *H1 = initNode();
    struct node *H2 = initNode();
    struct node *H3 = NULL;
    int choice;
    double x;

    while (1) {
        printf("\n1. Create Polynomial 1\n");
        printf("2. Create Polynomial 2\n");
        printf("3. Display Polynomials\n");
        printf("4. Add Polynomials\n");
        printf("5. Evaluate Polynomial 1\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        if (scanf("%d", &choice) != 1) break;

        switch (choice) {
            case 1:
                H1 = initNode();
                create(H1);
                break;

            case 2:
                H2 = initNode();
                create(H2);
                break;

            case 3:
                printf("Polynomial 1: ");
                display(H1);
                printf("Polynomial 2: ");
                display(H2);
                break;

            case 4:
                H3 = add(H1, H2);
                printf("Sum: ");
                display(H3);
                break;

            case 5:
                printf("Enter value of x: ");
                scanf("%lf", &x);
                eval(H1, x);
                break;

            case 6:
                return 0;

            default:
                printf("Invalid choice\n");
        }
    }
    return 0;
}
