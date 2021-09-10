#include <cstdlib>
#include <iostream>
#include "Node.h"
#include "LinkedStack.h"

LinkedStack::LinkedStack() {
    t = NULL;
	stackSize = 0;
}

LinkedStack::~LinkedStack(){
	Node* cursor = t, * next;
	while(cursor != NULL) {
		next = cursor->getNext();
		delete cursor;
		cursor = next;
	}
	t = NULL;
	stackSize = 0;
}

void LinkedStack::push(int n) {
    Node * cursor = new Node(n);
	cursor->setNext(t);
	t = cursor;
	stackSize++;
}

int LinkedStack::pop() {
    if(t == NULL) return -1;
	int n = t->getValue();
	if(t->getNext() == NULL) t = NULL;

	else t = t->getNext();

	stackSize--;
	return n;
}

bool LinkedStack::empty() { return t == NULL; }

int LinkedStack::top() {
    if(empty()) return -1; 
    return t->getValue();
}

void LinkedStack::printStack() {
	Node * cursor = t;
	std::cout << "[ ";
	while (cursor != NULL) {
		std::cout << cursor->getValue() << " ";
		cursor = cursor->getNext();
	}
	std::cout << "]";
}

int LinkedStack::size() { return stackSize; }

int LinkedStack::onStack(int n) {
	if(empty()) return -1;
    Node * cursor = t;
	while(cursor != NULL){
        if(cursor->getValue() == n) return 0;
        cursor = cursor->getNext();
    }
    return -1;
}

void LinkedStack::mergeSort(){ merge(&t); }

void LinkedStack::merge(Node** topRef) {
    Node* h = *topRef;
    Node* a;
    Node* b;
    if ((h == NULL) || (h->getNext() == NULL)) {return;}
 
    split(h, &a, &b);
	
    merge(&a);
    merge(&b);
	
    *topRef = sortedMerge(a, b);
}

Node* LinkedStack::sortedMerge(Node* a, Node* b) {
    Node* result = NULL;

    if (a == NULL) return (b);
	
    else if (b == NULL) return (a);
	
    if (a->getValue() >= b->getValue()) {
        a->setNext(sortedMerge(a->getNext(), b));
		result = a;
    } else {
        b->setNext(sortedMerge(a, b->getNext()));
		result = b;
    }
    return result;
}
 
void LinkedStack::split(Node* source, Node** frontRef, Node** backRef) {
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