/*
 * testOrderedLinkedList.cpp
 *
 *  Created on: Oct 8, 2014
 *      Author: sandyarathidas
 */


#include "orderedLinkedList.h"

int main(){
	orderedLinkedList<int> list1,list2,mergeList;
	int usrNum;
	cout<<"Enter numbers ending with -999\n\n";
	cin>>usrNum;
	while(usrNum!=-999){
		list1.insertLast(usrNum);
		cin>>usrNum;
	}
	cout<<endl;
	cout<<"\nThe list formed is :"<<endl;
	list1.print();
	int usrNum2;
	cout<<"\n\n\nEnter numbers ending with -999\n";
	cin>>usrNum2;
	while(usrNum2!=-999){
		list2.insertLast(usrNum2);
		cin>>usrNum2;
	}
	cout<<endl;
	cout<<"The list formed is :"<<endl;
	list2.print();
	mergeList.merge(list1,list2);
	cout<<"\n\nThe merged list formed is :"<<endl;
	mergeList.print();

	return 0;





}



