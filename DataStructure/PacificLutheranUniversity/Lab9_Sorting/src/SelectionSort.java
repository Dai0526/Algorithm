
/** Implements the Selection Sort algorithm.
 */
public class SelectionSort {
	/**
	 * Sorts the specified array of integers using the selection
	 * sort algorithm.
	 *
	 * @param data the array to be sorted
	 */
	public static <T extends Comparable<T>>
	void sort(T[] data)
	{
		int min;
		T temp;

		for (int index = 0; index < data.length-1; index++)
		{
			min = index;
			for (int scan = index+1; scan < data.length; scan++)
				if (data[scan].compareTo(data[min])<0)
					min = scan;

			swap(data, min, index);
		}
	}

	/**
	 * Swaps to elements in an array. Used by various sorting algorithms.
	 * 
	 * @param data   the array in which the elements are swapped
	 * @param index1 the index of the first element to be swapped
	 * @param index2 the index of the second element to be swapped
	 */
	private static <T extends Comparable<T>>
	void swap(T[] data, int index1, int index2)
	{
		T temp = data[index1];
		data[index1] = data[index2];
		data[index2] = temp;
	}

}
