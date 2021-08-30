  //Name: Tianhua Fang
  //Assignment: Lab 2
  //Title: Matrix Entertainment Class Hierarchy -- Inheritance, Polymorphism, Files, JUnit Testing
  //Course: CSCE 270
  //Lab Section: 02
  //Semester: Fall, 2014
  //Instructor: Laurie Murphy
  //Date: Sept 27th
  //Sources consulted: java doc, Professor
  //Program description: This EntertainmentItem program is to construct Entertainment Items includes Movie
  //                     and Albums. It will shows item's cost, title, and rating. Movie is rated by
  //                     acting, soundtrack and directing. Album is rated by vocal, lyrics and accompaniment.
  //                     It also contains some basic setter, getter methods and a compare method.
  //                                          
  //                     The Entertainment file is offered by instructor. It can read data from a file. I add
  //                     the sort method to sort Item's by rating. It can sort album by rating of vocal and sort
  //                     movie by rating of acting. You can also sort the data by your budget and title. 
  //Known Bugs:          
  //            
  //Creativity: Add method Comparator to sort items by their title
import java.util.Comparator;

public abstract class EntertainmentItem implements Comparable<EntertainmentItem>{
	private String title;
	private double cost=0.0;
	
	
	/**
	 * This is to construct an Entertainment item with name
	 * @param name The name of this item
	 */
	public EntertainmentItem(String name){
		title= name;
		
	}
	
	/**
	 *  This is to construct an Entertainment item with name and price.
	 * @param name The name of this item
	 * @param price The price of this item
	 */
	public EntertainmentItem(String name, Double price){
		this.title= name;
		this.cost=price;
	}
	
	/**
	 *  This method is to get the average of rating
	 * @return Rating
	 */
	public abstract double rating();
	
	/**
	 * This method is to compare items by thier rating.
	 */
	public int compareTo(EntertainmentItem o){
		if (this.rating() > o.rating())
			return 1;
		else if (this.rating() < o.rating())
			return -1;
		else
			return 0;
	}
	
	/**
	 *  This is the comparator method to compare items' name
	 */
	public static Comparator<EntertainmentItem> titleComparator =new Comparator<EntertainmentItem>(){
		@Override
		public int compare(EntertainmentItem o1, EntertainmentItem o2) {
			
			return o1.title.compareTo(o2.title);
		}
	};
	
	
	//get and set
	/**
	 * Title getter
	 * @return title
	 */
	public String getTitle() {
		return title;
	}
	
	/**
	 * Title setter
	 * @param name The new title 
	 */
	public void setTitle(String name) {
		this.title = name;
	}
	
	/**
	 * Price setter
	 * @param newPrice new Price
	 */
	public void setCost(double newPrice) {
		this.cost=newPrice;
	}
	
	/**
	 * Price getter
	 * @return get the price
	 */
	public double getCost() {
		return cost;
	}
	

	
	/**
	 * This method is to print the information about this item
	 */
	public String toString(){
		return "title is "+title+", and the cost is "+cost+" .";
	}
}// end
