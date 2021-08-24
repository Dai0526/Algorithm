import java.io.BufferedReader;
import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.IOException;
import java.util.ArrayList;
import java.util.Iterator;
import java.util.List;
import java.util.Scanner;

public class BwogBot {
	private AvlMap<String, Integer> map;

	public BwogBot() {
		/*
		 * I use AvlMap because I think SeparateChainngMap will take longer time and space
		 * I tested my BwogBot with SeparateChainingMap, and it takes about 10-15 seconds 
		 * to show the result of two very simple test case. I think my put and get methods
		 * are good(maybe not), so I think AvlMap is a better choice.
		 * 
		 */
		map = new AvlMap<>();
	}

	public void readFile(String fileName) throws IOException {
		/*
		 * My scanner can only read part of the file. I think the reason 
		 * why scanner does't work is because there are some double space between 
		 * each words in the text so I change my method to use BufferedReader, 
		 * but the big-o of my bufferReader is
		 * about n^3, so I have no idea if it is the right way.
		 * 
		 * Below is the code when I use scanner which does't work
		 * //File file=new File(fileName); //Scanner sc = new Scanner(file);
		 * while(sc.hasNext()){ words=sc.next();
		 * 
		 * if(this.map.get(words)==null){
		 * 	 this.map.put(words, 1); 
		 * }else{ 
		 * 	 int count=this.map.get(words)+1; 
		 * 	 this.map.put(words, count); 
		 * }
		 *  }//while
		 * 	loop sc.close(); file.exists();
		 */
		String[] words; //the array to store each wrod after spliting a line
		String lines;  

		try {
			FileReader fr = new FileReader(fileName);
			BufferedReader br = new BufferedReader(fr);
			
			//read file
			while ((lines = br.readLine()) != null) {
				words = lines.split(" ");//split the line by space and store each word in this array
				
				//lop over the array to put the element in the map
				for (String st : words) {
					if (this.map.get(st) == null) {
						this.map.put(st, 1); // if this word never be put, then add thisword and set value to 1
					} else {
						int count = this.map.get(st) + 1;
						this.map.put(st, count);//set the new value to this keyword
					}
				}//for
			}//while

			br.close();
			
		} catch (FileNotFoundException e) {
			System.out.println("File " + fileName + " not exist");
			
		}

		
	}

	public int getCount(String word) {
		return this.map.get(word); //return the int value stored in map
	}

	public List<String> getNMostPopularWords(int n) {
		// I didn't wirte my code, but my idea is to use iterator to loop over the map and store the key into a comparable(compare the value) 
		// maxheap, then call deletMax n time from this mexHeap and store the element into a list.
		// and This list will contains the n most popular words.
		
		// I think it is a bad way to analyze the text. Because some words are not useful such as "you", "it", "he",etc
		// Because they are just plain English.
		return null;
	}

	public Map<String, Integer> getMap() {
		return this.map; //get the map table
	}

	public static void main(String[] args) throws IOException {
		BwogBot bot = new BwogBot();
		bot.readFile("comments.txt");
		System.out.println(bot.getCount("hamdel")); // because linan's hungry
													// now
		System.out.println(bot.getMap().get("joke"));
		System.out.println(bot.getNMostPopularWords(100));
	}
}
