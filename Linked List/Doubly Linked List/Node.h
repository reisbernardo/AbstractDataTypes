//#ifndef __Node__
//#define __Node__

#ifndef Node_H
#define Node_H

class Node {
	private:
		int value; // Node value
		Node * next; // Points to the next Node pointer, if its the tail's Node then it points to head
		Node * prev; // Points to the previous Node pointer, if its the head Node then it points to tail

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

		// Gets previous pointer 
		Node * getPrev();

		// Sets previous pointer adress
		void setPrev(Node * );
};
#endif