// Rushy Panchal
// stack.h
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

Stack* stack_init(void) {
	// Create a new Stack and return a pointer to it
	Stack *s = malloc(sizeof(Stack));
	s->current = STACK_NULL;
	return s;
	}

void stack_destroy(Stack *s) {
	// Destroy a stack
	if (s) free(s);
	}

void stack_push(Stack *s, int datum) {
	// Push an item onto a stack
	Node *nextNode = malloc(sizeof(Node));
	nextNode->data = datum;
	if (s->current) {
		// if not the first item, progress the next item in the stack
		nextNode->next = s->current;
		}
	s->current = nextNode;
	s->size++;
	return;
	}

int stack_pop(Stack *s) {
	// Pop an item from the stack
	if (stack_empty(s)) return STACK_NULL;
	int retval = (s->current->data);
	s->current = s->current->next;
	s->size--;
	return retval;
	}

int stack_size(Stack *s) {
	// Get the size of a stack
	return s->size;
	}

bool stack_empty(Stack *s) {
	// Check if a stack is empty
	return stack_size(s) == 0;
	}

#endif
