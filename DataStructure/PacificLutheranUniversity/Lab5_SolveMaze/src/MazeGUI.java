import java.awt.BorderLayout;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.io.IOException;
import java.util.Hashtable;
import java.util.LinkedList;

import javax.swing.JButton;
import javax.swing.JFrame;
import javax.swing.JLabel;
import javax.swing.JOptionPane;
import javax.swing.JPanel;
import javax.swing.JSlider;
import javax.swing.JTextField;
import javax.swing.Timer;
import javax.swing.event.ChangeEvent;
import javax.swing.event.ChangeListener;

/**
 * A simple GUI for displaying and animating maze solvers.
 * 
 * @author David Wolff
 */
public class MazeGUI extends JPanel implements ActionListener, ChangeListener {
	
	private MazeView mazeView;
	private JTextField mazeFileTF;
	private JButton loadButton;
	private JLabel infoLabel;
	private JSlider animationSlider;
	private JButton startStopButton;
	private JButton startStopButton2;
	private boolean animationRunning = false;
	private Timer timer;
	private int animationSpeed;
	
	private Maze maze;
	
	private LinkedList<MazeGUIListener> listeners;
	
	/**
	 * Creates and displays the Maze GUI.
	 */
	public MazeGUI() {
		listeners = new LinkedList<MazeGUIListener>();
		
		animationSpeed = 500;
		timer = new Timer(animationSpeed,this);
		
		buildGUI();
		JFrame frame = new JFrame();
		frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		frame.add(this);
		frame.setResizable(false);
		frame.pack();
		frame.setVisible(true);
	}
	
	/**
	 * Add a listener object to receive events from this MazeGUI.
	 * 
	 * @param listener the listener object.
	 */
	public void addMazeGUIListener(MazeGUIListener listener) {
		this.listeners.add(listener);
	}
	
	/**
	 * Set the text of the status label displayed at the bottom of 
	 * this window.
	 * 
	 * @param text the text for the status bar.
	 */
	public void setStatusText( String text ) {
		this.infoLabel.setText(text);
	}
	
	/**
	 * Stops the currently running animation.  If no animation is running,
	 * this method does nothing.
	 */
	public void stopAnimation() {
		if(animationRunning ) {
			animationRunning = false;
			startStopButton.setEnabled(true);
			timer.stop();
		}
	}
	
	private void buildGUI() {
		this.setLayout(new BorderLayout());
		JPanel inputPanel = new JPanel();
		
		mazeFileTF = new JTextField(6);
		mazeFileTF.addActionListener(this);
		inputPanel.add(mazeFileTF);
		
		loadButton = new JButton("Load");
		loadButton.addActionListener(this);
		inputPanel.add( loadButton );
		
		startStopButton = new JButton("Start");
		startStopButton.setEnabled(false);
		startStopButton.addActionListener(this);
		inputPanel.add( startStopButton );
	
		animationSlider = new JSlider(0,3000,animationSpeed);
		Hashtable table = animationSlider.createStandardLabels(1500);
		table.put(0, new JLabel("Fast"));
		table.put(1500, new JLabel("Medium"));
		table.put(3000, new JLabel("Slow"));
		animationSlider.setLabelTable(table);
		animationSlider.setPaintLabels(true);
		animationSlider.setMinorTickSpacing(1000);
		animationSlider.setMajorTickSpacing(500);
		animationSlider.setPaintTicks(true);
		animationSlider.addChangeListener(this);
		
		inputPanel.add( animationSlider );
		
		this.add(inputPanel, BorderLayout.NORTH);
		
		mazeView = new MazeView();
		this.add(mazeView, BorderLayout.CENTER);
		JPanel infoPanel = new JPanel();
		this.infoLabel = new JLabel("Enter file name above.");
		infoPanel.add(infoLabel);
		this.add(infoPanel,BorderLayout.SOUTH);
	}

	@Override
	public void actionPerformed(ActionEvent e) {
		if( e.getSource() == loadButton || e.getSource() == mazeFileTF ) {
			infoLabel.setText("Loading maze: " + mazeFileTF.getText());
			try {
				maze = new Maze(mazeFileTF.getText());
				mazeView.setMaze(maze);
				mazeView.redrawMaze();
				infoLabel.setText("Maze " + mazeFileTF.getText() + " loaded." );
				startStopButton.setEnabled(true);
				startStopButton.setText("Start1");
				animationRunning = false;
			} catch(IOException ex) {
				String message = "Unable to load maze file: " 
					+ ex.getMessage();
				JOptionPane.showMessageDialog(this, message);
				infoLabel.setText(message);
			}
		}
		
		if( e.getSource() == startStopButton ) {
			if(animationRunning) {
				this.stopAnimation();
			} else {
				animationRunning = true;
				startStopButton.setEnabled(false);
				maze.reset();
				mazeView.redrawMaze();
				timer.start();
				for( MazeGUIListener l : listeners ) l.start(maze);
			}
		}

		if( e.getSource() == timer ) {
			for( MazeGUIListener l : listeners ) {
				l.step(maze);
				mazeView.redrawMaze();
			}
		}
	}

	@Override
	public void stateChanged(ChangeEvent e) {
		if( e.getSource() == this.animationSlider ) {
			int value = this.animationSlider.getValue();
			timer.setDelay(value);
		}
	}

	
	
}
