/*
 * testStackByQueue.cpp
 *
 *  Created on: Nov 6, 2014
 *      Author: sandyarathidas
 */


#include <iostream>
#include "stackByQueue.h"


using namespace std;

int main()
{
	stackByQueue<int> s;

	cout << "testStackByQueue by Sandyarathi" << endl;

	s.push(3);
	cout << "after push 3, top = " << s.top() << endl;
	s.push(19);
	cout << "after push 19, top = " << s.top() << endl;
	s.push(7);
	cout << "after push 7, top = " << s.top() << endl;
	s.pop();
	cout << "after pop, top = " << s.top() << endl;
	s.push(11);
	cout << "after push 11, top = " << s.top() << endl;
	s.pop();
	cout << "after pop, top = " << s.top() << endl;
	s.pop();
	cout << "after pop, top = " << s.top() << endl;

	s.push(13);
	cout << "after push 13, stack = ";
	while (!s.isEmptyStack()) {
		cout << s.top() << " ";
		s.pop();
	}
	cout << endl << "***over***" << endl;

	return 0;
}

