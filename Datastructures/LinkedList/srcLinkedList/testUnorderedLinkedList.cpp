/*
 * testUnorderedLinkedList.cpp
 *
 *  Created on: Oct 8, 2014
 *      Author: sandyarathidas
 */

#include "unorderedLinkedList.h"

int main(){
	unorderedLinkedList<int> list1;
	list1.insertLast(15);
	list1.insertLast(65);
	list1.insertLast(27);
	list1.insertLast(65);
	list1.insertLast(12);
	cout<<"**LINKEDLIST Manipulation by SANDYARATHI**"<<endl;
	cout<<"The list formed is :"<<endl;
	list1.print();cout<<endl;
    list1.deleteSmall();
    cout<<"The list formed after deleting the smallest element"<<endl;
    list1.print();cout<<endl;
    list1.deleteSmall();
    list1.print();cout<<endl;
	list1.deleteAll(27);

	list1.print();cout<<endl;
	list1.deleteAll(65);
	cout<<"The list formed after deleting all the occurences of an element"<<endl;
	list1.print();cout<<endl;
	unorderedLinkedList<int> myList,sublist;
	myList.insertLast(34);
	myList.insertLast(65);
	myList.insertLast(27);
	myList.insertLast(89);
	myList.insertLast(12);
    cout<<"New list formed is :"<<endl;
    myList.print();cout<<endl;
    myList.split2(sublist);
    cout<<"The list after splitting :"<<endl;
    myList.print();cout<<endl;
    cout<<"The new sublist :"<<endl;
    sublist.print();

    return 0;

}

