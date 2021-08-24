import java.util.*;

public class Person implements Comparable<Person> {
	private String firstName, lastName;
	private List<Person> children;
	private Person spouse;
	
	public Person(String f, String l){
		firstName=f;
		lastName=l;
		spouse=null;
		children=new LinkedList<Person>();
	}
	
	public void getMarried(Person sp) throws IllegalArgumentException{
		if(this.spouse!=null||sp.spouse!=null){
			throw new IllegalArgumentException("They are already married!");
		}
		else if(this.spouse==null&&sp.spouse==null){
			this.spouse=sp;
			sp.spouse=this;
		}
	}
	
	public void getDivorced() throws IllegalArgumentException{
		if(this.spouse==null){
			throw new IllegalArgumentException("Thie Person is not Married!!!");
		}
		else{
			this.spouse=null;
			spouse.spouse=null;
		}
	}
	
	public boolean addChild(Person child){
		if (this.children.contains(child)==true){
			return false;
		}
		else{
			this.children.add(child);
			return true;
		}
	}
	
	public boolean equals(Object o){
		//if(o instanceof Person)
		return this.compareTo((Person)o)==0;
	
	}
	
	@Override
	public int compareTo(Person p) {
		int compare;
		compare=this.lastName.compareTo(p.lastName);
		if(compare==0)
			compare=this.firstName.compareTo(p.firstName);	
		return compare;
	}
	
	//getter
	public String getFname(){
		return this.firstName;
	}
	public String getLname(){
		return this.lastName;
	}
	public Person getSpouse(){
		return this.spouse;
	}
	public LinkedList getChildren(){
		return (LinkedList) this.children;
	}
	
	//to String
	public String toString(){
		return "["+this.firstName+" "+this.lastName+ "]";
	}
	
	
	public static void main(String args[]){
		Person Ali=new Person("Joe", "Ye");
		Person YZ=new Person("Rachael", "Feng");
		Person HaiZi=new Person("BlackHole", "Lucky Star");
		Ali.getMarried(YZ);
		Ali.addChild(HaiZi);
		
		System.out.println("Ali's Spouse is : "+ Ali.getSpouse());
		System.out.println("Ali's Children are "+Ali.getChildren());
		System.out.println(Ali.toString());
		System.out.println(Ali.equals(YZ));
		System.out.println(Ali.compareTo(YZ));
		
	}
	
}
