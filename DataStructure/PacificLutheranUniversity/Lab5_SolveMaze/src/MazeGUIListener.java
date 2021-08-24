
public interface MazeGUIListener {
	
	/**
	 * This method is called when the start button is
	 * clicked in the MazeGUI.
	 * 
	 * @param m the Maze.
	 */
	void start(Maze m);
	
	/**
	 * This method is called repeatedly until the animation is stopped
	 * by calling MazeGUI.stopAnimation().
	 * You should implement one step of your algorithm within
	 * this method.  (e.g. Set one cell in the Maze as "visited," 
	 * and update the "agenda." )  When the maze is solved, or
	 * is deemed unsolvable, this method should call MazeGUI.stopAnimation().
	 * 
	 * @param m the Maze.
	 */
	void step(Maze m);
}
