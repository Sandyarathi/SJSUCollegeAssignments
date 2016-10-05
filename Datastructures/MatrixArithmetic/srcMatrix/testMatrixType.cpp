/*
 * testMatrixType.cpp
 *
 *  Created on: Sep 27, 2014
 *      Author: sandyarathidas
 */

#include<iostream>
#include "matrixType.h"
#include<stdlib.h>
using namespace std;

//Based on users choice of operation to be performed on the Matrix,it takes
//in the values of the input matrices and validates their dimensions.
//Pre-Condition : The user choice must be passed for the selection of operation
//Post-Condition: It prompts the user for the dimensions(rowsize and column size) of the two input matrices
//And based on the operation choice,it validates the dimensions of the two matrices.
//If the dimensions are valid for the operation,then the two matrix objects are either added,subtracted or multiplied
//The operators used for the operations have been overloaded.
//If the dimensions are invalid,it displays the appropriate message to the user and prompts another entry of choice.

int operation(int option){
	/**
	 * option=1 for addition
	 * option=2 for subtraction
	 * option=3 for multiplication
	 */
	int rowSize1,columnSize1, rowSize2, columnSize2;
	cout<<"The First Matrix!\n"<<endl;
	cout<<"Enter the row Size: ";

	cin>>rowSize1;
	cout<<"Enter the column Size: "<<endl;

	cin>>columnSize1;
	matrixType matrixObj1 = matrixType(rowSize1,columnSize1);
	//Method to set the matrix values as per the dimensions is called.
	matrixObj1.setMatrix();
	cout<<"\n\nThe Second Matrix!\n"<<endl;

	cout<<"Enter the row Size: ";

	cin>>rowSize2;
	cout<<"Enter the column Size: "<<endl;

	cin>>columnSize2;
	matrixType matrixObj2 = matrixType(rowSize2,columnSize2);
	//Method to set the matrix values as per the dimensions is called.
	matrixObj2.setMatrix();
	matrixType tempMatrix = matrixType(matrixObj1); //placeholder matrix to store result
	if(option==1){
		//Invalid dimensions validation
		if((rowSize1!=rowSize2)|| columnSize1!=columnSize2){
			cerr<<"Cannot add 2 matrices of different dimensions!";
			return -1;
		}

		matrixType resultMatrix = matrixType(rowSize1,columnSize1);
		//Valid dimensions and thus are added.'+' : overloaded addition operator used.
		resultMatrix = tempMatrix + matrixObj2;//assignment
        //The result matrix is displayed.'<<' :overloaded outsream operator used.
		cout<<"\nThe result matrix is:\n "<<endl;
		cout<<resultMatrix;


	}
	else if(option==2){
		if((rowSize1!=rowSize2)|| columnSize1!=columnSize2){
			//Invalid dimensions validation
			cerr<<"Cannot subtract 2 matrices of different dimensions!";
			return -1;
		}
		matrixType resultMatrix = matrixType(rowSize1,columnSize1);
		//Valid dimensions and thus are subtracted.'-' : overloaded subtraction operator used.
		resultMatrix = tempMatrix - matrixObj2;
		cout<<"The result matrix is:\n "<<endl;
		//The result matrix is displayed.'<<' :overloaded outsream operator used.
		cout<<resultMatrix;

	}

	else if(option==3){
		if(columnSize1!=rowSize2){
			//Invalid dimensions validation
			cerr<<"Matrix Multiplication cannot be performed on these 2 matrices. Invalid dimensions!"<<endl;
			return -1;
		}
		matrixType resultMatrix = matrixType(rowSize1,columnSize2);
		//Valid dimensions and thus are multiplied.'*' : overloaded multiplication operator used.
		resultMatrix = tempMatrix * matrixObj2;
		cout<<"The result matrix is:\n "<<endl;
		//The result matrix is displayed.'<<' :overloaded outstream operator used.
		cout<<resultMatrix;
	}

	else{
		//Invalid input choice is captured.
		cerr<<"Invalid Option!"<<endl;
	}
	return 0;
}





int main(){

	//Display Introduction

	cout<<"******************WELCOME TO THE MATRIX*******************"<<endl;
	cout<<"************MATRIX ARITHMETIC BY SANDYARATHI DAS**********"<<endl;
	cout<<"**********************************************************"<<endl;
	short choice;
	while(true){
		choice=0;
		//Display instructions
		cout<<"\n\nEnter your choice!\n"<<endl;
		cout<<"1. Matrix Addition"<<endl;
		cout<<"2. Matrix Subtraction"<<endl;
		cout<<"3. Matrix Multiplication"<<endl;
		cout<<"4. Exit"<<endl;
		cin>>choice;
		switch(choice){
		case 1:
			//Takes choice 1 for addition
			operation(1);
			break;
		case 2:
			//Takes choice 2 for subtraction
			operation(2);
			break;
		case 3:
			//Takes choice 3 for multiplication
			operation(3);
			break;
		case 4:
			//Takes choice 4 to exit the MATRIX APP
			cout<<"Thank you!"<<endl;
			exit(0);
			break;
		default:
			//Traps any other inputs given and displays its Invalidity
			cout<<"Invalid option!\n";
			break;

		}
	}
}



