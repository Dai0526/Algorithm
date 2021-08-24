import static org.junit.Assert.*;

import org.junit.BeforeClass;
import org.junit.Test;


public class BoggleBoardTest {
	private static BoggleBoard board;
	private static String word1,word2,word3,word4;
	
	@BeforeClass
	public static void setUpBeforeClass() throws Exception {
			board=new BoggleBoard("board.txt");
			word1="A";//single character
			word2=" ";//empty
			word3="ETHIC"; //on board
			word4="apple";//off board
	}

	@Test
	public void testOnBoard() { 
		//I didn't convert lower case to upper case in BoggleBoard onBoard method
		//So the test case has to be upper case. but I do this in my Boggle class.
		assertTrue(board.onBoard(word1));
		assertFalse(board.onBoard(word2));
		assertTrue(board.onBoard(word3));
		assertFalse(board.onBoard(word4));
	}

}
