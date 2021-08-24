import java.util.*;
public class test {
	public static void main(String[] args){
		SimpleLinkedList<String> ls = new SimpleLinkedList<>();
		
		ls.add("a");
		ls.add("b");
		ls.add("c");
		ls.add("d");
		ls.add("e");
		ls.add("f");
		ls.flip();
		System.out.println(ls);
	}
}
