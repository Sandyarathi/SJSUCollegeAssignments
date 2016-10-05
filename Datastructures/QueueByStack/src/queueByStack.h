//Header file queueByStack

#ifndef H_QueueByStack
#define H_QueueByStack

#include <iostream>
#include "derivedLinkedStack.h"
#include "queueADT.h"

using namespace std;

template <class Type>
class queueByStack: public queueADT<Type>
{
public:
    bool isEmptyQueue() const;
      //Function to determine whether the queue is empty.
      //Postcondition: Returns true if the queue is empty,
      //    otherwise returns false.

    bool isFullQueue() const;
      //Function to determine whether the queue is full.
      //Postcondition: Returns true if the queue is full,
      //    otherwise returns false.

    void initializeQueue();
      //Function to initialize the queue to an empty state.
      //Postcondition: The queue is empty

    Type front() const;
      //Function to return the first element of the queue.
      //Precondition: The queue exists and is not empty.
      //Postcondition: If the queue is empty, the program
      //    terminates; otherwise, the first element of the
      //    queue is returned.

    Type back() const;
      //Function to return the last element of the queue.
      //Precondition: The queue exists and is not empty.
      //Postcondition: If the queue is empty, the program
      //    terminates; otherwise, the last element of the queue
      //    is returned.

    void addQueue(const Type& queueElement);
      //Function to add queueElement to the queue.
      //Precondition: The queue exists and is not full.
      //Postcondition: The queue is changed and queueElement is
      //    added to the queue.

    void deleteQueue();
      //Function to remove the first element of the queue.
      //Precondition: The queue exists and is not empty.
      //Postcondition: The queue is changed and the first element
      //    is removed from the queue.

    queueByStack();
      //Constructor

    ~queueByStack();
      //Destructor

private:
    linkedStackType<Type>	*stack1;
    linkedStackType<Type>	*stack2;
	int count;
};


template <class Type>
bool queueByStack<Type>::isEmptyQueue() const
{
	return (count == 0);
} //end isEmptyQueue

template <class Type>
bool queueByStack<Type>::isFullQueue() const
{
	return false;
} //end isFullQueue

template <class Type>
void queueByStack<Type>::initializeQueue()
{
	if (stack1) {
		stack1->initializeStack();
	}
	if (stack2) {
		stack2->initializeStack();
	}
	stack1 = new linkedStackType<Type>;
	stack2 = new linkedStackType<Type>;
	count = 0;
} //end initializeQueue

template <class Type>
Type queueByStack<Type>::front() const
{
	// algorithm: (stack1 is inbox and stack2 is outbox)
	// 1. if stack2 is empty, move items from stack1 to stack2
	// 2. pop stack2
	if (!isEmptyQueue()) {
		if (stack2->isEmptyStack()) {
			while (!stack1->isEmptyStack() && !stack2->isFullStack()) {
				Type t = stack1->top();
				stack1->pop();
				stack2->push(t);
			}
		}
		return stack2->top();
	} else
		cout << "Cannot read from an empty queue." << endl;
} //end front

template <class Type>
Type queueByStack<Type>::back() const
{
	// algorithm: (stack1 is inbox and stack2 is outbox)
	// 1. if stack1 is empty, move items from stack2 to stack1
	// 2. pop stack1
	if (!isEmptyQueue()) {
		if (stack1->isEmptyStack()) {
			while (!stack1->isFullStack() && !stack2->isEmptyStack()) {
				Type t = stack2->top();
				stack2->pop();
				stack1->push(t);
			}
		}
		return stack1->top();
	} else
		cout << "Cannot read from an empty queue." << endl;
} //end back

template <class Type>
void queueByStack<Type>::addQueue(const Type& newElement)
{
	// algorithm: (stack1 is inbox and stack2 is outbox)
	// 1. push to stack 1
    if (!isFullQueue() && !stack1->isFullStack()) {
		stack1->push(newElement);
		count++;
    } else
        cout << "Cannot add to a full queue." << endl;
} //end addQueue

/*
 *
 * void ENQUEUE ( element ){

stack1.PUSH (element) //

}
 */

template <class Type>
void queueByStack<Type>::deleteQueue()
{
	// algorithm: (stack1 is inbox and stack2 is outbox)
	// 1. if stack2 is empty, move items from stack1 to stack2
	// 2. pop stack2
    if (!isEmptyQueue()) {
		if (stack2->isEmptyStack()) {
			while (!stack1->isEmptyStack() && !stack2->isFullStack()) {
				Type t = stack1->top();
				stack1->pop();
				stack2->push(t);
			}
		}
		stack2->pop();
        count--;
    } else
        cout << "Cannot remove from an empty queue" << endl;
} //end deleteQueue

/*
 * bool Dequeue (){
 * 	if(!stack1.isEmpty()){
 * 		Type popElement=stack1.pop();
 * 		if(!Dequeue()){
 * 			cout<<popElement;
 * 		}
 * 		else{
 * 			stack1.push(popElement)
 * 		}
 * 		return true;
 * 	}
 * 	return false;
 *

If ( NOT stacky_queue.EMPTY())

{

popped_element = stacky_queue.POP()

IF ( NOT DEQUE() )

{

PRINT popped_element

}

ELSE

{

stacky_queue.PUSH(popped_element)

}

return true

}

return false

}
 */

//Constructor
template <class Type>
queueByStack<Type>::queueByStack()
{
	stack1 = NULL;
	stack2 = NULL;
	initializeQueue();
} //end constructor

//Destructor
template <class Type>
queueByStack<Type>::~queueByStack()
{
	if (stack1) delete stack1;
	if (stack2) delete stack2;
} //end destructor

#endif
