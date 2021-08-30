import java.awt.Graphics;
import java.awt.Color;

public class HappyHallowen 
{
	public static void main(String[] args)
	{
		// set up teh canvas panel
		DrawingCanvas canvas= new DrawingCanvas(300,250);
		canvas.setBackground(Color.black);
		
		Graphics g = canvas.getGraphics();
		
		g.setColor(Color.green);
		g.fillRect(140,30,20,30);
		
		g.setColor(Color.orange);
		g.fillRect(50,50,200,160);
		
		g.setColor(Color.yellow);
		g.fillRect(110,90,20,20);
		g.fillRect(170,90,20,20);
		g.fillOval(100,140,100,20);

		g.setColor(Color.orange);
		g.drawString("Happy Halloween!",20,30);		
		
	}



}
