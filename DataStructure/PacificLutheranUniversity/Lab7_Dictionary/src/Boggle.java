/*
 *Name: Tianhua Fang	
  Assignment: Lab 07
  Title: Boggle & Recursion
  Course: CSCE 270
  Lab Section: 02
  Semester: Fall, 2014
  Instructor: Laurie Murphy
  Date: November 9th 2014
  Sources consulted: Lab Handout
  Program description: This program contains three parts, board constructor, dictionary
  					  constructor, and the board game main part. It reads board and
  					  dictionary information from source files. Enter empty string to 
  					   stop the game anddisplay the total score you get.
  					  Players don't need to care about lowerCase or UpperCase for input,
  					  program will automatically convert it into the proper formation.
  					  
  					  					  
  Known Bugs: NA
  Creativity: At the end of the game, it will show all the words which is in dictionary
  			  but player didn't found.
 */

import java.util.*;
import java.io.*;

public class Boggle {
	public static void main(String args[]) throws IOException{
		//set up 
		BoggleBoard board;
		Dictionary dict;
		String userInput;
		int totalScore=0;
		LinkedList<String> userWords=new LinkedList<String>();//used to store all user's input,
																//so that one word will not be 
														      //counted repeately	
		board= new BoggleBoard("board.txt");
		dict= new Dictionary("words.txt");
		Scanner sc = new Scanner(System.in);
		
		//Display the first set of board and ask for words.
		System.out.println(board.toString());
		System.out.println("---------");
		System.out.println("Enter a word: ");
		userInput=sc.nextLine().toUpperCase();

		
		while(!userInput.equals("")){			
			System.out.println(board.toString());
			System.out.println("-------");
			if(userInput.length()<3){
				System.out.println("The word "+userInput+" is too short. ");
			}
			else if(userWords.contains(userInput)){// repeat one words is not allowed!!!
				System.out.println("The word "+userInput+" has already been used. ");
			}
			else if(Dictionary.Search(dict.dictionary, userInput)==true){
				if(board.onBoard(userInput)==true){
					userWords.add(userInput);// add the vaild words into a list
					System.out.println("The word "+ userInput+" is good!  You score "+score(userInput)+" points!");
					totalScore= totalScore+ score(userInput);//add score
				}
				else{
					System.out.println("The word "+userInput+" word is a valid word, but is not on the board.");
				}
			}
			else{
				System.out.println("The word "+userInput+" is not a valid word (not in the dictionary).");
			}	
			
			board.clearAllMark();//clear all marks so we can do next words properly
			System.out.println("Enter a word: ");
			userInput=sc.nextLine().toUpperCase();//ask for next word
		}
		if(userInput.equals("")){
			//creativity part to give a list of unused word but in dictionary
			LinkedList<String> allwords=new LinkedList<String>();
			for(int i=0;i<dict.dictionary.length;i++){
				String newWord=dict.dictionary[i].toUpperCase();
				if(board.onBoard(newWord)==true&&newWord.length()>=3&&!userWords.contains(newWord)){
					//#1  on baord,        #2 length greater than3   # not found during game
					allwords.add(dict.dictionary[i]);
				}
				board.clearAllMark();//clear all marks to run check all dictionary words
			}
			
			System.out.println("Game Over");
			System.out.println("Totoal score : "+totalScore);
			System.out.println("Below are all the words can be found on this board and you did't find!");
			System.out.println(allwords.toString());
			
			userWords.clear();// clear the user's words list so it won't affect next game
		}
		
	}
	
	/**
	 * Return score depends on the length of your words.
	 * @param words the input word
	 * @return the score you get
	 */
	public static int score(String words){
		if(words.length()<3){
			return 0;
		}
		else if(words.length()==3||words.length()==4){
			return 1;
		}
		else if(words.length()==5){
			return 2;
		}
		else if(words.length()==6){
			return 3;
		}
		else if(words.length()==7){
			return 5;
		}
		else{
			return 11;
		}
	}
	

		
	
}
