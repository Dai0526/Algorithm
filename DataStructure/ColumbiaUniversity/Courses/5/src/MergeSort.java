import java.util.Arrays;
import java.util.LinkedList;
import java.util.List;
import java.util.ListIterator;

public class MergeSort {

	/**
	 * Internal method that merges two sorted halves of a subarray (from Weiss
	 * Data Structures and Algorithm Analysis in Java)
	 * 
	 * @param a
	 *            an array of Comparable items.
	 * @param tmpArray
	 *            an array to place the merged result.
	 * @param leftPos
	 *            the left-most index of the subarray.
	 * @param rightPos
	 *            the index of the start of the second half.
	 * @param rightEnd
	 *            the right-most index of the subarray.
	 */
	private static void merge(Integer[] a, Integer[] tmpArray, int leftPos, int rightPos, int rightEnd) {
		int leftEnd = rightPos - 1;
		int tmpPos = leftPos;
		int numElements = rightEnd - leftPos + 1;

		// Main loop
		while (leftPos <= leftEnd && rightPos <= rightEnd) {
			if (a[leftPos] <= a[rightPos]) {
				tmpArray[tmpPos++] = a[leftPos++];
			} else {
				tmpArray[tmpPos++] = a[rightPos++];
			}
		}

		while (leftPos <= leftEnd) { // Copy rest of first half
			tmpArray[tmpPos++] = a[leftPos++];
		}

		while (rightPos <= rightEnd) { // Copy rest of right half
			tmpArray[tmpPos++] = a[rightPos++];
		}

		// Copy tmpArray back
		for (int i = 0; i < numElements; i++, rightEnd--) {
			a[rightEnd] = tmpArray[rightEnd];
		}

	}

	/**
	 * Merge Sort algorithm. This is the Merge Sort algorithm from from Weiss,
	 * Data Structures and Algorithm Analysis in Java, as presented in class.
	 * 
	 * @param a
	 *            an array of Comparable items.
	 */
	public static void mergeSort(Integer[] a) {
		Integer[] tmpArray = new Integer[a.length];
		mergeSort(a, tmpArray, 0, a.length - 1);
	}

	/**
	 * Internal method that makes recursive calls. This is part of the MergeSort
	 * algorithm from from Weiss, Data Structures and Algorithm Analysis in
	 * Java, as presented in class.
	 * 
	 * @param a
	 *            an array of Comparable items.
	 * @param tmpArray
	 *            an array to place the merged result.
	 * @param left
	 *            the left-most index of the subarray.
	 * @param right
	 *            the right-most index of the subarray.
	 */
	private static void mergeSort(Integer[] a, Integer[] tmpArray, int left, int right) {
		if (left < right) {
			int center = (left + right) / 2;
			mergeSort(a, tmpArray, left, center);
			mergeSort(a, tmpArray, center + 1, right);
			merge(a, tmpArray, left, center + 1, right);
		}
	}

	/**
	 * Problem 5: Iterative Bottom-up Merge Sort
	 */
	public static void mergeSortB(Integer[] inputArray) {
		int size = inputArray.length;
		Integer[] tmp = new Integer[size];
		for (int i = 1; i < size; i *= 2) { // first for loop to divided the
											// array into subarray(bolck) with
											// size 2,4,8,18,etc....
			for (int left = 0; left < size - i; left += i + i) { // sort each
																	// sub block
				int right = left + i;
				int rightEnd = Math.min(left + i + i - 1, size - 1);
				merge(inputArray, tmp, left, right, rightEnd);
				// System.out.println(i+" "+left+" "+rightEnd+" "+center);
				// System.out.println(Arrays.toString(tmp)); //print all
				// informations to debug
			}
		}

	}

	/**
	 * Problem 6: Merge Sort for Lists, Without Side Effects
	 */
	public static List<Integer> sortList(List<Integer> inputList) {
		LinkedList<Integer> l = new LinkedList<Integer>();
		for (Integer i : inputList) {
			l.add(i);
		}

		return sortListRec(l);

	}

	private static List<Integer> sortListRec(List<Integer> inputList) {

		int midIndex = (inputList.size()) / 2;
		if (inputList.size() == 1) { // base case when the size is 1
			return inputList;
		}
		/*
		 * if (inputList.size() == 2) { // when the size is 2, divided into two
		 * 							    // list with size of 1, but it turns out I don't need this part.
		 * return mergeLists(inputList.subList(0, 1), inputList.subList(1, 2));
		 * }
		 */
		return mergeLists(sortListRec(inputList.subList(0, midIndex)),
				sortListRec(inputList.subList(midIndex, inputList.size())));
	}

	/**
	 * New merge method that merges two lists and returns a new list. Use this
	 * method to implement sortList.
	 */
	public static List<Integer> mergeLists(List<Integer> left, List<Integer> right) {
		LinkedList<Integer> l = new LinkedList<Integer>();
		// int expectedSize=left.size()+right.size();
		int leftcount = 0;
		int rightcount = 0;
		for (Integer i : left.subList(leftcount, left.size())) {
			for (Integer j : right.subList(rightcount, right.size())) {
				if (j < i) {
					l.add(j);
					rightcount++;
				}
			}
			l.add(i);
			leftcount++;
		}
		// Although it is a nested for loop, but the running time is still
		// bigO(leftSize+rightSize), because
		// the element already added will be 'removed' from the new sublist
		// which need to be looped.

		// the method above will ignore the part that right element greater the
		// last element in the left,
		// so this if loop is to check and add all the rest into the list.
		if (!right.subList(rightcount, right.size()).isEmpty()) {
			for (Integer restelement : right.subList(rightcount, right.size())) {
				l.add(restelement);
			}
		}

		// second method
		/*
		 * LinkedList<Integer> l2 = new LinkedList<Integer>(); int
		 * lSize=left.size(); int rSize=right.size(); ListIterator<Integer>
		 * leftI = left.listIterator(); ListIterator<Integer> rightI=
		 * right.listIterator(); int le=leftI.next(); int re=rightI.next();
		 * 
		 * while(leftI.hasNext()||rightI.hasNext()){
		 * 
		 * if(le<re){ l2.add(le); le=leftI.next(); } else{ l2.add(re);
		 * re=rightI.next(); } }
		 */

		return l;
	}

	public static void main(String[] args) {
		// Weiss sort
		Integer[] a = { 1, 4, 9, 131, 0, 2, 7, 19, 245, 18 };
		MergeSort.mergeSortB(a);
		// System.out.println(Arrays.toString(a)); // Should be [0, 1, 2, 4, 7,
		// 9,
		// 18, 19, 131, 245]

		List<Integer> l = new LinkedList<Integer>();
		List<Integer> r = new LinkedList<Integer>();
		List<Integer> result;
		// l.add(1);
		// l.add(3);
		// l.add(5);
		// l.add(7);
		// l.add(9);
		// l.add(11);
		// r.add(2);
		// r.add(4);
		// r.add(6);
		// r.add(8);
		l.add(5);
		l.add(4);
		l.add(3);
		l.add(2);
		l.add(1);
		l.add(0);
		// result = mergeLists(l, r);
		System.out.println(l.subList(1, 1));
		// result = mergeLists(l, r);
		// System.out.println(l.subList(2, 6));
		result = sortList(l);

		System.out.println(result);
	}

}
