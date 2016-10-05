/*
 * HugeInteger.cpp
 *
 *  Created on: Sep 24, 2014
 *      Author: sandyarathidas
 */


#include "HugeInteger.h"
#include <vector>
#include<stdlib.h>
#include<stdio.h>
#include<iostream>
#include<math.h>



using namespace std;
// constructor: converts a long integer into a HugeInteger object
//Pre-Condition : takes a long input value and stores it in the Huge Integer vector.
//Post-Condition : Either stores the long value into the vector or by default stores zeroes.
HugeInteger::HugeInteger(long inputLong){
    //the input long number is checked for the maximum limit of long dataType
	if(inputLong>9223372036854775807){
		//returns a error message
		cerr<<"Given user input exceeds the data type limits!!Sorry";
        exit(0);
	}
	else{
		// passes the long value to a function to set the object vector.
		convertLongToVec(inputLong);
	}

}
//Constructor : To store a string into the object vector
HugeInteger::HugeInteger(const string& inputString){
	if(inputString.length()>MAXSIZE){
		//checks for the string limit to be the MAXSIZE of the vector
			cerr<<"Given user input exceeds the class storage limits!!Sorry"<<endl;
            exit(0);
		}
		else{
			//post validating the length of the string it is
			//passed to the function to set the string to the object vector
			convertStrToVec(inputString);
		}

}

// convert a string representing a large integer into a HugeInteger
void HugeInteger::input(const string& inputString){
	//takes a string input and calls a function to store into object vector.
	if(inputString.length()>MAXSIZE){
			//checks for the string limit to be the MAXSIZE of the vector
				cerr<<"Given user input exceeds the class storage limits!!Sorry"<<endl;
	            exit(0);
			}
			else{
				//post validating the length of the string it is
				//passed to the function to set the string to the object vector
				convertStrToVec(inputString);
			}
}

//function to add the vector numbers in the calling object and called object
HugeInteger HugeInteger::add(const HugeInteger& objUser) const {
	HugeInteger sumObj=HugeInteger();//Initialize the result object
	short carry=0,sum=0;
	for(int index=MAXSIZE;index>0;index--){
		//the initial sum is stored in a temporary variable
		sum=integerVector[index]+objUser.integerVector[index]+carry;
		carry=0;
		if(sum>9){
			//carry is set in case the sum exceeds a single digit value
			sum=sum%10;
			carry=1;
		}
        //the result object vector is stored with the sum value
		sumObj.integerVector[index]=sum;
	}
	//Overflow condition is checked and the result vector is stored with zeroes.
	if(carry==1){
		cout<<"Addition Overflow!!";
		for (int index = 0; index < MAXSIZE; index++){
			sumObj.integerVector[index]=0;
	    }

	}
	//return the result object that stores the result vector
	return sumObj;

}

//adds the passed string value to the number in the calling object vector
HugeInteger HugeInteger::add(const std::string& strInput) const {
	//initializes a object that stores the string into the object vector.
	HugeInteger strObj=HugeInteger(strInput);
	//calls the addition function that implements the addition of two objects
	HugeInteger sumObj=this->add(strObj);
	//returns the result object
	return sumObj;
}

//subtracts the values stores in passed object vector from the calling object vector
HugeInteger HugeInteger::subtract(const HugeInteger& op2) const {
	HugeInteger subObj=HugeInteger();
	short tempRes=0;short borrow=0;
	//declares two temporary vectors to store the vectors in the two objects
	vector<short> thisVector,op2Vector;
	//storing the calling object vector into temp1 vector
	thisVector=this->integerVector;
	//storing the called object vector into temp1 vector
	op2Vector=op2.integerVector;
	//boolean function to check if the calling object value is lesser than the second value
	if(this->isLessThan(op2)){
		cout<<"\n Error: Tried to subtract larger value from smaller value"<<endl;

	}
	//if the validation holds good then continue with the subtraction logic
	else{
       for(int index=MAXSIZE;index>0;index--){
    	   if(thisVector[index]>=op2Vector[index]){

    		   tempRes=thisVector[index]-op2Vector[index];

    	   }
    	   else{
    		   //set borrow
    		   borrow=10;
    		   tempRes=thisVector[index]+borrow-op2Vector[index];
    		   thisVector[index-1]--;

    	   }
    	   borrow=0;
    	   subObj.integerVector[index]=tempRes;
       }
	}
	return subObj;

}

//function used to trim the leading zeroes of a number
void leftTrim(std::string& str, char chr)
{
  std::string::size_type pos =  str.find_first_not_of(chr,0);
  if(pos > 0)
    str.erase(0,pos);

}

//the calling is compared with the called object to check if it is lesser in value.
//post-Condition : return 'true' if Obj1 is less than oBj2

bool HugeInteger::isLessThan(const HugeInteger& obj2) const {
	bool var=false;
	int index=0;
	for(index=0;index<MAXSIZE;index++)
	{
			if(this->integerVector[index]<obj2.integerVector[index]){
				var=true;
				break;
			}
			else if(this->integerVector[index]==obj2.integerVector[index]){
				continue;
			}
			else{
				var=false;
				break;
			}

		}
		return var;

}

//function to subtract the int value from the HugeInteger
//Post-Condition : the Difference value is storesd in a Object vector and is returned

HugeInteger HugeInteger::subtract(int op2) const {
   HugeInteger intObj=HugeInteger();
   intObj.integerVector=intObj.convertIntToVec(op2);
   HugeInteger subObj=this->subtract(intObj);
   return subObj;
}
//function to subtract the string value from the HugeInteger
//Post-Condition : the Difference value is stored in a Object vector and is returned

HugeInteger HugeInteger::subtract(const std::string& op2) const {
	HugeInteger strObj=HugeInteger(op2);
	HugeInteger subObj=this->subtract(strObj);
	return subObj;
}
//the calling is compared with the called object to check if it is equal in value.
//post-Condition : return 'true' if Obj1 is equal to oBj2
bool HugeInteger::isEqualTo(const HugeInteger& obj2) const {
	bool var=false;
	for(int i=0;i<MAXSIZE;i++){
		if(this->integerVector[i]==obj2.integerVector[i]){
			var=true;
		}
		else{
			var=false;
			break;
		}
	}
	return var;
}

//the calling is compared with the called object to check if it is equal in value.
//post-Condition : return 'true' if Obj1 is  not equal to oBj2
bool HugeInteger::isNotEqualTo(const HugeInteger& obj2) const {
	bool var=false;
		for(int i=0;i<MAXSIZE;i++){
			if(this->integerVector[i]!=obj2.integerVector[i]){
				var=true;
				break;
			}
			else{
				var=false;

			}
		}
		return var;
}

//the calling is compared with the called object to check if it is greater in value.
//post-Condition : return 'true' if Obj1 is greater than oBj2

bool HugeInteger::isGreaterThan(const HugeInteger& obj2) const {

	bool var=false;
		//string thisTemp="";
	int index=0;

	for(index=0;index<MAXSIZE;index++){
		if(this->integerVector[index]>obj2.integerVector[index]){
			var=true;
			break;
		}
		else if(this->integerVector[index]==obj2.integerVector[index]){
			continue;
		}
		else{
			var=false;
			break;
		}

	}
	return var;

}

//the calling is compared with the called object to check if it is greater or equal in value.
//post-Condition : return 'true' if Obj1 is greater or equal to oBj2
bool HugeInteger::isGreaterThanOrEqualTo(const HugeInteger& obj2) const {
	bool var=true;
	if(this->isEqualTo(obj2) || this->isGreaterThan(obj2)){
		var=true;
	}
	else
		var=false;


		return var;
}

//the calling is compared with the called object to check if it is lesser or equal in value.
//post-Condition : return 'true' if Obj1 is less than or equal to oBj2

bool HugeInteger::isLessThanOrEqualTo(const HugeInteger& obj2) const {
	bool var=true;
		if(this->isEqualTo(obj2) || this->isLessThan(obj2)){
			var=true;
		}
		else
			var=false;


			return var;
}
//the calling is checked if it is zero in value.
//post-Condition : return 'true' if Obj1 is zero
bool HugeInteger::isZero() const {
	bool var=false;
		for(int i=0;i<MAXSIZE;i++){
			if(this->integerVector[i]==0){
				var=true;
			}
			else{
				var=false;
				break;
			}
		}
		return var;
}


//converts a int input into vector.
//Post-Condtion : A vector is returned
vector<short> HugeInteger::convertIntToVec(int intInput) {

		vector<short> intVector;
		int inputLength=0;
		int temp1=intInput,temp2=intInput;
		for(; temp1!= 0; temp1 /= 10, inputLength++)
		{

		}



			 for (int index = 0; index < MAXSIZE; index++){

				 intVector.push_back(0);
			 }
			 for (int index=MAXSIZE-1;index>=MAXSIZE-inputLength;index--){
				 intVector[index]=temp2%10;
				 temp2 = temp2/10;
			 }

			 return intVector;
}



HugeInteger HugeInteger::add(int int1) const {

    HugeInteger intObj=HugeInteger();
	intObj.integerVector=intObj.convertIntToVec(int1);
	HugeInteger sumObj=HugeInteger();
	short carry=0,sum=0;
	for(int index=MAXSIZE;index>0;index--){
		sum=this->integerVector[index]+intObj.integerVector[index]+carry;
		carry=0;

		if(sum>9){
			sum=sum%10;
			carry=1;
		}
		sumObj.integerVector[index]=sum;
	}

	if(carry==1){
		cout<<"Addition Overflow!!\n\n"<<endl;
		for (int index = 0; index < MAXSIZE; index++){
			sumObj.integerVector[index]=0;
		}

	}

	return sumObj;


}
//converts a string input into vector.
//Post Condition :convert a string and stores it in the calling object .
void HugeInteger::convertStrToVec(string input){

    unsigned int index;
	for (index = 0; index < MAXSIZE-input.length(); index++){
		integerVector.push_back(0);
	}
	for(index=0;index<input.length();index++){
		integerVector.push_back(input[index]-'0');
	}
}
//converts a long input into vector.
//Post Condition :convert a long value and stores it in the calling object
 void HugeInteger::convertLongToVec(long input){

	 int inputLength=0;
	 long temp1=input,temp2=input;
	 for(; temp1 != 0; temp1 /= 10, inputLength++);

	 for (int index = 0; index < MAXSIZE; index++){

		 integerVector.push_back(0);
	 }
	 for (int index=MAXSIZE-1;index>=MAXSIZE-inputLength;index--){
		 integerVector[index]=temp2%10;
		 temp2 = temp2/10;
	 }

 }





 void HugeInteger::output() const {
	 char thisTemp1[MAXSIZE+1];
	 int index=0;

	for(index=0;index<MAXSIZE;index++){
		thisTemp1[index]=this->integerVector[index]+'0';
	}
	thisTemp1[index]='\0';
	string thisTemp = string(thisTemp1);
	if(!(this->isZero())){
		leftTrim(thisTemp,'0');
	}

	cout<<thisTemp;
 }





