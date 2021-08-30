
/** Implements the Insertion Sort algorithm.
 */
public class InsertionSort {
	/**
	 * Sorts the specified array of objects using an insertion
	 * sort algorithm.
	 *
	 * @param data the array to be sorted
	 */
	public static <T extends Comparable<T>>
	void sort(T[] data)
	{
		for (int index = 1; index < data.length; index++)
		{
			T key = data[index];
			int position = index;

			// shift larger values to the right
			while (position > 0 && data[position-1].compareTo(key) > 0)
			{
				data[position] = data[position-1];
				position--;
			}

			data[position] = key;
		}
	}

}
