#include <stdio.h>
#include <stdlib.h>

// Define structure for a polynomial term node
struct Node {
    int coeff;
    int pow;
    struct Node *next;
};

// Function to create a new node
struct Node* createNode(int c, int p) {
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->coeff = c;
    newNode->pow = p;
    newNode->next = newNode; // Points to itself initially (circular)
    return newNode;
}

// i) Function to insert a term into the circular linked list
struct Node* insertTerm(struct Node *head, int c, int p) {
    struct Node *newNode = createNode(c, p);
    
    if (head == NULL) {
        return newNode;
    }
    
    struct Node *temp = head;
    while (temp->next != head) {
        temp = temp->next;
    }
    
    temp->next = newNode;
    newNode->next = head; // Close the circle
    return head;
}

// ii) Function to display the polynomial
void display(struct Node *head) {
    if (head == NULL) {
        printf("Polynomial is empty!\n");
        return;
    }
    
    struct Node *temp = head;
    do {
        printf("%dx^%d", temp->coeff, temp->pow);
        temp = temp->next;
        if (temp != head) {
            printf(" + ");
        }
    } while (temp != head);
    printf("\n");
}

// iii) Function to add two polynomials using Circular Linked Lists
struct Node* addPolynomials(struct Node *head1, struct Node *head2) {
    if (head1 == NULL) return head2;
    if (head2 == NULL) return head1;

    struct Node *p1 = head1;
    struct Node *p2 = head2;
    struct Node *resHead = NULL;

    do {
        // Match powers and add coefficients
        if (p1->pow == p2->pow) {
            resHead = insertTerm(resHead, p1->coeff + p2->coeff, p1->pow);
            p1 = p1->next;
            p2 = p2->next;
        } 
        // If poly1 power is greater
        else if (p1->pow > p2->pow) {
            resHead = insertTerm(resHead, p1->coeff, p1->pow);
            p1 = p1->next;
        } 
        // If poly2 power is greater
        else {
            resHead = insertTerm(resHead, p2->coeff, p2->pow);
            p2 = p2->next;
        }
    } while (p1 != head1 && p2 != head2);

    // Copy remaining terms of poly1 if any
    while (p1 != head1) {
        resHead = insertTerm(resHead, p1->coeff, p1->pow);
        p1 = p1->next;
    }

    // Copy remaining terms of poly2 if any
    while (p2 != head2) {
        resHead = insertTerm(resHead, p2->coeff, p2->pow);
        p2 = p2->next;
    }

    return resHead;
}

// Main function to test creation, display, and addition
int main() {
    struct Node *poly1 = NULL;
    struct Node *poly2 = NULL;
    struct Node *sum = NULL;

    // Creating Polynomial 1: 3x^2 + 2x^1 + 1x^0
    poly1 = insertTerm(poly1, 3, 2);
    poly1 = insertTerm(poly1, 2, 1);
    poly1 = insertTerm(poly1, 1, 0);

    // Creating Polynomial 2: 5x^2 + 1x^0
    poly2 = insertTerm(poly2, 5, 2);
    poly2 = insertTerm(poly2, 1, 0);

    printf("Polynomial 1: ");
    display(poly1);

    printf("Polynomial 2: ");
    display(poly2);

    // Adding Polynomial 1 and Polynomial 2
    sum = addPolynomials(poly1, poly2);

    printf("Sum of Polynomials: ");
    display(sum);

    return 0;
}
