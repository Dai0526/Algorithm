import static org.junit.Assert.*;

import org.junit.BeforeClass;
import org.junit.Test;


public class LinkedBinarySearchTreeTestTest {
	private static LinkedBinarySearchTree<String> tree;
	private static LinkedBinarySearchTree<String> tree2;
	private static LinkedBinarySearchTree<String> tree3;
	@BeforeClass
	public static void setUpBeforeClass() throws Exception {
		tree=new LinkedBinarySearchTree<String>();
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
		
		tree2=new LinkedBinarySearchTree<String>(); //make a copy of tree1
		tree2.addElement("f");
		tree2.addElement("c");
		tree2.addElement("j");
		tree2.addElement("a");
		tree2.addElement("e");
		tree2.addElement("h");
		tree2.addElement("b");
		tree2.addElement("d");
		tree2.addElement("g");
		tree2.addElement("i");
		
		tree3=new LinkedBinarySearchTree<String>();//empty tree
	}


	@Test
	public void testTestToString() {
		assertEquals("(a(b))c((d)e))f((g))h((i)j)",tree.toString());
		assertEquals("",tree3.toString());
	}

	@Test
	public void testTestRemoveMax() {
		assertEquals("j",tree2.removeMax());
		//print all the other element to see if other element get influenced by method
		assertEquals("(a(b))c((d)e))f((g))h((i)",tree2.toString());
	}

	@Test
	public void testTestFindMin() {
		assertEquals("a",tree.findMin());
		assertEquals("a",tree2.findMin());
		//assertEquals("",tree3.findMin()); //get empty exception as expected
	}

	@Test
	public void testTestFindMax() {
		assertEquals("j",tree.findMax());
		assertEquals("j",tree2.findMax());
		//assertEquals("",tree3.findMax()); //get empty exception as expected
	}

	@Test
	public void testTestSize() {
		assertEquals(10,tree.size());
		assertEquals(0,tree3.size());
	}

	@Test
	public void testTestInteriorNodes() {
		assertEquals(6,tree.interiorNodes());
		assertEquals(5,tree2.interiorNodes());//one leaf removed
		assertEquals(0,tree3.interiorNodes());
	}

	@Test
	public void testTestLeaves() {
		assertEquals(4,tree.leaves());
		assertEquals(4,tree2.leaves());
		assertEquals(0,tree3.leaves());
	}

	@Test
	public void testTestGetHeight() {
		assertEquals(3,tree.getHeight());
		assertEquals(3,tree2.getHeight());
		assertEquals(-1,tree3.getHeight());//empty tree is -1
	}

	@Test
	public void testTestContains() {
		assertTrue(tree.contains("a"));//test leaf
		assertTrue(tree.contains("f"));//test root
		assertTrue(tree.contains("c"));//test second level
		assertFalse(tree.contains("z"));//test not contain
	}


	@Test
	public void testTestIteratorInOrder() {
		assertEquals("a",tree.iteratorInOrder().next());
	}

	@Test
	public void testTestIteratorPreOrder() {
		assertEquals("f",tree.iteratorPreOrder().next());
	}

	@Test
	public void testTestIteratorPostOrder() {
		assertEquals("b",tree.iteratorPostOrder().next());
	}

	@Test
	public void testTestIteratorLevelOrder() {
		assertEquals("f",tree.iteratorLevelOrder().next());
	}

}
