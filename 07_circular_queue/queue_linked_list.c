#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

struct node *front, *rear;

int isempty() {
    if (front->next == NULL)
        return 1;
    else
        return 0;
}

void enqueue(int element) {
    struct node *new_node = (struct node *)malloc(sizeof(struct node));
    if (!new_node) return;
    new_node->data = element;
    new_node->next = NULL;

    if (isempty()) {
        front->next = rear = new_node;
    } else {
        rear->next = new_node;
        rear = new_node;
    }
    printf("Enqueued: %d\n", element);
}

int dequeue() {
    if (isempty()) {
        printf("Queue is empty\n");
        return -1;
    } else {
        struct node *temp = front->next;
        int value = temp->data;
        front->next = temp->next;
        temp->next = NULL;
        free(temp);
        return value;
    }
}

void display() {
    if (isempty()) {
        printf("Queue is empty\n");
        return;
    }
    struct node *temp = front->next;
    printf("\nQueue elements:\n");
    while (temp != NULL) {
        printf("%d\t", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    int choice, element, val;

    front = (struct node *)malloc(sizeof(struct node));
    front->next = NULL;
    rear = NULL;

    enqueue(10);
    enqueue(20);
    enqueue(30);

    while (1) {
        printf("\n1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        if (scanf("%d", &choice) != 1) break;

        switch (choice) {
            case 1:
                printf("Enter element: ");
                scanf("%d", &element);
                enqueue(element);
                break;

            case 2:
                val = dequeue();
                if (val != -1) {
                    printf("Dequeued: %d\n", val);
                }
                break;

            case 3:
                display();
                break;

            case 4:
                while (!isempty()) {
                    dequeue();
                }
                free(front);
                return 0;

            default:
                printf("Invalid choice\n");
        }
    }
    return 0;
}
