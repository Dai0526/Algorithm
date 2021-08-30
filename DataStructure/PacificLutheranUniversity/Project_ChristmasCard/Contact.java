import java.io.*;
import java.util.*;

public class Contact {

private int numContacts;
private String firstName;
private String lastName;
private String address;
private boolean sent;
private boolean received;

public Contact(String contactInfo) {
	Scanner readString = new Scanner(contactInfo);
	readString.useDelimiter(",|\\r?\\n");
	firstName = readString.next();
	lastName = readString.next();
	address = readString.next();
	sent = readString.nextBoolean();
	received = readString.nextBoolean();	
}

public String getFirstName() {
	return firstName;	
}

public String getLastName() {
	return lastName;
}

public String getAddress() {
	return address;
}

public String getSent() {
	if (sent)
		return "x";
	else
		return " ";
}

public String getReceived() {
	if (received)
		return "x";
	else
		return " ";
}

public void setFirstName(String newName) {
	firstName = newName;
}

public void setLastName(String newName) {
	lastName = newName;
}

public void setAddress(String newAddress) {
	address = newAddress;
}
public void setSent(boolean newSent) {
	sent = newSent;
}

public void setReceived(boolean newReceived) {
	received = newReceived;
}

public String toString() {
	return firstName + " " + lastName + " " + address + " " + sent + " " + received;
}


}
