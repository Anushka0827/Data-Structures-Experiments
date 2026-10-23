#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node {
    int reg_no;
    char name[50];
    struct node *next;
};

struct node* createNode(int reg_no, char *name) {
    struct node *nnode = (struct node *)malloc(sizeof(struct node));
    if (!nnode) return NULL;
    nnode->reg_no = reg_no;
    strcpy(nnode->name, name);
    nnode->next = NULL;
    return nnode;
}

int len(struct node *H) {
    int i = 0;
    struct node *curr = H->next;
    while (curr != NULL) {
        i++;
        curr = curr->next;
    }
    return i;
}

void display(struct node *H) {
    if (H->next == NULL) {
        printf("List is empty\n");
        return;
    }
    struct node *curr = H->next;
    printf("\nRegNo\tName\n");
    while (curr != NULL) {
        printf("%d\t%s\n", curr->reg_no, curr->name);
        curr = curr->next;
    }
}

void addStudent(struct node *H, int reg_no, char *name) {
    struct node *nnode = createNode(reg_no, name);
    if (!nnode) return;

    struct node *temp = H;
    while (temp->next != NULL) {
        if (temp->next->reg_no == reg_no) {
            printf("Student with RegNo %d already registered\n", reg_no);
            free(nnode);
            return;
        }
        temp = temp->next;
    }

    temp->next = nnode;
    printf("Student added\n");
}

void removeStudent(struct node *H, int reg_no) {
    if (H->next == NULL) {
        printf("List is empty\n");
        return;
    }

    struct node *prev = H;
    struct node *curr = H->next;

    while (curr != NULL && curr->reg_no != reg_no) {
        prev = curr;
        curr = curr->next;
    }

    if (curr == NULL) {
        printf("Student not found\n");
        return;
    }

    struct node *temp = curr;
    prev->next = curr->next;
    curr->next = NULL;
    free(temp);
    printf("Student removed\n");
}

void reverse(struct node *head) {
    struct node *prev = NULL;
    struct node *curr = head->next;
    struct node *future;

    while (curr != NULL) {
        future = curr->next;
        curr->next = prev;
        prev = curr;
        curr = future;
    }
    head->next = prev;
    printf("List reversed\n");
}

void sort(struct node *H) {
    int l = len(H);
    struct node *prev;
    struct node *curr;
    struct node *temp;

    for (int i = 1; i <= l - 1; i++) {
        prev = H;
        curr = H->next;
        for (int j = 0; j < l - i; j++) {
            temp = curr->next;
            if (curr->reg_no > temp->reg_no) {
                prev->next = temp;
                curr->next = temp->next;
                temp->next = curr;
                prev = temp;
            } else {
                prev = curr;
                curr = curr->next;
            }
        }
    }
    printf("List sorted\n");
}

int main() {
    struct node *head = (struct node *)malloc(sizeof(struct node));
    head->next = NULL;

    int choice, reg_no;
    char name[50];

    addStudent(head, 202103, "Rohit");
    addStudent(head, 202101, "Aarav");
    addStudent(head, 202105, "Priyanka");

    while (1) {
        printf("\n1. Add Student\n");
        printf("2. Remove Student\n");
        printf("3. Display List\n");
        printf("4. Count Participants\n");
        printf("5. Sort List\n");
        printf("6. Reverse List\n");
        printf("7. Exit\n");
        printf("Enter your choice: ");
        if (scanf("%d", &choice) != 1) break;

        switch (choice) {
            case 1:
                printf("Enter RegNo: ");
                scanf("%d", &reg_no);
                printf("Enter Name: ");
                scanf(" %[^\n]", name);
                addStudent(head, reg_no, name);
                break;

            case 2:
                printf("Enter RegNo to remove: ");
                scanf("%d", &reg_no);
                removeStudent(head, reg_no);
                break;

            case 3:
                display(head);
                break;

            case 4:
                printf("Total participants: %d\n", len(head));
                break;

            case 5:
                sort(head);
                display(head);
                break;

            case 6:
                reverse(head);
                display(head);
                break;

            case 7: {
                struct node *curr = head;
                while (curr != NULL) {
                    struct node *next = curr->next;
                    free(curr);
                    curr = next;
                }
                return 0;
            }

            default:
                printf("Invalid choice\n");
        }
    }
    return 0;
}
