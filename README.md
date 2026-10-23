# Data Structures Laboratory

## Repository Structure

```
Data Structures and Algorithms/
├── 01_matrices/
│   └── matrix_operations.c       # Addition, subtraction, multiplication, transpose
├── 02_sparse_matrix/
│   └── sparse_matrix.c           # Compact, simple transpose, fast transpose, addition
├── 03_searching_and_sorting/
│   └── student_database.c        # Linear, sentinel, binary (iterative/recursive), bubble, selection, insertion, shell, radix
├── 04_singly_linked_list/
│   └── workshop_enrollment.c     # Add, remove, display, count, sort, reverse
├── 05_circular_linked_list/
│   └── polynomial_cll.c          # Create, display, and add polynomials
├── 06_stacks/
│   ├── infixtopostfix.c          # Infix to postfix conversion
│   ├── infixtoprefix.c           # Infix to prefix conversion
│   ├── postfixtoinfix.c          # Postfix to infix conversion
│   ├── prefixtoinfix.c           # Prefix to infix conversion
│   └── evaluate_postfix.c        # Postfix expression evaluation
├── 07_circular_queue/
│   ├── printer_queue.c           # Circular queue using array (AddCQ, DelCQ with front=rear=0)
│   └── queue_linked_list.c       # Queue using linked list (enqueue, dequeue, isempty)
├── Makefile                      # Easy compilation
└── README.md
```

## Compilation and Execution

### Using Make
```bash
make
make clean
```

### Compiling Individually
```bash
# Matrix operations
gcc 01_matrices/matrix_operations.c -o 01_matrices/matrix_operations
./01_matrices/matrix_operations

# Sparse matrix
gcc 02_sparse_matrix/sparse_matrix.c -o 02_sparse_matrix/sparse_matrix
./02_sparse_matrix/sparse_matrix

# Student database
gcc 03_searching_and_sorting/student_database.c -o 03_searching_and_sorting/student_database
./03_searching_and_sorting/student_database

# Workshop enrollment (Singly Linked List)
gcc 04_singly_linked_list/workshop_enrollment.c -o 04_singly_linked_list/workshop_enrollment
./04_singly_linked_list/workshop_enrollment

# Polynomial operations (Circular Linked List)
gcc 05_circular_linked_list/polynomial_cll.c -o 05_circular_linked_list/polynomial_cll
./05_circular_linked_list/polynomial_cll

# Stacks
gcc 06_stacks/infixtopostfix.c -o 06_stacks/infixtopostfix
./06_stacks/infixtopostfix

gcc 06_stacks/infixtoprefix.c -o 06_stacks/infixtoprefix
./06_stacks/infixtoprefix

gcc 06_stacks/postfixtoinfix.c -o 06_stacks/postfixtoinfix
./06_stacks/postfixtoinfix

gcc 06_stacks/prefixtoinfix.c -o 06_stacks/prefixtoinfix
./06_stacks/prefixtoinfix

gcc 06_stacks/evaluate_postfix.c -o 06_stacks/evaluate_postfix -lm
./06_stacks/evaluate_postfix

# Queues
gcc 07_circular_queue/printer_queue.c -o 07_circular_queue/printer_queue
./07_circular_queue/printer_queue

gcc 07_circular_queue/queue_linked_list.c -o 07_circular_queue/queue_linked_list
./07_circular_queue/queue_linked_list
```
