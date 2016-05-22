/*
* test_queue.c
* Author: Rushy Panchal
* Description: Tests queue implementation.
*/

#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include "queue.h"

int main(int argc, const char* argv[]) {
	// Test the Queue class
	int i; /* iterating index */
	void *item; /* current item */

	Queue_T q = Queue_new();
	if (q == NULL) {
		fprintf(stderr, "Could not create queue.\n");
		exit(EXIT_FAILURE);
		}

	// Enqueue argv
	for (i = 1; i < argc; i++) {
		if (! Queue_enqueue(q, argv[i])) {
			fprintf(stderr, "Could not enqueue item: %d.\n", i);
			exit(EXIT_FAILURE);
			}
		}

	i = 1;
	printf("Queue: ");
	while (! Queue_empty(q)) {
		item = Queue_dequeue(q);
		if (item != argv[i]) {
			fprintf(stderr, "Queue item %d should be %p, but is %p.\n",
				i, argv[i], item);
			fflush(NULL);
			}
		i++;

		printf("%s ", (char*) item);
		}
	printf("\n");

	Queue_free(q);
	return 0;
	}
