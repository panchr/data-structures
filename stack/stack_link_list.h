// Rushy Panchal
// stack_link_list.h
// A linked-list implementation of a stack

#ifndef STACK_HEADER
#define STACK_HEADER

#include <stdlib.h>
#include <stdbool.h>

#define STACK_NULL 0;

typedef struct Stack_ { 
	// linked-list Stack
	struct Node_ *current; // current item in the stack
	int size; // size of the stack
	} Stack;

typedef struct Node_ {
	// Node in a linked list
	struct Node_ * next; // next item in the linked list
	int data; // data stored in the item
	} Node;

Stack* stack_init(void);
void stack_destroy(Stack *s);
void stack_push(Stack *s, int datum);
int stack_pop(Stack *s);
int stack_size(Stack *s);
bool stack_empty(Stack *s);

/*
Create a new Stack
*/
Stack* stack_init(void) {
	Stack *s = malloc(sizeof(Stack));
	s->current = STACK_NULL;
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
	Node *nextNode = malloc(sizeof(Node));
	nextNode->data = datum;
	// if not the first item, progress the next item in the stack
	if (s->current) nextNode->next = s->current;
	s->current = nextNode;
	s->size++;
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
	int retval = (s->current->data);
	free(s->current); // prevent memory leaks
	s->current = s->current->next;
	s->size--;
	return retval;
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
	return s->size == 0;
	}

#endif
