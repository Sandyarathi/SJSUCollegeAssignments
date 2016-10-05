/*
 * testHugeInteger.cpp
 *
 *  Created on: Sep 27, 2014
 *      Author: sandyarathidas
 */
#include "HugeInteger.h"
#include <iostream>
#include <stdio.h>
using namespace std;
int main(){
    cout<<"\n******HugeInterger Arithmetic by Sandyarathi Das****** "<<endl;
    cout<<"=========================================================="<<endl;
    cout<<"Addition :"<<endl;
    cout<<"========"<<endl;
    cout<<"\n 1) HugeInteger Long object + HugeInteger Long object\n"<<endl;
    long var1=9223372036854775807;
    long var2=9223372036854775807;
    HugeInteger AObj1=HugeInteger(var1);
    HugeInteger AObj2=HugeInteger(var2);
    HugeInteger Sum1=AObj1.add(AObj2);
    AObj1.output();cout<<" + ";AObj2.output();cout<<" = ";Sum1.output();cout<<endl;
    cout<<"\n\n 2)HugeInteger Long Object + HugeInteger String Object\n"<<endl;
    string var3="922337203685477580776543";
	HugeInteger AObj3=HugeInteger(var3);

	HugeInteger Sum2=AObj1.add(AObj3);
	AObj1.output();cout<<" + ";AObj3.output();cout<<" = ";Sum2.output();cout<<endl;
	/*cout<<"\n\n String taken from console"<<endl;
	string inString;
	cout<<"Enter a large number "<<endl;
	cin>>inString;
	HugeInteger inStrObj=HugeInteger();
	inStrObj.input(inString);
    inStrObj.output();*/
	cout<<"\n\n 3)Int + HugeInteger Object \n"<<endl;
	int var5=2147483647;
    HugeInteger Sum4=AObj3.add(var5);
    AObj3.output();cout<<" + "<<var5;cout<<" = ";Sum4.output();cout<<endl;
    cout<<"\n\n 4)String + HugeInteger Object \n"<<endl;
    string var6="878654321987654329876";
    HugeInteger Sum5=AObj3.add(var6);
    AObj3.output();cout<<" + "<<var6;cout<<" = ";Sum5.output();cout<<endl;
	string var4="9999999999999999999999999999999999999999";
	HugeInteger AObj4=HugeInteger(var4);
	string var7="99999999999999999999999999";
	cout<<"\n 5)OverFlow Example\n"<<endl;
	HugeInteger AObj5=HugeInteger(var7);
	HugeInteger Sum3=AObj5.add(AObj4);
	cout<<endl;
	AObj5.output();cout<<" + ";AObj4.output();cout<<" = ";Sum3.output();cout<<endl;
	cout<<"Subtraction :"<<endl;
	cout<<"==========="<<endl;
	cout<<"\n 1) HugeInteger Long Object - HugeInteger Long Object\n"<<endl;
    long DVar1=9223372036854775807;
	long DVar2=9223372036854775;
	HugeInteger DObj1=HugeInteger(DVar1);
	HugeInteger DObj2=HugeInteger(DVar2);
	HugeInteger Diff1=DObj1.subtract(DObj2);
	DObj1.output();cout<<" - ";DObj2.output();cout<<" = ";Diff1.output();cout<<endl;
	cout<<"\n\n 2)HugeInteger Long Object - HugeInteger String Object\n"<<endl;
	string DVar3="543210000000000";
	HugeInteger DObj3=HugeInteger(DVar3);
	HugeInteger Diff2=DObj1.subtract(DObj3);
	DObj1.output();cout<<" - ";DObj3.output();cout<<" = ";Diff2.output();cout<<endl;
	cout<<"\n\n 3)Int - HugeInteger Object \n"<<endl;
	int DVar5=2147483647;
	HugeInteger Diff4=DObj3.subtract(DVar5);
	DObj3.output();cout<<" - "<<DVar5;cout<<" = ";Diff4.output();cout<<endl;
	cout<<"\n\n 4)String - HugeInteger Object \n"<<endl;
	string DVar6="878654321987654329876";
	HugeInteger Diff5=DObj3.subtract(DVar6);
	DObj3.output();cout<<" - "<<DVar6;cout<<" = ";Diff5.output();cout<<endl;
	string DVar4="9999999999999999999999999999999999999999";
	HugeInteger DObj4=HugeInteger(DVar4);
	string DVar7="99999999999999999999999999";
	cout<<"\n 5)Overdrawn Example\n"<<endl;
	HugeInteger DObj5=HugeInteger(DVar7);
	HugeInteger Diff3=DObj5.subtract(DObj4);
	cout<<endl;
	DObj5.output();cout<<" - ";DObj4.output();cout<<" = ";Diff3.output();cout<<endl;


	 cout<<"\nComparison or Predicate output\n";
	 cout<<"=================================="<<endl;
	 long longInt=832123456788;
	 HugeInteger Obj1=HugeInteger(longInt);
	 string str2="832123456788";
	 HugeInteger Obj2=HugeInteger(str2);
	 if(Obj1.isEqualTo(Obj2)){
		 Obj1.output();cout<<" is equal to";Obj2.output();cout<<endl;

	 }
	 long longInt1=832123456788;
	 HugeInteger Obj3=HugeInteger(longInt1);
	 string str3="8321234567888765434887765";
	 HugeInteger Obj4=HugeInteger(str3);

	 if(Obj4.isGreaterThan(Obj3)){
		 Obj4.output();cout<<" is greater than";Obj3.output();cout<<endl;
	 }
	 long longInt2=8321230000;
	 HugeInteger Obj5=HugeInteger(longInt2);
	 string str4="832123456788000000000";
	 HugeInteger Obj6=HugeInteger(str4);

	 if(Obj5.isLessThan(Obj6)){
		 Obj5.output();cout<<" is lesser than";Obj6.output();cout<<endl;
	 }

	 long longInt3=832123456788;
	 HugeInteger Obj7=HugeInteger(longInt3);
	 string str5="832123";
	 HugeInteger Obj8=HugeInteger(str5);

	 if(Obj7.isGreaterThanOrEqualTo(Obj8)){
		 Obj7.output();cout<<" is greater than or equal to";Obj8.output();cout<<endl;
	 }
	 if(Obj8.isLessThanOrEqualTo(Obj7)){
		 Obj8.output();cout<<" is lesser than or equal to";Obj7.output();cout<<endl;
	 }

	 if(Obj8.isNotEqualTo(Obj7)){
		 Obj8.output();cout<<" is not equal to";Obj7.output();cout<<endl;
	 }


	 HugeInteger Obj9=HugeInteger();
	 if(Obj9.isZero()){
		 Obj9.output();cout<<" is zero!!";cout<<endl;
	 }





    return 0;

}




