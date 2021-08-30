import java.util.Arrays;

/**
 * This getInfo method. It will create a 2D array, which computes all the
 * necessary information and store them in forms of array to solve SuperSoda
 * problem.
 * 
 * I discussed the algorithm(from line 85 to 107 ) about how to create and how the
 * table will help this hw with my friend Edwin.
 * 
 * @author Tianhua
 *
 */

public class getInfo {
	public static int[][] Combination; // The main table which contains how many
										// packs of soda it needs
	public static double[] costOfDifferentCombination;// The cost of different
														// Combination of
														// soda(The last column
														// of the table)
	public static int[] minSodaCostCombination; // The combination of minSoda
												// Combination
	public static double minCost; // The minCost

	/**
	 * 
	 * getInfo Constructor Create a "empty" array, which only has the first
	 * column and first row.
	 * 
	 * For example, a getInfo(3,7) will look like as follow
	 *  0 1 2 3 4 5 6 7
	 *  1 * * * * * * *
	 *  2 * * * * * * *
	 *  3 * * * * * * *, where * are the place to solve data
	 * 
	 * 
	 * @param sodaSizes
	 *            different size of soda. And sodaSize+1 will be the number of
	 *            rows
	 * @param n
	 *            number of soda. And n+1 will be the number of columns
	 */
	public getInfo(int[] sodaSizes, int n) {

		Combination = new int[n + 1][sodaSizes.length + 1];
		Combination[0][0] = 0;

		// create a 2d table
		for (int i = 1; i < n + 1; i++) {
			Combination[i][0] = i;
		} // fill the first row
		for (int j = 1; j < sodaSizes.length + 1; j++) {
			Combination[0][j] = sodaSizes[j - 1];
		} // fill the first column

		// create an array of costOfDifferentCombination
		costOfDifferentCombination = new double[sodaSizes.length];

		// create an array of minSodaCostCombination
		minSodaCostCombination = new int[sodaSizes.length];
		for (int i = 0; i < sodaSizes.length; i++) {
			minSodaCostCombination[i] = 0;
		}

		// the data of minCost
		minCost = 0;
	}

	/**
	 * This method will compute and fill the table with all the information
	 * provided. It has 4 sections.
	 * 
	 * Section 1: fills the table slots with numbers of different combinations
	 * of how many packs of Soda need to buy
	 * 
	 * Section
	 * 
	 * @param sodaSizes
	 * @param costs
	 * @param n
	 */
	public static void makeTable(int[] sodaSizes, double[] costs, int n) {
		// Section 1: fills the table slots
		for (int i = 1; i < n + 1; i++) {
			for (int j = 1; j < sodaSizes.length + 1; j++) {
				int x = Combination[i][0] - Combination[0][j];
				int min = Integer.MAX_VALUE;
				int level = 0; // to trace the level of the row

				if (x > 0) {
					for (Integer temp : Combination[x]) { // find the min value
															// of data in this
															// column
						if (level <= j) {
							if (temp < min) {
								min = temp;
							}
						}
						level += 1;
					}
					Combination[i][j] = min + 1;
				}

				if (x < 0) {
					Combination[i][j] = Combination[i][j - 1];
				} else if (x == 0 && min == Integer.MAX_VALUE) { // if it is an
																	// empty
																	// slot and
																	// the
																	// difference
																	// is the
																	// same, it
																	// means can
																	// buy one
																	// pack of
																	// this size
																	// of soda,
																	// so put 1
																	// in this
																	// slot.
					Combination[i][j] = 1;
				}
			} // for #2
		} // for #1

		// Section 2: get all cost for the combination
		double[] costForNCans = new double[sodaSizes.length]; // instantiate an
																// array to hold
																// all the cost
																// of last
																// column's
																// combination

		for (int i = 1; i < sodaSizes.length + 1; i++) { // start from row 1
			int row = i;
			int col = n; // it is also a count of the remainning cans.
			double cost = 0.0;
			int numberOfPack = Combination[col][row]; // number of packs I can
														// buy, it is also a
														// count of my while
														// loop to compute the
														// cost.

			while (numberOfPack > 0) {
				if (row == 1) { // the first row is a special case, just buy 1
								// cans a time, so only need to -1
					cost = cost + costs[row - 1];
					col--;
					numberOfPack--;
				} else if (Combination[col][row] == Combination[col][row - 1] && col < sodaSizes[row - 1]) {
					row = row - 1;
				} else if (Combination[col][row] > Combination[col][row - 1]) {
					row = row - 1; // these two else if is to find the min value
									// of the least of the sodaSize.
				} else {
					cost = cost + costs[row - 1]; // once find the least
													// sodaSize, buy one pack of
													// this size, compute the
													// cost and store the
													// data(Dynamic
													// Programming).
					col = col - sodaSizes[row - 1]; // get the remainning number
													// of cans(Dynamic
													// Programming).
					numberOfPack--;
				}

			}
			costForNCans[i - 1] = cost;

		} // for loop to solve cost
		costOfDifferentCombination = costForNCans;

		// section 3, get the min cost
		double min = Double.MAX_VALUE;
		for (double Cost : costOfDifferentCombination) {
			if (Cost < min) {
				min = Cost;
			}
		}
		minCost = min;

		// section 4: get the combiantion of shopping strategy of minCost
		int count = 0;
		for (double Cost : costOfDifferentCombination) {
			if (Cost == minCost) {
				break;
			}
			count++; // get the row index of min Cost
		}
		count = count + 1; // get the row index of min Cost

		// once I know the index of min cost, I know the the number of packs I
		// can buy,
		// The code below has the same structure of computing the cost for all
		// combination, but this time I only need to deal with one possibility.
		int comboCount = Combination[n][count];
		int colforMinCombo = n;
		double cost = 0;

		while (comboCount > 0 && colforMinCombo >= 0) {

			if (count == 1) {
				cost = cost + costs[count - 1];
				colforMinCombo = colforMinCombo - sodaSizes[count - 1];
				comboCount--;
				minSodaCostCombination[count - 1]++;
			} else if (Combination[colforMinCombo][count] == Combination[colforMinCombo][count - 1]
					&& colforMinCombo < sodaSizes[count - 1]) {
				count = count - 1;
			} else if (Combination[colforMinCombo][count] > Combination[colforMinCombo][count - 1]) {
				count = count - 1;
			} else {
				cost = cost + costs[count - 1];
				colforMinCombo = colforMinCombo - sodaSizes[count - 1];

				comboCount--;
				minSodaCostCombination[count - 1]++;
			}
		}
	}// make table

	/**
	 * get min Cost
	 * 
	 * @return the minCost
	 */
	public double getMinCost() {

		return this.minCost;
	}

	/**
	 * get an array of Cost for the last column in the table
	 * 
	 * @return cost
	 */
	public double[] getCost() {
		return this.costOfDifferentCombination;
	}

	/**
	 * Return the combination of the min cost
	 * 
	 * @return combination of min cost
	 */
	public int[] getMinimalSodaCostCombinations() {
		return this.minSodaCostCombination;
	}

	
	/** Testing
	public static void main(String[] args) {
		int[] size = new int[5];
		size[0] = 1;
		size[1] = 6;
		size[2] = 12;
		size[3] = 25;
		size[4] = 36;

		double[] cost = new double[] { 0.8, 4, 7.5, 14, 20 };

		getInfo gf = new getInfo(size, 1337);
		gf.makeTable(size, cost, 1337);
		System.out.println(Arrays.deepToString(gf.Combination));
		System.out.println(Arrays.toString(gf.getCost()));
		System.out.println(gf.getMinCost());
		System.out.println(Arrays.toString(gf.getMinimalSodaCostCombinations()));
		System.out.println(52.8 / 20.0 * 36);
	}*/
}
