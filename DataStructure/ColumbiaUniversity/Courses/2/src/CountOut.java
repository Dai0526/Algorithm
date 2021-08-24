import java.util.*;

public class CountOut {
	/**
	 * This method is using a queue to find the winner of Countout game.
	 * 
	 * @param n
	 *            number of players
	 * @param k
	 *            number of count
	 * @return a list in order of the players who get out
	 */
	public static List<Integer> play(int n, int k) {
		if (k <= 0) {
			throw new IllegalArgumentException("Illegal Input");
		}
		Queue<Integer> remainingPlayers = new LinkedList<>();
		LinkedList<Integer> playerOut = new LinkedList<>();

		// put all player index into this array
		for (int i = 0; i < n; i++) {
			remainingPlayers.add(i);
		}

		while (playerOut.size() != n) {
			// for loop to let the player out to be the first element
			for (int i = 0; i < k - 1; i++) {
				remainingPlayers.add(remainingPlayers.poll());
			}

			// add the one who get out to the end of the playerOut List
			playerOut.add(remainingPlayers.poll());
		}
		return playerOut;
	}

	/**
	 * Find the winner of Countout game, basically is to return the last player
	 * of the playerOut list
	 * 
	 * @param n
	 *            number of players
	 * @param k
	 *            count out number
	 * @return the winner of the game
	 */
	public static Integer findWinner(int n, int k) {
		// The bigO is n^2, since the play(int,int) method has a nested
		// while-for loop
		return play(n, k).get(n - 1); // get the last object of the playerOut
										// list
	}

	/**
	 * call the recursion method to find the winner
	 * 
	 * @param n
	 *            number of players
	 * @param k
	 *            count out number
	 * @return the winner of the game
	 */
	public static Integer findWinnerRec(int n, int k) {
		if (k <= 0) {
			throw new IllegalArgumentException("Illegal Input");
		}
		return RecursiveFindWinner(n, k); // call the recursion method

	}

	/**
	 * 
	 * @param n
	 *            number of players
	 * @param k
	 *            countout number
	 * @return the winner of the game
	 */
	private static Integer RecursiveFindWinner(int n, int k) {
		// I got the idea about how to make progress of the recursion from both
		// TA and Wikipedia(Josephus problem). I was wrong at beginning that I
		// tried to use n%k to find some evidences.

		// The bigO for this recursion is n, since it will loop all n players
		if (n == 1)
			return 0;
		else
			return (findWinnerRec(n - 1, k) + k) % n;
	}

}// class

