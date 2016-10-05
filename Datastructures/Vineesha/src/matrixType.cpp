#include<iostream>
#include<istream>
#include<ostream>
#include "matrixType.h"


matrixType::matrixType(const int &row, const int &col) {
	cout << " Calling default constructor\n";
	rowSize = row;
	columnSize = col;
	matrix = new int*[rowSize];
	for (int countR = 0; countR < rowSize; countR++) {
		matrix[countR] = new int[columnSize];
	}
	for (int countR = 0; countR < rowSize; countR++) {
		for (int countC = 0; countC < columnSize; countC++) {
			matrix[countR][countC] = 0;
			//cout << matrix[countR][countC] << "\t";
		}
		cout << endl;
	}
}

//copy constructor performing deep copy
matrixType::matrixType(matrixType &matObj) {
	//matrixType tempMat;
	cout << " Calling copy constructor\n";
	rowSize = matObj.rowSize;
	columnSize = matObj.columnSize;
	matrix = new int*[rowSize];
	for (int count = 0; count < rowSize; count++) {
		matrix[count] = new int[columnSize];
	}
	cout << "this->rowSize ============= " << rowSize;
	cout << "this->columnSize ============= " << columnSize;
	for (int rowC = 0; rowC < rowSize; rowC++) {
		for (int colC = 0; colC < columnSize; colC++) {
			matrix[rowC][colC] = matObj.matrix[rowC][colC];
			cout << matrix[rowC][colC] << "\t";
		}
	}

}

//destructor
matrixType::~matrixType() {
	cout << " Calling destructor\n";
		delete [] matrix;
}

//implementing overloaded >> operator as friend function
istream& operator >>(istream &mat_in, matrixType &mat) {
	/*cout << "Enter the number of rows and columns for matrix :" << endl;
	mat_in >> mat.rowSize;
	mat_in >> mat.columnSize;*/
	cout << "overloaded >> operator \n";
	cout << mat.rowSize << " ==== " << mat.columnSize;
	cout << "Enter the elements for matrix :" << endl;
	if (mat.rowSize != 0 && mat.columnSize != 0) {
		for (int rowCount = 0; rowCount < mat.rowSize; rowCount++) {
			for (int colCount = 0; colCount < mat.columnSize; colCount++) {
				mat_in >> mat.matrix[rowCount][colCount];
			}
		}
	}

	return mat_in;
}

//implementing overloaded << operator as friend function
ostream& operator <<(ostream &mat_out, matrixType &mat) {
	cout << "overloaded << operator \n";
	//rowSize = mat.rowSize;
	cout << mat.rowSize << " ==== " << mat.columnSize;
	for (int rCount = 0; rCount < mat.rowSize; rCount++) {
		for (int cCount = 0; cCount < mat.columnSize; cCount++) {
			mat_out << mat.matrix[rCount][cCount] << "\t";
		}
	}
	return mat_out;
}

void matrixType::setMatrix(const int &rowVal, const int &colVal) {
	/*cout << "Enter the number of rows and columns for matrix :" << endl;
	cin >> rowSize;
	cin >> columnSize;*/
	cout << "in setMatrix \n";
	cout << " Now matrix row size is === " << rowVal << endl;
	cout << " Now matrix col size is === " << colVal << endl;

	/*cout << "Enter the elements for matrix :" << endl;
	if (this->rowSize != 0 && this->columnSize != 0) {
		for (int rowCount = 0; rowCount < this->rowSize; rowCount++) {
			for (int colCount = 0; colCount < this->columnSize; colCount++) {
				cin >> matrix[rowCount][colCount];
			}
		}
	}*/
	for (int i = 0; i < rowVal; i++) {
		for (int j = 0; j < colVal; j++) {
			cout << matrix[i][j] << "\t";
		}
	}
	cout << "Enter the elements for matrix :" << endl;
	if (rowVal != 0 && colVal != 0) {
		for (int rowCount = 0; rowCount < rowVal; rowCount++) {
			for (int colCount = 0; colCount < colVal; colCount++) {
				//cout << "At row " << rowCount << " and column " << colCount << endl;
				cin >> matrix[rowCount][colCount];
				//cout << matrix[rowCount][colCount] << "\t";
			}
		}
	}
	cout << endl;
}

matrixType matrixType::operator +(matrixType &mat) {
	//Creating an 2D int array object to store sum
	cout << "in + operator overloading" << endl;
	cout << rowSize << endl;
	cout << columnSize << endl;
	matrixType sumMat(rowSize, columnSize);
	if (rowSize == mat.rowSize && columnSize == mat.columnSize) {
		for (int rowC = 0; rowC < rowSize; rowC++) {
			for (int colC = 0; colC < columnSize; colC++) {
				sumMat.matrix[rowC][colC] = matrix[rowC][colC] + mat.matrix[rowC][colC];
				cout << sumMat.matrix[rowC][colC] << "\t";
			}
			cout << endl;
		}
	}
	else {
		cout << " The sizes of the two matrices must be the same to perform addition.\n";
		return *this;
	}
	return sumMat;

}

matrixType matrixType::operator -(matrixType &mat) {
	//Creating an 2D int array object to store difference between two matrices
	cout << "in - operator overloading" << endl;
	matrixType diffMat(rowSize, columnSize);
	for (int rowC = 0; rowC < rowSize; rowC++) {
		for (int colC = 0; colC < columnSize; colC++) {
			diffMat.matrix[rowC][colC] = matrix[rowC][colC] - mat.matrix[rowC][colC];
			cout << diffMat.matrix[rowC][colC] << "\t";
		}
		cout << endl;
	}
	return diffMat;
}

matrixType matrixType::operator *(matrixType &mat) {
	//Creating an 2D int array object to store product of two matrices
	cout << "in * operator overloading" << endl;
	matrixType prodMat(rowSize, columnSize);
	for (int rowC = 0; rowC < rowSize; rowC++) {
		for (int colC = 0; colC < columnSize; colC++) {
			prodMat.matrix[rowC][colC] = 0;
			for (int count = 0; count < mat.rowSize; count++) {
				prodMat.matrix[rowC][colC] = prodMat.matrix[rowC][colC]
					+ matrix[rowC][count] * mat.matrix[count][colC];
			}
			cout << prodMat.matrix[rowC][colC] << "\t";
		}
		cout << endl;
	}
	return prodMat;

}

matrixType matrixType::operator =(matrixType &mat) {
	//Creating an 2D int array object to store product of two matrices
	cout << "in = operator overloading" << endl;
	matrixType equalMat(rowSize, columnSize);
	for (int rowC = 0; rowC < rowSize; rowC++) {
		for (int colC = 0; colC < columnSize; colC++) {
			equalMat.matrix[rowC][colC] = 0;
			for (int count = 0; count < mat.rowSize; count++) {
				equalMat.matrix[rowC][colC] = mat.matrix[rowC][colC];
			}
			cout << equalMat.matrix[rowC][colC] << "\t";
		}
		cout << endl;
	}
	return *this;

}
