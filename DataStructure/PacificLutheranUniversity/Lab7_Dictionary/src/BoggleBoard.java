import java.io.File;
import java.io.FileNotFoundException;
import java.io.IOException;
import java.util.Scanner;


public class BoggleBoard {
	private int row;
	private int col;
	private String[][] board;
	private String[][] panel;
	private int[][] visited;
	public int score=0;
	
	/**
	 * Boggle board constructor
	 * @param fileName file name in string form
	 * @throws FileNotFoundException file not found exception
	 */
	public BoggleBoard(String fileName) throws FileNotFoundException{	
		panel=loadBoggleBoard(fileName);	
	}
	
	/**
	 * read information from a file
	 * @param fileName file name in String form
	 * @return return a array display board information
	 * @throws FileNotFoundException file not found information
	 */
	public String[][] loadBoggleBoard(String fileName) throws FileNotFoundException{
		File file = new File(fileName);
		Scanner inputFile = new Scanner(file);
			row=col=inputFile.nextInt();
			
			visited=new int[row][col];
			board=new String[row][col];
			for (int i=0;i<row;i++){
				for (int j=0;j<col;j++){
					board[i][j]=inputFile.next();
					visited[i][j]=0;
				}
			}
		inputFile.close();
		return board;		
		//board constructor
	}
	
	
	/**
	 * On board method to call recursive onBoard method 
	 * @param words the words need to be found on board
	 * @return true if can be found on board
	 * 		   flase if it cannot be found
	 */
	public boolean onBoard(String words){
		for (int i = 0; i< this.board.length; i++) {
            for (int j = 0; j < this.board.length; j++) {
            	if (this.recOnBoard(words, i, j)) {
                    return true;
                }
            }
        }
        return false;
		
	}
	/**
	 * Recursive method to found if the words is on the given board
	 * @param words words need to be found
	 * @param row row information
	 * @param col colum information
	 * @return true if the word is on board
	 * 		   false if not found
	 */
	private boolean recOnBoard(String words, int row, int col){
		if(words.equals(""))
			return true;
		if(col>=this.col||col<0||row>=this.row||row<0)
			return false;
		if(this.visited(row, col))
			return false;
		if (this.board[row][col].equals(words.charAt(0)+"")==false)	
			return false;
	
		this.markCellVisited(row, col);
		String restPart=words.substring(1);
		
		for(int i=row-1;i<=row+1;i++){
			for(int j=col-1; j<=col+1;j++){
				if(recOnBoard(restPart,i,j)){
					return true;
				}
			}
		}
		this.markCellopen(row, col);
		return false;
			
		}
		
	//mark visited and check if visited
	/**
	 * Marks a cell of the board to be drawn as visited.
	 * @param r the cell row
	 * @param c the cell column
	 */
	public void markCellVisited( int r, int c ) {
		
		visited[r][c] = 1;
	}
	/** 
	 * Marks a cell of the maze to be drawn as not visited.
	 * @param r the cell row
	 * @param c the cell column
	 */	
	public void markCellopen( int r, int c ){
	
		visited[r][c] = 0;
	}
	/**
	 * Returns whether or not a cell has been marked "visited."
	 * @param r the row number
	 * @param c the column number
	 * @return true if cell (r,c) has been marked visited.
	 */
	public boolean visited( int r, int c ) throws IllegalArgumentException {
		
		return visited[r][c] == 1;
	}
	/**
	 * Clear all the marks
	 */
	public void clearAllMark(){
		for(int i=0;i<board.length;i++){
			for(int j=0;j<board.length;j++){
				visited[i][j]=0;
			}
		}
	}

	/**
	 * ToString method for a boggle board to print 
	 * the board as required
	 */
	public String toString(){
		String ans="";
		for(int i=0; i<this.row;i++){
			for (int j=0;j<this.col;j++){
				 ans=ans+board[i][j]+" ";
			}
			ans=ans+"\n";
		}
		return ans;
	}
	
}
