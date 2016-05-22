/*
* queue.h
* Author: Rushy Panchal
* Description: A queue that can store any pointer type.
*/

#ifndef QUEUE_HEADER
#define QUEUE_HEADER

#include <stdbool.h>

typedef struct Queue *Queue_T;

/*
* Create a new queue.
* Returns
* 	(Queue_T) Queue object on creation, or NULL on memory exhaustion.
*/
Queue_T Queue_new(void);

/*
* Free the queue object.
* Parameters
*	Queue_T q - queue to free
*/
void Queue_free(Queue_T q);

/*
* Enqueue an item onto the queue.
* Parameters
*	Queue_T q - queue to enqueue onto
*	const void* item - item to add to queue
* Returns
*	(bool) true if successfully added to queue and false otherwise
*/
bool Queue_enqueue(Queue_T q, const void* item);

/*
* Dequeue an item from the queue.
* Parameters
*	Queue_T q - queue to dequeue from
* Returns
*	(void*) dequeued or NULL if no item exists
*/
void *Queue_dequeue(Queue_T q);

/*
* Check if the queue is empty.
* Parameters
*	const Queue_T q - queue to test
* Returns
*	(bool) whether or not queue is empty
*/
bool Queue_empty(const Queue_T q);

#endif
