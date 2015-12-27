// Rushy Panchal
// LinkedListStack.java

import java.util.Iterator;
import java.util.NoSuchElementException;

/**
* The LinkedListStack class implements the Stack data structure.
* This implementation uses a linked list.
* @author Rushy Panchal
* @version 0.1.0
*/
public class LinkedListStack<Item> implements Iterable<Item> {
	private Node current; // current node
	private int size = 0; // size of stack

	/**
	* Create a new LinkedListStack
	*/
	public LinkedListStack() {}

	/**
	* Push an item onto the stack
	* @param item what to push onto the stack
	*/
	public void push(Item item) {
		Node newNode = new Node();
		newNode.data = item;

		if (this.current != null) newNode.next = this.current;
		this.current = newNode;
		this.size++;
		}

	/**
	* Pop an item from the stack
	* @return popped item
	*/
	public Item pop() {
		if (isEmpty()) throw new NoSuchElementException("No more elements exist");
		Item retval = this.current.data;
		this.current = this.current.next;
		this.size--;
		return retval;
		}

	/**
	* Check if the stack is empty
	* @return whether or not the stack is empty
	*/
	public boolean isEmpty() {
		return this.current == null;
		}

	/**
	* Get the size of the stack
	* @return size of the stack
	*/
	public int size() {
		return this.size;
		}

	/**
	* Iterate over the items in the stack
	* @return an Iterator to traverse the stack (in LIFO order)
	*/
	public Iterator<Item> iterator() {
		return new LinkedListIterator(this.current);
		}

	/**
	* Record to represent a node in the linked list
	* The record holds the node data and a pointer to the next node
	*/
	private class Node {
		private Item data;
		private Node next;
		}

	/**
	* An iterator over the Stack
	*/
	private class LinkedListIterator implements Iterator<Item> {
		Node currentNode; // current node

		/**
		* Create a new LinkedListIterator
		* @param node starting node of the iteration
		*/
		public LinkedListIterator(Node node) {
			this.currentNode = node;
			}

		/**
		* Get the next item in the stack
		* @return next item in iterator
		*/
		public Item next() {
			if (hasNext()) {
				Item retval = this.currentNode.data;
				this.currentNode = this.currentNode.next;
				return retval;
				}
			else throw new NoSuchElementException("Stack is out of items");
			}

		/**
		* Check whether or not the iterator has more items
		* @return whether or not iterator has more items
		*/
		public boolean hasNext() {
			return this.currentNode != null;
			}
		}
	}
