#include <iostream>
#include <string.h>
#include "Node.h"

class CircularLinkedQueue {
	private:
		Node * f; // First Queue's Node
		Node * b; // Last Queue's Node
		int queueSize; // Queue current size
		void merge(Node** frontRef);
		Node* sortedMerge(Node* a, Node* b);
		void split(Node* source, Node** frontRef, Node** backRef);
	
	public:
		// Initializes queue
		CircularLinkedQueue();

		// Destroys queue
		~CircularLinkedQueue();
		
		// Adds element to the back of the queue. Queue is increased by one. The back node is set to point at the new Node.
		void enqueue(int n); 
		
		// Removes the front element of the queue. Queue is decreased by one. Returns the removed element.
		int dequeue();
		
		// Check if queue is empty, returns true or false
		bool empty();
		
		// Get queue's front element
		int front();
		
		// Get queue's back element
		int back();
		
		// Print queue's elements
		void printQueue();
		
		// Get queue's current size
		int size();
		
		// Check if element is on queue
		int onQueue(int value);
		
		// Sort linked queue using mergeSort
		void mergeSort();
};