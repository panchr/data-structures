// Rushy Panchal
// test_stack.c
// Test stack implementation

#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

int main(int argc, const char* argv[]) {
	// Unit test the Stack
	int i; /* iterating index */
	void *item; /* current item */

	Stack_T s = Stack_new();
	if (s == NULL) {
		fprintf(stderr, "Could not create stack.\n");
		exit(EXIT_FAILURE);
		}

	// Push all argv items onto the stack
	for (i = 1; i < argc; i++) {
		if (! Stack_push(s, argv[i])) {
			fprintf(stderr, "Could not push item: %d.\n", i);
			exit(EXIT_FAILURE);
			}
		}

	i = argc - 1;
	printf("Stack: ");
	while (! Stack_empty(s)) {
		item = Stack_pop(s);
		if (item != argv[i]) {
			fprintf(stderr, "Stack item %d should be %p, but is %p.\n",
				i, argv[i], item);
			}
		i--;

		printf("%s ", (char*) item);
		}
	printf("\n");

	Stack_free(s);

	return 0;
	}
