import static org.junit.Assert.*;


import org.junit.BeforeClass;
import org.junit.Test;


public class HugeIntegerTest {
	private static HugeInteger test1;    
	private static HugeInteger test2;     
	private static HugeInteger test3;
	private static HugeInteger test4;
	private static HugeInteger test5;
	private static HugeInteger test6;
	private static HugeInteger test7;
	private static HugeInteger test8;
	private static HugeInteger test9;
	private static HugeInteger test10;
	private static HugeInteger test11;
	private static HugeInteger test12;

	@BeforeClass
	public static void setUp() throws Exception {
		
		test2=new HugeInteger("123456");
		test3=new HugeInteger(123456);
		test4=new HugeInteger(176544);
		test5=new HugeInteger(3000000);
		test6=new HugeInteger("0123456");
		test7=new HugeInteger(0123456);
		test8=new HugeInteger(534);
		//different 0 HugeInteger
		test1=new HugeInteger();
		test9=new HugeInteger(000000);
		test10=new HugeInteger("000000");
		//test11 and test12 is to use two small integer to test the result 
		test11=new HugeInteger(123);
		test12=new HugeInteger(111);
	}

	@Test
	public void testHugeInteger() {
		assertTrue(test1.isZero());// Test if it is a default HugeInteger with 0; 
		assertFalse(test2.isZero());
		assertFalse(test3.isZero());
		assertFalse(test6.isZero());
		assertFalse(test7.isZero());
	}

	@Test
	public void testHugeIntegerString() {
		assertEquals("123456",test2.toString());
		assertEquals("0123456",test6.toString());
	}

	@Test
	public void testHugeIntegerInt() {
		assertEquals("123456", test3.toString());
		assertEquals("176544", test4.toString());
		assertEquals("42798", test7.toString());// 42798 in Dec is equal to 123456 in Oct
												// java will read the leading 0 int become Oct as default
	}

	@Test
	public void testEqual() {
		assertEquals(true,test2.equal(test3));
		assertEquals(false,test2.equal(test4));
		assertEquals(true,test2.equal(test6));
		assertEquals(true,test3.equal(test2));
		assertEquals(false,test4.equal(test2));
		assertEquals(true,test6.equal(test2));
	}

	@Test
	public void testCompareTo() {
		assertEquals(0,test2.compareTo(test3));
		assertEquals(-1,test4.compareTo(test5));
		assertEquals(1,test5.compareTo(test4));
		
	}

	@Test
	public void testIsZero() {
		assertTrue(test1.isZero());
		assertTrue(test9.isZero());
		assertTrue(test10.isZero());// above 3 is to test different 0 Hugeinteger constructed
									//by different constructor
		assertFalse(test2.isZero());
		assertFalse(test3.isZero());
		assertFalse(test4.isZero());
		assertFalse(test6.isZero());	
	}

	@Test
	public void testAdd() {
		assertEquals("300000",test3.add(test4).toString());//add same size integer
		assertEquals("300000",test4.add(test3).toString());
		assertEquals("123990",test3.add(test8).toString());//add different size integer
		assertEquals("123990",test8.add(test3).toString());//switch order to see if size difference 
														   // will have problem
	}
	
	@Test
	public void testMultiply(){
		assertEquals("",(test1.multiply(test3)).toString());
		assertEquals("13653",(test11.multiply(test12)).toString());
		
		
	}
	
	@Test
	public void testToString() {
		assertEquals("0",test1.toString());
		assertEquals("123456",test2.toString());
		assertEquals("123456",test3.toString());
		assertEquals("123456",test6.toString());
		assertEquals("",test9.toString()); 
		assertEquals("000000",test10.toString());
		
	}

}
