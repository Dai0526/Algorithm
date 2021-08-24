import java.awt.Color;
import java.awt.Dimension;
import java.awt.Graphics;
import java.awt.image.BufferedImage;
import java.io.IOException;

import javax.swing.JOptionPane;
import javax.swing.JPanel;

/**
 * The panel that manages the graphical representation
 * of the maze.
 * 
 * @author David Wolff
 */
public class MazeView extends JPanel {

	private BufferedImage img;
	private static int WIDTH = 600;
	private static int HEIGHT = 600;
	private Maze maze;
	
	/**
	 * Creates a "blank" MazeView.  The view is initially
	 * black with a message in the center.
	 */
	public MazeView() {
		this.setPreferredSize(new Dimension(WIDTH,HEIGHT));
		img = new BufferedImage(WIDTH,HEIGHT,BufferedImage.TYPE_INT_ARGB);
		Graphics g = img.getGraphics();
		g.setColor(Color.black);
		g.fillRect(0, 0, WIDTH, HEIGHT);
		g.setColor(Color.white);
		g.drawString("To load a maze, type in the file name, and click Load.", 
				WIDTH/2 - 200, HEIGHT/2);
		maze = null;
	}
	
	/**
	 * Draws the content for this MazeView.
	 */
	public void paintComponent( Graphics g ) {
		super.paintComponent(g);
		
		g.drawImage(img, 0, 0, this);
	}
	
	/**
	 * Initiates a redraw of the maze.  If the Maze is not set
	 * (see setMaze) this does nothing.
	 */
	public void redrawMaze() {
		if( maze != null ) {
			Graphics g = img.getGraphics();
			maze.draw(g, WIDTH, HEIGHT);
			this.repaint();
		}
	}
	
	/**
	 * Sets the maze to be used by this MazeView.
	 * 
	 * @param m a Maze.
	 */
	public void setMaze( Maze m ) {
		this.maze = m;
	}
}
