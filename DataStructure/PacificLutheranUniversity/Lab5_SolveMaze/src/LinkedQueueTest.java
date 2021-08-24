import static org.junit.Assert.*;

import org.junit.BeforeClass;
import org.junit.Test;


public class LinkedQueueTest {
	private static LinkedQueue test1;//empty
	private static LinkedQueue test2;//with some elements
	private static LinkedQueue test3;// to test clear
	@BeforeClass
	public static void setUpBeforeClass() throws Exception {
		test1=new LinkedQueue();
		test2=new LinkedQueue();
		test3=new LinkedQueue();
		test2.enqueue(1);
		test2.enqueue(2);
		test2.enqueue(3);
		test2.enqueue(4);
		test2.enqueue(5);
		test2.dequeue();
		test2.enqueue(6);
		test3.enqueue(1);
		test3.clear();
	}
	
	@Test
	public void testFirst() {
		assertEquals(2,test2.first());	
	}

	@Test
	public void testIsEmpty() {
		assertTrue(test1.isEmpty());
		assertFalse(test2.isEmpty());
		assertTrue(test3.isEmpty()); //test if it is empty to
									// see if clear method works
	}

	@Test
	public void testSize() {
		assertEquals(0,test1.size());
		assertEquals(5,test2.size());
		assertEquals(0,test3.size());		
	}

	@Test
	public void testToString() {
		assertEquals("23456",test2.toString());
		assertEquals("",test1.toString());
		assertEquals("",test3.toString());
	}
}
