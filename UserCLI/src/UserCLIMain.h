/*
 * UserCLIMain.h
 *
 *  Created on: Sep 6, 2014
 *      Author: sandyarathidas
 */

#ifndef USERCLIMAIN_H_
#define USERCLIMAIN_H_

#include<iostream>
#include<stdio.h>
using namespace std;



class UserCLIMain {
private :

	string user_command;
	string system_command;
	string path;
	string currWorkDir;

public :
	void setUser_command(string usrCommand);

	string getUser_command();

	void setSystem_command(string sysCommand);

	string getSystem_command();

	void setPath(string usrPath);

	string getPath();

	void setCurrWorkDir(string dir);

	string getCurrWorkDir();

	string usageDisplay();

	void execute();

	void getSystemTime();


};

#endif /* USERCLIMAIN_H_ */
