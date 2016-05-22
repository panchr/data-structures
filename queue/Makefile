# Makefile
# Rushy Panchal

# Options
CC := gcc
JC := javac

# Patterns
%.o: %c
	$(CC) -c $< -o $@

all: test_queue QueueTester.class

# Binary Executables
test_queue: test_queue.o queue.o
	$(CC) $^ -o $@

# Object files
test_queue.o: test_queue.c
queue.o: queue.c queue.h

# (Java) Class files
QueueTester.class: QueueTester.java
	$(JC) $(JFLAGS) $<

clean:
	rm -fv test_queue *.o *.class
