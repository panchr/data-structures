// Rushy Panchal
// LinkedListStack.java

import java.util.Iterator;
import java.util.NoSuchElementException;

public class LinkedListStack<Item> implements Iterable<Item> {
	// a linked-list implementation of a stack
	private Node current;
	private int size = 0;

	public LinkedListStack() {}

	public void push(Item item) {
		// Push an item onto the stack
		Node newNode = new Node();
		newNode.data = item;

		if (this.current != null) newNode.next = this.current;
		this.current = newNode;
		this.size++;
		}

	public Item pop() {
		// Pop an item from the stack
		if (isEmpty()) throw new NoSuchElementException("No more elements exist");
		Item retval = this.current.data;
		this.current = this.current.next;
		this.size--;
		return retval;
		}

	public boolean isEmpty() {
		// Check if the stack is empty
		return this.current == null;
		}

	public int size() {
		// Get the size of the stack
		return this.size;
		}

	public Iterator<Item> iterator() {
		return new LinkedListIterator(this.current);
		}

	private class Node {
		// A node in a linked list
		private Item data;
		private Node next;
		}

	private class LinkedListIterator implements Iterator<Item> {
		// iterate through the stack
		Node currentNode;

		public LinkedListIterator(Node node) {
			// Create a new LinkedListIterator
			this.currentNode = node;
			}

		public Item next() {
			// Get the next item in the stack
			if (hasNext()) {
				Item retval = this.currentNode.data;
				this.currentNode = this.currentNode.next;
				return retval;
				}
			else throw new NoSuchElementException("Stack is out of items");
			}

		public boolean hasNext() {
			// Check if the iterator has another item
			return this.currentNode != null;
			}
		}
	}
