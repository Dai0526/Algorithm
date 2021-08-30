  //Name: Tianhua Fang
  //Assignment: Lab 1
  //Title: Matrix Class -- Eclipse, Classes, 2-Dimensional Arrays, JUnit Testing
  //Course: CSCE 270
  //Lab Section: 02
  //Semester: Fall, 2014
  //Instructor: Laurie Murphy
  //Date: Sept 18th
  //Sources consulted: java doc, Professr Murphy
  //Program description: This Matrix program is to construct matrix with any dimension.
  //                 It can do some operations like addition, subtraction and multiplication.
  //                 There are more functions it can work for, such as  check isDiagonal, 
  //                 check equal, get information about # rows, # columns, element of a
  //                 certain position and set element.
  //Known Bugs: The dimensions of matrix has to be matched as default. Addition, subtraction,  
  //            and multiplication will not work if the dimension doesn't match. Later on, 
  //            I will add some codes to check the dimensions before we do the operation for matrixes.
  //Creativity: 1. Construct matrix from a existed matrix file.
  //            2. Add the multiplication function.


import java.util.*;
import java.io.*;

public class Matrix {
	private int rows;
	private int columns;
	private int[][] matrix; // initialize a matrix

/**
 * This method is to construct a matrix with r rows and c columns, 
 * and fill all position with 0 as default matrix.
 * 
 * @param r The numbers of rows for the matrix .
 * @param c The number of columns for the matrix.
 */
	
	public Matrix(int r, int c){
		matrix = new int [r][c];
		rows=r;
		columns=c;
		for (int i=0; i<rows;i++)
			for(int j=0; j< columns; j++)
				this.matrix[i][j]=0;
	}// end matrix constructor with rows and clumns
	
	/**
	 * This method is to create 2x2 matrix will all elements are 0 as default.
	 * Note that columns = rows =2
	 */
	public Matrix(){
		matrix = new int [2][2];
		this.rows=2;
		this.columns=2;
		for (int i=0; i<rows;i++)
			for(int j=0; j< columns; j++)
				this.matrix[i][j]=0;
	}// end matrix with no parameter
	
	/**
	 * This method is to copy a matrix from the object matrix you choose.
	 * The size and all elements is exactly the same as the object matrix.
	 * 
	 * @param other The matrix you want to copy.
	 */
	
	public Matrix(Matrix other){ 
		rows=other.rows;
		columns=other.columns; // copy the #rows and #columns
		matrix =new int[rows][columns];
		for (int i=0; i<rows; i++)
			for (int j=0; j<columns; j++)
				matrix[i][j]=other.matrix[i][j];// copy the element in each position			
	}// end matrix copy function
	
	/**
	 * This method is to create a matrix by read a matrix TXT file in your folder.
	 * The matrix will be constructed by the given rows, elements, and all specific
	 * elements.
	 * 
	 * @param fileName The name of matrix file.
	 * @throws FileNotFoundException File not found exception.
	 */
	public Matrix (String fileName) throws FileNotFoundException{
		File file = new File(fileName);
		Scanner inputFile = new Scanner(file);
			rows=inputFile.nextInt();
			columns=inputFile.nextInt();
			
			matrix=new int[rows][columns];
			for (int i=0;i<rows;i++)
				for (int j=0;j<columns;j++)
					matrix[i][j]=inputFile.nextInt();
			
		inputFile.close();
	} // end matrix constructor from reading a FILE
	
	
	/**
	 * This method is to get the number of columns of the object matrix. 
	 * 
	 * @return Return number of columns. 
	 */
	public int getColumns(){
		return this.columns;
	}// end get columns
	
	
	/**
	 * This method is to get the number of rows of the object matrix. 
	 * 
	 * @return Return number of rows. 
	 */
	public int getRows(){
		return this.rows;
	}// end get rows
	
	
	/**
	 * This method is to set up a value into the matrix with a specific position.
	 * 
	 * @param r       Position row
	 * @param columns Position columns
	 * @param val     The value to be set up in this position
	 *  
	 * @return  Return number of columns. 
	 */
	public void setElement(int r, int c, int val){
		this.matrix[r][c]=val;
	
	}// end set elements
	
	
	/**
	 * This method is to get the element from a given position of the object matrix.
	 * 
	 * @param r Position information: rows
	 * @param c Position information: columns
	 * 
	 * @return return the value of the given position from matrix.
	 * 
	 */
	public int getElement(int r, int c){
		return this.matrix[r][c];
	}// end get elements

	
	/**
	 * This Method is to show the information of a matrix.
	 * 
	 * @return Return the information by String.
	 */
	public String toString(){
		return "This is a Matrix with "+this.rows+" rows and "+ this.columns+" columns";
	}// end toString
	
	
	/**
	 * This method is get the sum of two given matrixes, which have the same dimension
	 * 
	 * @param other A matrix has the same dimension with the object matrix.
	 * @return Return a matrix which is the sum of two given matrixes.
	 */
	public Matrix plus(Matrix other){
		rows=this.getRows();
		columns=this.getColumns();
		Matrix C= new Matrix(rows, columns);
		for (int i=0; i<rows; i++){
			for (int j=0; j<columns; j++){
				C.matrix[i][j]= this.matrix[i][j]+ other.matrix[i][j];
			}
		}
		return C;  // addition		
	}//end sum
	
	/**
	 * This method is get the subtraction of two given matrixes, which have the same dimension
	 * 
	 * @param other A matrix has the same dimension with the object matrix.
	 * @return Return a matrix which is the subtraction of two given matrixes.
	 */
	public Matrix minus(Matrix other){
		rows=this.getRows();
		columns=this.getColumns();
		Matrix C= new Matrix(rows, columns);
		for (int i=0; i<rows; i++)
			for (int j=0; j<columns; j++)
				C.matrix[i][j]= this.getElement(i,j)- other.getElement(i,j);
		return C;  
	}//subtraction	
	
	
	/**
	 * This method is get the multiplication of two given matrixes. The number of rows of Matrix A 
	 * need to be equal to the number of columns of Matrix B.
	 * 
	 * @param other A matrix 'B', which the numbers of columns is equal to the number of rows of Matrix A
	 * @return Return a new matrix C which is the multiplication of two given matrixes.
	 * 
	 */
	public Matrix times(Matrix other){
		rows=this.getRows();
		columns=this.getColumns();
		// if (rows!=other.getColumns()) to check dimension		
		Matrix C= new Matrix(rows, columns);
		for (int i=0; i<columns; i++){
			for (int j=0; j<rows; j++){
				for (int count=0; count<columns;count++){
					C.matrix[i][j]+= this.matrix[i][count]*other.matrix[count][j];
				}
			}
		}
		return C;
	}// end multiplication
	
	
	/** This method is to check if the object matrix is diagonal, which means all elements when
	 * columns not equal to row is 0.
	 * 
	 * @return True if it is diagonal or False if it is not diagonal.
	 */
	public boolean isDiagonal(){
		int columns=this.getColumns();
		int rows=this.getRows();
		boolean diagonal=true;
		if (rows != columns)
			diagonal=false;	// check if the dimension match		
		else
			for (int i=0; i<rows; i++)
					for (int j=0; j<columns;j++)
						if(i!=j && matrix[i][j]==0)
							diagonal=true;    // check the elements is 0 or not
		return diagonal;	
	}// end diagonal
	
	
	/**This method is to check if two given Matrix A, B is the same.
	 * Same dimension and same elements corresponding to each position.
	 * 
	 * @param a Matrix a;
	 * @param b Matrix b;
	 * @return  True if Matrix a,b are the same, or False if Matrix a,b are different.
	 */
	public static boolean isEqual(Matrix a, Matrix b){
		boolean equal=true;
		if (a.getRows()!=b.getRows()&&a.getColumns()!=b.getColumns())
			equal=false;
		for (int i=0; i<a.getRows(); i++)
			for (int j=0; j<a.getColumns(); j++)
				if (a.matrix[i][j] != b.matrix[i][j])
					equal=false;
		return equal;		
	} // end equal


	
}// the last bracket
