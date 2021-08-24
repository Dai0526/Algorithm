
/**
 * LinkedList class implements a doubly-linked list. Adapted from Weiss, Data
 * Structures and Algorithm Analysis in Java. 3rd ed.
 * http://users.cis.fiu.edu/~weiss/dsaajava3/code/SimpleLinkedList.java
 */
public class SimpleLinkedList<T> implements Iterable<T> {

	private int size;
	private Node<T> beginMarker;
	private Node<T> endMarker;

	/**
	 * This is the doubly-linked list node class.
	 */
	public class Node<NodeT> {
		public Node(NodeT d, Node<NodeT> p, Node<NodeT> n) {
			data = d;
			prev = p;
			next = n;
		}

		public NodeT data;
		public Node<NodeT> prev;
		public Node<NodeT> next;
	}

	/**
	 * Construct an empty LinkedList.
	 */
	public SimpleLinkedList() {
		doClear();
	}

	/**
	 * Change the size of this collection to zero by initializing the beginning
	 * and end marker.
	 */
	public void doClear() {
		beginMarker = new Node<>(null, null, null);
		endMarker = new Node<>(null, beginMarker, null);
		beginMarker.next = endMarker;

		size = 0;
	}

	/**
	 * @return the number of items in this collection.
	 */
	public int size() {
		return size;
	}

	/**
	 * @return boolean indicating if the linked list is empty
	 */
	public boolean isEmpty() {
		return size() == 0;
	}

	/**
	 * Gets the Node at position idx, which must range from lower to upper.
	 * 
	 * @param idx
	 *          index to search at.
	 * @param lower
	 *          lowest valid index.
	 * @param upper
	 *          highest valid index.
	 * @return internal node corresponding to idx.
	 * @throws IndexOutOfBoundsException
	 *           if index is not between lower and upper, inclusive.
	 */
	private Node<T> getNode(int idx, int lower, int upper) {
		Node<T> p;

		if (idx < lower || idx > upper)
			throw new IndexOutOfBoundsException("getNode index: " + idx + "; size: "
					+ size());

		if (idx < size() / 2) { // Search through list from the beginning
			p = beginMarker.next;
			for (int i = 0; i < idx; i++)
				p = p.next;
		} else { // serch through the list from the end
			p = endMarker;
			for (int i = size(); i > idx; i--)
				p = p.prev;
		}

		return p;
	}

	/**
	 * Gets the Node at position idx, which must range from 0 to size( ) - 1.
	 * 
	 * @param idx
	 *          index to search at.
	 * @return internal node corresponding to idx.
	 * @throws IndexOutOfBoundsException
	 *           if index is out of range.
	 */
	private Node<T> getNode(int idx) {
		return getNode(idx, 0, size() - 1);
	}

	/**
	 * Returns the item at position idx.
	 * 
	 * @param idx
	 *          the index to search in.
	 * @throws IndexOutOfBoundsException
	 *           if index is out of range.
	 */
	public T get(int idx) {
		return getNode(idx).data;
	}

	/**
	 * Changes the item at position idx.
	 * 
	 * @param idx
	 *          the index to change.
	 * @param newVal
	 *          the new value.
	 * @return the old value.
	 * @throws IndexOutOfBoundsException
	 *           if index is out of range.
	 */
	public T set(int idx, T newVal) {
		Node<T> p = getNode(idx);
		T oldVal = p.data;

		p.data = newVal;
		return oldVal;
	}

	/**
	 * Adds an item in front of node p, shifting p and all items after it one
	 * position to the right in the list.
	 * 
	 * @param p
	 *          Node to add before.
	 * @param x
	 *          any object.
	 * @throws IndexOutOfBoundsException
	 *           if idx < 0 or idx > size()
	 */
	private void addBefore(Node<T> p, T x) {
		Node<T> newNode = new Node<>(x, p.prev, p);
		newNode.prev.next = newNode;
		p.prev = newNode;
		size++;
	}

	/**
	 * Adds an item at specified index. Remaining items shift up one index.
	 * 
	 * @param x
	 *          any object.
	 * @param idx
	 *          position to add at.
	 * @throws IndexOutOfBoundsException
	 *           if idx < 0 or idx > size()
	 */
	public void add(int idx, T x) {
		addBefore(getNode(idx, 0, size()), x);
	}

	/**
	 * Adds an item to this collection, at the end.
	 * 
	 * @param x
	 *          any object.
	 */
	public void add(T x) {
		add(size(), x);
	}

	/**
	 * Removes the object contained in Node p.
	 * 
	 * @param p
	 *          the Node containing the object.
	 * @return the item was removed from the collection.
	 */
	private T remove(Node<T> p) {
		p.next.prev = p.prev;
		p.prev.next = p.next;
		size--;

		return p.data;
	}

	/**
	 * Removes an item from this collection.
	 * 
	 * @param idx
	 *          the index of the object.
	 * @return the item was removed from the collection.
	 */
	public T remove(int idx) {
		return remove(getNode(idx));
	}


	public void flip(){
		Node<T> curr;
		Node<T> next;
		Node<T> temp = null;
		curr=this.beginMarker.next;
		next=curr.next;
			temp=curr;			
			curr=next;
			next=temp;	
			
	}
	/**
	 * Returns a String representation of this collection.
	 */
	public String toString() {
		StringBuilder sb = new StringBuilder("[ ");
		for (T x : this) {
			sb.append(x + " ");
		}
		sb.append("]");

		return new String(sb);
	}

	
	/********* ADD YOUR SOLUTIONS HERE *****************/
	/**
	 * Find the index of the first element which is euqal to the object o
	 * @param o the object need to be matched
	 * @return the index of the element
	 */
	public int indexOf(Object o){
		int count=0;                    // set a counter to trace the current position
		Node<T> temp= beginMarker;      // set a start point at the beginning
		
		for(int i=0;i<this.size;i++){   // loop over the list to find the object
			temp=temp.next;
			
			if(temp.data.equals(o)){
				return count;	
			}	
			
			count++;
		}
		
		return -1;                      // return -1 if this obj is not exist		
	}//IndexOf
	
	
	/**
	 *  This method will reverse a linkedList 
	 */
	public void reverse(){
		/*
		 * The basic idea is to loop over the list from the endmarker
		 * to beginMarker, and store each nodes in a new LinkedList 
		 * in order to get a reverse list
		 */
		SimpleLinkedList<T> rev = new SimpleLinkedList<T>();
		Node<T> temp=endMarker;  // set the temp as the ending point
		
		for(int i=0;i<this.size;i++){  
			temp=temp.prev;            // get the previous data
			rev.add(temp.data);        // add the data to the new list at the end position
		}	
		
		this.beginMarker=rev.beginMarker;
		this.endMarker=rev.endMarker;
		
	}

	/**
	 * This method is to remove the duplicate elements
	 * 
	 */
	public void removeDuplicates(){
		/*
		 * The idea is to set up a new LinkedList, store the
		 * non-repeated element in this new LinkedList.
		 * In order to achieve this, this method need a nested
		 * for loop to check both LinkedList.
		 */
		Node<T> temp = this.beginMarker;                        //start from the beginning of a list
		SimpleLinkedList<T> noDup = new SimpleLinkedList<T>();  //set up a new List to store non-repeated data
		boolean repeat;
		
		for(int i=0;i<this.size;i++){                           //#1 for loop 
			repeat=false;
			temp=temp.next;
			
			for(int j=0;j<noDup.size;j++){                      //#2 for loop
				if(noDup.get(j).equals(temp.data)){             
					repeat=true;
				}		
			}//for #2
			
			if(repeat==false){                                  //if the obj is not in new list, then add it
				noDup.add(temp.data);
			}
		}//for #1
		this.beginMarker=noDup.beginMarker;
		this.endMarker=noDup.endMarker;
	}//method
	
	/**
	 * This method will interleaves elements from the other list into 
	 * the linked list. If other is longer than the current list its 
	 * remaining elements should simply be appended.
	 * @param other
	 */
	
	public void interleave(SimpleLinkedList<T> other){
		int originalThisSize=this.size;
		
		if(this.size>=other.size){		
			for(int i=0;i<other.size;i++){
				this.add(2*i+1,other.get(i));   // add the item in other list to the position 2i+1 in this list
			}
		}
		else{
			for(int i=0;i<originalThisSize;i++){
				this.add(2*i+1,other.get(i));
			}
			for(int i=originalThisSize;i<other.size;i++){ // add all the rest data
				this.add(other.get(i));               
					
			}
			
		}//else
	}//method
	
	
	/**

	 * Obtains an Iterator object used to traverse the collection.
	 * 
	 * @return an iterator positioned prior to the first element.
	 */
	public java.util.Iterator<T> iterator() {
		return new LinkedListIterator();
	}

	/**
	 * This is the implementation of the LinkedListIterator. It maintains a notion
	 * of a current position and of course the implicit reference to the
	 * SimpleLinkedList.
	 */
	private class LinkedListIterator implements java.util.Iterator<T> {
		private Node<T> current = beginMarker.next;

		private Node<T> prev = beginMarker;

		private boolean okToRemove = false;

		public boolean hasNext() {
			return current != endMarker;
		}

		public T next() {
			if (!hasNext())
				throw new java.util.NoSuchElementException();

			T nextItem = current.data;
			current = current.next;
			okToRemove = true;
			return nextItem;
		}

		public void remove() {
			if (!okToRemove)
				throw new IllegalStateException();

			SimpleLinkedList.this.remove(current.prev);
			// ensures that remove() cannot be called twice during a single step in
			// iteration
			okToRemove = false;
		}
	}

}
