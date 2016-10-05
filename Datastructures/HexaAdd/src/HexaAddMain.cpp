/*
 * HexaAddMain.cpp
 *
 *  Created on: Sep 13, 2014
 *      Author: sandyarathidas
 */

#include "HexaAddMain.h"

#include<iostream>
#include<stdio.h>
#include<math.h>
#include<fstream>
#include<iomanip>
using namespace std;


const int MAX_SIZE=12;
//The Hexadecimal input/output is limited to 12;

bool inputVal(string input);
//Validates the string input to be a valid hexadecimal number.
//Pre-condition : A user input string is passed.
//Post-condition : returns a boolean;'true' if string is valid hexadecimal;'false' if invalid.

bool getHexInput(char hex_input[]);
//Reads the Hexadecimal input from keyboard and stores it in a character array.
//Pre-condition :Array with elements initialized to zeroes is passed.
//Post-condition : returns true if valid hexadecimal number is read into the character array;
                   //returns false if invalid inputs are entered.


void displayHex(const char hex_input[]);
//Displays a character array
//Pre-Condition : An array to be displayed is passed.
//Post-Condition :A Hexadecimal number is displayed onto the screen.



string getHexFileInput(char hex_fileInput1[],char hex_fileInput2[]);
//Reads the Hexadecimal input from a file and stores it in a character array.
//Pre-condition :Arrays with elements initialized to zeroes is passed.
//Post-condition : The path of the Input file is returned.


int hexToDec(char hex);
//Converts a hexadecimal number to decimal.


char decToHex(int dec);
//Converts a decimal value to hexadecimal value.


int getHexSum(const char input1[],const char input2[],char sum[]);
//Computes the addition of the two hexadecimal inputs and stores the output in the sum Array.
//Pre-Condition : Unmodifiable input arrays are passed.
//Post-Condition: Addition over flow is indicated if sum exceeds 12 numbers and Program is terminated.
                 //Else the Sum is stored in the sum array and a success status with value '0' is returned.


int displayInstr();
//Initial program header and instructions are displayed and choice of input is validated.
//Pre-Condition : User Chooses 1.to provide input from keyboard.
                 //Chooses 2.to provide input from a file.
//Post-Condition : The user choice is returned .


int inputChoiceVal();
//The UserChoice is validated.
//Pre-condition :user choice to read input from keyboard or from file is sent;could be any number.
//Post-condition : values 1 or 2 are returned as valid input choices
                 //Invalidity of user input choice is indicated and initial instructions
				 //to again select input choice is displayed by calling displayInstr() function ,
				 //till valid input choice is entered.



void displayOutput(const char input1[],const char input2[],const char sumOutput[]);
//Displays the output for addition of input numbers read from keyboaard.


void sendOutputToFile(const char sumOutput[MAX_SIZE],string& filepath);
//Writes the sum of the the input numbers, read from input files,into an output file.
//Pre-condition : the sumArray and the user input filepath is passed.
//Post-condition : the user input file name in the  filepath is appended with '-out'
				//and the sum array is written into the output file as a string.


int main(){
	int inputChoice=0;char userChoice;
	//the sum to be stored in sum array is initialized with zeroes and null character at the end;
	char sum[MAX_SIZE+1]={'0','0','0','0','0','0','0','0','0','0','0','0','\0'};

	//the input character arrays are initialized with zeroes and null character at the end;
	char hex_input1[MAX_SIZE+1]={'0','0','0','0','0','0','0','0','0','0','0','0','\0'};
	char hex_input2[MAX_SIZE+1]={'0','0','0','0','0','0','0','0','0','0','0','0','\0'};

	//the filepath variable is declared and stores the input and output file paths.
    string filepath;

    //validity variable is declared to store the input validity status;true indicates valid inputs entered;
    //false indicates invalid inputs and results in provision to enter keyboard inputs again.
    bool validity;

	//This loop calls functions to take input from either keyboard or input
    //files and then computes the sum of the two hexadecimal inputs and to display the output on the
    //screen or write it to a file.
    //Also reads user choice to either continue using the Adder for different set of inputs or terminate the Adder.
    //label for goto statement;
    tryagain:do{
		inputChoice=inputChoiceVal();
		if(inputChoice==1){
			validity=getHexInput(hex_input1);
            //Validity of the input1 from keyboard is checked.
			if(!validity){
				cout<<"Invalid Inputs!!Try again with Valid hexadecimal numbers!!"<<endl;
				//Execution jumps to the start of the loop in case invalid inputs are read from keyboard.
				goto tryagain;

			}
			//Validity of the input2 from keyboard is checked.
			validity=getHexInput(hex_input2);
			if(!validity){
				cout<<"Invalid Inputs!!Try again with Valid hexadecimal numbers!!"<<endl;
				//Execution jumps to the start of the loop in case invalid inputs are read from keyboard.
				goto tryagain;

			}
		}
		else if(inputChoice==2){
			//Invokes function to read hexadecimal numbers from files and File path is set.
			filepath=getHexFileInput(hex_input1,hex_input2);

		}

		int statusInt=getHexSum(hex_input1,hex_input2,sum);
		if(statusInt==0 && inputChoice==1){
			//Based on input choice  the function to display output on screen is invoked.
			displayOutput(hex_input1,hex_input2,sum);

		}
		else if(statusInt==0 && inputChoice==2){
			//Based on input choice,the function to write output into a file is invoked.
			sendOutputToFile(sum,filepath);

		}
		//User is allowed to choose to either continue for another set of addition or terminate the Adder.
		cout<<"\nDo you want to continue? Enter 'y' or 'n'!!"<<endl;
		cin>>userChoice;
		if(userChoice=='n'){
			//Adder is terminated.
			cout<<"\n Thank you!!Good Bye!!"<<endl;
			exit(0);
		}

	}while(userChoice=='y');

    return 0;


}


//Used commonly for both input from keyboard or from files.
bool inputVal(string input){
	int index;bool valid;
	//A Hexadecimal number should have values 0 to 9 and characters 'A' to 'F'
	for(index=0;index<input.size();index++){
		if((input[index]>='A' && input[index]<='F')|| (input[index]>='0' && input[index]<='9')){
			//true is returned and execution continues.
			valid=true;

		}
		else{
			//false is returned and User is prompted of the invalidity
			valid=false;
			break;
		}
	}

	return valid;
}

bool getHexInput(char hex_input[]){
	string strInput;
	Return:
	cout<<"\nEnter a HexaDecimal number of 12 or fewer digits :";
	//Do a length validation at this point.
    cin>>strInput;
    if(strInput.size()>MAX_SIZE){
    	strInput="";
    	cout<<"Sorry!!Number of digits entered exceeds 12."<<endl;
    	goto Return;
    }
    //Hexadecimal input is read from keyboard as string and stored into character array.
	if(inputVal(strInput)){
		int stringIndex=0;
        //the string inputs are queued into the character arrays
		for(int inputIndex=MAX_SIZE-strInput.size();inputIndex<12;inputIndex++){


				hex_input[inputIndex]=strInput[stringIndex];
			 stringIndex++;

		}
        //returns true if valid inputs are read
		return true;
	}
	else {
        //returns false if invalid inputs are read
		return false;
	}




}


void displayHex(const char hex_input[]){

	//displays a character array
	for(int inputIndex=0;inputIndex<MAX_SIZE;inputIndex++){
		cout<<hex_input[inputIndex];
	}


}

string getHexFileInput(char hex_fileInput1[],char hex_fileInput2[]){
	//The input file path is read
	cout<<"Enter the input file path :"<<endl;
	string filePath;
	cin>>filePath;
	ifstream in_stream;
	in_stream.open(filePath);
	//File path errors are captured and The Adder terminated!!
	if (in_stream.fail()){
		cout<<"Input file opening failed!!"<<endl;
		exit(1);
	}
	string input1,input2;

	in_stream>>input1>>input2;
	if(input1.size()>MAX_SIZE || input2.size()>MAX_SIZE){
		cout<<"The number of digits in one of the Input values in File Exceeds 12!!"<<endl;
		cout<<"Adder terminated!!" <<endl;
		exit(1);
	}
	//The two strings read from input file are validated and read into the character arrays.
	if(inputVal(input1)&& inputVal(input2)){
		int stringIndex=0;
		for(int inputIndex=MAX_SIZE-input1.size();inputIndex<12;inputIndex++){
            //input 1
			hex_fileInput1[inputIndex]=input1[stringIndex];
			stringIndex++;
		}

		stringIndex=0;
		for(int inputIndex=MAX_SIZE-input2.size();inputIndex<12;inputIndex++){
            //input 2
			hex_fileInput2[inputIndex]=input2[stringIndex];
			stringIndex++;
		}
	}
	else{
		//in case of invalid numbers in the input file,The program is terminated!!
		cout<<"Invalid input in File!!Adder terminated!!" <<endl;
		exit(1);
	}
    //input file is closed.
	in_stream.close();
    return filePath;

}



int hexToDec(char hex){
	int dec=0;
	if(hex>='0'&& hex<='9'){

	 dec= hex-'0';
	}
	else if(hex=='A' || hex=='B'||hex=='C'||hex=='D'||hex=='E'||hex=='F'){
       //corresponding decimal values are obtained using ASCII table.
	   dec=hex-55;

	}
	else{
		//<<"Invalid Input!!"<<endl;
		dec=-1;

	}
	return dec;
}

char decToHex(int dec){
    //Each decimal value is mapped to corresponding Hexadecimal value.
	switch(dec){

	case 10:
		return 'A';
		break;
	case 11:
		return 'B';
		break;
	case 12:
		return 'C';
		break;
	case 13:
		return 'D';
		break;
	case 14:
		return 'E';
		break;
	case 15:
		return 'F';
		break;
	default:
		//0 to 9 numbers are converted to char as is;
		char c = char(dec+'0');
		return c;
	}

}

int getHexSum(const char input1[],const char input2[],char sum[]){
	int carry=0;//used to store the carry over the next sum.
	int tempSum;//used to stored the current sum temporarily.

    //Addition is done from Least Significant Digit end.
	for(int inputIndex=MAX_SIZE-1;inputIndex>=0;inputIndex--){

		//Each hexadecimal digit from input1 is added to each digit of input 2.
		//The carry over from the previous unit addition is also added.
		tempSum=hexToDec(input1[inputIndex])+ hexToDec(input2[inputIndex])+carry;
		carry=0;

        //The decimal sum value is mapped to corresponding hexadecimal value
		if(tempSum>=0 && tempSum<=9){

			sum[inputIndex]=decToHex(tempSum);

		}

		else if(tempSum>=10 && tempSum<=15){

			sum[inputIndex]=decToHex(tempSum);
		}
		else{
            //if the sum is greater than 'F',the remainder is taken as sum
			//and a carry is passed to the next sum;
			sum[inputIndex]=decToHex(tempSum%16);
			carry=pow(16,0);

		}

	}
    //In case the sum array exceeds 12 digits,the user is prompted about
	//the Addition OverFlow and Program is terminated.
	if(carry!=0){
		cout<<"\n ***********Addition Overflow!!************"<<endl;
		exit(0);
	}

	return 0;
}

int displayInstr(){
	int choice=0;
	//Initial Header and instructions are displayed.
	cout<<"**********Hexadecimal Adder by Sandyarathi_Das.***********"<<endl;
	cout<<"Enter 1 or 2 :"<<endl;
	cout<<"1.Input from keyboard."<<endl<<"2.Input from file."<<endl;
	//user input choice is read.
	cin>>choice;
	return choice;
}

int inputChoiceVal(){
	int inputChoice=displayInstr();
	//Invalid input choice is captured and instructions to re-enter user input choice is displayed.
	while(inputChoice!=1 && inputChoice!=2){
		cout<<"Invalid input choice!!"<<endl;
		inputChoice=displayInstr();
	}
	return inputChoice;

}

void displayOutput(const char input1[],const char input2[],const char sumOutput[]){
	//output to screen is displayed in <Hex1>+<Hex2>=<sum> format.
	displayHex(input1);
	cout<<" + ";
	displayHex(input2);
	cout<<" = ";
	displayHex(sumOutput);
}
 void sendOutputToFile(const char sumOutput[MAX_SIZE],string& filepath){
	 ofstream out_stream;
	 //input file path is appended with '-out'
	 filepath=filepath+"-out";
     //output file path errors are captured.
	 out_stream.open(filepath);
	 if(out_stream.fail()){
		 cout<<"Output File Opening Failed!!"<<endl;
		 exit(1);
	 }
     //output sum is written into the out put File.
	 string outString=string(sumOutput);
	 out_stream<<outString;
	 out_stream.close();
 }



