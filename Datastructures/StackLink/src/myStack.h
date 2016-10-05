/*
 * myStack.h
 *
 *  Created on: Nov 5, 2014
 *      Author: sandyarathidas
 */

#ifndef MYSTACK_H_
#define MYSTACK_H_

#include <iostream>
#include <cassert>
#include "stackADT.h"

using namespace std;
template<class Type>
struct nodeType{
	nodeType<Type> link;
	Type info;
};

template <class Type>
class stackLinkedType: public stackADT<Type>
{
public:
	const stackLinkedType<Type>& operator=(const stackLinkedType<Type>&);
	//Overload the assignment operator.
	void initializeStack();
	//Function to initialize the stack to an empty state.
	//Postcondition: stackTop = 0;
	bool isEmptyStack() const;
	//Function to determine whether the stack is empty.
	//Postcondition: Returns true if the stack is empty,
	// otherwise returns false.

	bool isFullStack() const;
	//Function to determine whether the stack is full.
	//Postcondition: Returns true if the stack is full,
	// otherwise returns false.
	void push(const Type& newItem);
	//Function to add newItem to the stack.
	//Precondition: The stack exists and is not full.
	//Postcondition: The stack is changed and newItem is
	// added to the top of the stack.
	Type top() const;
	//Function to return the top element of the stack.
	//Precondition: The stack exists and is not empty.
	//Postcondition: If the stack is empty, the program
	// terminates; otherwise, the top element of the stack
	// is returned.
	void pop();
	//Function to remove the top element of the stack.
	//Precondition: The stack exists and is not empty.
	//Postcondition: The stack is changed and the top element is
	// removed from the stack.
	stackLinkedType();
	//Default Constructor

	stackLinkedType(const stackLinkedType<Type>& otherStack);
	//Copy constructor
	~stackLinkedType();
	//Destructor
	//Remove all the elements from the stack.
	//Postcondition: The array (list) holding the stack
	// elements is deleted.
private:

	nodeType<Type> *stackTop;
	void copyStack(const linkedStackType<Type>& otherStack);
	//Function to make a copy of otherStack.
	//Postcondition: A copy of otherStack is created and
	// assigned to this stack.

};

template<class Type>
const stackLinkedType<Type>& stackLinkedType<Type>::operator=
		(const stackLinkedType<Type>& otherStack) {

	if (this != &otherStack) //avoid self-copy
		copyStack(otherStack);
	return *this;

}

template<class Type>
inline void stackLinkedType<Type>::initializeStack() {
	nodeType<Type> *temp;
	while(stackTop!=NULL){
		temp=stackTop;
		stackTop=stackTop->link;
		delete temp;
	}

}

template<class Type>
inline bool stackLinkedType<Type>::isEmptyStack() const {
	return (stackTop==NULL);
}

template<class Type>
inline bool stackLinkedType<Type>::isFullStack() const {
	return false;
}

template<class Type>
inline void stackLinkedType<Type>::push(const Type& newItem) {

	nodeType<Type>* item;
	item=new nodeType<Type>;
	if(isEmpty()){
		stackTop->info=newItem;
	}
	else{
		item->info=newItem;
		item->link=NULL;
		stackTop=item;
	}

}

template<class Type>
inline Type stackLinkedType<Type>::top() const {

	return stackTop->info;
}

template<class Type>
inline void stackLinkedType<Type>::pop() {
	if(stackTop!=NULL){

	nodeType<Type> *temp;
	temp=stackTop;
	stackTop=stackTop->link;
	delete temp;
	}
	else{
		cerr<<"Cannot delete from an empty stack"<<endl;
	}
}

template<class Type>
inline stackLinkedType<Type>::stackLinkedType() {
	stackTop=NULL;
}

template<class Type>
inline stackLinkedType<Type>::stackLinkedType(
		const stackLinkedType<Type>& otherStack) {


	stackTop = NULL;
	copyStack(otherStack);
}

template<class Type>
inline stackLinkedType<Type>::~stackLinkedType() {
	initializeStack();
}

template<class Type>
inline void stackLinkedType<Type>::copyStack(
		const linkedStackType<Type>& otherStack) {

	nodeType<Type> *current,*newNode,*last;
		if(stackTop!=NULL){
			initializeStack();
		}
		if(otherStack.stackTop==NULL){
			stackTop=NULL;
		}
		else{
			current=otherStack.stackTop;
			stackTop=new nodeType<Type>;
			stackTop->info=current->info;
			stackTop->link=NULL;
			last=stackTop;
			current=current->link;
			while(current!=NULL){
				newNode=new nodeType<Type>;
				newNode->info=current->info;
				newNode->link=NULL;
				last->link=newNode;
				last=newNode;
				current=current->link;
			}


		}
}

#endif /* MYSTACK_H_ */
