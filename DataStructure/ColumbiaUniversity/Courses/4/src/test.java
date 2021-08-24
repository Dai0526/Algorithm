
public class test {
	public static void main(String args[]){
		AvlMap test = new AvlMap<>();
		test.put(1,"a");
		test.put(2,"b");
		test.put(3,"c");
		//System.out.println(test.get(100));
		
		SeparateChainingMap sc =new SeparateChainingMap();
		//sc.put(3, "c");
		//sc.put(2, "a");
		//sc.put(1, "b");
		//sc.put(3, "qq");
		for(int i=0;i<720;i++){
			sc.put(i, i+" ");
		}

		System.out.println(sc.getTableSize());
		System.out.println(sc.getSize());
		
		for(int i=0;i<720;i++){
			System.out.println(sc.get(i)==null);
			System.out.println(i);
		}
	}
}
