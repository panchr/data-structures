// Rushy Panchal
// test_stack.c
// Test stack implementation

#include <stdio.h>
#include "stack.h"

int main(int argc, const char* argv[]) {
	Stack *s = stack_init();

	for (int i = 1; i < argc; i++) {
		stack_push(s, strtol(argv[i], NULL, 10));
		}

	while (! stack_empty(s)) {
		printf("%d\n", stack_pop(s));
		}

	stack_destroy(s);

	return 0;
	}
