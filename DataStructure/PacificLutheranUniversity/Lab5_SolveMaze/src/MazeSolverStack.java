
import javax.swing.JComponent;
	public class MazeSolverStack implements MazeGUIListener {
		LinkedStack<Position> mazeSolver= new LinkedStack();
		private MazeGUI GUI; 	
		private Maze maze;
		
		/**
		 * Constructor to initialize the mazeSolver
		 */
		public MazeSolverStack(){
			GUI = new MazeGUI();
			GUI.addMazeGUIListener(this);
		}
		
		// Start method
		@Override
		public void start(Maze m) {
			mazeSolver.clear();   // clear every thing when introduce a new maze
			Position start=new Position( m.getStartRow(),m.getStartCol());
			mazeSolver.push(start);//set start point		
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
				currentCell=(Position) mazeSolver.pop();
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
						mazeSolver.push(up);
					}
					if(checkIfaviable(down,m)==true){
						mazeSolver.push(down);
					}
					if(checkIfaviable(left,m)==true){
						mazeSolver.push(left);
					}
					if(checkIfaviable(right,m)==true){
						mazeSolver.push(right);
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
			MazeSolverStack mazeSolve=new MazeSolverStack();
			
		}

	}


