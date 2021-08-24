import java.util.PriorityQueue;
import java.util.ArrayList;
import java.util.Collections;
import java.util.List;

public class KBestCounter<T extends Comparable<T>> {
	int count;
    PriorityQueue<T> heap;

    public KBestCounter(int k) {
    	heap = new PriorityQueue<T>();
        count=k;
    }

    public void count(T x) {
    	if(this.heap.size()<this.count){
    		this.heap.add(x);
    	}
    	else{
    		this.heap.add(x);
    		this.heap.remove();
    	}
    	
    }

    public List<T> kbest() {
    	ArrayList<T> l = new ArrayList<>(this.count);
    	for(T i: this.heap){
    		l.add(i);
    	}
    	Collections.sort(l);
    	Collections.reverse(l);  //reverse the list as required(eror message)
        return l; 
    } 

}
