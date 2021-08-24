
public class Movie extends EntertainmentItem {
	private String studio;
	private int act=0;
	private int directing=0;
	private int soundtrack=0;
	
	/**
	 * Construct the Movie item with name and its studio
	 * @param name Title of this movie
	 * @param stu  The studio of this movie
	 */
	public Movie(String name, String stu) {
		super(name);
		studio=stu;
		act=0;
		directing=0;
		soundtrack=0;
		// TODO Auto-generated constructor stub
	}
	/**
	 * Construct the Movie item with name, price and its studio
	 * @param name  movie's title 
	 * @param price price
	 * @param stu   studio name
	 */
	public Movie(String name, Double price,String stu) {
		super(name, price);
		studio=stu;
		act=0;
		directing=0;
		soundtrack=0;
		// TODO Auto-generated constructor stub
	}

	/**
	 *  Specify Movie's rating by take average rating of act, directing and soundtrack
	 */
	@Override
	public double rating() {
		int sum=(act+directing+soundtrack);
		double avg=Math.round((sum/3.0)*100.0)/100.0;
		return avg;
	}
	
	//set and get methods
	/**
	 *  studio getter
	 * @return studio
	 */
	public String getStudio() {
		return studio;
	}
	
	/**
	 * studio setter
	 * @param name new studio for this movie
	 */
	public void setStudio(String name) {
		this.studio = name;
	}
	
	/**
	 *  Rating of vocal getter
	 * @return rating of vocal
	 */
	public double getActing() {
		return act;
	}
	
	/**
	 * rating of acting setter
	 * @param newAct new acting rating
	 */
	public void setActing(int newAct) {
		this.act=newAct;
	}

	/**
	 * rating of directing getter
	 * @return rating of directing
	 */
	public double getDirecting() {
		return directing;
	}
	
	/**
	 * Rating of directing setter
	 * @param newD new rating of directing
	 */
	public void setDirecting(int newD) {
		this.directing=newD;
	}
	/**
	 * Rating of Sound track getter
	 * @param newD  rating of sound track
	 */
	public double getSoundtrack() {
		return soundtrack;
	}
	/**
	 * Rating of Sound track setter
	 * @param newD new rating of sound track
	 */
	public void setSoundtrack(int newS) {
		this.soundtrack=newS;
	}
	/**
	 * Tostring method to print the information of movie
	 */
	public String toString(){
		return super.toString()+" "+studio+ " , Rating: "+ this.rating();
		
	}

}
