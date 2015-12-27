// Rushy Panchal
// Queue.java

import java.util.Iterator;
import java.util.NoSuchElementException;

/**
* A Queue implementation which uses a resizing array
* @author Rushy Panchal
* @version 0.1.0
*/
public class Queue<Item> implements Iterable<Item> {
	private Item[] data; // the data in the queue
	private int size; // current size of the queue
	private int filled = 0; // number of filled items
	private int popPointer = 0; // pointer to pop out of the queue
	private int pushPointer = 0; // pointer to push into the queue

	private static final int INITIAL_SIZE = 10; // initial size of queue

	/**
	* Create a new Queue
	*/
	public Queue() {
		this.data = (Item[]) new Object[INITIAL_SIZE];
		this.size = INITIAL_SIZE;
		}

	/**
	* Enqueue an item onto the queue
	* @param item item to enqueue
	*/
	public void enqueue(Item item) {
		if (item == null) throw new NullPointerException("Item cannot be null");
		this.data[this.pushPointer++] = item;
		this.filled++;
		if (this.filled == this.size) this.resize(this.size * 2);
		}

	/**
	* Dequeue an item from the queue
	* @return dequeued item
	*/
	public Item dequeue() {
		if (isEmpty()) throw new NoSuchElementException("No more elements exist");
		Item retval = this.data[this.popPointer];
		this.data[this.popPointer] = null;
		this.popPointer++;
		this.filled--;
		if (((double) this.filled) / this.size <= 0.25) this.resize(this.size / 2);
		return retval;
		}

	/**
	* Check if the queue is empty
	* @return whether or not the queue is empty
	*/
	public boolean isEmpty() {
		return this.filled == 0;
		}

	/**
	* Get the size of the queue
	* @return size of the queue
	*/
	public int size() {
		return this.filled;
		}

	/**
	* Iterate over the queue
	* @return iterator to traverse the queue (FIFO order)
	*/
	public Iterator<Item> iterator() {
		return new QueueIterator(this.data, this.popPointer, this.pushPointer);
		}

	/**
	* Resize the queue
	* @param newSize new size of the queue
	*/
	private void resize(int newSize) {
		// copy the data to a temporary array
		Item[] tmp = (Item[]) new Object[newSize];
		for (int i = 0; i < this.filled; i++) tmp[i] = this.data[i + this.popPointer];
		this.popPointer = 0;
		this.pushPointer = this.filled;
		this.data = tmp;
		this.size = newSize;
		}

	/**
	* An iterator for the queue
	*/
	private class QueueIterator implements Iterator<Item> {
		int index; // index to start iterating from
		int stop; // index to stop iterating at
		Item[] queueData; // all queue data

		/**
		* Create a new QueueIterator
		* @param objects array of data to iterate over
		* @param start starting point of iteration
		* @param end ending point of iteration
		*/
		public QueueIterator(Item[] objects, int start, int end) {
			this.index = start;
			this.stop = end;
			this.queueData = objects;
			}

		/**
		* Get the next item in the iterator
		* @return next item in the iterator
		*/
		public Item next() {
			if (hasNext()) return this.queueData[this.index++];
			else throw new NoSuchElementException("Stack is out of items");
			}

		/**
		* Check if the iterator has any more items
		* @return whether or not the iterator has more items
		*/
		public boolean hasNext() {
			return this.index < this.stop;
			}
		}
	}

