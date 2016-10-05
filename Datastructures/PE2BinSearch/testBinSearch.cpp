/*
 * testBinSearch.cpp
 *
 *  Created on: Nov 6, 2014
 *      Author: sandyarathidas
 */

#include <iostream>

using namespace std;

struct node {
	int id;
	char *name;
};

// recursively search the array data[] with length size for key
// return the array index of the node with id matching the key (i.e., 0..size-1). else return -1.
int recBinarySearch(const node data[], const int size, const int key)
{
	//data[] is an array of structures.
	//size is the length of the data array
	//key is an id
	int mid;
	int low=0,high=size-1;
	if(low<high){
		mid=(low+high)/2;
		//cout<<"Print mid :"<<mid<<endl;

		if(data[mid].id==key){
			return mid;
		}
		else if(data[mid].id<key){
			//so as the array is in descending order we need to check
			//0-mid indexes of array

			return recBinarySearch(data,mid+1,key);

		}
		else if(data[mid].id>key){//if data [mid].id is > key
			//the array is in descending order so we need to check
			//from mid to size-1
			//cout<<"Print to check if here"<<endl;
			node temp[size-mid];//temporary array of nodes to hold a subset of data.
			int tempIndex=0;
			for(int i=mid+1;i<size;i++){
				temp[tempIndex].id=data[i].id;
				//cout<<temp[tempIndex].id<<endl;
				temp[tempIndex].name=data[i].name;
				//cout<<temp[tempIndex].name<<endl;
				tempIndex++;

			}

			int tempSize=sizeof(temp) / sizeof(node);
			return recBinarySearch(temp,tempSize,key);
		}
	}
	else
		return -1;




}

int main()
{
	cout << "testBinarySaearch by Sandyarathi" << endl;

	// sorted array in descending order (id field of each node)
	node list[] = { { 23, "John" }, { 19, "Mary" }, { 17, "Jane" }, { 13, "Alan" },
						{ 11, "Bob" }, { 7, "Jack" }, { 5, "Sue" }, { 3, "Bill" },
						{ 1, "Lily" }, { 0, "Emily" } };

	int length = sizeof(list) / sizeof(node);

	//cout << "searching 19: " << recBinarySearch(list, length, 19) << endl;
	//cout << "searching 11: " << recBinarySearch(list, length, 11) << endl;
	cout << "searching 0: " << recBinarySearch(list, length, 0) << endl;
	//cout << "searching 9: " << recBinarySearch(list, length, 9) << endl;
	//cout << "searching 23: " << recBinarySearch(list, length, 23) << endl;
	//cout << "searching 15: " << recBinarySearch(list, length, 15) << endl;

	return 0;
}


