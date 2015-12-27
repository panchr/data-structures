// Rushy Panchal
// test_queue.c
// Test queue implementation

#include <stdio.h>
#include "queue.h"

int main(int argc, const char* argv[]) {
	// Test the Queue class

	Queue *q = queue_init();

	for (int i = 1; i < argc; i++) {
		queue_enqueue(q, strtol(argv[i], NULL, 10));
		}

	while (! queue_empty(q)) {
	 	printf("%d\n", queue_dequeue(q));
	 	}

	queue_destroy(q);

	return 0;
	}
