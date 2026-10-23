CC = gcc
CFLAGS = -Wall -Wextra -std=c99
LDFLAGS = -lm

all: 01_matrices/matrix_operations \
     02_sparse_matrix/sparse_matrix \
     03_searching_and_sorting/student_database \
     04_singly_linked_list/workshop_enrollment \
     05_circular_linked_list/polynomial_cll \
     06_stacks/infixtopostfix \
     06_stacks/infixtoprefix \
     06_stacks/postfixtoinfix \
     06_stacks/prefixtoinfix \
     06_stacks/evaluate_postfix \
     07_circular_queue/printer_queue \
     07_circular_queue/queue_linked_list

01_matrices/matrix_operations: 01_matrices/matrix_operations.c
	$(CC) $(CFLAGS) $< -o $@

02_sparse_matrix/sparse_matrix: 02_sparse_matrix/sparse_matrix.c
	$(CC) $(CFLAGS) $< -o $@

03_searching_and_sorting/student_database: 03_searching_and_sorting/student_database.c
	$(CC) $(CFLAGS) $< -o $@

04_singly_linked_list/workshop_enrollment: 04_singly_linked_list/workshop_enrollment.c
	$(CC) $(CFLAGS) $< -o $@

05_circular_linked_list/polynomial_cll: 05_circular_linked_list/polynomial_cll.c
	$(CC) $(CFLAGS) $< -o $@ $(LDFLAGS)

06_stacks/infixtopostfix: 06_stacks/infixtopostfix.c
	$(CC) $(CFLAGS) $< -o $@

06_stacks/infixtoprefix: 06_stacks/infixtoprefix.c
	$(CC) $(CFLAGS) $< -o $@

06_stacks/postfixtoinfix: 06_stacks/postfixtoinfix.c
	$(CC) $(CFLAGS) $< -o $@

06_stacks/prefixtoinfix: 06_stacks/prefixtoinfix.c
	$(CC) $(CFLAGS) $< -o $@

06_stacks/evaluate_postfix: 06_stacks/evaluate_postfix.c
	$(CC) $(CFLAGS) $< -o $@ $(LDFLAGS)

07_circular_queue/printer_queue: 07_circular_queue/printer_queue.c
	$(CC) $(CFLAGS) $< -o $@

07_circular_queue/queue_linked_list: 07_circular_queue/queue_linked_list.c
	$(CC) $(CFLAGS) $< -o $@

clean:
	rm -f 01_matrices/matrix_operations \
	      02_sparse_matrix/sparse_matrix \
	      03_searching_and_sorting/student_database \
	      04_singly_linked_list/workshop_enrollment \
	      05_circular_linked_list/polynomial_cll \
	      06_stacks/infixtopostfix \
	      06_stacks/infixtoprefix \
	      06_stacks/postfixtoinfix \
	      06_stacks/prefixtoinfix \
	      06_stacks/evaluate_postfix \
	      07_circular_queue/printer_queue \
	      07_circular_queue/queue_linked_list

.PHONY: all clean
