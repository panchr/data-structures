# Makefile
# Rushy Panchal

### Configuration
# Options
CC := gcc
JC := javac

TEST_STRING := 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20 21 22 23 24 25

# Patterns
%.o: %c
	$(CC) $(CFLAGS) -c $< -o $@

### Build Tasks
all: test

# Binary Executables
test_queue: test_queue.o queue.o
	$(CC) $(CFLAGS) $^ -o $@

# Object files
test_queue.o: test_queue.c
queue.o: queue.c queue.h

# (Java) Class files
QueueTester.class: QueueTester.java
	$(JC) $(JFLAGS) $<

### Other tasks
# Test the implementations
test: test_queue QueueTester.class
	./test_queue $(TEST_STRING)
	java QueueTester $(TEST_STRING)

# Clean the directory
clean:
	rm -fv test_queue *.o *.class
