//#ifndef __NODE__
//#define __NODE__

#ifndef NODE_H
#define NODE_H

class Node {
	private:
		int value; // Node value
		Node * next; // Points to the next Node pointer

	public:
		// Initializes a Node
		Node(int); 

		// Gets Node's value
		int  getValue(); 

		// Sets Node's value
		void setValue(int);

		// Gets next pointer 
		Node * getNext(); 

		// Sets next pointer adress
		void setNext(Node * ); 
};

#endif