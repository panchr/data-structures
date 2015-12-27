// Rushy Panchal
// Stack.java

import java.util.Iterator;
import java.util.NoSuchElementException;

/**
* The Stack class implements the Stack data structure, using a resizing array
* @author Rushy Panchal
* @version 0.1.0
*/
public class Stack<Item> implements Iterable<Item> {
	private Item[] data; // data in the Stack
	private int size; // current size of the stack
	private int current = -1; // current element in the stack

	private static final int INITIAL_SIZE = 10; // initial size of stack

	/**
	* Create a new Stack
	*/
	public Stack() {
		this.data = (Item[]) new Object[INITIAL_SIZE];
		this.size = INITIAL_SIZE;
		}

	/**
	* Push an item onto the stack
	* @param item what to push onto the stack
	*/
	public void push(Item item) {
		if (item == null) throw new NullPointerException("Item cannot be null");
		this.data[++this.current] = item;
		if (this.current == this.size - 1) this.resize(this.size * 2);
		}

	/**
	* Pop an item from the stack
	* @return popped item
	*/
	public Item pop() {
		if (isEmpty()) throw new NoSuchElementException("No more elements exist");
		Item retval = this.data[this.current];
		this.data[this.current] = null;
		this.current--;
		if (((double) this.current) / this.size <= 0.25) this.resize(this.size / 2);
		return retval;
		}

	/**
	* Check if the stack is empty
	* @return whether or not the stack is empty
	*/
	public boolean isEmpty() {
		return this.current == -1;
		}

	/**
	* Get the size of the stack
	* @return size of the stack
	*/
	public int size() {
		return this.current + 1;
		}

	/**
	* Iterate over the items in the stack
	* @return an Iterator to traverse the stack (in LIFO order)
	*/
	public Iterator<Item> iterator() {
		return new StackIterator(this.data, this.current);
		}

	/**
	* Resize the stack
	* @param newSize new size of the stack
	*/
	private void resize(int newSize) {
		// copy all data to a temporary array
		Item[] tmp = (Item[]) new Object[newSize];
		for (int i = 0; i <= this.current; i++) tmp[i] = this.data[i];
		this.data = tmp;
		this.size = newSize;
		}

	/**
	* An iterator over the Stack
	*/
	private class StackIterator implements Iterator<Item> {
		int index; // index of the current iteration
		Item[] stackData; // all stack data

		/**
		* Create a new StackIterator
		* @param objects array of objects to iterate over
		* @param index starting index of iteration
		*/
		public StackIterator(Item[] objects, int index) {
			this.index = index;
			this.stackData = objects;
			}

		/**
		* Get the next item in the stack
		* @return next item in iterator
		*/
		public Item next() {
			if (hasNext()) return this.stackData[this.index--];
			else throw new NoSuchElementException("Stack is out of items");
			}

		/**
		* Check whether or not the iterator has more items
		* @return whether or not iterator has more items
		*/
		public boolean hasNext() {
			return this.index >= 0;
			}
		}
	}
