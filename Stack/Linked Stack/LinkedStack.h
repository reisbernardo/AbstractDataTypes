#include <iostream>
#include "Node.h"

class LinkedStack {
	private:
        Node * t; // Stack's top Node
		int stackSize; // Stack current size
		void merge(Node** headRef);
		Node* sortedMerge(Node* a, Node* b);
		void split(Node* source, Node** frontRef, Node** backRef);
        
	public:
		// Initializes stack
        LinkedStack();

		// Destroys stack
        ~LinkedStack();

		// Adds element to the top of the stack. Stack is increased by one. The top node is set to point at the new Node.
		void push(int n);

		// Removes the top element of the stack. Stack is decreased by one. Returns the removed element.
		int pop();

		// Check if stack is empty, returns true or false
		bool empty();

		// Get stack's front element
		int top();

		// Print stack's elements
		void printStack();

		// Get stack's current size
		int size();

		// Check if element is on stack
		int onStack(int n);

		// Sort linked stack using mergeSort
		void mergeSort();
};