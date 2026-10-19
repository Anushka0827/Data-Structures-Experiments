#include <stdio.h>
#include <stdlib.h>

// 1. Structure for a student node
struct Node {
    int regNo;
    char name[20];
    struct Node *next;
};

struct Node *head = NULL;

// a) Add a Student at the end
void addStudent() {
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    printf("Enter Reg No: ");
    scanf("%d", &newNode->regNo);
    printf("Enter Name: ");
    scanf("%s", newNode->name);
    newNode->next = NULL;

    if (head == NULL) {
        head = newNode;
    } else {
        struct Node *temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
    printf("Added successfully!\n");
}

// c) Display the List
void display() {
    if (head == NULL) {
        printf("List is empty!\n");
        return;
    }
    struct Node *temp = head;
    printf("\n--- Students List ---\n");
    while (temp != NULL) {
        printf("RegNo: %d | Name: %s\n", temp->regNo, temp->name);
        temp = temp->next;
    }
}

// d) Count Total Participants
void count() {
    int c = 0;
    struct Node *temp = head;
    while (temp != NULL) {
        c++;
        temp = temp->next;
    }
    printf("Total Participants: %d\n", c);
}

// b) Remove a Student by RegNo
void removeStudent() {
    if (head == NULL) {
        printf("List is empty!\n");
        return;
    }
    int target;
    printf("Enter Reg No to remove: ");
    scanf("%d", &target);

    struct Node *temp = head, *prev = NULL;

    // If first node is the target
    if (temp != NULL && temp->regNo == target) {
        head = temp->next;
        free(temp);
        printf("Removed successfully!\n");
        return;
    }

    // Search for target node
    while (temp != NULL && temp->regNo != target) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Student not found!\n");
        return;
    }

    prev->next = temp->next;
    free(temp);
    printf("Removed successfully!\n");
}

// e) Sort List (Bubble sort by swapping values)
void sortList() {
    if (head == NULL) return;
    struct Node *i, *j;
    int tempReg;
    char tempName[20];

    for (i = head; i->next != NULL; i = i->next) {
        for (j = i->next; j != NULL; j = j->next) {
            if (i->regNo > j->regNo) {
                // Swap RegNo
                tempReg = i->regNo;
                i->regNo = j->regNo;
                j->regNo = tempReg;

                // Swap Name manually (without strcpy)
                int k = 0;
                while (i->name[k] != '\0' || j->name[k] != '\0') {
                    tempName[k] = i->name[k];
                    i->name[k] = j->name[k];
                    j->name[k] = tempName[k];
                    k++;
                }
            }
        }
    }
    printf("Sorted successfully!\n");
}

// f) Reverse the List
void reverseList() {
    struct Node *prev = NULL, *current = head, *next = NULL;
    while (current != NULL) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    head = prev;
    printf("Reversed successfully!\n");
}

// Main Menu
int main() {
    int choice;
    do {
        printf("\n--- MENU ---\n");
        printf("1. Add\n2. Display\n3. Count\n4. Remove\n5. Sort\n6. Reverse\n7. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: addStudent(); break;
            case 2: display(); break;
            case 3: count(); break;
            case 4: removeStudent(); break;
            case 5: sortList(); break;
            case 6: reverseList(); break;
            case 7: printf("Good luck!\n"); break;
            default: printf("Invalid choice!\n");
        }
    } while (choice != 7);

    return 0;
}
