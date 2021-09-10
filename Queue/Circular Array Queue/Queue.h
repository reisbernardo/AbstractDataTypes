#ifndef ADT_QUEUE_H
#define ADT_QUEUE_H

class Queue {
	private:
		int * queue; // Queue's array
		int queueSize; // Queue current size
		int sizeMax; // Queue's max size
		int f; // First Queue's Node
		int b; // Last Queue's Node
		
	public:
		// Initializes queue
		Queue(int max);

		// Destroys queue
		~Queue();

		/* Adds element to the back of the queue. Queue is increased by one. 
		The back node is set to point at the new Node. Returns queue current size or -1 if queue is full */
		int enqueue(int n); 
		
		// Removes the front element of the queue. Queue is decreased by one. Returns the removed element.
		int dequeue();
		
		// Check if queue is empty, returns true or false
		bool empty();
		
		// Check if queue is full, returns true or false
		bool full();

		// Get queue's front element
		int front();
		
		// Get queue's back element
		int back();
		
		// Print queue's elements
		void printQueue();
		
		// Get queue's current size
		int size();
		
		// Check if element is on queue
		int onQueue(int n);

		// Sorts the array based queue using qsort() function
		void sortQueue();
};

#endif