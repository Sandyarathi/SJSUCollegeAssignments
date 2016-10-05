/*
 * matrixType.h
 *
 *  Created on: Sep 27, 2014
 *      Author: sandyarathidas
 */



#ifndef MATRIXTYPE_H_
#define MATRIXTYPE_H_

#include <iostream>
using namespace std;

class matrixType {
public:
	matrixType(int, int);		//constructor
	~matrixType();				//destructor
	matrixType(const matrixType&);		//copy constructor

	//operator overloading functions
	friend ostream& operator<< (ostream &out,matrixType &matrixObj);
	friend istream& operator>> (istream &in, matrixType &matrixObj);
	matrixType operator+(const matrixType&);
	matrixType operator-(const matrixType&);
	matrixType operator*(const matrixType&);
	matrixType operator=(const matrixType&);
	//void displayMatrix();
	void setMatrix();			//accepts matrix from user through console
	int getColumnSize() const {//getter function for column size
		return columnSize;
	}

	void setColumnSize(int columnSize) {
		this->columnSize = columnSize;//setter function for column size
	}

	int getRowSize() const {//getter function for row size
		return rowSize;
	}

	void setRowSize(int rowSize) {
		this->rowSize = rowSize;//setter function for row size
	}

private:
	int ** matrix;
	int rowSize;
	int columnSize;
	void initializeMatrix();//Method used to initialize Matrix object with matrix values and dimensions.

};

#endif /* MATRIXTYPE_H_ */
