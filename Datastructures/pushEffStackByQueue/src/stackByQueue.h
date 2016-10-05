/*
 * stackByQueue.h
 *
 *  Created on: Nov 6, 2014
 *      Author: sandyarathidas
 */

#ifndef STACKBYQUEUE_H_
#define STACKBYQUEUE_H_


#include "stackADT.h"
#include "linkedQueue.h"
#include <cassert>

// push efficient
template <class Type>
class stackByQueue : public stackADT<Type>
{
public:
	void initializeStack();
	//Method to initialize the stack to an empty state.
	//Postcondition: Stack is empty.

	bool isEmptyStack() const;
	//Function to determine whether the stack is empty.
	//Postcondition: Returns true if the stack is empty,
	//    otherwise returns false.

	bool isFullStack() const;
	//Function to determine whether the stack is full.
	//Postcondition: Returns true if the stack is full,
	//    otherwise returns false.

	void push(const Type& newItem);
	//Function to add newItem to the stack.
	//Precondition: The stack exists and is not full.
	//Postcondition: If the stack is full, the program
	//    terminates; otherwise, the stack is changed and newItem is added
	//    to the top of the stack.

	Type top();
	//Function to return the top element of the stack.
	//Precondition: The stack exists and is not empty.
	//Postcondition: If the stack is empty, the program
	//    terminates; otherwise, the top element of the stack
	//    is returned.

	void pop();
	//Function to remove the top element of the stack.
	//Precondition: The stack exists and is not empty.
	//Postcondition: If the stack is empty, the program
	//    terminates; otherwise, the stack is changed and the top element
	//    is removed from the stack.
	stackByQueue();
	~stackByQueue();

private:
	linkedQueueType<Type>	*queue;
};

template <class Type>
void stackByQueue<Type>::initializeStack()
{
	queue = new linkedQueueType<Type>;

}

template <class Type>
bool stackByQueue<Type>::isEmptyStack() const
{
	return queue->isEmptyQueue();

}

template <class Type>
bool stackByQueue<Type>::isFullStack() const
{
	return queue->isFullQueue();

}

template <class Type>
void stackByQueue<Type>::push(const Type& newItem)
{
	assert(!isFullStack());

		// push efficient.  simply add to the queue
		// rear of queue is top of stack
		queue->addQueue(newItem);

}

template <class Type>
Type stackByQueue<Type>::top()
{
	assert(!isEmptyStack());

		// the rear item in queue is the top of the stack
		return queue->back();
	/*
		// alternative solution
		Type tmp;
		int size = queue->size();

		// traverse the entire queue
		// restore the entire queue
		while (size > 0) {
			tmp = queue->front();
			queue->deleteQueue();
			queue->addQueue(tmp);
			size--;
		}
		// tmp is the rear item in the queue, or the top of the stack

		return tmp;
	*/

}

template <class Type>
void stackByQueue<Type>::pop()
{
	assert(!isEmptyStack());

		Type tmp;
		int size = queue->size();

		// traverse the entire queue
		// restore the entire queue, except the rear item (top of the stack)
		while (size > 0) {
			tmp = queue->front();
			queue->deleteQueue();
			if (size > 1)
				queue->addQueue(tmp);
			size--;
		}
}

template <class Type>
stackByQueue<Type>::stackByQueue()
{
	initializeStack();
}

template <class Type>
stackByQueue<Type>::~stackByQueue()
{
	delete queue;

}



#endif /* STACKBYQUEUE_H_ */
