import static org.junit.Assert.*;

import org.junit.BeforeClass;
import org.junit.Test;



public class InfixToPostfixTest {
	static String test1="7-3^2";//String with ^
	static String test2="(7-3)*2";//String with ()
	static String test3="((3*4)-(2+5))*4/2";
	static String test4="";// nothing
	static String test5="(6 + 20 ) * 5 - 12 / 4";//String with space inbetween
	static String result1, result2,result3, result4;
	
	@BeforeClass
	public static void setUpBeforeClass() throws Exception {
		test1=InfixToPostfix.convert(test1);
		test2=InfixToPostfix.convert(test2);
		test3=InfixToPostfix.convert(test3);
		test4=InfixToPostfix.convert(test4);
		test5=InfixToPostfix.convert(test5);
		result1=InfixToPostfix.Evalute(test1);
		result2=InfixToPostfix.Evalute(test2);
		result3=InfixToPostfix.Evalute(test3);
		
		
	}

	@Test
	public void testConvert() {

		assertEquals("732^-", test1);
		assertEquals("73-2*",test2);
		assertEquals("34*25+-42/*",test3);
		assertEquals("",test4);
		assertEquals("6  20 +  5 * 12  4/-",test5);
	}

	
	@Test
	public void testEvalute() {
		assertEquals("-2",result1);
		assertEquals("8",result2);
		assertEquals("10",result3);
		
		
	}




}
