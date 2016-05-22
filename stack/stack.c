/*
* stack.c
* Author: Rushy Panchal
* Description: Stack implementation using a resizing array.
*	Implements stack.h.
*/

#include <stdlib.h>
#include <stdbool.h>
#include <stddef.h>
#include <string.h>
#include <assert.h>
#include "stack.h"

#define INITIAL_SIZE 10

/* Macro to calculate the filled ratio of a stack. */
#define STACK_RATIO(s) ((double) s->size / s->filled)

/* A struct Stack represents a resizing-array implementation of a FIFO stack. */
struct Stack {
	void **data; // Data in the stack
	void **current; // Current stack item pointer
	size_t filled; // Amount filled
	size_t size; // Size of the stack
	};

/* --- Internal Method Prototypes --- */
/*
* Resize the stack.
* Parameters
*	Stack_T s - stack to resize
*	size_t new_size - new size of the stack
* Returns
*	(bool) if stack resizing was successful
*/
static bool Stack_resize(Stack_T s, size_t new_size);

/*
* Create a new stack by allocating memory for it and initializing it.
* Returns
* 	(Stack_T) Stack object on creation, or NULL on memory exhaustion.
*/
Stack_T Stack_new(void) {
	Stack_T s = (Stack_T) malloc(sizeof(struct Stack));
	if (s == NULL) return NULL;

	/* Allocate memory for the data storage of the stack. */
	s->data = (void**) malloc(INITIAL_SIZE * sizeof(void*));
	if (s->data == NULL) {
		free(s);
		return NULL;
		}

	/* Initialize the fields of the stack struct. */
	s->filled = 0;
	s->size = INITIAL_SIZE;
	s->current = s->data;

	return s;
	}

/*
* Free the stack object.
* Parameters
*	Stack_T s - stack to free
*/
void Stack_free(Stack_T s) {
	if (s != NULL) free(s->data);
	free(s);
	}

/*
* Push an item onto the stack.
* Parameters
*	Stack_T s - stack to push onto
*	const void* item - item to add to stack
* Returns
*	(bool) true if successfully added to stack and false otherwise
*/
bool Stack_push(Stack_T s, const void* item) {
	assert(s != NULL);

	*(s->current++) = (void*) item;
	s->filled++;

	/* Resize the queue if it is full. */
	if (STACK_RATIO(s) == 1) return Stack_resize(s, s->size * 2);

	return true;
	}

/*
* Pop an item from the stack.
* Parameters
*	Stack_T s - stack to pop from
* Returns
*	(void*) popped item or NULL if no item exists
*/
void *Stack_pop(Stack_T s) {
	void *item; /* popped item */

	assert(s != NULL);

	if (Stack_empty(s)) return NULL;

	item = *(--s->current);
	s->filled--;

	/* Resize the queue if it is full. */
	if (STACK_RATIO(s) >= 4) Stack_resize(s, s->size / 2);

	return item;
	}

/*
* Check if the stack is empty.
* Parameters
*	const Stack_T s - stack to test
* Returns
*	(bool) whether or not stack is empty
*/
bool Stack_empty(const Stack_T s) {
	assert(s != NULL);

	return (s->filled == 0);
	}

/* --- Internal Methods --- */
/* Resize the stack. */
static bool Stack_resize(Stack_T s, size_t new_size) {
	void **new_data; /* New (resized) data array. */
	
	assert(s != NULL);
	assert(new_size >= 0);

	if (new_size < INITIAL_SIZE) return true;

	/* Allocate memory for the new array, and ensure it is successful. */
	new_data = (void**) malloc(new_size * sizeof(void*));
	if (new_data == NULL) return false;

	/* Copy the current data to the new array. */
	memcpy(new_data, s->data, s->filled * sizeof(void*));

	/* Set the fields of the stack with the new array. */
	s->data = new_data;
	s->size = new_size;
	s->current = (new_data + s->filled);

	return true;
	}
