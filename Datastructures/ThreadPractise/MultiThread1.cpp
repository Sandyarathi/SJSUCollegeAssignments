/*
 * MultiThread1.cpp
 *
 *  Created on: Oct 1, 2014
 *      Author: sandyarathidas
 */




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

void *Sum(int arr[])
{

  int i;  int total;

	total=0;

	for(i=1;i<=10;++i){
		total+=arr[i];

	}

	pthread_exit((void *)total); // Notice the cast
	return 0;
}

void *Avg(int arr[])
{

  int i;  int total;double average;

	total=0;

	for(i=1;i<=10;++i){
		total+=arr[i];

	}
	average=total/10;

	pthread_exit((void *)average); // Notice the cast
	return 0;
}


int main(){
	int userArray[10]={1,2,3,4,5,6,7,8,9,10};

	pthread_t avgThread;
	pthread_t sumThread;
	int total;
	double average;

    pthread_create(&sumThread,NULL,Sum,(void *)userArray);
    pthread_join(sumThread,(void**)&total);
    cout<<"\nTotal Sum= "<<total;

    pthread_create(&avgThread,NULL,Avg,(void *)userArray);
        pthread_join(avgThread,(void**)&average);
        cout<<"\nTotal Average= "<<average;


    return 0;



}

