#include <stdio.h>

typedef struct student 
{
    char name[10];
    int roll;
} student;

void accept(student s[10], int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("Student %d:\n", i + 1);
        printf("Enter the name of the student: ");
        scanf("%s", s[i].name);
        printf("Enter the roll number: ");
        scanf("%d", &s[i].roll);
    }
}

void display(student s[10], int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("\nStudent %d:\n", i + 1);
        printf("Name: %s\n", s[i].name);
        printf("Roll Number: %d\n", s[i].roll);
    }
    printf("\n");
}

void linear_search(student s[10], int n, int target) 
{
    int found = 0;
    for (int i = 0; i < n; i++) 
    {
        if (s[i].roll == target) 
        {
            printf("Found! Student %d: %s\n", i + 1, s[i].name);
            found = 1;
        }
    }
    if (!found) 
    {
        printf("Student not found.\n");
    }
}

void binary_search(student s[10], int n, int target)
{
    int low = 0, high = n - 1, found = 0;
    
    while (low <= high)
    {
        int mid = (low + high) / 2;
        
        if (s[mid].roll == target)
        {
            printf("Found! Student %d: %s\n", mid + 1, s[mid].name);
            found = 1;
            break;
        }
        else if (s[mid].roll < target)
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }
    
    if (!found)
    {
        printf("Student not found.\n");
    }
}

void bubble_sort(student s[10], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (s[j].roll > s[j + 1].roll)
            {
                student temp = s[j];
                s[j] = s[j + 1];
                s[j + 1] = temp;
            }
        }
    }
}

int main()
{
    student s[10];
    int n, target, choice;
    
    printf("Enter the number of students: ");
    scanf("%d", &n);
    
    accept(s, n);
    printf("The details of students are:\n");
    display(s, n);
    
    while (1)
    {
        printf("\nMenu:\n");
        printf("1. Linear Search\n");
        printf("2. Binary Search\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch (choice)
        {
            case 1:
                printf("Enter roll number to search: ");
                scanf("%d", &target);
                linear_search(s, n, target);
                break;
                
            case 2:
                bubble_sort(s, n);
                printf("Enter roll number to search: ");
                scanf("%d", &target);
                binary_search(s, n, target);
                break;
                
            case 3:
                printf("Exiting program.\n");
                return 0;
                
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }
    
    return 0;
}
