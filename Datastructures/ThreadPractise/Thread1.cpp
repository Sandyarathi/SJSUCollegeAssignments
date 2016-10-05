/*
 * Thread1.cpp
 *
 *  Created on: Sep 30, 2014
 *      Author: sandyarathidas

#include <iostream>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <pthread.h>
#include<thread>
#include <sys/syscall.h>




using namespace std;

void *PrintHello(void *threadid)
{
  long tid;

   cout << "In thread with Id  :"<<std::this_thread::get_id();
   sleep(3);
   cout<<endl;


   //pthread_exit(NULL);
}

int main(){
	pthread_t thread1;
	pid_t pid;
	pid = fork(); //PO and P1 print 2 hello1
	cout<<"Hello "<<getpid()<<endl;
	if (pid == 0) { /* child process */

		/*fork(); //P1 and P2 print 2 hello2
		cout<<"Hello "<<getpid()<<endl;
		//thread create( . . .);
	 	 int rc;
		rc = pthread_create (&thread1, NULL, PrintHello, (void *)1);
		if (rc){
		         cout << "Error:unable to create thread," << rc << endl;
		         exit(-1);
		      }


	 }
    sleep(4);
	fork(); //P0 - P3; P1 - P4; P2 - P5 print 6  Hello3
	cout<<"Hello "<<getpid()<<endl;


}
*/
