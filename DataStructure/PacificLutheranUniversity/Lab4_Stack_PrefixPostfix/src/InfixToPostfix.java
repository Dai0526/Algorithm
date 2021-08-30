  /*Name: Tianhua Fang	
  Assignment: Lab 4
  Title: LinkedStack and Infix to Postfix Converter
  Course: CSCE 270
  Lab Section: 02
  Semester: Fall, 2014
  Instructor: Laurie Murphy
  Date: October 11th 2014
  Sources consulted: Lab Handout, instructor
  Program description: This program is to change the infix math expression of a  
  		Spring into a postfix math expression. There are two private methods to 
  		test if it is operator and the order of the expressions.
  Known Bugs: Error will occur String include other symbols such as @,#,$,etc.
  		      Space between number and operator works for convert method, but 
  		      sometimes may have error when using evaluate method.
  Creativity: Evaluate the value
*/
import java.util.Stack;


public class InfixToPostfix  {
	public static String convert( String infix ){
		  String postfix = "";  
		  Stack<String> s = new Stack<String>();  //stack to hold symbols
		  s.push("+");// give a plus to prevent empty stack excpetion in line 13
		  for(int i = 0; i < infix.length(); i++){
			  char ch = infix.charAt(i);  
			  if(isOperator(Character.toString(ch))){  //if a operator
				  //loop pops if stack top has same or higher precedence
				  while(precedence(Character.toString(ch),s.peek())==-1){
					    postfix += s.pop();    
				  }
				  s.push(Character.toString(ch));  
			  }
			  else if(ch == '(')
				  s.push(Character.toString(ch));  //push if (
			  else if(ch == ')'){//keep pop if right parenthesis until get left parenthesis
				  while(!s.peek().equals("(")){
					  postfix += s.pop();
				  }
				  s.pop();
			  }
			  else
				  postfix += Character.toString(ch);  
			  
			  //System.out.println(postfix); //test each loop to see algrothim
		  	}
		 
		  //pops all elements of stack left
		  while(s.size()>1){//leave the + sign pop at the beginning
			  postfix += s.pop();
		  	}
		  
        return postfix;

     }

	
	private static boolean isOperator(String s){
		boolean operator=false;
		if (s.equals("*")||s.equals("+")||s.equals("-")||s.equals("/")||s.equals("^")){
			operator=true;
		}
		return operator;
	}
	
	private static int precedence(String operator1, String operator2){
		int orderFor1=0;
		int orderFor2=0;
		int result;
		
		if (operator1.equals("-")||operator1.equals("+")){
			orderFor1=0; 
		}
		else if (operator1.equals("*")||operator1.equals("/")){
			orderFor1=1;
		}
		else if(operator1.equals("^")){
			orderFor1=2;
		}
		
		if (operator2.equals("-")||operator2.equals("+")){
			orderFor2=0; 
		}
		else if (operator2.equals("*")||operator2.equals("/")){
			orderFor2=1;
		}
		else if(operator2.equals("^")){
			orderFor2=2;
		}
		
		if (orderFor1>orderFor2){
			result=1;
		}
		else if(orderFor1<orderFor2){
			result = -1;
		}
		else{
			result=0;
		}
		return result;
	}



	public static String Evalute(String s){
		Stack<String> data = new Stack<String>();
		for(int i=0; i<s.length();i++){
			char c =s.charAt(i);
			if(!isOperator(Character.toString(c))){
				String temp= Character.toString(c);
				data.push(temp);
			}
			else{
				int num1=Integer.parseInt(data.pop());
				int num2=Integer.parseInt(data.pop());
				if(c=='+'){
					int result=num1+num2;
					data.push(Integer.toString(result));
				}
				if(c=='-'){
					int result=num2-num1;
					data.push(Integer.toString(result));
				}
				if(c=='*'){
					int result=num1*num2;
					data.push(Integer.toString(result));
				}
				if(c=='/'){
					int result=num2/num1;
					data.push(Integer.toString(result));
				}
				if(c=='^'){
					int result=(int) Math.pow(num2,num1);
					data.push(Integer.toString(result));
				}
			}//else
		}// for
				
		return data.pop();
	}

}
