
public class test {


	
	public static void main(String[] args) {
		BinarySearchTree<Integer> st = new BinarySearchTree<Integer>();
		st.insert(5);
		st.insert(3);
		st.insert(7);
		st.insert(2);

		st.insert(4);
		st.insert(6);
		st.insert(9);
		st.insert(8);
		
		System.out.print();
		System.out.println(st.getInterval(-1,5));
		for(Integer i : st){
			System.out.println(i);
		}
		
		
	}

}
