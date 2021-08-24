
public class Album extends EntertainmentItem {
	private String artist;
	private int vocal =0;
	private int accompaniment=0;
	private int lyrics=0;
	
	//Constructor
	/**
	 * 	/**
	 * Construct the Movie item with name and its studio
	 * @param name
	 * @param art
	 */
	public Album(String name, String art) {
		super(name);
		artist=art;
		this.vocal =0;
		this.accompaniment=0;
		this.lyrics=0;
		// TODO Auto-generated constructor stub
	}
	/**
	 * 	/**
	 * Construct the Album item with name, price and its artist
	 * @param name title
	 * @param price price
	 * @param art artist
	 */
	public Album(String name, Double price, String art) {
		super(name, price);
		artist=art;
		this.vocal =0;
		this.accompaniment=0;
		this.lyrics=0;
		// TODO Auto-generated constructor stub
	}
	/**
	 * Specify Album's rating by its vocal, accompaniment and lyrics
	 */
	@Override
	public double rating() {
		double sum=this.getVocal()+this.getAccompaniment()+this.getLyrics();
		double avg=sum/3.0;
		avg=Math.round(avg*100.0)/100.0;
		return avg;
	}
	
	/**
	 * Rating of Artist getter
	 */
	public String getArtist() {
		return this.artist;
	}
	/**
	 * Rating of Artist setter
	 * @param art
	 */
	public void setArtist(String art) {
		this.artist = art;
	}
	
	/**
	 * Rating of vocal getter
	 * @return rating of vocal
	 */
	public double getVocal() {
		return this.vocal;
	}
	/**
	 * rating of vocal setter
	 * @param newVocal rating of vocal
	 */
	public void setVocal(int newVocal) {
		this.vocal=newVocal;
	}
	/**
	 * Rating of accompaniment getter
	 * @return rating of accompaniment
	 */
	public double getAccompaniment() {
		return this.accompaniment;
	}
	
	/**
	 * rating of accompaniment setter
	 * @param newA
	 */
	public void setAccompaniment(int newA) {
		this.accompaniment=newA;
	}
	/**
	 * rating of lyrics getter
	 * @return rating of lyrics
	 */
	public double getLyrics() {
		return this.lyrics;
	}
	/**
	 * rating of lyric setter
	 * @param newLyric new rating of lyrics
	 */
	public void setLyrics(int newLyric) {
		this.lyrics=newLyric;
	}
	
	/**
	 *toString method to print the information about Ablum item 
	 */
	public String toString(){
		return super.toString()+" "+artist+ ", Rating: "+ this.rating();
	}
}
