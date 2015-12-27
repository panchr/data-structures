// Rushy Panchal
// test_queue.c
// Test queue implementation

#include <stdio.h>
#include "queue.h"

int main(int argc, const char* argv[]) {
	// Test the Queue class

	Queue *q = queue_init();

	// enqueue argv
	for (int i = 1; i < argc; i++) {
		queue_enqueue(q, strtol(argv[i], NULL, 10));
		}

	printf("Queue: ");
	while (! queue_empty(q)) {
	 	printf("%d ", queue_dequeue(q));
	 	}
	 printf("\n");

	queue_destroy(q);

	return 0;
	}
