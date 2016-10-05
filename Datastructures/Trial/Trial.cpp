#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<pthread.h>
#include<semaphore.h>
#include<errno.h>
#include<sys/ipc.h>

# define MAX_WAITING_ROOM_SIZE 9;

void ta_function(void *arg);
void student_function(void *arg);

sem_t wait_queue_sem, student_sem, ta_sem; //, ta_work_sem, ta_sync_sem;

int waiting_room_count = MAX_WAITING_ROOM_SIZE;
int static stud_count = 0;

time_t end_time;

int main(){
	pthread_t ta_id[3], student_id[10];
	int thread_status = 0;
	int i, j, k,l;
	//int ta_count, max_student_count;
	//printf("Enter the number of TAs available for the day(0-3).\n");
	//scanf("%d", &ta_count);
	//Initializing the semaphores
		sem_init(&wait_queue_sem, 0, 1);
		sem_init(&student_sem, 0, 0);
		sem_init(&ta_sem, 0, 3);
		//sem_init(&ta_work_sem, 0, 0);
		//sem_init(&ta_sync_sem, 0, ta_count);

		//Creating threads for ta and student
		for (i = 1; i <= 3; i++){
			thread_status = pthread_create(&ta_id[i], NULL, (void *)ta_function, (void*)&i);
			sleep(1);
			if (thread_status != 0)
				perror("Creating TA Thread failed!\n");

		}
		for (j = 1; j <= 10; j++){
			thread_status = pthread_create(&student_id[j], NULL, (void *)student_function, (void*)&j);
			sleep(1);
			if (thread_status != 0)
				perror("Creating student Thread failed!\n");

		}

		for (k = 1; k <= 10; k++)
			pthread_join(student_id[k], NULL);
		//for (l = 1; l <= 3; l++)
			//pthread_join(ta_id[l], NULL);

		exit(0);
}

void ta_function(void *arg)
{
	int j = *(int *)(arg);
	printf("TA %d is waiting for student.\n", j);
	while (1)
	{
		sem_wait(&student_sem);
		printf("TA %d is helping student.\n", j);
		sem_post(&ta_sem);
		sleep(0.5);
		printf("TA %d finishes helping.\n", j);
	}
}


void student_function(void *arg)
{
	int n = *(int *)(arg);
	sem_wait(&wait_queue_sem);
	stud_count++;
	printf("Student %d arrives.\n", n);
	if (waiting_room_count>0){
		waiting_room_count--;
		sem_post(&wait_queue_sem);
		printf("Student %d waits for TA.\n", n);
		sem_post(&student_sem);
		sleep(1);
		sem_wait(&ta_sem);
		sem_wait(&wait_queue_sem);
		waiting_room_count++;
		sem_post(&wait_queue_sem);
	}
	else{
		sem_post(&wait_queue_sem);
		printf("No seats avaialble to wait.Student %d leaves\n", n);
	}
	pthread_exit(0);
}
