import java.awt.AlphaComposite;
import java.awt.Color;
import java.awt.Dimension;
import java.awt.Graphics;
import java.awt.Graphics2D;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.awt.image.BufferedImage;
import java.io.File;
import java.io.IOException;

import javax.imageio.ImageIO;
import javax.swing.JFrame;
import javax.swing.JPanel;
import javax.swing.Timer;

/**
 * <p>This is a simple class that implements a blank canvas in a JFrame
 * that can be used for basic 2D drawing.  To use it, simply create
 * an instance of <code>DrawingCanvas</code>, retrieve the 
 * <code>Graphics2D</code> object by 
 * calling <code>getGraphics()</code>, and begin calling some of the drawing
 * methods.  Upon instantiation, this class creates a
 * <code>JFrame</code> and makes it visible on the screen.</p>
 * 
 * <p>You can retrieve the <code>Graphics2D</code> object suitable for drawing onto
 * this window by calling the <code>getGraphics()</code> method.  It is important to
 * realize that the <code>Graphics2D</code> object is valid only until the window
 * is resized by calling <code>setSize()</code>.  After a call to <code>setSize()</code>, a new
 * <code>Graphics2D</code> object needs to be retrieved by calling 
 * <code>getGraphics()</code>.</p>
 * 
 * <p>Simple animation can be achieved by using <code>Thread.sleep()</code> to slow down
 * the execution of drawing calls to this object.</p>
 * 
 * <p>Individual pixels can be modified by calling <code>setPixel()</code>.</p>
 * 
 * <p>An example of the use of this class is shown below:</p>
 * 
 * <p>
 * <code>
 * DrawingCanvas canvas = new DrawingCanvas();<br />
 * Graphics g = canvas.getGraphics();<br />
 * <br />
 * canvas.setBackground(new Color(1.0f,1.0f,0.0f));<br />
 * g.setColor(new Color(1.0f,0.0f,0.0f,0.5f));<br />
 * g.fillRect(20, 20, 320, 240);<br />
 * </code>
 * </p>
 * 
 * @author David Wolff
 *
 */
public class DrawingCanvas {

	private static final int DEFAULT_REPAINT_DELAY = 100;
	
	private BufferedImage image;
	private Color bgColor = Color.white;
	private Color transparent = new Color(0,0,0,0);
	private Graphics2D imgGraphics;
	private JFrame frame;
	private DrawingCanvasPanel panel;
	private Timer timer;
	private int repaintDelay = DEFAULT_REPAINT_DELAY;
	
	/** 
	 * Creates and displays a new DrawingCanvas of size 640x480.
	 */
	public DrawingCanvas() {
		this(640,480);
	}
	
	/**
	 * Creates and displays a new DrawingCanvas with the given dimensions.
	 * 
	 * @param w the width of the window.
	 * @param h the height of the window.
	 */
	public DrawingCanvas(int w, int h) {
		
		// Create the JFrame
		frame = new JFrame("Drawing Canvas");
		
		// Create the image that will contain the drawing
		image = new BufferedImage(w,h,BufferedImage.TYPE_INT_ARGB);
		imgGraphics = image.createGraphics();
		imgGraphics.setColor( Color.BLACK );
		
		// Create the panel to hold the image, and add to the frame
		panel = new DrawingCanvasPanel();
		panel.setPreferredSize( new Dimension(w,h) );
		frame.add(panel);
		
		// Set up the JFrame
		frame.setResizable(false);
		frame.pack();
		frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		frame.setVisible(true);
		
		// Clear the canvas to transparent
		this.clear();
		
		// Set up the timer that will constantly redraw the screen
		timer = new Timer(repaintDelay, new ActionListener() {
			public void actionPerformed(ActionEvent e) {
				panel.repaint();
			}
		});
		timer.start();
	}
	
	/**
	 * Sets the title for this window to the specified string.
	 * @param title the title to be displayed in the window's border.
	 */
	public void setTitle( String title )
	{
		frame.setTitle( title );
	}
	
	/**
	 * Sets how often the window is repainted.  Drawing will not appear
	 * on the canvas until the window is repainted.  Hence, one can expect
	 * that updates to the image will appear on the screen 
	 * in a maximum of <code>delay</code> milliseconds.  The default delay is 100.
	 * 
	 * @param delay the delay in milliseconds
	 */
	public void setRepaintDelay( int delay ) 
	{
		this.repaintDelay = delay;
		timer.setDelay(this.repaintDelay);
	}
	
	/**
	 * Returns the width of the inside of this DrawingCanvas.
	 * @return the width of the inside of this DrawingCanvas.
	 */
	public int getWidth() {
		return panel.getWidth();
	}
	
	/**
	 * Returns the height of the inside of this DrawingCanvas.
	 * @return the height of the inside of this DrawingCanvas.
	 */
	public int getHeight() { 
		return panel.getHeight();
	}
	
	private class DrawingCanvasPanel extends JPanel {
		public void paintComponent( Graphics g ) {
			super.paintComponent(g);
			
			g.drawImage(image, 0,0, bgColor, this);
		}
	}
	
	/**
	 * Changes the size of this window to the given dimension.
	 * This invalidates the current Graphics object, so one should retrieve
	 * the Graphics object by calling getGraphics after executing this
	 * method.
	 * 
	 * @param d the new dimension for this window.
	 */
	public void setSize( Dimension d ) {
		resizeImage(d.width,d.height);
	}
	
	/**
	 * Changes the size of this window to the given width and height.
	 * This invalidates the current Graphics object, so one should retrieve
	 * the Graphics object by calling getGraphics after executing this
	 * method.
	 * 
	 * @param w the new width in pixels.
	 * @param h the new height in pixels.
	 */
	public void setSize(int w, int h) {
		resizeImage(w,h);
	}
	
	private void resizeImage(int w, int h) {
		// Save the old image and Graphics 
		BufferedImage oldImg = image;
		Graphics2D oldGraphics = imgGraphics;
		
		// Create the new image and Graphics
		image = new BufferedImage(w,h,BufferedImage.TYPE_INT_ARGB);
		imgGraphics = image.createGraphics();
		
		// Clear the new image to transparent
		this.clear();
		
		// Restore the old color
		imgGraphics.setColor( oldGraphics.getColor() );
		
		// Draw the old image onto the new image
		imgGraphics.drawImage(oldImg, 0, 0, panel);
		
		panel.setPreferredSize(new Dimension(w,h));
		frame.pack();
	}
	
	/**
	 * Sets the background color for this window.
	 * @param c the background color.
	 */
	public void setBackground( Color c ) {
		if(c != null) bgColor = c;
	}
	
	/**
	 * Returns a Graphics2D object suitable for drawing onto the 
	 * window.  The Graphics2D object is invalidated when setSize is called,
	 * hence should be kept around only as long as needed to execute
	 * the desired drawing operations, then discarded for safety.
	 * 
	 * @return a Graphics2D object suitable for drawing onto this window.
	 */
	public Graphics2D getGraphics() { 
		return imgGraphics;
	}
	
	/**
	 * Clears the window to the background color.
	 */
	public void clear() {
		Color oldColor = imgGraphics.getColor();
		imgGraphics.setComposite(AlphaComposite.Src);
		imgGraphics.setColor(transparent);
		imgGraphics.fillRect(0, 0, image.getWidth(), image.getHeight() );
		imgGraphics.setColor(oldColor);
		imgGraphics.setComposite(AlphaComposite.SrcOver);
	}
	
	/**
	 * Sets the pixel at the given location to the given color.
	 * 
	 * @param x the x coordinate of the pixel (between 0 and the 
	 * width of the window minus one).
	 * @param y the y coordinate of the pixel (between 0 and the 
	 * height of the window minus one).
	 * @param c the color of the pixel.
	 */
	public void setPixel(int x, int y, Color c) {
		image.setRGB(x, y, c.getRGB());
	}
	
	/**
	 * Gets the color for the pixel at the given location.
	 * @param x the x coordinate of the pixel.
	 * @param y the y coordinate of the pixel.
	 * @return the color of the pixel.
	 */
	public Color getPixel( int x, int y ) {
		return new Color(image.getRGB(x, y));
	}
	
	/**
	 * Draws an image that is loaded from a file into this DrawingCanvas.
	 * @param x the x coordinate of the upper left of the image.
	 * @param y the y coordinate of the upper left of the image.
	 * @param fileName the file name of the image file.
	 */
	public void drawImage(int x, int y, String fileName) {
		File imageFile = new File(fileName);
		
		try {
			BufferedImage img = ImageIO.read(imageFile);
			imgGraphics.drawImage(img, x, y, panel);
		} catch(IOException e) {
			System.err.println("Error loading image file: " + fileName);
			System.err.println(e);
			System.exit(1);
		}
		
	}
}
