/*
 * Manager.h
 *
 *  Created on: Nov 16, 2014
 *      Author: sandyarathidas
 */

#ifndef MANAGER_H_
#define MANAGER_H_

#include<semaphore.h>
#include <pthread.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/syscall.h>
#include<thread>
#include<unistd.h>


using namespace std;

const unsigned int waitingRoomCapacity = 3;


class Manager{

public:
	Manager();
	void wakeUpTA();
	void sleepTA();
	void joinWaitingRoom();
	void leaveWaitingRoom();
	bool isWaitingRoomEmpty();
	void teachStudent();

	void waitForTA();

	unsigned int getTotalStudents() const {
		return totalStudents;
	}

	void setTotalStudents(unsigned int totalStudents) {
		this->totalStudents = totalStudents;
	}

	unsigned int getNumberOfSeatsFreeinWr() const {
		return numberOfSeatsFreeinWR;
	}

	void setNumberOfSeatsFreeinWr(unsigned int numberOfSeatsFreeinWr = 3) {
		numberOfSeatsFreeinWR = numberOfSeatsFreeinWr;
	}

	unsigned int getStudentsInWaitingRoom() const {
		return studentsInWaitingRoom;
	}

	void setStudentsInWaitingRoom(unsigned int studentsInWaitingRoom = 0) {
		this->studentsInWaitingRoom = studentsInWaitingRoom;
	}

private:
	sem_t studentAvailable;
	sem_t taReady;
	sem_t waitingRoom;
	unsigned int numberOfSeatsFreeinWR = 3;
	unsigned int studentsInWaitingRoom = 0;
	unsigned int totalStudents;

public:
	bool isTAsleeping=false;




};

inline void Manager::wakeUpTA() {
	sem_post(&studentAvailable);
}

inline void Manager::sleepTA() {
	if(isTAsleeping==false){
		sem_wait(&studentAvailable);
		cout<<"TA is Asleep"<<endl;
		isTAsleeping=true;
	}

}

inline Manager::Manager() {
	sem_init(&taReady,0,1);
	sem_init(&studentAvailable,0,0);
	sem_init(&waitingRoom,0,1);
}

inline void Manager::waitForTA() {
	sem_wait(&taReady);
}

inline void Manager::joinWaitingRoom() {
	sem_wait(&waitingRoom);//Request access to the number of available seats in the waiting room
	if(numberOfSeatsFreeinWR != 0){
		studentsInWaitingRoom++;
		cout<<"\nNumber of Students waiting for TA is " << studentsInWaitingRoom<<endl;
		numberOfSeatsFreeinWR--;
		sem_post(&studentAvailable);//Signal that there is a student waiting
		sem_wait(&taReady);

	}
	else{

		 cout << "\nWaitingRoom is full." <<endl;
		 cout << "\tNumber of Students in waiting Room :" << studentsInWaitingRoom << endl;
		 sleep(4);
	}
	sem_post(&waitingRoom);//release lock on seats; lock not needed

	isTAsleeping=false;

}

inline void Manager::leaveWaitingRoom() {
	 sem_wait(&waitingRoom); //release the lock on the seats and leave.
	 studentsInWaitingRoom--;
	 numberOfSeatsFreeinWR++;
	 cout<<"In leave :: "<<studentsInWaitingRoom<<endl;
	 if(studentsInWaitingRoom==0){
		 sleepTA();
	 }
	 sem_post(&waitingRoom);
	 sem_post(&taReady);
}

inline bool Manager::isWaitingRoomEmpty() {
	sem_wait(&waitingRoom);
	if(studentsInWaitingRoom==0){
		sem_post(&waitingRoom);
		return true;
	}
	else{
		sem_post(&waitingRoom);
		return false;
	}
}

inline void Manager::teachStudent() {
	sleep(9);
	totalStudents--;
	sem_post(&taReady);
}



#endif /* MANAGER_H_ */
