package recursive;

public class recursive {
	public static double power(double x, double n){
		if (n<0){
			n= -n;
			if(n==0){
				return 1;
			}
			else{
				return (1/x)*power(x,-(n-1));
			}
				
		}
		else{
			if(n==0){
				return 1;
			}
			else{
				return x*power(x,n-1);
			}
		}
	}

	public static int square(int x){
		if(x==0){
			return 0;
		}
		else{
			return x*x+square(x-1);
		}
		
	}
	
	
	public static void writeVertical(int x){
		if(x<10){
			System.out.println(x%10);
		}
		else{
			System.out.println(x%10);
			writeVertical((x-x%10)/10);
		}
	}
	
	
	public static void main(String args[]){
		System.out.println(power(2,4));
		System.out.println(power(2,-4));
		System.out.println(square(3));
		System.out.println(square(5));
		writeVertical(123489);
	}
}
