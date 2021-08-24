import java.util.*;
import java.io.*;

public class ChristmasList {

	private Contact[] contacts;
	
	private class LoadListener implements ActionListener {
		
		public void actionPerformed(ActionEvent e) {
		try {
			// INSERT FILE READING CODE?
			File file = new File(loadField);
			Scanner inFile = new Scanner(file);
			int numContacts = inFile.nextInt();
			inFile.useDelimiter("\\r?\\n");
			contacts = new Contact[numContacts];
			for (int i = 0; i < numContacts; i++) {
				contacts[i] = new Contact(inFile.nextLine());
			}
			inFile.close();
			// INSERT for LOOP TO DISPLAY contacts IN displayArea
			for (int i = 0; i < numContacts; i++) {
				displayArea.append(contacts[i].getFirstName() + "\t");
				displayArea.append(contacts[i].getLastName() + "\t");
				displayArea.append(contacts[i].getAddress() + "\t");
				displayArea.append(contacts[i].getSent() + "\t");
				displayArea.append(contacts[i].getReceived() + "\n");
			}
		}
		catch (IOException exception) {
			System.out.print("Problem reading file" + exception);
		}
		}
	}
	public static void main(String[] args) {
	
	}
	
	
}
