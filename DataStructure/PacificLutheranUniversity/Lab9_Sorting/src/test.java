import java.util.Arrays;


public class test {
	public static <T> void main(String args[]){
		Integer[] array=new Integer[10000];
		array[0]=4;
		array[1]=7;
		array[2]=1;
		array[3]=5;
		array[4]=2;
		array[5]=8;
		array[6]=9;
		array[7]=3;
		array[8]=6;
		for(int i=9;i<10000;i++){
			array[i]=i+1;
		}
		
		//System.out.println(array.toString());
		
		BubbleSort bubbleSort=new BubbleSort();
		Timer timer=new Timer();
		timer.start();
		bubbleSort.sort(array);
		timer.stop();
		System.out.println(Arrays.toString(array));
		System.out.println(timer.getElapsedTime());
	}
}
