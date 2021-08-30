import static org.junit.Assert.*;
import org.junit.BeforeClass;
import org.junit.Test;



public class LinkedUnorderedListTest {
	//First set of test data
	private static LinkedUnorderedList<String> test1;
	private static LinkedUnorderedList<String> test2;
	private static LinkedUnorderedList<String> test3;
	private static LinkedUnorderedList<String> test4;
	private static LinkedUnorderedList<String> test5;
	private static LinkedUnorderedList<String> test6;
	//second set of test data to test remove
	private static LinkedUnorderedList<String> test2b;
	private static LinkedUnorderedList<String> test3b;
	private static LinkedUnorderedList<String> test4b;
	private static LinkedUnorderedList<String> test5b;
	//second set of test data to test clear
	private static LinkedUnorderedList<String> test1c;
	private static LinkedUnorderedList<String> test2c;
	private static LinkedUnorderedList<String> test3c;
	private static LinkedUnorderedList<String> test4c;

	private static LinkedUnorderedList<String> test7;
	@BeforeClass 
	public static void setUpBeforeClass() throws Exception {
		//First set of data to test all 3 add functions
		test1=new LinkedUnorderedList<String>();//create an empty list
		
		test2=new LinkedUnorderedList<String>();//create a list with only one element
		test2.addToFront("a");					// List is a			

		
		test3=new LinkedUnorderedList<String>();//creat a list with two element
		test3.addToFront("a");
		test3.addToRear("b");                // List is a b
		
		test4=new LinkedUnorderedList<String>();//creat a list with more than two element
		test4.addToFront("a");
		test4.addToFront("g");
		test4.addToFront("f");
		test4.addToFront("e");
		test4.addToFront("b");
		test4.addToFront("c");
		test4.addToFront("b");
		test4.addToFront("a");//"abcbefga"
		
		test5=new LinkedUnorderedList<String>();//creat a list with with all same elements
		test5.addToFront("a");
		test5.addToFront("a");
		test5.addToFront("a");
		test5.addToFront("a");
		test5.addToFront("a");//"aaaaa"
		
		test6=new LinkedUnorderedList<String>();//create another empty list to test
		
		// use the method to manipulate my test cases
		//addTofront
		test1.addToFront("PLU");
		test1.addToFront("A");//test1: APLU
		test2.addToFront("PLU");
		test2.addToFront("A");//test2: APLUa
		test3.addToFront("PLU");
		test3.addToFront("A");//test3: APLUab
		test4.addToFront("PLU");
		test4.addToFront("A");//test4: APLUabcbefga
		test5.addToFront("PLU");
		test5.addToFront("A");//test5: APLUaaaaa
		//addToRear
		test1.addToRear("CSCE");
		test1.addToRear("Z");//test1: APLUCSCEZ
		test2.addToRear("CSCE");
		test2.addToRear("Z");//test2: APLUaCSCEZ
		test3.addToRear("CSCE");
		test3.addToRear("Z");//test3: APLUabCSCEZ
		test4.addToRear("CSCE");
		test4.addToRear("Z");//test4: APLUabcbefgaCSCEZ
		test5.addToRear("CSCE");
		test5.addToRear("Z");//test5: APLUaaaaaCSCEZ
		//addAfter
		test1.addAfter("270", "A");//test1: A270PLUCSCEZ
		test2.addAfter("270", "PLU");//test2: APLU270aCSCEZ
		test3.addAfter("270", "Z");//test3: APLUabCSCEZ270
		test4.addAfter("270", "b");//test4: APLUabcb270efgaCSCEZ
		test5.addAfter("270", "a");//test5: APLUaaaaaCSCEZ
		
		//Second set of data to test remove function
		test2b=new LinkedUnorderedList<String>();
		test3b=new LinkedUnorderedList<String>();
		test4b=new LinkedUnorderedList<String>();
		test5b=new LinkedUnorderedList<String>();

		test2b.addToFront("a");					// List is a			

		test3b.addToFront("a");
		test3b.addToRear("b");                // List is a b
		
		test4b.addToFront("a");
		test4b.addToFront("g");
		test4b.addToFront("f");
		test4b.addToFront("e");
		test4b.addToFront("b");
		test4b.addToFront("c");
		test4b.addToFront("b");
		test4b.addToFront("a");//"abcbefga"

		test5b.addToFront("a");
		test5b.addToFront("a");
		test5b.addToFront("a");
		test5b.addToFront("a");
		test5b.addToFront("a");//"aaaaa"
		//remove first
		test2b.removeFirst();
		test3b.removeFirst();
		test4b.removeFirst();
		test5b.removeFirst();
		
		//remove last
		test3b.removeLast();
		test4b.removeLast();
		test5b.removeLast();
		
		//remove 
		test4b.remove("b");
		test4b.remove("c");
		test4b.remove("g");
		test5b.remove("a");
		
		//third set of data to test clear
		test1c=new LinkedUnorderedList<String>();
		test2c=new LinkedUnorderedList<String>();
		test3c=new LinkedUnorderedList<String>();
		test4c=new LinkedUnorderedList<String>();
		
		test2c.addToFront("a");					// List is a			

		test3c.addToFront("a");
		test3c.addToRear("b");                // List is a b
		
		test4c.addToFront("a");
		test4c.addToFront("g");
		test4c.addToFront("f");
		test4c.addToFront("e");
		test4c.addToFront("b");
		test4c.addToFront("c");
		test4c.addToFront("b");
		test4c.addToFront("a");//"abcbefga"
		//clear
		test1c.clear();
		test2c.clear();
		test3c.clear();
		test4c.clear();

		test7=new LinkedUnorderedList<String>();//creat a list with with all same elements
		test7.addToFront("a");
		test7.addToFront("a");
		test7.addToFront("a");
		test7.addToFront("a");
		test7.addToFront("a");//"aaaaa"
	}

	@Test
	public void testLinkedUnorderedList() {
		assertEquals("",test6.toString());
	}


	@Test
	public void testAddToFront() {
		assertEquals("A270PLUCSCEZ",test1.toString());
		assertEquals("APLU270aCSCEZ",test2.toString());
		assertEquals("APLUabCSCEZ270",test3.toString());
		assertEquals("APLUab270cbefgaCSCEZ",test4.toString());
		assertEquals("APLUa270aaaaCSCEZ",test5.toString());
		
	}

	@Test
	public void testAddToRear() {
		assertEquals("A270PLUCSCEZ",test1.toString());
		assertEquals("APLU270aCSCEZ",test2.toString());
		assertEquals("APLUabCSCEZ270",test3.toString());
		assertEquals("APLUab270cbefgaCSCEZ",test4.toString());
		assertEquals("APLUa270aaaaCSCEZ",test5.toString());
		
	}

	@Test
	public void testAddAfter() {
		assertEquals("A270PLUCSCEZ",test1.toString());
		assertEquals("APLU270aCSCEZ",test2.toString());
		assertEquals("APLUabCSCEZ270",test3.toString());
		assertEquals("APLUab270cbefgaCSCEZ",test4.toString());
		assertEquals("APLUa270aaaaCSCEZ",test5.toString());

	}


	@Test
	public void testRemoveFirst() {
		assertEquals("", test2b.toString());
		assertEquals("b", test3b.toString());
		assertEquals("bef", test4b.toString());
		assertEquals("aaa", test5b.toString());
		
	}

	@Test
	public void testRemoveLast() {
		assertEquals("", test2b.toString());
		assertEquals("b", test3b.toString());
		assertEquals("bef", test4b.toString());
		assertEquals("aaa", test5b.toString());
	}

	@Test
	public void testRemove() {
		assertEquals("", test2b.toString());
		assertEquals("b", test3b.toString());
		assertEquals("bef", test4b.toString());
		assertEquals("aaa", test5b.toString());
	}

	@Test
	public void testFirst() {
		assertEquals("A",test1.first());
		assertEquals("A",test2.first());
		assertEquals("A",test3.first());
		assertEquals("A",test4.first());
		assertEquals("A",test5.first());
		

		assertEquals("b",test4b.first());
		assertEquals("a",test5b.first());
	}

	@Test
	public void testLast() {
		assertEquals("Z",test1.last());
		assertEquals("Z",test2.last());
		assertEquals("270",test3.last());
		assertEquals("Z",test4.last());
		assertEquals("Z",test5.last());
		

		assertEquals("f",test4b.last());
		assertEquals("a",test5b.last());
	}

	@Test
	public void testContains() {

		
		assertTrue(test4.contains("A"));
		assertTrue(test4.contains("Z"));
		assertTrue(test4.contains("PLU"));
		assertTrue(test4.contains("270"));
		assertTrue(test4.contains("CSCE"));
		assertFalse(test4.contains("x"));
		assertFalse(test4.contains("y"));

		// test6 which is empty is tested and shows empty exception
		
		
	}

	@Test
	public void testIsEmpty() {
		assertTrue(test2b.isEmpty());
		assertTrue(test3b.isEmpty());
		assertTrue(test6.isEmpty());
		assertFalse(test1.isEmpty());
		assertFalse(test2.isEmpty());
		assertFalse(test3.isEmpty());
		assertFalse(test4.isEmpty());
		assertFalse(test5.isEmpty());

		assertFalse(test4b.isEmpty());
		assertFalse(test5b.isEmpty());	
	}

	@Test
	public void testSize() {
		assertEquals(5,test1.size());
		assertEquals(6,test2.size());
		assertEquals(8,test3.size());
		assertEquals(13,test4.size());
		assertEquals(10,test5.size());
		assertEquals(0,test6.size());
		assertEquals(0,test3b.size());
		assertEquals(3,test4b.size());
	}

	@Test
	public void testClear() {
		assertEquals("", test1c.toString());
		assertEquals("", test2c.toString());
		assertEquals("", test3c.toString());
		assertEquals("", test4c.toString());

	}

	@Test
	public void testIndexOf() {
		assertEquals(5,test3.indexOf("CSCE"));
		assertEquals(6,test3.indexOf("Z"));
		assertEquals(1,test3.indexOf("A"));
		assertEquals(7,test3.indexOf("270"));
	}

	@Test
	public void testLastIndexOf() {
		assertEquals(7,test5.lastIndexOf("a"));
		assertEquals(4,test7.lastIndexOf("a"));//aaaaa  the last a is pos:4
		
	}
	
	
	@Test
	public void testToString() {
		assertEquals("A270PLUCSCEZ",test1.toString());
		assertEquals("APLU270aCSCEZ",test2.toString());
		assertEquals("APLUabCSCEZ270",test3.toString());
		assertEquals("APLUab270cbefgaCSCEZ",test4.toString());
		assertEquals("APLUa270aaaaCSCEZ",test5.toString());
		
		assertEquals("", test2b.toString());
		assertEquals("b", test3b.toString());
		assertEquals("bef", test4b.toString());
		assertEquals("aaa", test5b.toString());
	}


}
