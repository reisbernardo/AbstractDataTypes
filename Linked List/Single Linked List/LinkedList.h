#include <iostream>
#include "Node.h"

class LinkedList {
	private:
		Node * head; // List's head Node
		Node * tail; // List's tail Node
		int listSize; // List current size

		/* Sort function to divide the list in several sublists containing 2 elements, 
		   doing it in a recursive way */
		Node *sort(Node *h);

		// Merge function to merge the sublists in a bigger and sorted list
		Node *merge(Node *left,Node *right);
	
	public:
		// Initializes list
		LinkedList();

		// Destroys list
		~LinkedList();

		// Adds element to the front of the list. List is increased by one.
		void addFront(int n);

		/* Adds element to the back of the list. List is decreased by one. 
		The tail node is set to point at the new Node. Returns the removed element.*/
		void addBack(int n);

		// Adds element "n" at "pos" position. List is increased by one. Ajust list's pointers.
		int addN(int n, int pos);

		// Removes the front element of the stack. Stack is decreased by one. Returns the removed element. Ajust list's pointers.
		int removeFront();

		// Removes the back element of the stack. Stack is decreased by one. Returns the removed element. Ajust list's pointers.
		int removeBack();

		// Removes the element in "pos" position from the stack. Stack is decreased by one. Returns the removed element. Ajust list's pointers.
		int removeN(int pos);

		// Check if list is empty, returns true or false
		bool empty();

		// Get lists's current size
		int size();

		// Print list's elements
		void printList();

		// Get list's head element
		int front();

		// Get list's tail element
		int back();

		// Removes duplicates elements from the list
		void removeDuplicate();

		// Sort linked list using mergeSort
		void mergeSort();

		// Check if element is on the list
		bool onList(int n);

		// Does the set union operation
		void uni(LinkedList a, LinkedList b);

		// Does the set intersection operation
		void intersec(LinkedList a, LinkedList b);

		// Does the set difference operation
		void diff(LinkedList a, LinkedList b);

		// Does the subset of a set operation
		bool contained(LinkedList a, LinkedList b);


		
};