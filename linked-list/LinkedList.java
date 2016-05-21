// Rushy Panchal
// LinkedList.java

import java.util.Iterator;

/**
* A {@link LinkedList} implements the basic operations of a linked list.
* In essence, this involves adding, removing, and querying for items.
* @author Rushy Panchal
* @version 0.1.0
*/
public class LinkedList<Item> implements Iterable<Item> {
	private int size = 0; // size of the linked list
	private Node current; // current node

	/**
	* A {@link Node} is an element in the {@link LinkedList}. This is created
	* as a record.
	*/
	private class Node {
		private Item data; // data stored in the node
		private Node next; // next item in the linked list
		private Node prev; // previous item in the linked list
		}

	/**
	* Construct a new {@link LinkedList}
	*/
	public LinkedList() {}

	/**
	* Add an item to the {@link LinkedList}
	* @param item item to add to the {@link LinkedList}
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
	* Remove an item from the {@link LinkedList}
	* @param index index to remove from the {@link LinkedList}
	* @throws ArrayIndexOutOfBoundsException index is greater than current size
	*/
	public void remove(int index) {
		if (index >= this.size) throw new ArrayIndexOutOfBoundsException(index);

		index = adjustedIndex(index);
		Node node = this.current;
		for (int i = 0; i < index; i++) node = node.prev;

		/* merge references of prev and next to point to each other, thus deleting
		the given index */
		if (node.next != null) node.next.prev = node.prev;
		if (node.prev != null) node.prev.next = node.next;
		if (node == this.current) this.current = null;
		
		this.size--;
		}

	/**
	* Get the item at a given index
	* @param index index to get the item at
	* @return item at the given index
	* @throws ArrayIndexOutOfBoundsException index is greater than current size
	*/
	public Item get(int index) {
		if (index >= size) throw new ArrayIndexOutOfBoundsException(index);
		index = adjustedIndex(index);

		Node node = this.current;
		for (int i = 0; i < index; i++) {
			if (node.prev == null) break;
			node = node.prev;
			}
		return node.data;
		}

	/**
	* Get the index of an item in the {@link LinkedList}, with -1 representing that
	* the item does not exist in the {@link LinkedList}.
	* @param item item to get the index for
	* @return index of item, or -1 if it is not found
	* @throws NullPointerException item is null
	*/
	public int index(Item item) {
		if (item == null) throw new NullPointerException("item cannot be null");

		// search through the linked list until the item is found
		Node node = this.current;
		for (int index = 0; index < this.size - 1; index++) {
			if (node.data.equals(item)) return adjustedIndex(index); // found :)
			node = node.prev;
			}

		return -1; // item not found
		}

	/**
	* Check if the {@link LinkedList} contains a certain item
	* @param item item to check for
	* @return whether or not the {@link LinkedList} contains the given item
	*/
	public boolean contains(Item item) {
		return index(item) != -1;
		}

	/**
	* Get the current size of the {@link LinkedList}
	* @return size of the {@link LinkedList}
	*/
	public int size() {
		return this.size;
		}

	/**
	* Check if the {@link LinkedList} is empty
	* @return whether or not the {@link LinkedList} is empty
	*/
	public boolean isEmpty() {
		return this.size == 0;
		}

	/**
	* Get an iterator for the items in the {@link LinkedList}
	* @return iterator for the {@link LinkedList}
	*/
	public Iterator<Item> iterator() {
		return null;
		}

	/**
	* Get the proper index of the given index. When mapping to a {@link LinkedList},
	* the most recent item is technically the "first" item, or index 0.
	* As a result, this does not follow an appropriate index mapping based on
	* the order of insertions. So, this method adjusts that index to match the
	* proper order in the {@link LinkedList}.
	* @param index index to adjust
	* @return adjusted index
	*/
	private int adjustedIndex(int index) {
		return (this.size - index - 1);
		}
	}
