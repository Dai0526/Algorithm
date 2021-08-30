//this class is to create a position unit in2D that in form of (row,col)
// It will be store in queue to solve maze
public class Position {
	private int row;
	private int col;
	
	//default constructor
	/**
	 * Default constructor to build a position object
	 */
	public Position(){
		col=0;
		row=0;	
	}
	/**
	 * Constructor a posiiton object with row and col
	 * @param r # of row
	 * @param c # of col
	 */
	//constructor with row and col
	public Position(int r, int c){
		col=c;
		row=r;	

	}
	
	//get and set
	public int getRow(){
		return this.row;
	}
	public int getCol(){
		return this.col;
	}
	/**
	 * Row Setter
	 * @param r new Row
	 */
	public void setRow(int r){
		this.row=r;
	}
	/**
	 * Col Setter
	 * @param c new Col
	 */
	public void setCol(int c){
		this.col=c;
	}
	
}
