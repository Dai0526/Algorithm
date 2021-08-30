
import java.util.*;
import java.io.*;
import java.awt.*;
import java.awt.event.*;
import javax.swing.*;


public class panel extends JFrame
{
	private Contact[] contacts;
	private JLabel top, sort,show , Searchlabel, picture;
	private JTextField search,datafile;
	private JButton Load, FirstName, LastName, Unsent, Both;
	private JTextArea info;
	private JScrollPane scroller;
	private ImageIcon pic;
	public panel()
	{
		super("Christmas Card List");
		this.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		
		// Nortah panel part
		JPanel northPanel = new JPanel();
		
		datafile = new JTextField(10);
		Load = new JButton( " Load  ");
		
		Load.addActionListener(new LoadListener());//button listener
		
		//insert picture
		pic = new ImageIcon("tree.jpg");
		top = new JLabel("Data File :  ", pic, SwingConstants.CENTER);
		//add component
		northPanel.add(top);
		northPanel.add(datafile);
        	northPanel.add(Load);
      
		northPanel.setPreferredSize(new Dimension(500,100));
		this.add(northPanel,BorderLayout.NORTH);  
		this.setVisible(true);
		
		//main panel
		JPanel mainPanel = new JPanel();
		info = new JTextArea(20,30);   
		info.setEditable(false); 
		info.setFont(new Font("Monospaced", Font.PLAIN, 12));
		//add scroller
		scroller = new JScrollPane (info); 
		scroller.setPreferredSize(new Dimension(500,300)); 
		mainPanel.add( scroller, BorderLayout.CENTER);
 		
 		info.setText("  First \t Last   \t Address \t Sent \t Received  "); //delete existing text and replace with "new text"
 	 	info.append("\n  --------\t--------\t ---------\t -----\t -------- \n"); //append "more text" to  existing text
		this.add(mainPanel,BorderLayout.CENTER); 
                this.setSize(500,300); 
                this.setVisible(true);
		
		
		// South Panel
		JPanel southPanel = new JPanel();
		
		//set up component
		sort = new JLabel(" Sort By : ");
		FirstName = new JButton( " First Name ");
		LastName = new JButton( " Last Name ");
		
		Searchlabel = new JLabel(" Search ");	
		search = new JTextField(10);
		
		show = new JLabel("Show Only : ");
		Unsent = new JButton( " Uncent ");
		Both = new JButton( " Received and Unsent ");
			
		// add component 
		southPanel.add(sort);
		southPanel.add(FirstName);
        	southPanel.add(LastName);
        	southPanel.add(Searchlabel);
        	southPanel.add(search);
        	southPanel.add(show,BorderLayout.SOUTH);
        	southPanel.add(Unsent);
        	southPanel.add(Both);
        	southPanel.setPreferredSize(new Dimension(500,100));
        	
        	FirstName.addActionListener(new SortFnameListener());
        	LastName.addActionListener(new SortLnameListener());
		Unsent.addActionListener(new UnsentListener());
		Both.addActionListener(new UnsentandReceivedListener());
        	this.add(southPanel,BorderLayout.SOUTH);  
                this.setSize(500,500); 
                this.setVisible(true);
	
		
	}//organizer for panel
  
private class LoadListener implements ActionListener {
		
		public void actionPerformed(ActionEvent e) {
		try {
			// INSERT FILE READING CODE?
			File file = new File(datafile.getText());
			Scanner inFile = new Scanner(file);
			int numContacts = inFile.nextInt();
			inFile.useDelimiter("\\r?\\n");
			contacts = new Contact[numContacts];
			for (int i = 0; i < numContacts; i++) {
				contacts[i] = new Contact(inFile.next());
			}
			inFile.close();
			// INSERT for LOOP TO DISPLAY contacts IN displayArea
			for (int i = 0; i < numContacts; i++) {
				info.append(contacts[i].getFirstName() + "\t");
				info.append(contacts[i].getLastName() + "\t");
				info.append(contacts[i].getAddress() + "\t");
				info.append(contacts[i].getSent() + "\t");
				info.append(contacts[i].getReceived() + "\n");
			}
		}
		catch (IOException exception) {
			System.out.print("Problem reading file" + exception);
		}
		}
	}// Load button

private class	SortFnameListener implements ActionListener{
	
	public void actionPerformed(ActionEvent e){
	FirstNameSort(contacts);
	info.setText(" ");
	info.setText("  First \t Last   \t Address \t Sent \t Received  "); 
 	info.append("\n  --------\t--------\t ---------\t -----\t -------- \n"); 
	for (int i = 0; i < contacts.length; i++) {
				info.append(contacts[i].getFirstName() + "\t");
				info.append(contacts[i].getLastName() + "\t");
				info.append(contacts[i].getAddress() + "\t");
				info.append(contacts[i].getSent() + "\t");
				info.append(contacts[i].getReceived() + "\n");
			}
	}
	
}//Sort Listener FirstName
private class	SortLnameListener implements ActionListener{
	
	public void actionPerformed(ActionEvent e){
	LastNameSort(contacts);
	info.setText(" ");
	info.setText("  First \t Last   \t Address \t Sent \t Received  "); 
 	info.append("\n  --------\t--------\t ---------\t -----\t -------- \n");
	for (int i = 0; i < contacts.length; i++) {
				info.append(contacts[i].getFirstName() + "\t");
				info.append(contacts[i].getLastName() + "\t");
				info.append(contacts[i].getAddress() + "\t");
				info.append(contacts[i].getSent() + "\t");
				info.append(contacts[i].getReceived() + "\n");
			}
	}
	
}//Sort Listener LasttName

private class	UnsentListener implements ActionListener{
	public void actionPerformed(ActionEvent e){
		info.setText(" ");
		info.setText("  First \t Last   \t Address \t Sent \t Received  "); 
		info.append("\n  --------\t--------\t ---------\t -----\t -------- \n");
		for (int i=0; i<contacts.length;i++)
		{	
			if(contacts[i].getSent()==" ")// why "sent"  not sent
			{
				info.append(contacts[i].getFirstName() + "\t");
				info.append(contacts[i].getLastName() + "\t");
				info.append(contacts[i].getAddress() + "\t");
				info.append(contacts[i].getSent() + "\t");
				info.append(contacts[i].getReceived() + "\n");
			}
		}
	}
}//unsent
private class	UnsentandReceivedListener implements ActionListener{
	public void actionPerformed(ActionEvent e){
		info.setText(" ");
		info.setText("  First \t Last   \t Address \t Sent \t Received  "); 
		info.append("\n  --------\t--------\t ---------\t -----\t -------- \n");
		for (int i=0; i<contacts.length;i++)
		{	
			if(contacts[i].getSent()!="x" && contacts[i].getReceived()!="x" )// why "sent"  not sent
			{	
				info.append(contacts[i].getFirstName() + "\t");
				info.append(contacts[i].getLastName() + "\t");
				info.append(contacts[i].getAddress() + "\t");
				info.append(contacts[i].getSent() + "\t");
				info.append(contacts[i].getReceived() + "\n");
			}
		}
	}	
}//unsent
	
public static void main(String[] args) 
{
	panel fram = new panel();
}	

public static void FirstNameSort(Contact [] array)
{
	int startScan, index, minIndex;
	Contact minName;
	
	for (startScan = 0; startScan < (array.length-1); startScan++)
        {
        	minIndex = startScan;
        	minName = array[startScan];
        	for(index = startScan + 1; index < array.length; index++)
        	{
        		if (array[index].getFirstName().compareTo(minName.getFirstName())<0)
        		{
        			minName = array[index];
        			minIndex = index;
        		}
        	}
        	array[minIndex] = array[startScan];
        	array[startScan] = minName;
      }
 }//sort firstName

 public static void LastNameSort(Contact [] array)
{
	int startScan, index, minIndex;
	Contact minName;
	
	for (startScan = 0; startScan < (array.length-1); startScan++)
        {
        	minIndex = startScan;
        	minName = array[startScan];
        	for(index = startScan + 1; index < array.length; index++)
        	{
        		if (array[index].getLastName().compareTo(minName.getLastName())<0)
        		{
        			minName = array[index];
        			minIndex = index;
        		}
        	}
        	array[minIndex] = array[startScan];
        	array[startScan] = minName;
      }
 }//sort lastName	



}//class