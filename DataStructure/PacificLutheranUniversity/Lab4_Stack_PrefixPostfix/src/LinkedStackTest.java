import static org.junit.Assert.*;

import org.junit.BeforeClass;
import org.junit.Test;


public class LinkedStackTest {
	private static LinkedStack test1;
	private static LinkedStack test2;

	
	@BeforeClass
	public static void setUpBeforeClass() throws Exception {
		test1=new LinkedStack();
		test2=new LinkedStack();
		test2.push(6);
		test2.push(0);
		test2.push(0);
		test2.push(1);
		test2.push(4);
		test2.push(1);
		test2.push(0);
		test2.push(2);
		// make the test2 become 20141006
		
		
	}

	@Test
	public void testPeek() {
		assertEquals(2,test2.peek());
		
	}

	@Test
	public void testIsEmpty() {
		assertTrue(test1.isEmpty());
		assertFalse(test2.isEmpty());
	}

	@Test
	public void testSize() {
		assertEquals(0,test1.size());
		assertEquals(8,test2.size());
	}

	@Test
	public void testToString() {
		assertEquals("",test1.toString());
		assertEquals("20141006",test2.toString());
	}

}
