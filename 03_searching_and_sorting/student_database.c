#include <stdio.h>
#include <string.h>

#define MAX_STUDENTS 50

typedef struct {
    int roll_no;
    char name[50];
    float marks;
} Student;

void displayStudents(Student s[], int n) {
    if (n == 0) {
        printf("Database is empty.\n");
        return;
    }
    printf("\nRoll No\tName\t\tMarks\n");
    for (int i = 0; i < n; i++) {
        printf("%d\t%s\t\t%.2f\n", s[i].roll_no, s[i].name, s[i].marks);
    }
}

int linearSearch(Student s[], int n, int targetRoll) {
    int i;
    for (i = 0; i < n; i++) {
        if (s[i].roll_no == targetRoll) {
            return i;
        }
    }
    return -1;
}

int sentinelSearch(Student s[], int n, int targetRoll) {
    Student last = s[n - 1];
    s[n - 1].roll_no = targetRoll;

    int i = 0;
    while (s[i].roll_no != targetRoll) {
        i++;
    }

    s[n - 1] = last;

    if (i < n - 1 || last.roll_no == targetRoll) {
        return i;
    }
    return -1;
}

int binarySearchIterative(Student s[], int low, int high, int key) {
    while (low <= high) {
        int mid = (low + high) / 2;
        if (s[mid].roll_no == key) {
            return mid;
        } else if (key < s[mid].roll_no) {
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }
    return -1;
}

int binarySearchRecursive(Student s[], int low, int high, int key) {
    if (low <= high) {
        int mid = (low + high) / 2;
        if (s[mid].roll_no == key) {
            return mid;
        } else if (key < s[mid].roll_no) {
            return binarySearchRecursive(s, low, mid - 1, key);
        } else {
            return binarySearchRecursive(s, mid + 1, high, key);
        }
    }
    return -1;
}

void bubbleSort(Student s[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (s[j].roll_no > s[j + 1].roll_no) {
                Student temp = s[j];
                s[j] = s[j + 1];
                s[j + 1] = temp;
            }
        }
    }
}

void selectionSort(Student s[], int n) {
    int minpos;
    Student temp;
    for (int i = 0; i <= n - 2; i++) {
        minpos = i;
        for (int j = i + 1; j <= n - 1; j++) {
            if (s[j].roll_no < s[minpos].roll_no) {
                minpos = j;
            }
        }
        if (minpos != i) {
            temp = s[i];
            s[i] = s[minpos];
            s[minpos] = temp;
        }
    }
}

void insertionSort(Student s[], int n) {
    for (int i = 1; i < n; i++) {
        Student key = s[i];
        int j = i - 1;
        while (j >= 0 && s[j].roll_no > key.roll_no) {
            s[j + 1] = s[j];
            j = j - 1;
        }
        s[j + 1] = key;
    }
}

void shellSort(Student s[], int n) {
    int gap = n / 2;
    int swapped;
    do {
        do {
            swapped = 0;
            for (int i = 0; i < n - gap; i++) {
                if (s[i].roll_no > s[i + gap].roll_no) {
                    Student temp = s[i];
                    s[i] = s[i + gap];
                    s[i + gap] = temp;
                    swapped = 1;
                }
            }
        } while (swapped == 1);
    } while ((gap = gap / 2) >= 1);
}

void radixSort(Student s[], int n) {
    int large = s[0].roll_no;
    for (int i = 1; i < n; i++) {
        if (s[i].roll_no > large) {
            large = s[i].roll_no;
        }
    }

    int pass = 0;
    int tempLarge = large;
    while (tempLarge > 0) {
        pass++;
        tempLarge = tempLarge / 10;
    }

    int div = 1;
    for (int p = 1; p <= pass; p++) {
        int count[10] = {0};
        Student bkt[10][MAX_STUDENTS];

        for (int j = 0; j < n; j++) {
            int bktno = (s[j].roll_no / div) % 10;
            bkt[bktno][count[bktno]] = s[j];
            count[bktno]++;
        }

        int idx = 0;
        for (int bktno = 0; bktno <= 9; bktno++) {
            for (int k = 0; k < count[bktno]; k++) {
                s[idx++] = bkt[bktno][k];
            }
        }
        div = div * 10;
    }
}

int main() {
    Student s[MAX_STUDENTS];
    int n = 0;
    int choice, roll, idx;

    s[0] = (Student){104, "Rahul", 88.5};
    s[1] = (Student){101, "Ananya", 92.0};
    s[2] = (Student){105, "Pooja", 79.5};
    s[3] = (Student){102, "Amit", 85.0};
    n = 4;

    while (1) {
        printf("\n1. Add Student\n");
        printf("2. Display All Students\n");
        printf("3. Linear Search\n");
        printf("4. Sentinel Search\n");
        printf("5. Binary Search (Iterative)\n");
        printf("6. Binary Search (Recursive)\n");
        printf("7. Bubble Sort\n");
        printf("8. Selection Sort\n");
        printf("9. Insertion Sort\n");
        printf("10. Shell Sort\n");
        printf("11. Radix Sort\n");
        printf("12. Exit\n");
        printf("Enter your choice: ");
        if (scanf("%d", &choice) != 1) break;

        switch (choice) {
            case 1:
                if (n >= MAX_STUDENTS) {
                    printf("Database limit reached.\n");
                    break;
                }
                printf("Enter Roll No: ");
                scanf("%d", &s[n].roll_no);
                printf("Enter Name: ");
                scanf(" %[^\n]", s[n].name);
                printf("Enter Marks: ");
                scanf("%f", &s[n].marks);
                n++;
                break;

            case 2:
                displayStudents(s, n);
                break;

            case 3:
                printf("Enter Roll No to search: ");
                scanf("%d", &roll);
                idx = linearSearch(s, n, roll);
                if (idx != -1) {
                    printf("Found at index %d: Roll %d, Name %s, Marks %.2f\n", idx, s[idx].roll_no, s[idx].name, s[idx].marks);
                } else {
                    printf("Student not found.\n");
                }
                break;

            case 4:
                printf("Enter Roll No to search: ");
                scanf("%d", &roll);
                idx = sentinelSearch(s, n, roll);
                if (idx != -1) {
                    printf("Found at index %d: Roll %d, Name %s, Marks %.2f\n", idx, s[idx].roll_no, s[idx].name, s[idx].marks);
                } else {
                    printf("Student not found.\n");
                }
                break;

            case 5:
                bubbleSort(s, n);
                printf("Enter Roll No to search: ");
                scanf("%d", &roll);
                idx = binarySearchIterative(s, 0, n - 1, roll);
                if (idx != -1) {
                    printf("Found at index %d: Roll %d, Name %s, Marks %.2f\n", idx, s[idx].roll_no, s[idx].name, s[idx].marks);
                } else {
                    printf("Student not found.\n");
                }
                break;

            case 6:
                bubbleSort(s, n);
                printf("Enter Roll No to search: ");
                scanf("%d", &roll);
                idx = binarySearchRecursive(s, 0, n - 1, roll);
                if (idx != -1) {
                    printf("Found at index %d: Roll %d, Name %s, Marks %.2f\n", idx, s[idx].roll_no, s[idx].name, s[idx].marks);
                } else {
                    printf("Student not found.\n");
                }
                break;

            case 7:
                bubbleSort(s, n);
                printf("Sorted using Bubble Sort:\n");
                displayStudents(s, n);
                break;

            case 8:
                selectionSort(s, n);
                printf("Sorted using Selection Sort:\n");
                displayStudents(s, n);
                break;

            case 9:
                insertionSort(s, n);
                printf("Sorted using Insertion Sort:\n");
                displayStudents(s, n);
                break;

            case 10:
                shellSort(s, n);
                printf("Sorted using Shell Sort:\n");
                displayStudents(s, n);
                break;

            case 11:
                radixSort(s, n);
                printf("Sorted using Radix Sort:\n");
                displayStudents(s, n);
                break;

            case 12:
                return 0;

            default:
                printf("Invalid choice.\n");
        }
    }
    return 0;
}
