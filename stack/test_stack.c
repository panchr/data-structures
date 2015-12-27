// Rushy Panchal
// test_stack.c
// Test stack implementation

#include <stdio.h>
#include "stack.h"

int main(int argc, const char* argv[]) {
	// Unit test the Stack
	Stack *s = stack_init();

	// push all argv items onto the stack
	for (int i = 1; i < argc; i++) stack_push(s, strtol(argv[i], NULL, 10));

	// print out the stack
	while (! stack_empty(s)) printf("%d\n", stack_pop(s));

	stack_destroy(s);

	return 0;
	}
