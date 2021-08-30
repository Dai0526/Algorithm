import static org.junit.Assert.*;
import java.io.FileNotFoundException;
import org.junit.Test;
import org.junit.Before;


public class MatrixTest {
	private Matrix test1;
	private Matrix test2;
	private Matrix test3;
	private Matrix test4;
	private Matrix test5;
	private Matrix test6;
	
	@Before
	public void setUp() throws Exception {
		test1 = new Matrix(2,2);
		test2 = new Matrix(3,3);
		test3 = new Matrix();
		test4 = new Matrix(3,4);
		test5 = new Matrix(2,2);// construct 5 matrixes, two with same dimension.
	}	

	@Test
	public void testMatrixIntInt() {
		assertEquals(2,test1.getRows());
		assertEquals(2,test1.getColumns());// check numbers of rows and columns.
		
	}

	@Test
	public void testMatrix() {
		assertEquals(2,test3.getRows());
		assertEquals(2,test3.getColumns());// check nymers of rows and columns.
		
	}

	@Test
	public void testMatrixMatrix() {
		test6=new Matrix(test1);
		assertEquals(0,test6.getElement(0, 1));
		assertEquals(2,test6.getRows());
		assertEquals(2,test6.getColumns());
		
	}
	@Test
	public void testMatrixString() throws FileNotFoundException {
		test6=new Matrix("MatrixA.txt"); //read file MatrixA.txt
		assertEquals(3,test6.getRows()); 
		assertEquals(4,test6.getColumns()); // check row and columns information
		assertEquals(1,test6.getElement(0, 0));
		assertEquals(2,test6.getElement(1, 1));
		assertEquals(3,test6.getElement(2, 2));
		assertEquals(4,test6.getElement(2, 3));// check 4 elements to see if it is correct
}

	@Test
	public void testGetColumns() {
		assertEquals(2,test3.getColumns());
		assertEquals(2,test1.getColumns());
		assertEquals(4,test4.getColumns());
		
	}

	@Test
	public void testGetRows() {
		assertEquals(2,test3.getRows());
		assertEquals(2,test1.getRows());
		assertEquals(3,test4.getRows());
		
	}

	@Test
	public void testSetElement() {
		test2.setElement(2, 2, 2);
		assertEquals(2,test2.getElement(2, 2));
	
	}

	@Test
	public void testGetElement() {
		assertEquals(0, test1.getElement(1, 1));
		assertEquals(0, test1.getElement(0, 1));
	
	}

	@Test
	public void testToString() {
		assertEquals("This is a Matrix with 2 rows and 2 columns", test1.toString());
		assertEquals("This is a Matrix with 3 rows and 4 columns", test4.toString());
		assertEquals("This is a Matrix with 2 rows and 2 columns", test3.toString());
	
	}

	
	
	@Test
	public void testPlus() {
		test1=test1.plus(test5);  
		assertEquals(0,test1.getElement(0,0));
		assertEquals(0,test1.getElement(0,1));
		assertEquals(0,test1.getElement(1,0));
		assertEquals(0,test1.getElement(1,1));// check each element of the result

	}
	@Test
	public void testTimes(){
		test1.setElement(0, 0, 2);// make matrix test1 become 2 2
		test1.setElement(0, 1, 2);//                          0 0 
		test5.setElement(0, 0, 2);// make matrix test5 become 2 3
		test5.setElement(0, 1, 3);//                          0 0
		Matrix temp=new Matrix(2,2);
		temp=test1.times(test5);  //create a new matrix to store the result of multiplication
		assertEquals(4,temp.getElement(0,0));
		assertEquals(6,temp.getElement(0,1));
		assertEquals(0,temp.getElement(1,0));
		assertEquals(0,temp.getElement(1,1));// check each positon to to see if it is correct
	}

	@Test
	public void testMinus() {
		test1=test1.minus(test5);
		assertEquals(0,test1.getElement(0,0));
		assertEquals(0,test1.getElement(0,1));
		assertEquals(0,test1.getElement(1,0));
		assertEquals(0,test1.getElement(1,1));//check each positon to to see if it is correct
		
	}

	@Test
	public void testIsDiagonal() {
		assertEquals(true, test1.isDiagonal()); // check if test1 is diagonal
		assertEquals(false, test4.isDiagonal());// check if test 4 is not diagoanl
		
	}

	@Test
	public void testIsEqual() {
		boolean equal=Matrix.isEqual(test1,test5);// check if test1 and test5 is the same 
		assertTrue(equal);
	}

}
