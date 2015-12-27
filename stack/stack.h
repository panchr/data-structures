// Rushy Panchal
// stack.h
// A stack implemented with a resizing array

#ifndef STACK_HEADER
#define STACK_HEADER

#include <stdlib.h>
#include <stdbool.h>

#define STACK_NULL 0;

typedef struct Stack_ {
	// resizing-array Stack
	int *data; // data stored in stack
	int current; // current index
	int size; // size of stack
	} Stack;

Stack* stack_init(void);
void stack_destroy(Stack *s);
void stack_push(Stack *s, int datum);
int stack_pop(Stack *s);
void stack_resize(Stack *s, int size);
int stack_size(Stack *s);
bool stack_empty(Stack *s);

/*
Create a new Stack
*/
Stack* stack_init(void) {
	Stack *s = malloc(sizeof(Stack));
	s->current = 0;
	s->size = 5;
	s->data = (int *) calloc(s->size, sizeof(int));
	return s;
	}

/*
Destroy a stack

Args
	Stack *s - stack to destroy
*/
void stack_destroy(Stack *s) {
	if (s) free(s);
	}

/*
Push onto a stack

Args
	Stack *s - stack to push onto
	int datum - data to push onto stack
*/
void stack_push(Stack *s, int datum) {
	s->data[s->current++] = datum;
	if ((s->size / s->current) <= 2) stack_resize(s, s->size * 2);
	}

/*
Pop from a stack

Args
	Stack *s - stack to pop from

Returns
	int - popped item
*/
int stack_pop(Stack *s) {
	if (stack_empty(s)) return STACK_NULL;
	s->current--;
	int retval = (s->data[s->current]);
	if ((s->size / s->current) >= 4) stack_resize(s, s->size / 2);
	return retval;
	}

/*
Resize the stack

Args
	Stack *s - stack to resize
	int size - new size of stack
*/
void stack_resize(Stack *s, int size) {
	s->data = (int *) realloc(s->data, size);
	s->size = size;
	}

/*
Get the size of the stack

Args
	Stack *s - stack to get size of

Returns
	int - size of stack
*/
int stack_size(Stack *s) {
	return s->size;
	}

/*
Check whether or not the stack is empty

Args
	Stack *s - stack to check

Returns
	bool - whether or not stack is empty
*/
bool stack_empty(Stack *s) {
	return s->current == 0;
	}

#endif
