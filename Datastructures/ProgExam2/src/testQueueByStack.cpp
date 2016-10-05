/*
 * testQueueByStack.cpp
 *
 *  Created on: Nov 6, 2014
 *      Author: sandyarathidas
 */

#include<iostream>

#include "queueByStack.h"
using namespace std;

int main()
{
	queueByStack<int> q;

	cout << "testQueueByStack by Sandyarathi Das" << endl;

	q.addQueue(7);
	q.addQueue(23);
	q.addQueue(16);
	cout << "front = " << q.front() << endl;
	cout << "back = " << q.back() << endl;

	q.deleteQueue();
	q.addQueue(37);
	cout << "front = " << q.front() << endl;
	cout << "back = " << q.back() << endl;

	q.addQueue(48);

	while (!q.isEmptyQueue()) {
        cout << q.front() << " ";
        q.deleteQueue();
    }
    cout << endl;
}

