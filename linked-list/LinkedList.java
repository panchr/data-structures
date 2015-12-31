// Rushy Panchal
// LinkedList.java

import java.util.Iterator;

/**
* A LinkedList implements the basic operations of a linked list.
* In essence, this involves adding, removing, and querying for items.
* @author Rushy Panchal
* @version 0.1.0
*/
public class LinkedList<Item extends Comparable<Item>> implements Iterable<Item> {
	private int size = 0; // size of the linked list
	private Node current; // current node

	/**
	* A Node is an element in the linked list. This is created as a record
	*/
	private class Node {
		private Item data; // data stored in the node
		private Node next; // next item in the linked list
		private Node prev; // previous item in the linked list
		}

	/**
	* Construct a new LinkedList
	*/
	public LinkedList() {}

	/**
	* Add an item to the linked list
	* @param item item to add to the linked list
	* @return index of the inserted item
	*/
	public int add(Item item) {
		Node node = new Node();
		node.data = item;

		/* if this is the first node, then "current" is null and so, there is
		no value to set "current.next" this to */
		if (this.current != null) {
			this.current.next = node;
			node.prev = this.current;
			}
		this.current = node;

		return this.size++;
		}

	/**
	* Remove an item from the linked list
	* @param index index to remove from thel inked list
	* @throws ArrayIndexOutOfBoundsException index is greater than current size
	*/
	public void remove(int index) {
		if (index >= size) throw new ArrayIndexOutOfBoundsException(index);
		Node node = this.current;
		for (int i = 0; i < index; i++) node = node.next;

		/* merge references of prev and next to point to each other, thus deleting
		the given index */
		node.prev.next = node.next;
		if (node.next != null) node.next.prev = node.prev;
		}

	/**
	* Get the item at a given index
	* @param index index to get the item at
	* @return item at the given index
	* @throws ArrayIndexOutOfBoundsException index is greater than current size
	*/
	public Item get(int index) {
		if (index >= size) throw new ArrayIndexOutOfBoundsException(index);
		Node node = this.current;
		for (int i = 0; i < index; i++) node = node.next;
		return node.data;
		}

	/**
	* Get the index of an item in the linked list, with -1 representing that
	* the item does not exist in the linked list.
	* @param item item to get the index for
	* @return index of item, or -1 if it is not found
	* @throws NullPointerException item is null
	*/
	public int get(Item item) throws NullPointerException {
		if (item == null) throw new NullPointerException("item cannot be null");

		// search through the linked list until the item is found
		Node node = this.current;
		for (int index = 0; index < this.size; index++) {
			if (node.data.equals(item)) return index; // found :)
			node = node.next;
			}

		return -1; // item not found
		}

	/**
	* Check if the linked list contains a certain item
	* @param item item to check for
	* @return whether or not the linked list contains the given item
	*/
	public boolean contains(Item item) {
		return get(item) != -1;
		}

	/**
	* Get the current size of the linked list
	* @return size of the linked list
	*/
	public int size() {
		return this.size;
		}

	/**
	* Check if the linked list is empty
	* @return whether or not the linked list is empty
	*/
	public boolean isEmpty() {
		return this.size == 0;
		}

	public Iterator<Item> iterator() {
		return null;
		}
	}
