/** Implements the Shell sort algorithm.
 *  @author Koffman and Wolfgang
 * */

public class ShellSort {
	/** Sort the data using Shell sort algorithm.
	    pre:  data contains Comparable objects.
	    post: data is sorted.
	    @param data The array to be sorted
	 */
	public static < T
	extends Comparable < T >> void sort(T[] data) {
		// Gap between adjacent elements.
		int gap = data.length / 2;
		while (gap > 0) {
			for (int nextPos = gap; nextPos < data.length;
			                nextPos++) {
				// Insert element at nextPos in its subarray.
				insert(data, nextPos, gap);
			} // End for.

			// Reset gap for next pass.
			if (gap == 2) {
				gap = 1;
			}
			else {
				gap = (int) (gap / 2.2);
			}
		} // End while.
	} // End sort.

	/** Inserts element at nextPos where it belongs in array.
	    pre:  Elements through nextPos - gap in subarray are sorted.
	    post: Elements through nextPos in subarray are sorted.
	    @param data The array being sorted
	    @param nextPos The position of element to insert
	    @param gap The gap between elements in the subarray
	 */
	private static < T
	extends Comparable < T >> void insert(T[] data,
	                                      int nextPos,
	                                      int gap) {
		T nextVal = data[nextPos]; // Element to insert.
		// Shift all values > nextVal in subarray down by gap.
		while ( (nextPos > gap - 1) // First element not shifted.
		                && (nextVal.compareTo(data[nextPos - gap]) < 0)) {
			data[nextPos] = data[nextPos - gap]; // Shift down.
			nextPos -= gap; // Check next position in subarray.
		}
		data[nextPos] = nextVal; // Insert nextVal.
	}
}
