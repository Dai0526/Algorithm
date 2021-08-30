import static org.junit.Assert.*;


import org.junit.Test;
import org.junit.Before;




public class AlbumTest {
	private Album test1;
	private Album test2;
	private EntertainmentItem test3;
	
	@Before
	// construct 3 album items with different constructor, different title, artist, and cost
	public void setUp() throws Exception {
		test1 = new Album("111",10.0,"Tianhua"); 
		test2 = new Album("222", 20.0, "Yiqian");
		test3 = new Album("333", "Fang");
		
	}	
	@Test
	public void testRating() {
		test2.setVocal(5);
		test2.setAccompaniment(4);
		test2.setLyrics(3);
		assertEquals(4.0,test2.rating(),0.00001);
		
	}

	@Test
	public void testToString() {
		assertEquals("title is 111, and the cost is 10.0 . Tianhua, Rating: 0.0" ,test1.toString());
	}

	@Test
	public void testAlbumStringString() {
		assertEquals("333",test3.getTitle());
		assertEquals("Fang",((Album) test3).getArtist());
	}

	@Test
	public void testAlbumStringDoubleString() {
		assertEquals("222",test2.getTitle());
		assertEquals("Yiqian",((Album) test2).getArtist());
		assertEquals(20.0,test2.getCost(),0.000001);
	}



}
