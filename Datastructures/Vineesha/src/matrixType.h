#include<iostream>
#include<istream>
using namespace std;

class matrixType {
public:
	//constructor with parameters
	matrixType(const int &, const int &);

	//destructor
	~matrixType();

	//copy constructor
	matrixType(matrixType &);

	//member function
	void setMatrix(const int &, const int &);

	//overloaded functions
	matrixType operator +(matrixType &);
	matrixType operator -(matrixType &);
	matrixType operator *(matrixType &);
	matrixType operator =(matrixType &);

	//overloading >> and << operators as friend functions
	friend istream& operator >>(istream &, matrixType &);
	friend ostream& operator <<(ostream &, matrixType &);

private:
	int** matrix;
	int rowSize;
	int columnSize;

};
