#include <iostream>
#include "queueByStack.h"

using namespace std;

int main()
{
	queueByStack<int> q;

	q.addQueue(5);
	q.addQueue(23);
	q.addQueue(16);
	cout << "front = " << q.front() << endl;
	cout << "back = " << q.back() << endl;

	q.deleteQueue();
	q.addQueue(75);
	cout << "front = " << q.front() << endl;
	cout << "back = " << q.back() << endl;

	q.addQueue(48);

	while (!q.isEmptyQueue()) {
        cout << q.front() << " ";
        q.deleteQueue();
    }
    cout << endl;
}
