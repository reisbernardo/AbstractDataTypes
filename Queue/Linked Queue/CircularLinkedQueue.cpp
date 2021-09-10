#include <cstdlib>
#include <iostream>
#include "Node.h"
#include "CircularLinkedQueue.h"

CircularLinkedQueue::CircularLinkedQueue() {
	f = NULL;
	b = NULL;
	queueSize = 0;
}

CircularLinkedQueue::~CircularLinkedQueue() {
	b->setNext(NULL);
	Node* cursor = f, * next;
	while(cursor != NULL) {
		next = cursor->getNext();
		delete cursor;
		cursor = next;
	}
	f = NULL;
	b = NULL;
	queueSize = 0;
}

void CircularLinkedQueue::enqueue(int n) {
	Node * cursor = new Node(n);
	if(f == NULL){
		cursor->setNext(cursor);
		f = cursor;
		b = f;
	} else{
		b->setNext(cursor);
		cursor->setNext(f);
		b = cursor;
	}
	queueSize++;
}

int CircularLinkedQueue::dequeue(){
	if(f == NULL) return -1;
	int n = f->getValue();
	if(f->getNext() == f) {
		f = NULL;
		b = NULL;
	} else{
		f = f->getNext();
		b->setNext(f);
	}
	queueSize--;
	return n;
}

bool CircularLinkedQueue::empty() { return f == NULL; }

int CircularLinkedQueue::front() {
    if (f != NULL) return f->getValue();
	return -1;
}

int CircularLinkedQueue::back() {
    if (b != NULL) return b->getValue();
	return -1;
}

void CircularLinkedQueue::printQueue() {
	std::cout << "[ ";
	if(f != NULL){
		Node * cursor = f;
		while (cursor->getNext() != f) {
			std::cout << cursor->getValue() << " ";
			cursor = cursor->getNext();
		}
		std::cout << cursor->getValue() << " ";
	}
	std::cout << "]";
}

int CircularLinkedQueue::size() { return this->queueSize; }

int CircularLinkedQueue::onQueue(int n) {
	if(empty()) return -1;
    Node * cursor = f;
	do{
		if(cursor->getValue() == n) return 0;
        cursor = cursor->getNext();
	}
	while(cursor->getNext() != f);
    return -1;
}

void CircularLinkedQueue::mergeSort(){ 
	b->setNext(NULL);
	merge(&f);
	Node* cursor = f;
	while(cursor->getNext() != NULL){
		cursor = cursor->getNext();
	}
	b = cursor;
	b->setNext(f);
}

void CircularLinkedQueue::merge(Node** frontRef) {
    Node* h = *frontRef;
    Node* a;
    Node* b;
    if ((h == NULL) || (h->getNext() == NULL)) {return;}
 
    split(h, &a, &b);
	
    merge(&a);
    merge(&b);
	
    *frontRef = sortedMerge(a, b);
}

Node* CircularLinkedQueue::sortedMerge(Node* a, Node* b) {
    Node* result = NULL;

    if (a == NULL) return (b);
	
    else if (b == NULL) return (a);
	
    if (a->getValue() <= b->getValue()) {
        a->setNext(sortedMerge(a->getNext(), b));
		result = a;
    } else {
        b->setNext(sortedMerge(a, b->getNext()));
		result = b;
    }
    return result;
}
 
void CircularLinkedQueue::split(Node* source, Node** frontRef, Node** backRef) {
    Node* fast;
    Node* slow;
    slow = source;
    fast = source->getNext();
    while (fast != NULL) {
        fast = fast->getNext();
        if (fast != NULL) {
            slow = slow->getNext();
            fast = fast->getNext();
        }
    }

    *frontRef = source;
    *backRef = slow->getNext();
    slow->setNext(NULL);
}