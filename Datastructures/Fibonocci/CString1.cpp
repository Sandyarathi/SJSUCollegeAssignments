/*
 * CString1.cpp
 *
 *  Created on: Oct 19, 2014
 *      Author: sandyarathidas
 */


#include <iostream>
#include <cstring>
using namespace std;

int main(){
	int index = 0;
	cout<<"I am in here!!"<<endl;
	char our_string[10+1]="0000000000";
	 while (our_string[index] != '\0' && index<10)
	 {

		 our_string[index] = 'X';

		 index++;
	 }
	 our_string[index]='\0';
	 index=0;

	 while(our_string[index] != '\0'){

		 cout<<our_string[index];
		 index++;
	 }
     char your_string[15];
     cout<<endl;
     strncpy(your_string,"hello ",10);
     cout<<your_string<<endl;
     if(strcmp(our_string,your_string)){
    	 cout<<"the strings are not equal"<<endl;
     }
     else
    	 cout<<"The strings are equal"<<endl;

     strncat(your_string,"Girlie",2);
     cout<<your_string<<endl;
     char my_string[15];
     cin.getline(my_string,15);
     cout<<my_string<<endl;
     string str1,str2;
     str1="madam";
     str2="madam";
     if(str1.e)


}




