// Rushy Panchal
// Queue.java

import java.util.Iterator;
import java.util.NoSuchElementException;

public class Queue<Item> implements Iterable<Item> {
	// A resizing-array implementation of a queue
	private Item[] data; // the data in the queue
	private int size; // current size of the queue
	private int filled = 0; // number of filled items
	private int popPointer = 0; // pointer to pop out of the queue
	private int pushPointer = 0; // pointer to push into the queue

	private static final int INITIAL_SIZE = 10;

	public Queue() {
		// Create a new queue
		this.data = (Item[]) new Object[INITIAL_SIZE];
		this.size = INITIAL_SIZE;
		}

	public void enqueue(Item item) {
		// Enqueue an item onto the queue
		if (item == null) throw new NullPointerException("Item cannot be null");
		this.data[this.pushPointer++] = item;
		this.filled++;
		if (this.filled == this.size) this.resize(this.size * 2);
		}

	public Item dequeue() {
		// Dequeue an item from the queue
		if (isEmpty()) throw new NoSuchElementException("No more elements exist");
		Item retval = this.data[this.popPointer];
		this.data[this.popPointer] = null;
		this.popPointer++;
		this.filled--;
		if (((double) this.filled) / this.size <= 0.25) this.resize(this.size / 2);
		return retval;
		}

	public boolean isEmpty() {
		// Check if the queue is empty
		return this.filled == 0;
		}

	public int size() {
		// Get the size of the queue
		return this.filled;
		}

	public Iterator<Item> iterator() {
		// Get an iterator for the queue
		return new QueueIterator(this.data, this.popPointer, this.pushPointer);
		}

	private void resize(int newSize) {
		// Resize the array
		Item[] tmp = (Item[]) new Object[newSize];
		for (int i = 0; i < this.filled; i++) {
			tmp[i] = this.data[i + this.popPointer];
			}
		this.popPointer = 0;
		this.pushPointer = this.filled;
		this.data = tmp;
		this.size = newSize;
		}

	private class QueueIterator implements Iterator<Item> {
		// iterate through the queue
		int index;
		int stop;
		Item[] queueData;

		public QueueIterator(Item[] objects, int start, int end) {
			// Create a new Stack Iterator
			this.index = start;
			this.stop = end;
			this.queueData = objects;
			}

		public Item next() {
			// Get the next item in the iterator
			if (hasNext()) return this.queueData[this.index++];
			else throw new NoSuchElementException("Stack is out of items");
			}

		public boolean hasNext() {
			// Check if the iterator has any more items
			return this.index < this.stop;
			}
		}
	}

