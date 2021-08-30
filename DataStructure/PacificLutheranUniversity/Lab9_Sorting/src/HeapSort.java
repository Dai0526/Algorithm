/** Implementation of the Heap Sort algorithm.
 * */

public class HeapSort {
	/** Sort the array using heapsort algorithm.
	    pre: data contains Comparable items.
	    post: data is sorted.
	    @param data The array to be sorted
	 */

	public static < T
	extends Comparable < T >> void sort(T[] data ){

		// buildHeap
		for( int i=(data.length-2)/2; i >= 0; i-- )
			percDown( data, i, data.length );

		// sort
		for( int i = data.length - 1; i > 0; i-- ){
			// move max from heap to the list
			swap( data, 0, i );
			percDown( data, 0, i );
		}
	}


	/**
	 * Inserts an element into a heap made up of elements in positions
	 *  i through n-1 of the data array
	 * @param data the array containing the heap 
	 * @param i subscript of the element to be inserted 
	 * @param n number of items in the heap
	 */
	public static < T
	extends Comparable < T >> void percDown(T[] data,
	                                        int i, int n ) {
		int child;
		T tmp;

		// move new element down the heap until new element
		// is a leaf or is larger than both its children
		for( tmp = data[i]; leftChild(i) < n; i = child ) {

			// determine which child is larger
			child = leftChild( i );
			if( child != n - 1 &&
			                data[ child ].compareTo( data[child + 1]) < 0)
				child++;  // right child is larger

			// move child up if child is larger than element
			// to be inserted into the heap
			if( tmp.compareTo( data[ child ] ) < 0 )
				data[ i ] = data[ child ];

			else  // heap property is restored
				break;  // exit the loop
		}
		data[ i ] = tmp;  // put new element where it belongs
	}

	/**
	 * calculates the position of the left child in an array-based
	 * binary tree
	 * @param i position of the parent
	 * @return postion of the left child
	 */
	private static int leftChild(int i) {
		return 2*i + 1;
	}

	/** Swap the items in data[i] and data[j].
	    @param data The array that contains the items
	    @param i The index of one item
	    @param j The index of the other item
	 */
	private static < T
	extends Comparable < T >> void swap(T[] data,
	                                    int i, int j) {
		T temp = data[i];
		data[i] = data[j];
		data[j] = temp;
	}

}
