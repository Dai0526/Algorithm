/*Name: Tianhua Fang
  Assignment: Lab 09
  Title: Sorting
  Course: CSCE 270
  Lab Section: 02
  Semester: Fall, 2014
  Instructor: Laurie Murphy
  Date: November 23
  Sources consulted: Lab Handout
  Program description: A testing program with GUI to show run time for different
  					  sorting method. You can choose array type, array size and 
  					  repeation. 
  Known Bugs: NA
  Creativity: NA
*/

import java.awt.BorderLayout;
import java.awt.Dimension;
import java.awt.Font;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.util.Arrays;
import java.util.Random;
import javax.swing.JButton;
import javax.swing.JComboBox;
import javax.swing.JFrame;
import javax.swing.JLabel;
import javax.swing.JPanel;
import javax.swing.JScrollPane;
import javax.swing.JSlider;
import javax.swing.JTextArea;
import javax.swing.JTextField;

public class searchGUI extends JFrame implements ActionListener{
	
	private JTextField Repetitions, ArraySize;
	private JButton StartAndShow,StartNotShow, ArraySort;//Random, ascending , descend
	private JButton clear;
	private JLabel SelectMethod,Repetition,DisPlay,ArrayLabel,ArraySizeLabel;
	private JComboBox SelectionBox, ArrayBox;
	
	private JScrollPane scroller;
	private JTextArea ShowResult;
	private static Timer timer;

	public searchGUI(){
		super("Search Testing");
		this.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
	
		//North Panel
		//set up componments
		JPanel northPanel = new JPanel();
		SelectMethod = new JLabel("Select a Sorting Method: ");
	
		String[] SelectStrings = { "Selection Sort", "Shell Sort", "Merge Sort", "Bubble Sort", "Heap Sort", "Quick Sort", "Insertion Sort" };
		SelectionBox = new JComboBox(SelectStrings);
		SelectionBox.setSelectedIndex(6);
		SelectionBox.addActionListener(this);
     	
     	ArraySizeLabel = new JLabel("Array Size: ");
     	ArraySize= new JTextField(10);
     	
     	ArrayLabel=new JLabel("Choose an Array: ");
     	String[] ArrayString = { "Random", "Ascending Order", "Descending Order"};
     	ArrayBox = new JComboBox(ArrayString);
		ArrayBox.setSelectedIndex(2);
		ArrayBox.addActionListener(this);

		northPanel.add(ArraySizeLabel);
		northPanel.add(ArraySize);
		northPanel.add(ArrayLabel);
		northPanel.add(ArrayBox);
		
		//add componments
		northPanel.add(SelectMethod);
		northPanel.add(SelectionBox);
				
		northPanel.setPreferredSize(new Dimension(700,100));
		this.add(northPanel,BorderLayout.NORTH);  
		this.setVisible(true);
		
		//main panel
		JPanel mainPanel = new JPanel();
		ShowResult = new JTextArea(20,30);   
		ShowResult.setEditable(false); 
		ShowResult.setFont(new Font("Monospaced", Font.PLAIN, 12));
		
		scroller = new JScrollPane (ShowResult); 
		scroller.setPreferredSize(new Dimension(500,300)); 
		//add main componment
		mainPanel.add( scroller, BorderLayout.CENTER);
		ShowResult.setText("----Time-----------"); //delete existing text and replace with "new text"
 	 	ShowResult.append("       ---------------The array is------------------ :"); //append "more text" to  existing text
		this.add(mainPanel,BorderLayout.CENTER); 
        this.setSize(500,300); 
        this.setVisible(true);
                
     // South Panel
     	JPanel southPanel = new JPanel();
     	
     	Repetition = new JLabel("# Repetition: ");
     	Repetitions= new JTextField(10);
     	
		StartAndShow=new JButton("Start Search and show array");
		StartNotShow=new JButton("Start Search but not show array");
		clear=new JButton("Clear all Data");
		southPanel.add(Repetition);
		southPanel.add(Repetitions);
		southPanel.add(StartAndShow);
		southPanel.add(StartNotShow);
		southPanel.add(clear);
		
		StartNotShow.addActionListener(new NotShowResult());
		StartAndShow.addActionListener(new ShowResult());
		clear.addActionListener(new Clear());
		
    	this.add(southPanel,BorderLayout.SOUTH);  
        this.setSize(500,500); 
        this.setVisible(true);      
	}
	
	
	public static void main(String[] args) 
	{
		searchGUI fram = new searchGUI();
	}	
	
	private class Clear implements ActionListener{

		@Override
		public void actionPerformed(ActionEvent arg0) {
			ShowResult = new JTextArea(20,30);   
			ShowResult.setEditable(false); 
			ShowResult.setFont(new Font("Monospaced", Font.PLAIN, 12));
			
		}
	}
	//Listener Method
	private class ShowResult<T> implements ActionListener{
		@Override
		public void actionPerformed(ActionEvent arg0) {
			String Arrytype=(String) ArrayBox.getSelectedItem();//
			String SortType= (String) SelectionBox.getSelectedItem();
			int size=Integer.parseInt(ArraySize.getText());
			Integer[] arryTobeSorted=CreateArray(size,Arrytype);
			
			int repetion=Integer.parseInt(Repetitions.getText());	
			double totalTime=0;
			for(int i=0;i<repetion;i++){
				SortArray(SortType,arryTobeSorted);
				totalTime=totalTime+ timer.getElapsedTime();
			}
			double avgTime=totalTime/(repetion*1.0);
			ShowResult.append("\n"+Arrays.toString(arryTobeSorted));
			ShowResult.append("\n It will use "+ String.valueOf(avgTime)+ "seconds for "+SortType+" to sort an "+size+" random array." );
			
		}
		
	}

	private class NotShowResult<T> implements ActionListener{
		@Override
		public void actionPerformed(ActionEvent arg0) {
			String Arrytype=(String) ArrayBox.getSelectedItem();//
			String SortType= (String) SelectionBox.getSelectedItem();
			int size=Integer.parseInt(ArraySize.getText());
			int repetion=Integer.parseInt(Repetitions.getText());
			Integer[] arryTobeSorted=CreateArray(size,Arrytype);
			double totalTime=0;

			for(int i=0;i<repetion;i++){
				SortArray(SortType,arryTobeSorted);
				totalTime=totalTime+ timer.getElapsedTime();
			}
			double avgTime=totalTime/(repetion*1.0);
			
			ShowResult.append("\n It will use "+ String.valueOf(avgTime)+ "seconds for "+SortType+" to sort an "+size+" random array." );	
		}
			
	}
		
	public static<T> void SortArray(String SortType,Integer[] arryTobeSorted ){		
	
			timer = new Timer();
			if(SortType=="Bubble Sort"){
				timer.start();
				BubbleSort.sort( arryTobeSorted);
				timer.stop();
			}
			else if(SortType=="Insertion Sort"){
				
				timer.start();
				InsertionSort.sort( arryTobeSorted);
				timer.stop();
			}
			else if(SortType=="Shell Sort"){
			
				timer.start();
				ShellSort.sort( arryTobeSorted);
				timer.stop();
			}
			else if(SortType=="Merge Sort"){
			
				timer.start();
				MergeSort.sort( arryTobeSorted);
				timer.stop();
			}
			else if(SortType=="Heap Sort"){
			
				timer.start();
				HeapSort.sort( arryTobeSorted);
				timer.stop();
			}
			else if(SortType=="Quick Sort"){
			
				timer.start();
				QuickSort.sort( arryTobeSorted);
				timer.stop();
			}
			else if(SortType=="Selection Sort"){
			
				timer.start();
				SelectionSort.sort( arryTobeSorted);
				timer.stop();
			}//end all search
		
	}
	public static<T>  Integer[] CreateArray(int size, String order){
		//create an arry as required	
		Random rand = new Random(1000);
		Integer[] array=new Integer[size]; 
		if(order.charAt(0)=='R'){
			for(int i=0;i<size;i++){
				array[i]=rand.nextInt();
			}
		}
		else if(order.charAt(0)=='A'){
			for(int i=0;i<size;i++){
				array[i]=i;
			}
		}
		else{
			for(int i=0;i<size;i++){
				array[i]=101-i;
			}
		}
		return  array;
	}

	@Override
	public void actionPerformed(ActionEvent arg0) {
		// TODO Auto-generated method stub
		
	}
}