/*
* stack.h
* Author: Rushy Panchal
* Description: A stack that can store any pointer type. Supports the FIFO order -
*	first-in-first-out.
*/

#ifndef STACK_HEADER
#define STACK_HEADER

#include <stdbool.h>

typedef struct Stack *Stack_T;

/*
* Create a new stack.
* Returns
* 	(Stack_T) Stack object on creation, or NULL on memory exhaustion.
*/
Stack_T Stack_new(void);

/*
* Free the stack object.
* Parameters
*	Stack_T s - stack to free
*/
void Stack_free(Stack_T s);

/*
* Push an item onto the stack.
* Parameters
*	Stack_T s - stack to push onto
*	const void* item - item to add to stack
* Returns
*	(bool) true if successfully added to stack and false otherwise
*/
bool Stack_push(Stack_T s, const void* item);

/*
* Pop an item from the stack.
* Parameters
*	Stack_T s - stack to pop from
* Returns
*	(void*) popped item or NULL if no item exists
*/
void *Stack_pop(Stack_T s);

/*
* Check if the stack is empty.
* Parameters
*	const Stack_T s - stack to test
* Returns
*	(bool) whether or not stack is empty
*/
bool Stack_empty(const Stack_T s);

#endif
