#define	SIZE 13

#include <iostream>
#include "arrayListType.h"

using namespace std;

void printListInfo(arrayListType<int>& listInfo);

int list[SIZE] = {34, 77, 26, 51, 39, 8, 12, 67, 4, 98, 123, 10, 42};

int main()
{
	arrayListType<int> intList;
	int num;

	cout << "testKthLargestItem by Das,Sandyarathi." << endl << endl;

	for (int i = 0; i < SIZE; ++i) {
		intList.insert(list[i]);
	}

	cout << "The list is: " << endl;
	printListInfo(intList);

	intList.kThLargestItem(11, num);
	cout << "The 11th element = " << num << endl;

	intList.kThLargestItem(3, num);
	cout << "The 3rd element = " << num << endl;

	intList.kThLargestItem(7, num);
	cout << "The 7th element = " << num << endl;

	return 0;
}

void printListInfo(arrayListType<int>& list)
{
	cout << "List: ";
	list.print();

	cout << "List Size: " << list.listSize() << endl;
}
