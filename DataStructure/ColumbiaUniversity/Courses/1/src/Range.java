
/**
 * Simulates python's range function
 */
public class Range implements Iterable<Integer> {

	private SimpleLinkedList<Integer> numbers;
	
	/**
	 * It will create a LinkedList to present a series number
	 * with same increment.
	 * @param start Leading number
	 * @param stop  Ending number(not show up in the list)
	 * @param incr  Increment  
	 */
	public Range(int start, int stop, int incr) {
		// change this
		numbers=new SimpleLinkedList<Integer>();
			if(incr>0){                                 
				for(int i=start; i<stop;i+=incr){
				numbers.add(i);
				}
			}else{                                // When increment is negative number
				for(int i=start; i>stop;i+=incr){
					numbers.add(i);
					}
			}
	}

	/**
	 * It will create a LinkedList to present a series number
	 * with a default increment incr=1.
	 * @param start Starting number
	 * @param stop  Ending but not show up in the list
	 */
	public Range(int start, int stop) {
		// change this
		numbers= new SimpleLinkedList<Integer>();
			for(int i=start; i<stop;i++){
				numbers.add(i);
			}		
	}
	


	public java.util.Iterator<Integer> iterator() {
		/* I discussed this question with my classmate Edwin. 
		 * After ours several trying and testing, it works with this return statement.
		 * But I don't know how it works. In order to call the iterator class in 
		 * the SimpleLinkedList class, I think it should be "return new LinkedListIterator();"
		 *  I hope it is the correct answer.
		 * */
		
		return numbers.iterator();                  
		// change this
		// also understand what this actually does and the easiest way to do this
		// should be a one liner
	}
}
