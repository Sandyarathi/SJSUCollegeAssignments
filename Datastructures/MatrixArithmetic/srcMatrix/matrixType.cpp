/*
 * matrixType.cpp
 *
 *  Created on: Sep 27, 2014
 *      Author: sandyarathidas
 */

#include "matrixType.h"


//Constructor
//sets the matrix row size and column size
matrixType::matrixType(int rowSize,int columnSize) {
	this->rowSize=rowSize;
	this->columnSize=columnSize;
	//calls the method to initialize the matrix with given dimensions i.e allocate memory
	initializeMatrix();



}
//function to allocate memory to the matrix dynamic array
void matrixType::initializeMatrix() {
	matrix = new int *[rowSize];
		for(int i=0;i<rowSize;i++){
			matrix[i] = new int[columnSize];
			if(matrix[i]==NULL){
				//any error allocating the memory based on dimensions is captured.
				cerr<<"error allocating memory to matrix"<<endl;
			}
		}

}

//Copy constructor
//used to deep copy the result of the operation stored in a temp object to a resultant matrix object
//Pre-Condition : A matrix Object is passed
//Post-Condition : Corresponding matrix values are copied into the calling object space.
matrixType::matrixType(const matrixType& matrixObj) {
	this->rowSize=matrixObj.rowSize;
	this->columnSize=matrixObj.columnSize;
	initializeMatrix();
	for(int i = 0; i<rowSize;i++){
		for(int j = 0; j<columnSize;j++){
			this->matrix[i][j]=matrixObj.matrix[i][j];
		}
	}
}

//Destructor
matrixType::~matrixType() {
	for(int i=0;i<rowSize;i++){
		delete matrix[i];
	}
	delete[] matrix;
	matrix=NULL;
}

//Sets the matrix values from console
void matrixType::setMatrix() {
	cout<<"\nEnter the elements of the " <<rowSize<<"x"<<columnSize<<" Matrix, row wise: ";
	//Oveloaded instream operator used.
	cin>>*this;
	cout<<"The Matrix has been accepted: "<<endl;
	//Oveloaded outstream operator used.
	cout<<*this;
}


//overloaded >> operator function
istream& operator>> (istream &in, matrixType &matrixObj){

	for(int i=0;i<matrixObj.rowSize;i++){
		for(int j=0;j<matrixObj.columnSize;j++){
            //each value entered through the console is set into the matrix index positions
			in>> matrixObj.matrix[i][j];
		}
	}
	return in;
}

//overloaded << operator function
 ostream& operator <<(ostream& out, matrixType &matrixObj) {
	 for(int i = 0; i<matrixObj.rowSize;i++){
		 for(int j = 0; j< matrixObj.columnSize;j++){
			 //each value of the matrix is output to the console in a matrix format.
			 out<<matrixObj.matrix[i][j]<<"\t";
		 }
		 out<<"\n";
	 }
	 return out;
}

//overloaded addition operator
//The redefinition  of Addition operator is implemented
 //post-condition : result matrix is returned
matrixType matrixType::operator +(const matrixType& matrixObj) {
	matrixType sumObj = matrixType(rowSize,columnSize);
	for(int i=0;i<rowSize;i++){
		for(int j=0;j<columnSize;j++){
			//values from corresponding indices are added and stored in result object and returned
			sumObj.matrix[i][j] = this->matrix[i][j] + matrixObj.matrix[i][j];
		}
	}

	return sumObj;
}

//overloaded difference operator
//The redefinition  of subtraction operator is implemented
//post-condition : result matrix is returned
matrixType matrixType::operator -(const matrixType& matrixObj) {
	matrixType diffObj = matrixType(rowSize,columnSize);
		for(int i=0;i<rowSize;i++){
			for(int j=0;j<columnSize;j++){
				//values from corresponding indices are added and stored in result object and returned
				diffObj.matrix[i][j] = this->matrix[i][j] - matrixObj.matrix[i][j];

			}
		}


		return diffObj;
}

//overloaded multiplication operator
//The redefinition  of multiplication operator is implemented
//post-condition : result matrix is returned
matrixType matrixType::operator *(const matrixType& matrixObj) {
	matrixType multObj = matrixType(this->rowSize,matrixObj.columnSize);
	int sum=0;
	for(int i=0;i<rowSize;i++){
		for(int j=0;j<matrixObj.columnSize;j++){
			sum=0;
			for(int k=0;k<matrixObj.rowSize;k++){
				//values from corresponding indices are multiplied and added and stored in result object and returned
				sum= sum + this->matrix[i][k] * matrixObj.matrix[k][j];

			}

			multObj.matrix[i][j]=sum;
		}
	}
	return multObj;
}

//assignment operator overloading
//The redefinition  of assignment operator is implemented i.e the passed object values are copied into the calling object.
//post-condition : Pointer to the calling object is returned.
matrixType matrixType::operator =(const matrixType& matrixObj) {
	this->columnSize=matrixObj.columnSize;
	this->rowSize=matrixObj.rowSize;
	for(int i=0;i<rowSize;i++){
			for(int j=0;j<columnSize;j++){
				this->matrix[i][j] = matrixObj.matrix[i][j];

			}
		}
	return *this;

}

