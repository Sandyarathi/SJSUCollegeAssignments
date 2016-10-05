/*
 * listLarge.cpp
 *
 *  Created on: Oct 15, 2014
 *      Author: sandyarathidas
 */
#include<iostream>
using namespace std;

int largest(int listArr[],int lowIndex,int highIndex){
	int max;
	if(lowIndex==highIndex){
		return listArr[lowIndex];
	}
	else{
		max= largest(listArr,lowIndex+1,highIndex);
		if(listArr[lowIndex]>=max){
			return listArr[lowIndex];
		}
		else{
			return max;
		}
	}

}

int main(){
	int listArray[10]={2,4,34,56,64,34,2,-1,100,105};
	cout<<"The largest element in the given list is : "<<largest(listArray,0,9)<<endl;


}




