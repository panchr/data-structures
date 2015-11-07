// Rushy Panchal
// stack.h
// A stack implemented with a resizing array

#ifndef STACK_HEADER
#define STACK_HEADER

#include <stdlib.h>
#include <stdbool.h>

#define STACK_NULL 0;

typedef struct Stack_ {
	int *data;
	int current;
	int size;
	} Stack;

Stack* stack_init(void);
void stack_destroy(Stack *s);
void stack_push(Stack *s, int datum);
int stack_pop(Stack *s);
void stack_resize(Stack *s, int size);
int stack_size(Stack *s);
bool stack_empty(Stack *s);

Stack* stack_init(void) {
	// Create a new Stack and return a pointer to it
	Stack *s = malloc(sizeof(Stack));
	s->current = 0;
	s->size = 5;
	s->data = (int *) calloc(s->size, sizeof(int));
	return s;
	}

void stack_destroy(Stack *s) {
	// Destroy a stack
	if (s) free(s);
	}

void stack_push(Stack *s, int datum) {
	// Push an item onto the stack
	s->data[s->current++] = datum;
	if ((s->size / s->current) <= 2) {
		stack_resize(s, s->size * 2);
		}
	}

int stack_pop(Stack *s) {
	// Pop an item from the stack
	if (stack_empty(s)) return STACK_NULL;
	s->current--;
	int retval = (s->data[s->current]);
	if ((s->size / s->current) >= 4) {
		stack_resize(s, s->size / 2);
		}
	return retval;
	}

void stack_resize(Stack *s, int size) {
	// Resize the stack
	s->data = (int *) realloc(s->data, size);
	s->size = size;
	}

int stack_size(Stack *s) {
	// Get the size of a stack
	return s->size;
	}

bool stack_empty(Stack *s) {
	// Check if a stack is empty
	return s->current == 0;
	}

#endif
