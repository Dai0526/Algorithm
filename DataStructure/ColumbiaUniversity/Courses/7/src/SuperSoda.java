import java.util.Arrays;

public class SuperSoda {
	/*
	 * I wrote a separated class called getInfo which contains all the functions
	 * I need to create a table of all the data I need by using Dynamic
	 * programming. It basically create a 2-D table, and store the cost of all the
	 * possible combination of soda of the last Column in an individual array.
	 * 
	 * That class also has a set of get-methods so I can use these get methods
	 * in my SuperSoda class directly.
	 * 
	 * Although it will be more convenient to create a 1D array for each
	 * individual problem in this homework, I think my 2D table will be more
	 * helpful if I want to solve a collection of SuperSoda problem because it
	 * contains all the data I need.
	 * 
	 */

	public static double minimalSodaCost(int[] sodaSizes, double[] costs, int n) {
		getInfo gf = new getInfo(sodaSizes, n);
		gf.makeTable(sodaSizes, costs, n);
		return gf.getMinCost();
	}

	public static int maximumSodaNumber(int[] sodaSizes, double[] costs, double cost) {
		int maxSodaNumber = 0;

		getInfo gf;
		int approximateSize = (int) (cost / 20.0 * 36); // this is the maximum
														// soda numbers I could
														// buy --assume
														// I only buy soda with
														// the average price of
														// 36 pack
		boolean found = false;
		while (found == false) {
			gf = new getInfo(sodaSizes, approximateSize);
			gf.makeTable(sodaSizes, costs, approximateSize);

			for (double C : gf.getCost()) {

				if (C <= cost) {
					found = true; // once I found the cost is lower than the
									// budget, the result found
					maxSodaNumber = approximateSize;
				}
			}
			approximateSize--;
		}

		return maxSodaNumber;
	}

	public static int[] minimalSodaCostCombinations(int[] sodaSizes, double[] costs, int n) {
		getInfo gf = new getInfo(sodaSizes, n);
		gf.makeTable(sodaSizes, costs, n);
		return gf.getMinimalSodaCostCombinations();
	}

	public static void main(String[] args) {
		int[] sodaSizes = new int[] { 1, 6, 12, 25, 36 };
		double[] costs = new double[] { 0.8, 4, 7.5, 14, 20 };
		System.out.println(minimalSodaCost(sodaSizes, costs, 100));
		System.out.println(maximumSodaNumber(sodaSizes, costs, 25));
		System.out.println(Arrays.toString(minimalSodaCostCombinations(sodaSizes, costs, 105)));
	}
}
