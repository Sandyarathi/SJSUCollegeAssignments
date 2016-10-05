#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<pthread.h>
#include<errno.h>
#include<sys/ipc.h>
#include<semaphore.h>

int customers =0;

sem_t max_capacity,barber_chair,cust_ready,finished,leave_b_chair,payment,receipt,coord;

void barberthread(void *arg);
void customerthread(void *arg);

int main()

{
	pthread_t id1[3],id2[10];
	int j,k,status=0,loop =0;

	/*Semaphore initialization*/
	sem_init(&max_capacity,0,20);
	sem_init(&payment,0,0);
	sem_init(&barber_chair,0,3);
	sem_init(&cust_ready,0,0);
	sem_init(&finished,0,0);
	sem_init(&receipt,0,0);
	sem_init(&leave_b_chair,0,0);
	sem_init(&coord,0,3);

	/*Barber_thread initialization*/
	for (k =0;k<3;k++)
	{	int status=pthread_create(&id1[k],NULL,(void *)barberthread,(void*)&k);
	 	sleep(1);
		if(status!=0)
			perror("create barbers is failure!\n");

	}

	/*Customer_thread initialization*/

	label:
	for (j =0;j<10;j++)
	{	int status=pthread_create(&id2[j],NULL,(void *)customerthread,(void*)&j);
		if(status!=0)
			perror("create customers is failure!\n");
		sleep(1);
	}

	for (j =0;j<10;j++)
		pthread_join(id2[j],NULL);


	printf("Do u want more customers ? Yes :1 No: 2\n");
	scanf("%d",&k);
	if ( k == 1)
		goto label;
	else
		exit(0);
}

void customerthread(void *tmp)		/*Barber Process*/
{	int j = *(int *)(tmp);

	sem_wait(&max_capacity);
	printf("Customer[%d] has entered shop\n",j);
	sem_wait(&barber_chair);
	printf("Cutomer[%d] is sitting in barber chair\n",j);
	sem_post(&cust_ready);
	sleep((rand()%20)/5);
	sem_wait(&finished);
	printf("customer[%d] leaves barber chair\n",j);
	sem_post(&leave_b_chair);
	printf("Cutomer[%d] is offering to pay\n",j);
	sem_post(&payment);
	sem_wait(&receipt);
	printf("Customer[%d] is exiting shop\n",j);
	sem_post(&max_capacity);

	pthread_exit(0);
}



void barberthread(void *tmp)		/*Customers Process*/
{	int j = *(int *)(tmp);

	int loop = 0;
	while(loop == 0)	/*Infinite loop*/

	{	sem_wait(&cust_ready);
		sem_wait(&coord);
		printf("Barber[%d] is cutting hair\n",j);
		sem_post(&coord);
		sem_post(&finished);
		sem_wait(&leave_b_chair);
		sem_post(&barber_chair);
		sem_wait(&payment);
		sem_wait(&coord);
		printf("Barber[%d] is accepting payment\n",j);
		sem_post(&coord);
		sem_post(&receipt);
		sleep(2);

	}

}
