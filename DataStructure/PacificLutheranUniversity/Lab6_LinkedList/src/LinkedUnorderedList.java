/*Name: Tianhua Fang
  Assignment: Lab 06
  Title: Linked Lists
  Course: CSCE 270
  Lab Section: Lab02
  Semester: Fall, 2014
  Instructor: Laurie Murphy
  Date: November 1st
  Sources consulted: Lab Handout, textbook
  Program description:  This program is to give a certain methods for UnorderedList,
  						1. It has addToFront, addToRear, addAfter method to add element 
  						to a list.						
  						2. It has remove, remove last to remove an element from a list. 
  						3. toString and recursiveToString methods will give a String and its
  						   reversed form of a list.
  						4. Indexof and LaseIndexof will give you the index of a given element if 
  							it is inside the list.
  						   Last and First methods will return the last and the first element
  						   of the list.
  						5. clear method will make the list become empty.
  						   size method will give the size of the list.
  						   Contain method will tell whether the element is inside the list.
  Known Bugs: NA
  Creativity: reverseToString - Use recursive to reverse the list and print out the String form  
*/

/**LinkedUnorderedList represents a singly linked implementation of an 
 * unordered list.
 *
 * @author Lewis and Chase
 * @version 4.0
 */
public class LinkedUnorderedList<T> extends LinkedList<T> 
         implements UnorderedListADT<T>
{
    /**
     * Creates an empty list.
     */
    public LinkedUnorderedList()
    {
        super();
    }

    /**
     * Adds the specified element to the front of this list.
     *
     * @param element the element to be added to the list
	 */
    public void addToFront(T element)
    {	
    	LinearNode<T> temp=new LinearNode<T>();
    	temp.setElement(element);
    	if(this.count==0){
    		head=temp;
    	}
    	else{
    		temp.setNext(head);
    		head=temp;
    	}
    	count++;
    	modCount++;
        // To be completed as a Programming Project
    }
	
	/**
     * Adds the specified element to the rear of this list.
     *
     * @param element the element to be added to the list
	 */
    public void addToRear(T element)
    {	
    	LinearNode<T> temp=new LinearNode<T>();
    	temp.setElement(element);
        if (head == null){
            head = temp;//if it is an empty List
        } 
        else {
        	LinearNode<T> current = head;
            while(current.getNext() != null){
                 current = current.getNext();
            }
            current.setNext(temp);
        }
    	tail=temp; //set tail
    	
    	count++;
    	modCount++;
        // To be completed as a Programming Project
    }
	
	
    /**
     * Adds the specified element to this list after the given target.
     *
     * @param  element the element to be added to this list
	 * @param  target the target element to be added after
	 * @throws ElementNotFoundException if the target is not found
	 */
    public void addAfter(T element, T target)
    {
 
    	if(this.contains(target)==false)
    		throw new ElementNotFoundException("Element not FOund");
    	
    	LinearNode<T> temp=new LinearNode<T>();
    	LinearNode<T> current=head;
    	LinearNode<T> pre=new LinearNode<T>();
    	
    	temp.setElement(element);
    	
    	if(this.indexOf(target)==count||this.count==1){
    		this.addToRear(element);// use addrear method if object is at last
    	}

    	else{
    		while(current.getNext()!=null){
    			pre=current;
    			current=current.getNext();
    			if(pre.getElement().equals(target)==true){
    				pre.setNext(temp);
    				temp.setNext(current);
    			break;
    			}

    		}	
    	
    	}
    	count++;
    	modCount++;
        // To be completed as a Programming Project
    }
    

}
