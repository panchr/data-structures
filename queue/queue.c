/*
* queue.c
* Author: Rushy Panchal
* Description: A queue implementation using a resizing array.
* 	Implements queue.h.
*/

#include <stdlib.h>
#include <stdbool.h>
#include <stddef.h>
#include <string.h>
#include <assert.h>
#include "queue.h"

#define INITIAL_SIZE 10

/* Macro to calculate the filled ratio of a queue. */
#define QUEUE_RATIO(q) ((double) q->size / q->filled)

/* A struct Queue represents a resizing-array implementation of a LIFO queue. */
struct Queue {
	void **data; // Data in the queue
	void **pop; // Pop pointer
	void **push; // Push pointer
	size_t filled; // Amount filled
	size_t size; // Size of queue
	};

/* --- Internal Method Prototypes --- */
/*
* Resize the queue.
* Parameters
*	Queue_T q - queue to resize
*	size_t new_size - new size of the queue
* Returns
*	(bool) if queue resizing was successful
*/
static bool Queue_resize(Queue_T q, size_t new_size);

/*
* Create a new queue by allocating memory for it and initializing it.
* Returns
* 	(Queue_T) Queue object on creation, orNULL on memory exhaustion.
*/
Queue_T Queue_new(void) {
	Queue_T q = (Queue_T) malloc(sizeof(struct Queue));
	if (q == NULL) return NULL;

	/* Allocate memory for the data storage of the queue. */
	q->data = (void**) malloc(INITIAL_SIZE * sizeof(void*));
	if (q->data == NULL) {
		free(q);
		return NULL;
		}

	/* Initialize the fields of the queue struct. */
	q->filled = 0;
	q->size = INITIAL_SIZE;
	q->pop = q->data;
	q->push = q->data;

	return q;
	}

/*
* Free the queue object and any allocated fields.
* Parameters
*	Queue_T q - queue to free
*/
void Queue_free(Queue_T q) {
	if (q != NULL) free(q->data);
	free(q);
	}

/*
* Enqueue an item onto the queue.
* Parameters
*	Queue_T q - queue to add onto
*	const void* item - item to add to queue
* Returns
*	(bool) true if successfully added to queue and false otherwise
*/
bool Queue_enqueue(Queue_T q, const void* item) {
	assert(q != NULL);

	*(q->push++) = (void*) item;
	q->filled++;

	/* Resize the queue if it is full. */
	if (QUEUE_RATIO(q) == 1) return Queue_resize(q, q->size * 2);

	/* Wrap the push pointer around. */
	if ((q->push - q->data) == q->size) q->push = q->data;

	return true;
	}

/*
* Dequeue an item from the queue.
* Parameters
*	Queue_T q - queue to dequeue from
* Returns
*	(void*) dequeued item or NULL if no item exists
*/
void *Queue_dequeue(Queue_T q) {
	void* item; /* dequeued item */

	assert(q != NULL);

	if (Queue_empty(q)) return NULL;

	item = *(q->pop++);
	q->filled--;

	if (QUEUE_RATIO(q) >= 4) Queue_resize(q, q->size / 2);
	/* Wrap the pop pointer around. */
	else if ((q->pop - q->data) == q->size) q->pop = q->data;

	return item;
	}

/*
* Check if the queue is empty.
* Parameters
*	const Queue_T q - queue to test
* Returns
*	(bool) whether or not queue is empty
*/
bool Queue_empty(const Queue_T q) {
	assert(q != NULL);

	return (q->filled == 0);
	}

/* --- Internal Methods --- */
/* Resize the queue. */
static bool Queue_resize(Queue_T q, size_t new_size) {
	void** new_data; /* New (resized) data array. */

	assert(q != NULL);
	assert(new_size >= 0);

	if (new_size < INITIAL_SIZE) return true;

	/* Allocate memory for the new array, and ensure it is successful. */
	new_data = (void**) malloc(new_size * sizeof(void*));
	if (new_data == NULL) return false;

	/* Copy the current data, starting from the popped position, to the
	new array. */
	memcpy(new_data, q->pop, q->filled * sizeof(void*));
	
	/* Set the fields of the queue with the new array. */
	q->data = new_data;
	q->size = new_size;
	q->pop = new_data;
	q->push = (new_data + q->filled);

	return true;
	}
