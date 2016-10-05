/*
 * sleepTA.c
 *
 *  Created on: Dec 2, 2014
 *      Author: sandyarathidas
 */


#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<pthread.h>
#include<semaphore.h>
#include<sys/ipc.h>

// Maximum capacity of the waiting room.
# define MAX_WAITING_ROOM_SIZE 9;

//Function to create the TA threads and control the activities
void ta_function(void *arg);
//Function to create the student threads and control the activities
void student_function(void *arg);

/*Semaphore declarations for synchronizing the access to the shared variable
'waiting_room_count' and synchronizing the activities of ta and  students*/
sem_t wait_queue_sem, student_sem, ta_sem,ta_sync;

//Initializing the shared variable to the maximum capacity of waiting room
int waiting_room_count = MAX_WAITING_ROOM_SIZE;
int stud_with_ta_count = 3;
// variable to keep track of the number of students approching TAs
int static stud_count = 0;

int main(){
	//Declaring the ids for TA and student threads
	pthread_t ta_id[3], student_id[13];
	int thread_status = 0;
	int i, j, k, l;

	//Initializing the semaphores
	sem_init(&wait_queue_sem, 0, 1);//Binary semaphore to control the access to the shared variable 'waiting_room_count'
	sem_init(&student_sem, 0, 0);//semaphore to indicate if a student is available or not
	sem_init(&ta_sem, 0, 3);//semaphore to indicate if a TA is free or helping student.
	sem_init(&ta_sync, 0, 1);//semaphore to indicate if a TA is free or helping student.

	//Creating threads for TAs
	for (i = 1; i <= 3; i++){
		thread_status = pthread_create(&ta_id[i], NULL, (void *)ta_function, (void*)&i);
		sleep(1);
		if (thread_status != 0)
			printf("Creating TA Thread failed!\n");
	}
	//Creating threads for students
	for (j = 1; j <= 13; j++){
		thread_status = pthread_create(&student_id[j], NULL, (void *)student_function, (void*)&j);
		sleep(1);
		if (thread_status != 0)
			printf("Creating student Thread failed!\n");
	}

	//Blocking student threads
	for (k = 1; k <= 13; k++)
		pthread_join(student_id[k], NULL);

	exit(0);
}

/*Initially each TA waits for the student to approach.Once the student approaches,
the TA starts helping the student.*/
void ta_function(void *arg)
{
	int j = *(int *)(arg);
	printf("TA %d is waiting for student.\n", j);
	while (1)
	{
			sem_wait(&student_sem);
			printf("TA %d is helping student.\n", j);
			sem_post(&ta_sem);
			sleep(2);
	}
}


/*The student arrives and enters the waiting room. */
void student_function(void *arg)
{
	int n = *(int *)(arg);
	sem_wait(&wait_queue_sem);
	stud_count++;
	printf("Student %d arrives.\n", n);
	if (waiting_room_count>0){
		waiting_room_count--;
		printf("Student %d waits for TA.\n", n);
		sem_post(&wait_queue_sem);
		if (stud_with_ta_count>0){
			printf("Student %d approaches TA.\n", n);
			sem_wait(&ta_sync);
			stud_with_ta_count--;
			sem_post(&ta_sync);
			sem_post(&student_sem);
			sleep(1);
			sem_wait(&ta_sem);
			printf("Student %d leaves.\n", n);
			sem_wait(&ta_sync);
			stud_with_ta_count++;
			sem_post(&ta_sync);
			sem_wait(&wait_queue_sem);
			waiting_room_count++;
			sem_post(&wait_queue_sem);
		}
	}
	else{
		sem_post(&wait_queue_sem);
		printf("No seats avaialble to wait.Student %d leaves\n", n);
	}
	pthread_exit(0);
}

