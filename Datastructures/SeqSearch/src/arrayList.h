/*
 * arrayList.h
 *
 *  Created on: Nov 4, 2014
 *      Author: sandyarathidas
 */

#ifndef ARRAYLIST_H_
#define ARRAYLIST_H_
/*
 * SeqSer.cpp

 *
 *  Created on: Nov 1, 2014
 *      Author: sandyarathidas
 */

#include<iostream>
using namespace std;

template <class elemType>
class arrayListType
{
public:
	const arrayListType<elemType>& operator=
	(const arrayListType<elemType>&);
	//Overloads the assignment operator
	bool isEmpty() const;
	//Function to determine whether the list is empty
	//Postcondition: Returns true if the list is empty;
	// otherwise, returns false.
	bool isFull() const;
	//Function to determine whether the list is full.
	//Postcondition: Returns true if the list is full;
	// otherwise, returns false.
	int listSize() const;
	//Function to determine the number of elements in the list
	//Postcondition: Returns the value of length.
	int maxListSize() const;
	//Function to determine the size of the list.
	//Postcondition: Returns the value of maxSize.
	void print() const;
	//Function to output the elements of the list
	//Postcondition: Elements of the list are output on the
	// standard output device.
	bool isItemAtEqual(int location, const elemType& item) const;
	//Function to determine whether the item is the same
	//as the item in the list at the position specified by
	//Postcondition: Returns true if list[location]
	// is the same as the item; otherwise,
	// returns false.
	void insertAt(int location, const elemType& insertItem);
	//Function to insert an item in the list at the
	//position specified by location. The item to be inserted
	//is passed as a parameter to the function.
	//Postcondition: Starting at location, the elements of the
	// list are shifted down, list[location] = insertItem;,
	// and length++;. If the list is full or location is
	// out of range, an appropriate message is displayed.
	void insertEnd(const elemType& insertItem);
	//Function to insert an item at the end of the list.
	//The parameter insertItem specifies the item to be inserted.
	//Postcondition: list[length] = insertItem; and length++;
	// If the list is full, an appropriate message is
	// displayed.
	void insertOrd(const elemType& insertItem);
	//Function to insert an item in the list preserving the order.
	//The parameter insertItem specifies the item to be inserted.
	//The appropriate location at which the element can be inserted is found.
	//Postcondition: list[location] = insertItem; and length++;
	// If the list is full, an appropriate message is
	// displayed.
	void removeAt(int location);
	//Function to remove the item from the list at the
	//position specified by location
	//Postcondition: The list element at list[location] is removed
	// and length is decremented by 1. If location is out of
	// range, an appropriate message is displayed.


	void retrieveAt(int location, elemType& retItem) const;
	//Function to retrieve the element from the list at the
	//position specified by location.
	//Postcondition: retItem = list[location]
	// If location is out of range, an appropriate message is
	// displayed.
	void replaceAt(int location, const elemType& repItem);
	//Function to replace the elements in the list at the
	//position specified by location. The item to be replaced
	//is specified by the parameter repItem.
	//Postcondition: list[location] = repItem
	// If location is out of range, an appropriate message is
	// displayed.
	void clearList();
	//Function to remove all the elements from the list.
	//After this operation, the size of the list is zero.
	//Postcondition: length = 0;
	int seqSearch(const elemType& item) const;
	//Function to search the list for a given item.
	//Postcondition: If the item is found, returns the location
	// in the array where the item is found; otherwise,
	// returns -1.
	int recSeqSearch(const elemType& item) const;
	//Recursive Function to search the list for a given item.
	//Postcondition: If the item is found, returns the location
	// in the array where the item is found; otherwise,
	// returns -1.
	int seqSearchOrd(const elemType& item) const;
	//Function to search the list for a given item.
	//Postcondition: If the item is found, returns the location
	// in the array where the item is found; otherwise,
	// returns -1.
	int binSearch(const elemType& item) const;
	//Function to search the list for a given item.
	//Postcondition: If the item is found, returns the location
	// in the array where the item is found; otherwise,
	// returns -1.
	int recBinSearch(const elemType& item) const;
	//Recursive Function to search the list for a given item.
	//Postcondition: If the item is found, returns the location
	// in the array where the item is found; otherwise,
	// returns -1.
	void insert(const elemType& insertItem);
	//Function to insert the item specified by the parameter
	//insertItem at the end of the list. However, first the
	//list is searched to see whether the item to be inserted
	//is already in the list.
	//Postcondition: list[length] = insertItem and length++
	// If the item is already in the list or the list
	// is full, an appropriate message is displayed.
	void remove(const elemType& removeItem);
	//Function to remove an item from the list. The parameter
	//removeItem specifies the item to be removed.
	//Postcondition: If removeItem is found in the list,
	// it is removed from the list and length is
	// decremented by one.
	arrayListType(int size = 100);
	//constructor
	//Creates an array of the size specified by the
	//parameter size. The default array size is 100.
	//Postcondition: The list points to the array, length = 0,
	// and maxSize = size
	arrayListType(const arrayListType<elemType>& otherList);
	//copy constructor
	~arrayListType();
	//destructor
	//Deallocates the memory occupied by the array.
protected:
	elemType *list; //array to hold the list elements
	int length; //to store the length of the list
	int maxSize; //to store the maximum size of the list

private:
	int recSearch(const elemType& item,int first,int last) const;
	int recBin(const elemType& item,int low,int high) const;
};

template <class elemType>
bool arrayListType<elemType>::isEmpty() const{
	if (length==0){
		return true;
	}
	else
		return false;

}
template <class elemType> bool arrayListType<elemType>::isFull() const{

	return (length==maxSize);

}

template<class elemType>
int arrayListType<elemType>::listSize() const {
	return length;
}

template<class elemType>
inline int arrayListType<elemType>::maxListSize() const {
	return maxSize;
}

template<class elemType>
inline void arrayListType<elemType>::print() const {
	for(int i=0;i<length;i++){
		cout<<list[i];
	}
}

template<class elemType>
inline bool arrayListType<elemType>::isItemAtEqual(int location,
		const elemType& item) const {
	return (list[location]==item);
}

template<class elemType>
inline void arrayListType<elemType>::insertAt(int location,
		const elemType& insertItem) {
	if(location<0 || location > maxSize){
		cerr<<"The position at which element is to be inserted is out of range"<<endl;
	}
	else {
		if(location >=maxSize){
			cerr<<"List is full"<<endl;
		}
		else{
			for(int i=length;i>location;i--)
				list[i]=list[i-1];
			list[location]=insertItem;
			length++;

		}
	}



}

template<class elemType>
inline void arrayListType<elemType>::insertEnd(const elemType& insertItem) {
	if(length >= maxSize){
		cerr<<"List is full"<<endl;
	}
	else {

		list[length]=insertItem;
		length++;
	}
}

template<class elemType>
inline void arrayListType<elemType>::removeAt(int location) {
	if(location >length || location<0){
		cerr<<"The location is out of range"<<endl;
	}
	else{
		for(int i=location;i<length;i++){
			list[i]=list[i+1];
		}
		length--;
	}
}

template<class elemType>
inline void arrayListType<elemType>::retrieveAt(int location,
		elemType& retItem) const {
	if(location >length || location<0){
			cerr<<"The location is out of range"<<endl;
	}
	else{
		retItem=list[location];
	}

}

template<class elemType>
inline void arrayListType<elemType>::replaceAt(int location,
		const elemType& repItem) {
	if(location >length || location<0){
		cerr<<"The location is out of range"<<endl;
	}
	else{
		list[location]=repItem;
	}
}

template<class elemType>
inline void arrayListType<elemType>::clearList() {
	length=0;
}

template <class elemType>
int arrayListType<elemType>::seqSearch(const elemType& item) const
{
	int loc=0;
	bool found;
	for(loc=0;loc<length;loc++){
		if(list[loc]==item){
			found=true;
			break;
		}

	}
	if(found){
		return loc;
	}
	else
		return -1;

} //end seqSearch

template<class elemType>
inline void arrayListType<elemType>::insert(const elemType& insertItem) {
	if(length==0){
		list[length++]=insertItem;
	}
	else if(length==maxSize){
		cerr<<"list is full";
	}
	else{
		int loc=seqSearch(insertItem);
		if(loc>0){
			cerr<<"Item to be inserted already exists";
		}
		else{
			list[length++]=insertItem;
		}
	}
}

template<class elemType>
inline void arrayListType<elemType>::remove(const elemType& removeItem) {
	if(length==0){
		cerr<<"Sorry!!List is empty"<<endl;

	}
	else{
		int loc=seqSearch(removeItem);
		if(loc==-1){
			cerr<<"Item to be removed not found in the list"<<endl;

		}
		else{
			removeAt(loc);
		}
	}
}

template<class elemType>
inline arrayListType<elemType>::arrayListType(int size) {
	if (size < 0)
	{
	cerr << "The array size must be positive. Creating "
	<< "an array of size 100. " << endl;
	maxSize = 100;
	}
	else
	maxSize = size;
	length = 0;
	list = new elemType[maxSize];

}

template<class elemType>
inline arrayListType<elemType>::arrayListType(
		const arrayListType<elemType>& otherList) {
	maxSize=otherList.maxSize;
	length=otherList.length;
	list = new elemType[maxSize]; //create the array
	assert(list != NULL);
	for (int j = 0; j < length; j++) //copy otherList
	list [j] = otherList.list[j];
}

template<class elemType>
inline const arrayListType<elemType>& arrayListType<elemType>::operator =(
		const arrayListType<elemType>& constArrayListType) {

	if (this != &constArrayListType) //avoid self-assignment
	{
		delete [] list;
		maxSize = constArrayListType.maxSize;
		length = constArrayListType.length;
		list = new elemType[maxSize]; //create the array
		assert(list != NULL); //if unable to allocate memory
		//space, terminate the program
		for (int i = 0; i < length; i++)
		list[i] = constArrayListType.list[i];
	}
	return *this;
}

template<class elemType>
inline int arrayListType<elemType>::recSeqSearch(const elemType& item) const {
	return recSearch(item,0,length-1);
}

template<class elemType>
inline arrayListType<elemType>::~arrayListType() {
	delete [] list;
}

template<class elemType>
inline int arrayListType<elemType>::binSearch(const elemType& item) const {
	int high=0,low=0,mid=0;
	bool found=false;
	if(length==0){
		cerr<<"List is empty"<<endl;
	}
	else{

		high=length-1;
		while(low<=high && !
				found){

			mid=(low+high)/2;
			if(list[mid]==item){
				found=true;
			}
			else if(list[mid]<item){
				low=mid+1;
			}
			else{

				high=mid-1;
			}
		}

	}
	if(found)
		return mid;
	else
		return -1;


}

template<class elemType>
inline int arrayListType<elemType>::recBinSearch(const elemType& item) const {
	return recBin(item,0,length-1);
}



template<class elemType>
inline int arrayListType<elemType>::recSearch(const elemType& item, int first, int last) const {
	if(first<=last){
		if(list[first]==item){
			return first;
		}
		else
			return recSearch(item,first+1,last);
	}
	else
		return -1;
}

template<class elemType>
inline void arrayListType<elemType>::insertOrd(const elemType& insertItem) {
	int low=0,high=length-1,mid;
	if(length==0){
		list[length++]=insertItem;
	}
	else if(length==maxSize){
		cerr<<"List is full"<<endl;
	}
	else{
		bool found=false;
		while(low<=high && !found){

			mid=(low+high)/2;
			if(list[mid]==insertItem){
				found=true;
			}
			else if(list[mid]<insertItem){
				low=mid+1;
			}
			else{

				high=mid-1;
			}
		}
		if(found){
			cerr<<"Element already present in list "<<endl;
		}
		else{
				if(list[mid]<insertItem){
					mid++;
				}
				insertAt(mid,insertItem);
		}
	}
}

template<class elemType>
inline int arrayListType<elemType>::seqSearchOrd(const elemType& item) const {
	if(length==0){
		cerr<<"List is empty"<<endl;
	}
	else{
		int loc=0;
		bool found;

			for(loc=0;loc<length;loc++){
				cout<<"Iteration :"<<loc<<endl;
				if(list[loc]>=item){
					found=true;
					break;
				}


			}

		if(found){
			if(list[loc]==item)
				return loc;
			else
				return -1;

		}
		else
			return -1;
	}



}

template<class elemType>
inline int arrayListType<elemType>::recBin(const elemType& item, int low,
		int high) const {
	int mid;
	if(low<=high){
		mid=(low+high)/2;
		if(list[mid]==item){
			return mid;
		}
		else if(list[mid]<item){
			return recBin(item,mid+1,high);
		}
		else{
			return recBin(item,low,mid-1);
		}
	}
	else{
		return -1;
	}
}

#endif /* ARRAYLIST_H_ */
