/*
 * sleepTA.cpp
 *
 *  Created on: Nov 29, 2014
 *      Author: sandyarathidas
 */



#include <pthread/pthread.h>
#include <stdlib.h>
#include <sys/_pthread/_pthread_t.h>
#include <sys/_types/_time_t.h>
#include <sys/semaphore.h>
#include <unistd.h>
#include <ctime>
#include <iostream>
#include <thread>

using namespace std;

#define NUMBER_OF_STUDENTS 5

/*Indicate student Id of the student currently with TA*/
int stuID=100;

/*Time variable to control the TA's working hours.*/
time_t end_time;

/*Semaphore declaration :
 *waitingRoom semaphore : Access the waiting room.
 *taReady semaphore : indicate TA is free or TA is helping student.
 *studentAvailable semaphore :indicate student is waiting for help in room.
 */
sem_t waitingRoom,studentAvailable,taReady;

/*The number of student waiting for TA in waiting room*/
int studentsInWaitingRoom=0;


/*The TA thread checks if student is available.
 *Attends to one student and then chooses the next.
 *This routine first checks the studentAvailable semaphore,
 *acquires the waiting room semaphore to acquire a student and
 *then releases it after helping the student and again
 *indicates its availability using taReady semaphore.
 */
void *teachingAssistantRoutine(void *);

/*The studentRoutine thread first attempts to access the waiting room ,
 * and then after gaining the lock,it occupies one of the chairs,
 * indicates that it is ready and then waits for the TA to be ready.
 * In case the waiting room is full,it leaves the waiting room to try later.
 */
void *studentRoutine(void *);



int main()
{
	/*TA working hours is set to 20s*/
	end_time=time(NULL)+20;

	/*Semaphore initialization*/

	/*The waiting room lock is initially made available.*/
	sem_init(&waitingRoom,0,1);
	/*The student Available indicator is initially set to 0 i.e no student.*/
	sem_init(&studentAvailable,0,0);
	/*The TA signal is initially set to 1 i.e TA is available.*/
	sem_init(&taReady,0,1);

	pthread_t taThreadId,studentThreadId;

	/*Student thread creation and initialization*/
		int studThreadStatus=
				pthread_create(&studentThreadId,NULL,studentRoutine,(void *)0);
		if(studThreadStatus!=0)
			cerr<<"\nCreation of student thread failed!!"<<endl;

	/*TA thread creation and  initialization*/

	int taThreadStatus=
			pthread_create(&taThreadId, NULL, teachingAssistantRoutine, (void *)0);
	if(taThreadStatus!=0)
		cerr<<"\nCreation of TA thread failed!!"<<endl;



	/*Student threads are blocked first.*/
	pthread_join(studentThreadId,NULL);
	/*TA thread is blocked next.*/
	pthread_join(taThreadId,NULL);

	return 0;
}


/*TA thread routine */
void *teachingAssistantRoutine(void *)
{

	/*routine runs till the end of TA hrs or
	 * till a student is available in the waiting room.
	 */
	while(time(NULL)<end_time || studentsInWaitingRoom>0)
	{
		sem_wait(&studentAvailable);/*Check if resource is available*/
		sem_wait(&waitingRoom);/*Checks if waiting room is accessible*/
		studentsInWaitingRoom--;/*Make one chair free in the waiting room.*/
		stuID++;
		//cout<<"TA is helping student with Id: "<<this_thread::get_id()<<endl;
		cout<<"TA is helping student with Id: "<<stuID<<endl;
		cout<<"Number of students in waiting room :"<<studentsInWaitingRoom<<endl;
		sem_post(&waitingRoom);/*Release waiting room access*/
		sem_post(&taReady);/*Indicate its availability for the next student*/
		sleep(3);
	}
	return 0;
}

/*Student thread routine*/
void *studentRoutine(void *)
{
	/*routine runs till the end of TA working hours*/
	while(time(NULL)<end_time)
	{
		sem_wait(&waitingRoom);/*access the waiting room*/
		/*Run if there are free seats to be occupied in the waiting room.*/
		if(studentsInWaitingRoom<NUMBER_OF_STUDENTS)
		{
			studentsInWaitingRoom++;//Occupy a free chair
			cout<<"Student joins Waiting room!!Number of students in waiting :"
			    <<studentsInWaitingRoom<<endl;
			sem_post(&waitingRoom);/*Release waiting room access*/
			sem_post(&studentAvailable);/*Indicate student availability*/
			sem_wait(&taReady);/*check for ta availability*/
		}
		/*Run if there are no free seats to be occupied in the waiting room.*/
		else{
			/*release waiting room access, if it is full and leave*/
			sem_post(&waitingRoom);
			cout<<"Waiting Room is full!!Student leaves."<<endl;
		}

		sleep(1);
	}
	return 0;
}
