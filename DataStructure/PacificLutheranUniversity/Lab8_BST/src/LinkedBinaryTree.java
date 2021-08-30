import java.util.*;

/**
 * LinkedBinaryTree implements the BinaryTreeADT interface
 * 
 * @author Lewis and Chase
 * @version 4.0
 */
public class LinkedBinaryTree<T> implements BinaryTreeADT<T>, Iterable<T>
{
    protected BinaryTreeNode<T> root; 
    protected int modCount;
    
    /**
     * Creates an empty binary tree.
     */
    public LinkedBinaryTree() 
    {
        root = null;
    }

    /**
     * Creates a binary tree with the specified element as its root.
     *
     * @param element the element that will become the root of the binary tree
     */
    public LinkedBinaryTree(T element) 
    {
        root = new BinaryTreeNode<T>(element);
    }
    
    /**
     * Creates a binary tree with the specified element as its root and the 
     * given trees as its left child and right child
     *
     * @param element the element that will become the root of the binary tree
     * @param left the left subtree of this tree
     * @param right the right subtree of this tree
     */
    public LinkedBinaryTree(T element, LinkedBinaryTree<T> left, 
                            LinkedBinaryTree<T> right) 
    {
        root = new BinaryTreeNode<T>(element);
        root.setLeft(left.root);
        root.setRight(right.root);
    }
    
    /**
	 * Returns a reference to the element at the root
	 *
	 * @return a reference to the specified target
	 * @throws EmptyCollectionException if the tree is empty
	 */
	public T getRootElement() throws EmptyCollectionException
	{
	    return getRootNode().getElement();
	}

	/**
     * Returns a reference to the node at the root
     *
     * @return a reference to the specified node
     * @throws EmptyCollectionException if the tree is empty
     */
    protected BinaryTreeNode<T> getRootNode() throws EmptyCollectionException
    {
    	if (root == null) 
    		throw new EmptyCollectionException("Linked Binary Tree");	
        return root;
    }
    
    
    /**
     * Returns true if this binary tree is empty and false otherwise.
     *
     * @return true if this binary tree is empty, false otherwise
     */
    public boolean isEmpty() 
    {
        return (root == null);
    }

    /**
     * Returns the integer size of this tree.
     *
     * @return the integer size of the tree
     */
    public int size() 
    {		
        return size(this.root);
    }
    private int size(BinaryTreeNode<T> node){
    	if(node==null)
    		return 0;
    	else
    		return 1+size(node.getLeft())+size(node.getRight());
    }
    
    /**
     * Returns the number of non-leaf nodes in this tree.
     *
     * @return the integer count of the non-leaf nodes in the tree
     */
    public int interiorNodes() 
    {	
    	if(this.size()==1)
    		return 1;
        return interiorNodes(this.root);
    }
    private int interiorNodes(BinaryTreeNode<T> node){
    	if(node==null)
    		return 0;
    	if(node.getLeft()!=null||node.getRight()!=null)
    		return 1+interiorNodes(node.getLeft())+interiorNodes(node.getRight());
    	else
    		return interiorNodes(node.getLeft())+interiorNodes(node.getRight());
    }

    /**
     * Returns the number of leaf nodes in this tree.
     *
     * @return the integer count of the leaf nodes in the tree
     */
    public int leaves() 
    {
    	if(this.size()==1)
    		return 0;  	
        return leaves(this.root);
    }
    private int leaves(BinaryTreeNode<T> node){
    	if(node==null){
    		return 0;
    	}
    	if(node.getLeft()==null&&node.getRight()==null){
    		return 1; 
    	}
    	else
    		return leaves(node.getLeft())+leaves(node.getRight());
    }
    /**
     * Returns the height of this tree.
     *
     * @return the height of the tree
     */
     public int getHeight()
    {
        
        return height(this.root);
    }
    
    /**
     * Returns the height of the specified node.
     *
     * @param node the node from which to calculate the height
     * @return the height of the tree
     */
    private int height(BinaryTreeNode<T> node) 
    {
       if(node==null)
    	   return -1;//what is the height for a empty binary tree?? )?
       
       return 1+Math.max(height(node.getLeft()), height(node.getRight()));
       
    }
    
    /**
     * Returns true if this tree contains an element that matches the
     * specified target element and false otherwise.
     *
     * @param targetElement the element being sought in this tree
     * @return true if the element in is this tree, false otherwise
     */
    public boolean contains(T targetElement) 
    {
    	return recContains(root, targetElement);
    }
    private boolean recContains(BinaryTreeNode<T> node, T target){
    	if(node==null)
    		return false;
    	if(node.getElement().equals(target))
    		return true;
    	return recContains(node.getLeft(), target)||recContains(node.getRight(),target);
    	
    }
    
    /**
     * Returns a reference to the specified target element if it is
     * found in this binary tree.  Throws a ElementNotFoundException if
     * the specified target element is not found in the binary tree.
     *
     * @param targetElement the element being sought in this tree
     * @return a reference to the specified target
     * @throws ElementNotFoundException if the element is not in the tree
     */
    public T find(T targetElement) throws ElementNotFoundException
    {
        BinaryTreeNode<T> current = findNode(targetElement, root);
        
        if (current == null)
            throw new ElementNotFoundException("LinkedBinaryTree");
        
        return (current.getElement());
    }

    /**
     * Returns a reference to the specified target element if it is
     * found in this binary tree.
     *
     * @param targetElement the element being sought in this tree
     * @param next the element to begin searching from
     */
    private BinaryTreeNode<T> findNode(T targetElement, 
                                        BinaryTreeNode<T> next)
    {
        if (next == null)
            return null;
        
        if (next.getElement().equals(targetElement))
            return next;
        
        BinaryTreeNode<T> temp = findNode(targetElement, next.getLeft());
        
        if (temp == null)
            temp = findNode(targetElement, next.getRight());
        
        return temp;
    }
    
    /**
     * Returns a string representation of this binary tree showing
     * the nodes in an inorder fashion.
     *
     * @return a string representation of this binary tree
     */
    public String toString() 
    {
        return toString(root);
    }
    
    private String toString(BinaryTreeNode<T> node) {
    	if (node==null)
    		return "";//base case
    	return toString(node.getLeft())+" "+ node.getElement()+ " "+toString(node.getRight());
    }

    /**
     * Returns an iterator over the elements in this tree using the 
     * iteratorInOrder method
     *
     * @return an in order iterator over this binary tree
     */
    public Iterator<T> iterator()
    {
        return iteratorInOrder();
    }
    
    /**
     * Performs an inorder traversal on this binary tree by calling an
     * overloaded, recursive inorder method that starts with
     * the root.
     *
     * @return an in order iterator over this binary tree
     */
    public Iterator<T> iteratorInOrder()
    {
       ArrayList<T> tempList = new ArrayList<T>();
        inOrder(root, tempList);
        
        return new TreeIterator(tempList.iterator());
    }

    /**
     * Performs a recursive inorder traversal.
     *
     * @param node the node to be used as the root for this traversal
     * @param tempList the temporary list for use in this traversal
     */
    protected void inOrder(BinaryTreeNode<T> node, 
                          ArrayList<T> tempList) 
    {
        if (node != null)
        {
            inOrder(node.getLeft(), tempList);
            tempList.add(node.getElement());
            inOrder(node.getRight(), tempList);
        }
    }

    /**
     * Performs an preorder traversal on this binary tree by calling 
     * an overloaded, recursive preorder method that starts with
     * the root.
     *
     * @return a pre order iterator over this tree
     */
    public Iterator<T> iteratorPreOrder() 
    {
        //no idea
    	ArrayList<T> tempList = new ArrayList<T>();
        preOrder(root, tempList);
        
        return new TreeIterator(tempList.iterator());
    }

    /**
     * Performs a recursive preorder traversal.
     *
     * @param node the node to be used as the root for this traversal
     * @param tempList the temporary list for use in this traversal
     */
    protected void preOrder(BinaryTreeNode<T> node, 
                           ArrayList<T> tempList) 
    {
    	if (node != null)
        {       
            tempList.add(node.getElement());
            preOrder(node.getLeft(), tempList);
            preOrder(node.getRight(), tempList);
        }
    }

    /**
     * Performs an postorder traversal on this binary tree by calling
     * an overloaded, recursive postorder method that starts
     * with the root.
     *
     * @return a post order iterator over this tree
     */
    public Iterator<T> iteratorPostOrder() 
    {
    	ArrayList<T> tempList = new ArrayList<T>();
        postOrder(root, tempList);
        
        return new TreeIterator(tempList.iterator());
    }

    /**
     * Performs a recursive postorder traversal.
     *
     * @param node the node to be used as the root for this traversal
     * @param tempList the temporary list for use in this traversal
     */
    protected void postOrder(BinaryTreeNode<T> node, 
                            ArrayList<T> tempList) 
    {	
    	if (node != null)
        {       
            
            postOrder(node.getLeft(), tempList);
            postOrder(node.getRight(), tempList);
            tempList.add(node.getElement());
        }
        // To be completed as a Programming Project
    }

    /**
     * Performs a levelorder traversal on this binary tree, using a
     * templist.
     *
     * @return a levelorder iterator over this binary tree
     */
    public Iterator<T> iteratorLevelOrder() 
    {
       ArrayList<BinaryTreeNode<T>> nodes = 
                              new ArrayList<BinaryTreeNode<T>>();
       ArrayList<T> tempList = new ArrayList<T>();
        BinaryTreeNode<T> current;

        nodes.add(root);
        
        while (!nodes.isEmpty()) 
        {
            current = nodes.remove(0);
            
            if (current != null)
            {
                tempList.add(current.getElement());
                if (current.getLeft() != null)
                    nodes.add(current.getLeft());
                if (current.getRight() != null)
                    nodes.add(current.getRight());
            }
            else
                tempList.add(null);
        }
        
        return new TreeIterator(tempList.iterator());
    }
    
    /**
     * Inner class to represent an iterator over the elements of this tree
     */
    private class TreeIterator implements Iterator<T>
    {
        private int expectedModCount;
        private Iterator<T> iter;
        
        /**
         * Sets up this iterator using the specified iterator.
         *
         * @param iter the list iterator created by a tree traversal
         */
        public TreeIterator(Iterator<T> iter)
        {
            this.iter = iter;
            expectedModCount = modCount;
        }
        
        /**
         * Returns true if this iterator has at least one more element
         * to deliver in the iteration.
         *
         * @return  true if this iterator has at least one more element to deliver
         *          in the iteration
         * @throws  ConcurrentModificationException if the collection has changed
         *          while the iterator is in use
         */
        public boolean hasNext() throws ConcurrentModificationException
        {
            if (!(modCount == expectedModCount))
                throw new ConcurrentModificationException();
            
            return (iter.hasNext());
        }
        
        /**
         * Returns the next element in the iteration. If there are no
         * more elements in this iteration, a NoSuchElementException is
         * thrown.
         *
         * @return the next element in the iteration
         * @throws NoSuchElementException if the iterator is empty
         */
        public T next() throws NoSuchElementException
        {
            if (hasNext())
                return (iter.next());
            else 
                throw new NoSuchElementException();
        }
        
        /**
         * The remove operation is not supported.
         * 
         * @throws UnsupportedOperationException if the remove operation is called
         */
        public void remove()
        {
            throw new UnsupportedOperationException();
        }
    }
}

