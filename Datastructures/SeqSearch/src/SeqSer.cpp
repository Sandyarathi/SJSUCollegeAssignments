#include<iostream>
using namespace std;

#include "arrayList.h"

int main(){
	arrayListType<int> intList(100);
	int number;
	cout<<"Enter 5 numbers to be entered into the list in sorted order"<<endl;
	for(int counter=0;counter<5;counter++){
		cin>>number;
		intList.insertAt(counter,number);
	}
	int item;int foundAt;
	cout<<"Enter the item to be searched in the list"<<endl;
	cin>>item;
	foundAt=intList.seqSearchOrd(item);
	if(foundAt==-1){
		cout<<"Element not in list"<<endl;
	}
	else{
		cout<<"Element found at position :"<<foundAt<<endl;
	}
	/*cout<<"Enter another item to be searched in the list"<<endl;
	cin>>item;
	foundAt=intList.binSearch(item);
	if(foundAt==-1){
		cout<<"Element not in list"<<endl;
	}
	else
		cout<<"Element found at position :"<<foundAt<<endl;
	cout<<"Enter another item to be searched in the list"<<endl;
	cin>>item;
	foundAt=intList.recBinSearch(item);
	if(foundAt==-1){
		cout<<"Element not in list"<<endl;
	}
	else
		cout<<"Element found at position :"<<foundAt<<endl;


*/

}
