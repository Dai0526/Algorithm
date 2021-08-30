
public class RationalNumber {
	private int numerator;
	private int denominator;
	private static int count=0; //????
	
	public RationalNumber(int numer, int denom) {
		numerator= numer;
		denominator = denom; // this.denominator is from object class
		count++;	
	}
	public RationalNumber(int numer){
		numerator = numer;
		denominator =1;
		count++;
	}
	public RationalNumber(){
		numerator = 0;
		denominator = 1;
		count++;
	}
	public static int getCount(){
		return count; // to count how many times that we make rational number
		
	}
	
	public boolean equals(RationalNumber other){ 
		double num1 = (double)numerator/denominator; // we need to cast the type of variable especailly in the division
		double num2 = (double)other.numerator/other.denominator;
		return (Math.abs(num1-num2)<0.0000001);
	}
	/**
	 * @return the numerator
	 */            
	public int getNumerator() {
		return numerator;
	}
	/**
	 * @param numerator the numerator to set
	 */
	public void setNumerator(int numerator) {
		this.numerator = numerator;
	}
	/**
	 * @return the denominator
	 */
	public int getDenominator() {
		return denominator;
	}
	/**
	 * @param denominator the denominator to set
	 */
	
	// sbovr part is added from Source menu->Add getter and setter
	
	public void setDenominator(int denominator) {
		this.denominator = denominator;
	}
	
	public RationalNumber multiply( RationalNumber op2){ // This method is to multiply 
		
		RationalNumber ans = new RationalNumber(); // creating nwe numeraor to hold the ans
		ans.setNumerator(this.numerator* op2.numerator);   // which ans is n=0 ,d =1; Pass r2 = op2
		ans.setDenominator(this.denominator*op2.denominator);   // 
		return ans;
	}
	
	public static void swap(RationalNumber n1, RationalNumber n2){
		int temp=n1.getNumerator();
		n1.setNumerator(n2.getNumerator()); // Beong the method, so it inside
		n2.setNumerator(temp);
		temp=n1.getDenominator();	
		n1.setDenominator(n2.getDenominator()); 
		n2.setDenominator(temp);		
	}
	
	public String toString() {
		// which overwritting the main class
		if (denominator ==1)
			return "" + numerator;
		else 
			return numerator+ "/" + denominator;
	}
}
