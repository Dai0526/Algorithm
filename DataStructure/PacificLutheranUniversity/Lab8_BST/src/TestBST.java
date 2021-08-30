
public class TestBST {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		LinkedBinarySearchTree<String> tree=new LinkedBinarySearchTree<String>();
		tree.addElement("f");
		tree.addElement("c");
		tree.addElement("j");
		tree.addElement("a");
		tree.addElement("e");
		tree.addElement("h");
		tree.addElement("b");
		tree.addElement("d");
		tree.addElement("g");
		tree.addElement("i");
		LinkedBinarySearchTree<String> tree2=new LinkedBinarySearchTree<String>();
		System.out.println(tree.toString());
		System.out.println(tree.iteratorInOrder().next());
		//System.out.println(tree.find("a"));
		//System.out.println(tree.size());
		//System.out.println(tree2.size());
		
		//System.out.println(tree.leaves());
		//System.out.println(tree2.leaves());
		//System.out.println(tree.interiorNodes());
		//System.out.println(tree.getHeight());
		//System.out.println(tree2.getHeight());
		
		//System.out.println(tree.contains("a"));
	}

}
