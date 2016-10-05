/*
 * testSleepTA.cpp
 *
 *  Created on: Nov 14, 2014
 *      Author: sandyarathidas
 */
#include<pthread.h>
#include<iostream>
#include<thread>
#include <sys/syscall.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include "Manager.h"

using namespace std;
const int NUMBER_OF_STUDENTS=2;

pthread_t studentThreads[NUMBER_OF_STUDENTS];//array to hold student threads
pthread_t teachingAssistant;//ta thread id
Manager manager;
int studentID[NUMBER_OF_STUDENTS]={1,2};

void *studentRoutine(void *){
	//manager.sleep();	//student is programming
	manager.joinWaitingRoom();
	cout<<manager.getStudentsInWaitingRoom()<<endl;
	manager.waitForTA();
	cout<<"Student being taught by TA: "<<std::this_thread::get_id()<<endl;
	manager.leaveWaitingRoom();
	cout<<manager.getStudentsInWaitingRoom()<<endl;
    return 0;

}

void *teachingAssistantRoutine(void *threadId){
	while(manager.getTotalStudents()>0){
		if(manager.isWaitingRoomEmpty()){
			manager.sleepTA();
		}
		manager.teachStudent();
		//cout<<"finished teaching student"<<endl;
	}
	return 0;
}

int main(){

	manager.setTotalStudents(NUMBER_OF_STUDENTS);

	int taThreadStatus=pthread_create(&teachingAssistant, NULL, teachingAssistantRoutine, (void *)0);
	sleep(1);
	for (int index = 0; index < NUMBER_OF_STUDENTS; index++) {
			int studThreadStatus= pthread_create(&studentThreads[index],NULL,studentRoutine,(void *)&studentID[index]);
            //sleep(1);
	}


	pthread_join(teachingAssistant,NULL);
	for (int index = 0; index < NUMBER_OF_STUDENTS; index++) {
		pthread_join(studentThreads[index],NULL);
	}


		cout << "EXITING PROGRAM" << endl;
		return 0;

}
