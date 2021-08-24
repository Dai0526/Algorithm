/*Name: Tianhua Fang
  Assignment: Lab 03
  Title: ArrayList and HugeInteger
  Course: CSCE 270
  Lab Section: 02
  Semester: Fall, 2014
  Instructor: Laurie Murphy
  Date: October 4th
  Sources consulted: Lab Instructions
  Program description: This problem is to use ArrayList to store Integers, so we can operate
  					   some algorithms with huge integers. 
  					   It contains 3 constructors to construct HugeInteger objects by different 
  					   type of input. 
  					   Addition and multiplication functions offers some basic math operations 
  					   with HugeInteger. 
  					   CompareTo and Equal method help to compare two HugeIntegers. 
  					   toString function print the object in a neat and clean form.
  					    
  Known Bugs: 1. Constructor with leading zero input integer will give you a wrong number which is a 
  			octal of the input. For example, HugeInteger(020) will give you a numer 16 instead of 20.
  			This is caused by Java.
  			
  			  2. When a 0 HugeInteger multiply any HugeInteger object, the result will be an empty object
  			  instead of 0 HugeInteger. 
  Creativity: 1. Add multiplication method.
*/
import java.util.ArrayList;



public class HugeInteger implements Comparable<HugeInteger> {
	private ArrayList<Integer> digits;
	
	/**
	 * initializes the HugeInteger to 0 (one digit with the value 0)
	 */
	public HugeInteger(){
		digits= new ArrayList<Integer>();
		digits.add(0);
	}
	/**
	 * initialize a HugeInteger to the string of digits in s and throws
	 *  an InputMismatchException if there are characters in s that are
	 *  not digits
	 * @param s
	 */
	public HugeInteger(String s){
		int size=s.length();
		digits=new ArrayList<Integer>(size);
		for(int i=size-1;i >= 0;i--){
			char c=s.charAt(i);
			if(c>='0' && c<='9'){
			this.digits.add(new Integer( c-'0'));
			}
		}		
	}
	
	
	/**
	 * initialize a HugeInteger to an integer i
	 * @param i
	 */
	public HugeInteger(int num){
		digits=new ArrayList<Integer>();
		while(num>0){
			digits.add(num%10);
			num=num/10;
			}
			
	}
	

	/**
	 * This method will return true if this HugeIntegers is equal to
	 *  HugeInteger o and false otherwise;
	 *  
	 * @param o HungeInteger
	 * @return  true for equal and false for different
	 */
	public boolean equal(HugeInteger o){

		return this.compareTo(o)==0;
	}//is Equal
	
	/**
	 * 	This method is to compare Two hungeInteger
	 * 	return 1 if this is greater than o
	 *  return 0 if this is equal to o
	 *  return -1 if this is less than o
	 */

	public int compareTo(HugeInteger o){
		this.RemoveLeadingZero();
		o.RemoveLeadingZero();
		int temp=0;
		if (this.digits.size()<o.digits.size()){
			temp=-1;
		}
		else if(this.digits.size()> o.digits.size()){
			temp=1;
		}
		else{
			for(int i=this.digits.size()-1; i>=0; i=i-1){
				if(this.digits.get(i)<o.digits.get(i)){
					temp=-1;
				}
				else if(this.digits.get(i) > o.digits.get(i)){
					temp= 1;
				}
				else{
					temp=0;
				}
			}
		}
		return temp;
	}
	
	/**
	 * This method is to check if a hugeInteger is 0;
	 * @return true it this is 0, or false for otherwise;
	 */
	public boolean isZero(){
		boolean zero=true;
		for(int i=0;i<this.digits.size();i++){
			if(this.digits.get(i)!=0)
				zero=false;
		}
		return zero;
	}
	
	/**
	 * This method is to add two HugeIntegers
	 * @param rhs A hugeInteger to be added
	 * @return a sum in a new HugeInteger 
	 */
	public HugeInteger add(HugeInteger rhs){
		int temp=0;
		int sum=0;
		int size1=this.digits.size();
		int size2=rhs.digits.size();
		HugeInteger memory = new HugeInteger();
		memory.digits.remove(0);
		if(size1<size2){   // add the short size part first
			for(int i=0;i<size1;i++){
				sum=this.digits.get(i)+rhs.digits.get(i)+temp;
				if (sum>=10){
					memory.digits.add(sum%10);
					temp=1;
				}
				else{
					memory.digits.add(sum);
					temp=0;
				}
				
			}
			for(int i=this.digits.size(); i<size2;i++){//then add the rest part of the 
				sum=rhs.digits.get(i)+temp;                // longer hugeInteger
				if (sum>=10){
					memory.digits.add(sum%10);
					temp=1;
				}
				else{
					memory.digits.add(sum);
					temp=0;
				}
			}
		}//end if this is shorter than rhs
		else if(size1>size2){  // Same as the last part
			for(int i=0;i<size2;i++){
				sum=this.digits.get(i)+rhs.digits.get(i)+temp;
				if (sum>=10){
					memory.digits.add(sum%10);
					temp=1;
				}
				else{
					memory.digits.add(sum);
					temp=0;
				}
				
			}
			for(int i=size2; i<size1;i++){
				sum=this.digits.get(i)+temp;
				if (sum>=10){
					memory.digits.add(sum%10);
					temp=1;
				}
				else{
					memory.digits.add(sum);
					temp=0;
				}
			}
			
		}// end---- if rhs is shorter than this 
		else{
			for(int i=0;i<size1;i++){
				sum=this.digits.get(i)+rhs.digits.get(i)+temp;
				if (sum>=10){
					memory.digits.add(sum%10);
					temp=1;
				}
				else{
					memory.digits.add(sum);
					temp=0;
				}
			
			}
		}//end-- when this is eauql size as rhs
		return memory;
	}

	/**
	 * This method is to multiply two HugeIntegers
	 * @param rhs A hugeInteger to be multiplied
	 * @return the result in a new HugeInteger 
	 */
	public HugeInteger multiply(HugeInteger rhs){
		HugeInteger mult = new HugeInteger();
		mult.digits.remove(0);//remove the default 0 position"0";
		int carry=0;
		int size1=rhs.digits.size();
		int size2=this.digits.size();
		
		for(int i=0;i<size1;i++){
			for(int j=0;j<size2;j++){
				carry=(int) (carry+rhs.digits.get(i)*this.digits.get(j)*Math.pow(10.0,j+i));
			}
		}
		//store result into HugeInteger type array
		int size=Integer.toString(carry).length();
		digits=new ArrayList<Integer>(size);
		while(carry>0){
			mult.digits.add(carry%10);
			carry=carry/10;
			}

		return mult;
	}
	/**
	 * ToString method to return a string to represent this hugeInteger
	 */
	public String toString(){
        String ans="";
		for(int i=this.digits.size()-1;i>=0;i--)  
           ans=ans+this.digits.get(i);  
		
		return ans;
	}
	/**
	 * This method is to remove the leading 0 for a HugeInteger
	 */
	public void RemoveLeadingZero(){
		int size=this.digits.size();
		while(size>=0&&this.digits.get(size-1)==0){
			this.digits.remove(size-1);
			size--;
		}
	}

}//end
