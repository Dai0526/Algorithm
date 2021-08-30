/**
 * In-class Queue practice - you are encouraged to work with a partner
 * (1) Finish the CircularArrayQueue implementation of the QueueADT 
 *     by implementing isEmpty() size() and toString()
 * (2) Implement and test the client methods below 
 * (3) Submit one printout of QueuePractice.java 
 *    
 * @author Edwin Chan, TianHua
 * @date  10/10/2014
 */
public class QueuePractice {
	
	public static void main(String[] args) 
	{
		QueueADT<String> queue = new CircularArrayQueue<String>();
		
		// push several Strings objects onto the queue and 
		// use the toString method to display the queue 
		// contents as you implement and test each method
		
		queue.enqueue("A");
		queue.enqueue("B");
		queue.enqueue("C");
		queue.enqueue("A");
		queue.enqueue("D");
		queue.enqueue("E");
		queue.enqueue("F");
		queue.enqueue("55");
		
		
		//removeLast(queue);
		//reverse(queue);
		//replaceAll(queue, "A", "x");
		
		swapFirstAndLast(queue);
		
		System.out.println(queue);
		
	}
	/**
	 * (a) Implement the method below that swaps the 
	 *     first and last elements in the queue q
	 *     leaving the queue unchanged if size <= 1
	 *     
	 * @param q - queue on which elements are to be swapped
	 */
	public static <T> void swapFirstAndLast(QueueADT<T> q) {
		
		T first = q.dequeue();
		QueueADT<T> temp = new CircularArrayQueue<T>();
		
		int x = 0;
		int size = q.size();
		
		while(x < size - 1){
			temp.enqueue(q.dequeue());
			x++;
		}
		T last = q.dequeue();
		
		
		q.enqueue(last);
		while(temp.isEmpty() != true){
			q.enqueue((T)temp.dequeue());
		}
		q.enqueue(first);
			
		

	}

	/**
	 * (b) Implement the method below that removes the last
	 *     element of q leaving q unchanged if already empty 
	 *     
	 * @param q - queue to be modified 
	 */
	public static <T> void removeLast(QueueADT<T> q) {
		
		QueueADT<String> temp = new CircularArrayQueue<String>();
		
		int size = q.size();
		int x = 0;
		
		while(x < size -1){
			temp.enqueue((String)q.dequeue());
			x++;
		}
		
		q.dequeue();
		
		while(temp.isEmpty() != true){
			q.enqueue((T)temp.dequeue());
		}
		
		

	
	}
	
	/**
	 * (c) Implement the method below that replaces every instance 
	 *     of the object x on the queue q with the object y 
         *
	 * @param q - queue to be modified
	 * @param x - value to be replaced
	 * @param y - replacement value
	 */
	public static <T> void replaceAll(QueueADT<T> q, T x, T y) {
		
		QueueADT<T> temp = new CircularArrayQueue<T>();
		int size = q.size();
		
		for(int i = 0; i < size; i++){
			if(q.first() == x){
				temp.enqueue(y);
				q.dequeue();
			} else {
				temp.enqueue(q.dequeue());
			}
			
		}
		
		while(temp.isEmpty() != true){
			q.enqueue(temp.dequeue());
		}

	
	}

	/**
	 * (d) BONUS: Implement the method below that reverses the contents of 
	 *     the queue q 
	 *     HINT: Use a stack 
	 *     
	 * @param q - queue to be modified 
	 */
	public static <T> void reverse(QueueADT<T> q) {
		
		StackADT<T> temp = new ArrayStack<T>();
		
		while(q.isEmpty() == false){
			temp.push(q.dequeue());
		}
		
		while(temp.isEmpty() == false){
			q.enqueue(temp.pop());
		}
		

	
	}	
	
	
}
