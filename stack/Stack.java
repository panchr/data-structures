// Rushy Panchal
// Stack.java

import java.util.Iterator;
import java.util.NoSuchElementException;

public class Stack<Item> implements Iterable<Item> {
	// A resizing-array implementation of a stack
	private Item[] data; // the data in the Stack
	private int size; // current size of the stack
	private int current = -1; // current element in the stack

	private static final int INITIAL_SIZE = 10;

	public Stack() {
		// Create a new stack
		this.data = (Item[]) new Object[INITIAL_SIZE];
		this.size = INITIAL_SIZE;
		}

	public void push(Item item) {
		// Push an item onto the stack
		if (item == null) throw new NullPointerException("Item cannot be null");
		this.data[++this.current] = item;
		if (this.current == this.size - 1) this.resize(this.size * 2);
		}

	public Item pop() {
		// Pop an item from the stack
		if (isEmpty()) throw new NoSuchElementException("No more elements exist");
		Item retval = this.data[this.current];
		this.data[this.current] = null;
		this.current--;
		if (((double) this.current) / this.size <= 0.25) this.resize(this.size / 2);
		return retval;
		}

	public boolean isEmpty() {
		// Check if the stack is empty
		return this.current == -1;
		}

	public int size() {
		// Get the size of the stack
		return this.current + 1;
		}

	public Iterator<Item> iterator() {
		// Get an iterator for the stack
		return new StackIterator(this.data, this.current);
		}

	private void resize(int newSize) {
		// Resize the array
		Item[] tmp = (Item[]) new Object[newSize];
		for (int i = 0; i <= this.current; i++) {
			tmp[i] = this.data[i];
			}
		this.data = tmp;
		this.size = newSize;
		}

	private class StackIterator implements Iterator<Item> {
		// iterate through the stack
		int index;
		Item[] stackData;

		public StackIterator(Item[] objects, int index) {
			// Create a new Stack Iterator
			this.index = index;
			this.stackData = objects;
			}

		public Item next() {
			// Get the next item in the stack
			if (hasNext()) return this.stackData[this.index--];
			else throw new NoSuchElementException("Stack is out of items");
			}

		public boolean hasNext() {
			// Check if the iterator has any more items
			return this.index >= 0;
			}
		}
	}
