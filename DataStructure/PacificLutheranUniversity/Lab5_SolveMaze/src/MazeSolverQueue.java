/* Name: Tianhua
  Assignment: Lab 05
  Title: Queues and Mazes
  Course: CSCE 270
  Lab Section: 02
  Semester: Fall, 2014
  Instructor: Laurie Murphy
  Date:October 16th 2014
  Sources consulted: Lab handout 
  Program description: This program is going to solve the given maze.
  					   It will offer a GUI and let user to choose maze files,
  					   and it can control the solving speed.
  Known Bugs: NA
  Creativity: I wrote a MazeSolverStack.java to solve maze by stack.
  			  It works separately, but I failed to add it into one GUI. 
  			  Because both two solvers call the same listeners, please
  			   remove one of them from Source file when you test the other one.
  */
import javax.swing.JComponent;

public class MazeSolverQueue implements MazeGUIListener {
	LinkedQueue<Position> mazeSolver= new LinkedQueue();
	private MazeGUI GUI; 	
	private Maze maze;
	
	/**
	 * Constructor to initialize the mazeSolver
	 */
	public MazeSolverQueue(){
		GUI = new MazeGUI();
		GUI.addMazeGUIListener(this);
	}
	
	// Start method
	@Override
	public void start(Maze m) {
		mazeSolver.clear();   // clear every thing when introduce a new maze
		Position start=new Position( m.getStartRow(),m.getStartCol());
		mazeSolver.enqueue(start);//set start point		
	}

	@Override
	public void step(Maze m) {
		int row, col;
		Position currentCell=new Position();		
		if(mazeSolver.isEmpty()==true){ // if no place to go
			//display cannot solve
			GUI.setStatusText("Maze Cannot solve");
			//.stopAnimation();
			GUI.stopAnimation();
		}
		else{
			currentCell=(Position) mazeSolver.dequeue();
			row=((Position) currentCell).getRow();
			col=((Position) currentCell).getCol();
			m.markCellVisited(row,col); //mark the previous step visited
			if(m.getGoalRow()==row && m.getGoalCol()==col){
				GUI.setStatusText("Maze solved");
				GUI.stopAnimation(); // solve if col and row match the goal 
			}
			else{
				//try for different posiiton which is up, down left and right
				Position up=new Position(row+1,col);
				Position down=new Position(row-1,col);
				Position left=new Position(row,col+1);
				Position right=new Position(row,col-1);
				
				if(checkIfaviable(up,m)==true){
					mazeSolver.enqueue(up);
				}
				if(checkIfaviable(down,m)==true){
					mazeSolver.enqueue(down);
				}
				if(checkIfaviable(left,m)==true){
					mazeSolver.enqueue(left);
				}
				if(checkIfaviable(right,m)==true){
					mazeSolver.enqueue(right);
				}
			}//else
		}
	}
	
	/**
	 * This method is to check if the position for next step is available:
	 * 	1. on board
	 *  2. not wall
	 *  3. not visited
	 *  
	 * @param s Position object
	 * @param m the given maze
	 * @return
	 */
	public boolean checkIfaviable(Position s, Maze m){
		boolean result=true;
		int row= s.getRow();
		int col=s.getCol();
		if(m.visited(row,col)==true|| m.getCell(row,col)=='#'||row>=m.getRows()||col>=m.getCols())
			result=false;
		return result;
	}
	
	//main method to call constructor.
	public static void main(String args[]){
		MazeSolverQueue mazeSolve=new MazeSolverQueue();		
	}
}
