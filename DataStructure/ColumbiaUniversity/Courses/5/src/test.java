import java.util.ArrayList;
import java.util.Collections;
import java.util.PriorityQueue;

public class test {
	public static void main(String[] args){
	PriorityQueue<Integer> h = new PriorityQueue<Integer>(5);
	PriorityQueue<Integer> h2 = h;
	h.add(5);
	h.add(4);
	h.add(3);
	h.add(2);
	h.add(1);
	h.add(6);
	System.out.println(h.size());
	//System.out.println(h);
	ArrayList<Integer> l = new ArrayList<>(5);
	for(Integer i: h){
		l.add(i);
	}
	Collections.sort(l);
	Collections.reverse(l);
	System.out.println(l);
	System.out.println(h);
	
	}

	
}
