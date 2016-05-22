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
test_stack: test_stack.o stack.o
	$(CC) $(CFLAGS) $^ -o $@

# Object files
test_stack.o: test_stack.c
stack.o: stack.c stack.h

# (Java) Class files
StackTester.class: StackTester.java
	$(JC) $(JFLAGS) $<

### Other tasks
# Test the implementations
test: test_stack StackTester.class
	./test_stack $(TEST_STRING)
	java StackTester $(TEST_STRING)

# Clean the directory
clean:
	rm -fv test_stack *.o *.class
