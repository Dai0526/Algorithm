import java.awt.Graphics;
import java.awt.Color;

public class house
{
	public static void main(String[] args)
	{
		// set up teh canvas panel
		DrawingCanvas canvas= new DrawingCanvas(500,400);
		canvas.setBackground(Color.white);
		
		Graphics g = canvas.getGraphics();
		// front house body
		g.drawRect(100,200,200,100);
		//proof
		g.drawLine(75,210,200,160);
		g.drawLine(200,160,325,210);
		g.drawLine(200,160,300,140);
		g.drawLine(325,210,410,190);
		g.drawLine(300,140,410,190);
	
		// side wall
		g.drawLine(300,300,385,283);
		g.drawLine(385,283,385,200); 
		//door
		g.drawRect(190,265,20,35);
		g.drawRect(208,285,2,2);//doorknob
		// windows
		g.drawRect(125,220,30,20);
		g.drawRect(125,260,30,20);
		g.drawRect(240,220,30,20);
		g.drawRect(240,260,30,20);
		//chimney
		g.drawLine(155,178,155,158);
		g.drawLine(190,164,190,157);
		g.drawLine(155,158,190,157);
		
		// Line
		g.drawString("Tianhua's House",20,30);
	}	
	

	
}