import static org.junit.Assert.*;

import org.junit.BeforeClass;
import org.junit.Test;


public class DictionaryTest {
	private static Dictionary dict;
	private static String word1,word2,word3,word4,word5,word6;
	@BeforeClass
	public static void setUpBeforeClass() throws Exception {
		dict=new Dictionary("words.txt");
		word1="a";//not in dict
		word2="";//not in dict
		word3="abamperes";//in dict
		word4="abamps";//in dict
		word5="Tianhua";// not in dict
	}


	@Test
	public void testSearch() {
		assertFalse(Dictionary.Search(dict.dictionary, word1));
		assertFalse(Dictionary.Search(dict.dictionary, word2));
		assertTrue(Dictionary.Search(dict.dictionary, word3));
		assertTrue(Dictionary.Search(dict.dictionary, word4));
		assertFalse(Dictionary.Search(dict.dictionary, word5));
	}

}
