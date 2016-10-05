/*
 * UserCLIMain.cpp
 *
 *  Created on: Sep 6, 2014
 *      Author: sandyarathidas
 */

#include "UserCLIMain.h"
#include <iostream>
#include <stdlib.h>
#include <unistd.h>
#include <pwd.h>
#include <sys/time.h>

void UserCLIMain::setUser_command(string usrCommand){
	user_command=usrCommand;
}
string UserCLIMain::getUser_command(){
	return user_command;
}
void UserCLIMain::setSystem_command(string sysCommand){
	system_command=sysCommand;
}
string UserCLIMain::getSystem_command(){
	return system_command;
}
void UserCLIMain::setPath(string usrPath){
	path=usrPath;
}
string UserCLIMain::getPath(){
	return path;
}
void UserCLIMain::setCurrWorkDir(string dir){
	currWorkDir=dir;
}
string UserCLIMain::getCurrWorkDir(){
	return currWorkDir;
}
string UserCLIMain::usageDisplay(){
	string start;
	cout<<"\nUser mode Command Line Interpreter."<<endl;
	cout<<"======================================";
	cout<<"\nCommands available :"<<endl;
	cout<<"1.list-short : to list files in the current directory or in the user specified path."<<endl;
	cout<<"2.list-long  : to list files ,with dates and sizes ,in the current directory or in the user specified path ."<<endl;
	cout<<"3.change : to go to the home directory."<<endl;
	cout<<"4.exit : to exit the Interpreter."<<endl;
	cout<<"Also find the time stamps for each command executed!!";
	cout<<"\nPlease press 'Y' to start using the interpreter or press any other key to quit!!";
	cin>>start;
	return start;

}

void UserCLIMain::getSystemTime(){
	timeval currTime;
	gettimeofday(&currTime, NULL);
	int milli_sec = currTime.tv_usec / 1000;

	char buffer [80];
	strftime(buffer, 80, "%Y-%m-%d %H:%M:%S", localtime(&currTime.tv_sec));

	char currentTime[84] = "";
	sprintf(currentTime, "%s:%d", buffer, milli_sec);
	printf("%s \n\n", currentTime);
}

void UserCLIMain::execute(){
	if (!getPath().empty()){
		setSystem_command(getSystem_command()+" "+getPath());
	}
	else{
		setSystem_command(getSystem_command()+" "+getCurrWorkDir());
	}
	cout<<"\nBegin Time :";
	getSystemTime();
	const char * c = getSystem_command().c_str();
	int i = system(c);

	if(i!=0){
		cerr<<"\n Command could not be executed!!";
	}
	cout<<"\nEnd Time :";
    getSystemTime();


}


int main(){

	string usrStartIndicator;
	string usrCommand;
	string sysCommand;
	string usrPath;
	bool run='T';
	UserCLIMain userCLIMainObj;
    usrStartIndicator=userCLIMainObj.usageDisplay();
    if(usrStartIndicator!="Y"){
    	cout<<"\nThank you!!"<<endl;
    	exit(0);
    }
    else{
    	char charCwd[1024];
    	string cwd;
    	if (getcwd(charCwd, sizeof(charCwd)) != NULL){
    		cwd=string(charCwd);
    	}
		userCLIMainObj.setCurrWorkDir(cwd);
		cout<<"\nPlease enter your command at the $ prompt!!";
		while(run){
			cout<<"\n"<<userCLIMainObj.getCurrWorkDir()<<" $";
			cin>>usrCommand;
			if(cin.peek()=='\n'){
				userCLIMainObj.setPath("");
			}
			else{
				cin>>usrPath;
				userCLIMainObj.setPath(usrPath);
			}
			userCLIMainObj.setUser_command(usrCommand);
			if(userCLIMainObj.getUser_command()=="list-short"){
				userCLIMainObj.setSystem_command("ls");
				userCLIMainObj.execute();

			}
			else if(userCLIMainObj.getUser_command()=="list-long"){
				userCLIMainObj.setSystem_command("ls -l");
				userCLIMainObj.execute();

			}
			else if(userCLIMainObj.getUser_command()=="change"){
				if(userCLIMainObj.getPath().empty()){
					const char* home = getenv("HOME");
					userCLIMainObj.setCurrWorkDir(home);
				}
				else{
					userCLIMainObj.setCurrWorkDir(userCLIMainObj.getPath());

				}
				userCLIMainObj.setSystem_command("cd");
				userCLIMainObj.execute();
			}
			else if(userCLIMainObj.getUser_command()=="exit"){
				cout<<"\nThank you!!"<<endl;
				exit(0);

			}
			else{
				cerr<<"\nSorry!!Invalid command!!"<<endl;
				exit(0);
			}

		}
    }

}



