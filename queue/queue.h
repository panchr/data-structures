// Rushy Panchal
// queue.h
// A queue implemented with a resizing array

#ifndef QUEUE_HEADER
#define QUEUE_HEADER

#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

#define QUEUE_NULL 0;

#define QUEUE_RATIO(q) ((double) q->size / q->filled)

typedef struct Queue_ {
	// a resizing-array queue
	int *data; // data in the queue
	int popPointer; // index to pop from the queue
	int pushPointer; // index to push in the queue
	int filled; // amount filled (pushPointer - popPointer)
	int size; // size of the queue
	} Queue;

// compile signatures for various methods
Queue* queue_init(void);
void queue_destroy(Queue *q);
void queue_enqueue(Queue *q, int datum);
int queue_dequeue(Queue *q);
void queue_resize(Queue *q, int size);
int queue_size(Queue *q);
bool queue_empty(Queue *q);

/*
Create a new Queue

Returns
	Queue* - pointer to new queue
*/
Queue* queue_init(void) {
	Queue *q = malloc(sizeof(Queue));
	q->popPointer = 0;
	q->pushPointer = 0;
	q->filled = 0;
	q->size = 5;
	q->data = (int *) calloc(q->size, sizeof(int));
	return q;
	}

/*
Destroy a Queue

Args
	Queue* q - queue to destroy
*/
void queue_destroy(Queue *q) {
	if (q) free(q);
	}

/*
Enqueue an item to a queue

Args
	Queue* q - queue to enqueue onto
	int datum - data to enqueue
*/
void queue_enqueue(Queue *q, int datum) {
	q->data[q->pushPointer++] = datum;
	q->filled++;
	if (QUEUE_RATIO(q) <= 2) queue_resize(q, q->size * 2);
	}

/*
Dequeue an item from the queue

Args
	Queue* q - queue to dequeue from

Returns
	int - dequeued datum
*/
int queue_dequeue(Queue *q) {
	if (queue_empty(q)) return QUEUE_NULL;
	int retval = (q->data[q->popPointer++]);
	q->filled--;
	if (QUEUE_RATIO(q) >= 4) queue_resize(q, q->size / 2);
	return retval;
	}

/*
Resize a queue

Args
	Queue *q - queue to resize
	int size - new size of queue
*/
void queue_resize(Queue *q, int size) {
	int *temp_data = (int *) calloc(size, sizeof(int));
	for (int i = 0; i < q->filled; i++) temp_data[i] = q->data[i + q->popPointer];
	free(q->data);
	q->data = temp_data;
	q->size = size;
	q->popPointer = 0;
	q->pushPointer = q->filled;
	}

/*
Get the size of a queue

Args
	Queue *q - queue to get size of

Returns
	int - current size of queue
*/
int queue_size(Queue *q) {
	return q->size;
	}

/*
Check if a queue is empty

Args
	Queue *q - queue to check

Returns
	bool - whether or not queue is empty
*/
bool queue_empty(Queue *q) {
	return q->filled == 0;
	}

#endif