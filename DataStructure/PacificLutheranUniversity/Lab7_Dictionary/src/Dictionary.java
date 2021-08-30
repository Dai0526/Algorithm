import java.io.BufferedReader;
import java.io.File;
import java.io.FileReader;
import java.io.IOException;
import java.util.Scanner;


public class Dictionary {
	public String[] dictionary;
	/**
	 * Dictionary constructor to store all words into an array.
	 * @param fileName The fileNmae of your dictionary
	 * @throws IOException Exception when reading files
	 */
	public Dictionary(String fileName) throws IOException{
		dictionary=loadDictionary(fileName);
	}
	/**
	 * method to read file
	 * @param fileName filename in String form
	 * @return return an array of all the words in dictionary 
	 * @throws IOException Exception when reading files
	 */
	public String[] loadDictionary(String fileName)throws IOException{
		File file = new File(fileName);
		Scanner inputFile = new Scanner(file);
		int count=0;
			String [] dictionary= new String[readLine(fileName)];
			
			while(inputFile.hasNextLine()){
				dictionary[count]=inputFile.nextLine();
				count++;
			}
			
		inputFile.close();
		//put all words in an array
		return dictionary;
	}
	/**
	 * get the how many line in a file, in this case, how many words in dictionary
	 * file so we can set the array in a proper size
	 * @param fileName file name in String form
	 * @return return how many line in this file
	 * @throws IOException Exception when reading files
	 */
	public int readLine(String fileName) throws IOException{
		BufferedReader reader = new BufferedReader(new FileReader(fileName));
		int lines = 0;
		while (reader.readLine() != null){
		lines++;
		}
		reader.close();		
		return lines;  //get the size of array
	}
	
	/**
	 * Binary search function to call recursive search of a certain wrods
	 *  to see if it is in the dictionary
	 * @param data Dictionary data
	 * @param key the key words be searched
	 * @return true if found in dictionary
	 * 		   flase if not found
	 */
	public static <T extends Comparable<T>> boolean Search(T[] data, String key){
		  String lowerCase=key.toLowerCase();
		  return binarySearch(data, lowerCase, 0, data.length-1);
	}
	/**
	 * Recursive binary search for a words
	 * @param data dictionary data
	 * @param key key words need to be searched
	 * @param start the start index
	 * @param end the end index
	 * @return return true if found
	 * 			      false if not
	 */
	private static <T> boolean binarySearch(T[] data, String key, int start, int end){
		boolean found=false;
		int middle = start+(end-start)/2;
		if (((String) data[middle]).compareTo(key)==0) 
		  	found=true;
		else if (((String) data[middle]).compareTo(key) > 0 ) {
		  	if(start<=middle-1)
		  		found=binarySearch(data,key,start,middle-1);
		}
		else if(middle-1<=end){
		  	found= binarySearch(data,key,middle+1,end);
		}
		return found;
	}
		
}
