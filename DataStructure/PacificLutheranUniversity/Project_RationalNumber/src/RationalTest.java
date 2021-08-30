/**
 * 
 */

/**
 * @author CSCEUser
 *
 */
public class RationalTest {
	public static void main(String[] args) {
		RationalNumber r1 = new RationalNumber(1,2);
		RationalNumber r2 = new RationalNumber(4,8);
		RationalNumber r3 = new RationalNumber(3,7);
		RationalNumber r4= new RationalNumber(0,1);
		RationalNumber r5= new RationalNumber(1);
		// TODO Auto-generated method stub
		
		System.out.println("r1 = "+ r1.toString());
		System.out.println("r2 = "+ r2.toString());
		System.out.println("r3 = "+ r3.toString());
		System.out.println("r4 = "+ r4.toString());
		System.out.println("r5 = "+ r5.toString());
		
		RationalNumber r6= r3.multiply(r1);
		System.out.println("r6 = "+ r6.toString());
		// Example: store value to anoher operator
		// only when a variable was assign to a object
		// But if an object was assigned to an object, it will link to the 
		// same reference, so both of them will change when the reference changes.
		// SEE TOPHAT QUIZ "OBJECT REFERENCE AND ASSIGNMENT" PARRT
		int x=5;
		 int y=7;
		 x=y;
		 y=10;
		 System.out.println(x+ " "+ y);
		 
		 RationalNumber.swap(r1, r2);
		 System.out.println("After Swap"+ r1+r2 );// swap
		 
		 System.out.println("Count : it counts "+ RationalNumber.getCount()+"times");
		 
		 RationalNumber r7 = new RationalNumber(5,10);
		 if (r6==r2) // checking if there is the same address(same point which refers to)
			 System.out.println("equal");
		 else
			 System.out.println("not equal");
		 if (r6.equals(r2)) // if the address is the same or not
			 System.out.println("equal");
		 else
			 System.out.println("not equal");
			 
	}

}
