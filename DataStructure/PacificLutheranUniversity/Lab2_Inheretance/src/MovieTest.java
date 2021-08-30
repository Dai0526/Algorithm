import static org.junit.Assert.*;

import org.junit.BeforeClass;
import org.junit.Test;


public class MovieTest {
	private static Movie testMovie1;
	private static Movie testMovie2;
	private static EntertainmentItem testMovie3;
	
	@BeforeClass
	public static void setUpBeforeClass() throws Exception {
		testMovie1 = new Movie("444",10.0,"Tian");
		testMovie2 = new Movie("555", 20.0, "Hua");
		testMovie3 = new Movie("666", "Fang");
	}

	@Test
	public void testRating() {
		testMovie1.setActing(5);
		testMovie1.setDirecting(4);
		testMovie1.setSoundtrack(3);
		assertEquals(4.0,testMovie1.rating(),0.00001);
	}

	@Test
	public void testToString() {
		assertEquals("title is 444, and the cost is 10.0 . Tian , Rating: 0.0" ,testMovie1.toString());
	}

	@Test
	public void testMovieStringString() {
		assertEquals("666",testMovie3.getTitle());
		assertEquals("Fang",((Movie) testMovie3).getStudio());
	}

	@Test
	public void testMovieStringDoubleString() {
		assertEquals("555",testMovie2.getTitle());
		assertEquals("Hua",((Movie) testMovie2).getStudio());
		assertEquals(20.0,testMovie2.getCost(),0.0000001);
	}

}
