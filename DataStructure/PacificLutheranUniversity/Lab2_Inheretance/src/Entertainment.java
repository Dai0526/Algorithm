// Name: Tianhua
//Note: I put title information in my EntertainmanetItem.java file.

import java.util.*;
import java.io.*;

/**   Fill this in with an appropriate JavaDoc comment.
 */
public class Entertainment {
  
  
   /** Loads a set of EntertainmentItem objects from a file.  
    * Note: This method is provide by the instructor and does not require
    * modification.
    *
    * @param fileName is the name of the file used for data input.
    * @return an array of EntertainmentItem objects (Album and Movie objects) 
    *         read from the file.
    */
   public static EntertainmentItem[] loadData(String fileName) {
      //ArrayList to hold all the data
      ArrayList<EntertainmentItem> data = new ArrayList<EntertainmentItem>();
	  
      // Create the scanner (open the file for reading)
      Scanner scan = null;
      Scanner lineScan = null;  // used to parse one line
      String line = "";
      int lineNum;				//keep track of current line number
      
      // info read from the file for each item
      String type;
      String title;
      double cost;
      String artist;      	// for Albums
      String studio;       // for Movies
      int rating1, rating2, rating3;  // use as needed
      // the array to be returned
      EntertainmentItem[] arr;
      
      
      try {
         scan = new Scanner( new File ( fileName ) );
      } catch (IOException e) {
         System.err.println("Error reading from: " + fileName);
         System.exit(1);
      }
    
      // Start reading lines from the file
      lineNum = 0;
      try {
         while(scan.hasNext()) {
            //start process the next line
            lineNum++;
            line = scan.nextLine();
            /*  Debug ---  System.out.println(" " + lineNum + " " + line);*/      
            lineScan = new Scanner(line);
            lineScan.useDelimiter("\\s*\\|\\s*");  // delimiters are "|"
                                          		   // possibly surrounded by spacees
            // start reading data from line
            type = lineScan.next();
            title = lineScan.next();
            cost = lineScan.nextDouble();
            // Determine whether it is a Album or a Movie
            if( type.equals("Album") ) {
               // It's a Album object.  Read data to make sure it exists
               artist = lineScan.next();
               rating1 = lineScan.nextInt();
               rating2 = lineScan.nextInt();
               rating3 = lineScan.nextInt();
               // Create the Album object and add it to the list
               Album aAlbum = new Album(title, cost, artist);
               aAlbum.setVocal(rating1);
               aAlbum.setAccompaniment(rating2);
               aAlbum.setLyrics(rating3);
               data.add(aAlbum);
            } else if (type.equals("Movie")) {
               // It's a Movie object.  Read data to make sure it exists
               studio = lineScan.next();
               rating1 = lineScan.nextInt();
               rating2 = lineScan.nextInt();
               rating3 = lineScan.nextInt();
               // Create the Movie object and add it to the list
               Movie aMovie = new Movie(title, cost, studio);
               aMovie.setStudio(studio);
               aMovie.setActing(rating1);
               aMovie.setDirecting(rating2);
               aMovie.setSoundtrack(rating3);  
               data.add(aMovie);
            }
         }
      } catch( InputMismatchException e ) {
         System.err.println("Data error in " + fileName 
                            + "\nInvalid data found - namely " + lineScan.next()
                            + "\nin line " + lineNum + ": " + line );
         System.exit(1);
      } catch( NoSuchElementException e ) {
         System.err.println("Data error in " + fileName 
                            + "\nNot enough data items in line"
                            + "\non line " + lineNum + ": " + line );
         System.exit(1);
      } catch ( Exception e) {
         System.err.println("Unknown data error in " + fileName
                            + "\non line " + lineNum + ": " + line );
         System.exit(1);
      }
    
      // Copy the ArrayList into an array and return it.
      arr = new EntertainmentItem[ data.size() ];
      for( int i = 0; i < data.size(); i++) {
         arr[i] = data.get(i);
      }
      data = null;    // we don't need the ArrayList any more 
      return arr;
   }   // method loadData

   /** 
    * This is the main program that reads the loads the data and
    * then responds to arguments on the command line.
    *
    * Note:  Students were provide this routine but it only contained
    * the instructions load and print the data.
    */
   public static void main ( String[] args ) {
      // test driver program to test the loadData method       
      EntertainmentItem[] entItems;
    
      // read the data
      entItems = loadData("exampledata.txt");
      // print the data  This listing is optional.  It is not required
      System.out.println("***************** Complete listing of Items *****************");
      for (EntertainmentItem item : entItems)
         System.out.println(item);
         
     System.out.println();
         ///////////////////////////////////////////////////////////
         // The rest of the class would have to be written by the 
         // student.
         ///////////////////////////////////////////////////////////
    
     // List by sort rating
     listByRating();
     vocals(4); // call method to list items whose rating of vocals are higher than 4
     actings(3); // call method to list items whose rating of acting are higher than 3
     budget(10);// call method to list items whose price are lower than 10
     listByTitle();// call method to sort items by title
     help();// call method to give help menu
     
   }  // method main
   
   /**
    * This ListByRating method is to sort a list of entertainment item by its rating
    */
   public static void listByRating(){
	   EntertainmentItem[] entItems;
	   entItems = loadData("exampledata.txt");
	   System.out.println("**************** Listed by Rating ***************");
	   Arrays.sort(entItems);
	   for (EntertainmentItem item : entItems)
		   System.out.println(item);    
	   System.out.println();
   }//List by Rating
   
   /**
    * This method is to give a list of sorted Album by its rating of vocal
    * @param num The lowest rating of vocal of the album
    */
   public static void vocals(double num){
	   EntertainmentItem[] entItems;
	   entItems = loadData("exampledata.txt");
	   System.out.println("******************** Listed by Rating of Vocals ****************");
	   Arrays.sort(entItems);
	   for (EntertainmentItem item: entItems){
		   if ( item instanceof Album){
			  if(((Album) item).getVocal() >=num){
				  System.out.println(item);
			  }
		   }
	   }
	   System.out.println();
   }// vocals
   
   /**
    * This method is to give a list of sorted movie by its rating of acting
    * @param num The lowest rating of ratings of the movie
    */
   public static void actings(double num){
	   EntertainmentItem[] entItems;
	   entItems = loadData("exampledata.txt");
	   System.out.println("******************** Listed by Rating of Actings *****************");
	   Arrays.sort(entItems);
	   for (EntertainmentItem item: entItems){
		   if ( item instanceof Movie){
			  if(((Movie) item).getActing() >=num){
				  System.out.println(item);
			  }
		   }
	   }
	   System.out.println();
   }// actings
   /**
    * This methods is to give a list of items by a given price.
    * @param price The price you want to set.
    */
   public static void budget(double price){
	   EntertainmentItem[] entItems;
	   entItems = loadData("exampledata.txt");
	   System.out.println("******************* Listed of the price you can afford *******************");
	   Arrays.sort(entItems);
	   for (EntertainmentItem item: entItems){
		   if (item.getCost()<=price){
			   System.out.println(item);
		   }
	   }
	   System.out.println();
   }
   /**
    * This method is to sort a list of Entertainment items by its title.
    */
   public static void listByTitle(){
	   EntertainmentItem[] entItems;
	   entItems = loadData("exampledata.txt");
	   System.out.println("********************** Listed by Title *******************");
	   Arrays.sort(entItems,EntertainmentItem.titleComparator);
	   for (EntertainmentItem item : entItems)
		   System.out.println(item);    
	   System.out.println();
	 
   }
   /**
    * This help method is to give the instruction of what you can do with this program
    */
   public static void help(){
	   System.out.println("-----------------------------------THIS iS HELP MENU---------------------------------------");
	   System.out.println("Enter: java Entertainment listByRating. This code will give you a list of items sorted by rating! ");
	   System.out.println("Enter: java Entertainment vocals [number]. This code will give you a list of Albums whose ratings of Vocal are higher your expectation. " );
	   System.out.println("Enter: java Entertainment acting [number]. This code will give you a list of Movies whose ratings of Acting are higher your expectation. ");
	   System.out.println("Enter: java Entertainment budget [number]. This code will give you a list of items' cost. ");
   }
   
}// end