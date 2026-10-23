#include <stdio.h>
#include <string.h>

#define MAX 5

typedef struct {
    int job_id;
    char doc_title[50];
} PrintJob;

PrintJob Q[MAX];
int front = 0;
int rear = 0;

int isFull() {
    return (rear + 1) % MAX == front;
}

int isEmpty() {
    return front == rear;
}

void AddCQ(int id, char *title) {
    if ((rear + 1) % MAX == front) {
        printf("Queue is full.\n");
        return;
    }
    rear = (rear + 1) % MAX;
    Q[rear].job_id = id;
    strcpy(Q[rear].doc_title, title);
    printf("Job %d added.\n", id);
}

void DelCQ() {
    if (front == rear) {
        printf("Queue is empty.\n");
        return;
    }
    front = (front + 1) % MAX;
    PrintJob elem = Q[front];
    printf("Processing Job %d: %s\n", elem.job_id, elem.doc_title);
}

void display() {
    if (front == rear) {
        printf("Queue is empty.\n");
        return;
    }
    printf("\nSlot\tJob ID\tTitle\n");
    int i = (front + 1) % MAX;
    while (1) {
        printf("%d\t%d\t%s\n", i, Q[i].job_id, Q[i].doc_title);
        if (i == rear) break;
        i = (i + 1) % MAX;
    }
}

int main() {
    int choice, id;
    char title[50];

    AddCQ(101, "Notes.pdf");
    AddCQ(102, "Resume.pdf");

    while (1) {
        printf("\n1. Add Print Job\n");
        printf("2. Process Print Job\n");
        printf("3. Display Jobs\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        if (scanf("%d", &choice) != 1) break;

        switch (choice) {
            case 1:
                printf("Enter Job ID: ");
                scanf("%d", &id);
                printf("Enter Document Title: ");
                scanf(" %[^\n]", title);
                AddCQ(id, title);
                break;

            case 2:
                DelCQ();
                break;

            case 3:
                display();
                break;

            case 4:
                return 0;

            default:
                printf("Invalid choice.\n");
        }
    }
    return 0;
}
