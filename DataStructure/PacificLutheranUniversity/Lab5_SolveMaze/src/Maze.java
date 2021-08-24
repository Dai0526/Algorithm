import java.awt.Color;
import java.awt.Graphics;
import java.io.File;
import java.io.IOException;
import java.util.ArrayList;
import java.util.Scanner;

/**
 * The model for a maze.  A maze consists of a grid of cells.  Each
 * cell is either a wall or open space.  One of the (open space) cells is 
 * the start location, and another is the goal.  Mazes can be loaded
 * from text files.  The text file format is simply a set of lines,
 * each line representing a row of cells.  Each cell is a single 
 * character: '#' represents a wall, '.' represents open space,
 * 'o' represents the starting point, and '*' represents the goal.
 * 
 * @author David Wolff
 *
 */
public class Maze {
	private int rows;
	private int cols;
	private char[][] maze;
	private int[][] visited;
	private int goalRow, goalCol;
	private int startRow, startCol;
	
	private static final int BUFFER = 4;
	
	/**
	 * Creates a new Maze by loading data from a file.
	 * 
	 * @param fname the name of the file to load the maze data from.
	 * @throws IOException if an error occurs during file reading.
	 */
	public Maze(String fname) throws IOException {
		loadMaze(fname);
	}
	
	/**
	 * Returns the total number of rows in this Maze.
	 * 
	 * @return the number of rows in this Maze.
	 */
	public int getRows() {
		return rows;
	}
	
	/**
	 * Returns the total number of columns in this Maze.
	 * 
	 * @return the number of columns in this Maze.
	 */
	public int getCols() {
		return cols;
	}
	
	/**
	 * Returns the row number of the start location.
	 * 
	 * @return the row of the start location.
	 */
	public int getStartRow() { return startRow; }
	
	/**
	 * Returns the column number of the start location.
	 * 
	 * @return the column of the start location.
	 */
	public int getStartCol() { return startCol; }
	
	/**
	 * Returns the row number of the goal location.
	 * 
	 * @return the row of the goal location.
	 */
	public int getGoalRow() { return goalRow; }
	
	/**
	 * Returns the column number of the goal location.
	 * 
	 * @return the column of the goal location.
	 */
	public int getGoalCol() { return goalCol; }
	
	/**
	 * Marks a cell of the maze to be drawn as visited.  The
	 * cell will be drawn with a light grey color.
	 * 
	 * @param r the cell row
	 * @param c the cell column
	 * @throws IllegalArgumentException if the row or column is invalid.
	 */
	public void markCellVisited( int r, int c ) {
		if( r < 0 || r >= rows || c < 0 || c >= cols ) {
			throw new IllegalArgumentException("Invalid row/column: " + r + " " + c);
		}
		visited[r][c] = 1;
	}
	
	/**
	 * Returns whether or not a cell has been marked "visited."
	 * @param r the row number
	 * @param c the column number
	 * @return true if cell (r,c) has been marked visited.
	 */
	public boolean visited( int r, int c ) {
		if( r < 0 || r >= rows || c < 0 || c >= cols ) {
			throw new IllegalArgumentException("Invalid row/column: " + r + " " + c);
		}
		return visited[r][c] == 1;
	}
	
	/**
	 * Returns the value of a cell in this Maze.  A value of '#'
	 * represents a solid wall, and a value of '.' represents open
	 * space.
	 * 
	 * @param r the row number of the cell
	 * @param c the column number of the cell
	 * @return the "value" of the cell.  Either a '#' (wall), or 
	 *   a '.' (empty space).
	 */
	public char getCell( int r, int c ) {
		if( r < 0 || r >= rows || c < 0 || c >= cols ) {
			throw new IllegalArgumentException("Invalid row/column: " + r + " " + c);
		}
		char cell = maze[r][c];
		return cell;
	}
	
	/**
	 * Resets the Maze by marking all cells as unvisited.
	 */
	public void reset() {
		for( int i = 0 ; i < rows; i++ )
			for( int j = 0; j < cols; j++ )
				visited[i][j] = 0;
	}
	
	private void loadMaze(String fileName) throws IOException {
		Scanner fScan = new Scanner( new File(fileName) );
		
		ArrayList<String> lines = new ArrayList<String>();
		while(fScan.hasNextLine()) {
			String line = fScan.nextLine().trim();
			if( line.length() > 0 )
				lines.add(line);
		}
		
		if( lines.size() < 1 ) throw new IOException("No maze found in file."); 
		
		cols = lines.get(0).length();
		if( lines.get(lines.size() - 1).length() != cols) {
			lines.remove(lines.size() - 1);
		}
		
		rows = lines.size();
		maze = new char[rows][cols];
		visited = new int[rows][cols];
		for( int r = 0; r < rows; r++ ) {
			String rowStr = lines.get(r);
			if(rowStr.length() != cols) 
				throw new IOException("Found a row that is not the same length.");
			for( int c = 0 ; c < cols; c++ ) {
				char cell = rowStr.charAt(c);
				if( cell == 'o') {
					this.startRow = r;
					this.startCol = c;
					cell = '.';
				} else if( cell == '*' ) {
					this.goalRow = r;
					this.goalCol = c;
					cell = '.';
				}
				if( cell == '.' || cell == '#')
					maze[r][c] = cell;
				else
					throw new IOException("Invalid maze character: " + cell);
			}
		}
	}
	
	/**
	 * Draws this Maze using the given Graphics object.
	 * 
	 * @param g a Graphics object
	 * @param w the width of the canvas in pixels.
	 * @param h the height of the canvas in pixels.
	 */
	public void draw(Graphics g, int w, int h) {
		double cellW = (double)w / cols;
		double cellH = (double)h / rows;
		int cellWi = (int)Math.round(cellW);
		int cellHi = (int)Math.round(cellH);
		
		int x, y;
		g.setColor(Color.black);
		g.fillRect(0, 0, w, h);
		g.setColor(Color.white);
		for( int r = 0; r < rows; r++ ) {
			y = (int)Math.floor(r * cellH);
			for( int c = 0; c < cols; c++ ) {
				x = (int)Math.floor(c * cellW);
				char cell = maze[r][c];
				if( cell == '.') {
					if( visited[r][c] == 1 ) 
						g.setColor(Color.lightGray);
					else
						g.setColor(Color.white);
					g.fillRect(x, y, cellWi, cellHi);
					g.setColor(Color.black);
					g.drawRect(x,y,cellWi,cellHi);
				}
			}
		}
		
		g.setColor(Color.green);
		x = (int)Math.round(cellW * this.startCol) + BUFFER;
		y = (int)Math.round(cellH * this.startRow) + BUFFER;
		g.fillOval(x, y, cellWi - 2 * BUFFER, cellHi - 2 * BUFFER );
		
		g.setColor(Color.red);
		x = (int)Math.round(cellW * this.goalCol) + BUFFER;
		y = (int)Math.round(cellH * this.goalRow) + BUFFER;
		g.fillOval(x, y, cellWi - 2 * BUFFER, cellHi - 2 * BUFFER );
	}
}
