#include<iostream>
#include<istream>
#include<ostream>
#include "matrixType.h"

using namespace std;

//int** matrix1=0;
int row, col;
//int row2=0, col2=0;
//matrixType mat1(0, 0), mat2(0, 0);
int main() {
	int choice;

	cout << "Matrix Operations by Neha" << endl;

	cout << "Enter the number of rows and columns for matrix 1" << endl;
	cin >> row;
	cin >> col;
	matrixType mat1(row,col);
	mat1.setMatrix(row, col);

	cout << "Enter the number of rows and columns for matrix 2" << endl;
	cin >> row;
	cin >> col;
	matrixType mat2(row, col);
	mat2.setMatrix(row, col);

	cout << "Enter the choice of matrix operation that you wish to perform:" << endl;
	cout << "1. Matrix Addition\n";
	cout << "2. Matrix Subtraction\n";
	cout << "3. Matrix Multiplication\n";

	cin >> choice;

	matrixType sumMat(row, col), diffMat(row,col),prodMat(row,col);
	switch (choice) {
	case 1:
		cout << " Addition of two matrices :: " << endl;
		//cout << mat1 << "\t+\t" << mat2 << "\t=\t";
		sumMat = mat1 + mat2;
		//cout << mat1 << "\t+\t" << mat2 << "\t=\t";
		cout << sumMat << endl;
		break;
	case 2:
		cout << " Subtraction of two matrices :: " << endl;
		diffMat = mat1 - mat2;
		//cout << mat1 << "\t-\t" << mat2 << "\t=\t";
		cout << diffMat << endl;
		break;
	case 3:
		cout << " Multiplication of two matrices :: " << endl;
		prodMat = mat1 * mat2;
		//cout << mat1 << "\t*\t" << mat2 << "\t=\t";
		cout << prodMat << endl;
		break;
	default: cout << "Invalid choice\n";
		break;
	}
	cout << endl;

	return 0;
}
