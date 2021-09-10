#ifndef ADT_STACK_H
#define ADT_STACK_H

class Stack {
	private:
        int * stack; // Stack's circular array
		int t; // Stack's top element index
        int sizeMax; // Stack max size
        
	public:
		// Initializes stack
        Stack(int max);

		// Destroys stack
        ~Stack();

		/* Adds element to the back of the stack. Stack is increased by one. 
		The back node is set to point at the new Node. Returns stack current size or -1 if stack is full */
		int push(int n);

		// Removes the top element of the stack. Stack is decreased by one. Returns the removed element.
		int pop();

		// Check if stack is empty, returns true or false
		bool empty();

		// Check is stack is full, returns true or false
		bool full();

		// Get stack's front element
		int top();

		// Print stack's elements
		void printStack();

		// Get stack's current size
		int size();

		// Check if element is on stack
		int onStack(int n);

		// Sorts the array based queue using qsort() function
		void sortStack();
};

#endif
