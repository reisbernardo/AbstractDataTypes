#include <cstdlib>
#include <iostream>
#include <sstream>
#include "Node.h"
#include "CircularDoublyLinkedList.h"

CircularDoublyLinkedList::CircularDoublyLinkedList() {
	head = NULL;
	tail = NULL;
	listSize = 0;
}

CircularDoublyLinkedList::~CircularDoublyLinkedList(){
	if (head == NULL && tail == NULL) return;
	tail->setNext(NULL);
	Node* cursor = head, * next;
	while(cursor != NULL) {
		next = cursor->getNext();
		delete cursor;
		cursor = next;
		head = cursor;
	}
	head = NULL;
	tail = NULL;
	listSize = 0;
}

void CircularDoublyLinkedList::addFront(int i) {
	Node * cursor = new Node(i);

	if (head == NULL){
		cursor->setNext(cursor);
		cursor->setPrev(tail);
		tail = cursor;
		
	} else {
		head->setPrev(cursor);
		cursor->setNext(head);
		tail->setNext(cursor);
	}
	head = cursor;
	listSize++;
}

void CircularDoublyLinkedList::addBack(int n) {
	if(head == NULL) return this->addFront(n);
	Node * cursor = new Node(n);

	if (head == NULL){
		cursor->setNext(cursor);
		cursor->setPrev(tail);
		head = cursor;
		tail = head;
	} else{
		tail->setNext(cursor);
		cursor->setNext(head);
		cursor->setPrev(tail);
		tail = cursor;
	}
	listSize++;
}

int CircularDoublyLinkedList::addN(int n, int pos) {
	if (pos < 1) return -1;

	if (pos > listSize + 1) return -1;

	if (pos == 1) {
		addFront(n);
		return 1;
	}
	if (pos == listSize + 1){
		addBack(n);
		return pos;
	}

	Node * cursor1 = new Node(n), * cursor2;
	int i;
	if(pos <= listSize / 2){
		cursor2 = head;
		for (i = 1; i < pos; i++) cursor2 = cursor2->getNext();
	} else{
		cursor2 = tail;
		for (i = listSize; i > pos; i--) cursor2 = cursor2->getPrev();	
	}
	cursor1->setNext(cursor2);
	cursor1->setPrev(cursor2->getPrev());
	cursor2->getPrev()->setNext(cursor1);
	cursor2->setPrev(cursor1);	
	listSize++;
	return pos;
}


int CircularDoublyLinkedList::removeFront(){
	if(head == NULL) return -1;
	int n = head->getValue();
	if(head->getNext() == head){
		head = NULL;
		tail = NULL;
	} else{
		head = head->getNext();
		tail->setNext(head);
		head->setPrev(tail);
	}
	listSize--;
	return n;
}

int CircularDoublyLinkedList::removeBack(){
	if(head == NULL) return -1;
	int n = tail->getValue();
	if(head->getNext() == head) {
		n = head->getValue();
		head = NULL;
		tail = NULL;
	} else{
		tail = tail->getPrev();
		tail->setNext(head);
		head->setPrev(tail);
	}
	listSize--;
	return n;
}

int CircularDoublyLinkedList::removeN(int pos) {
	if(head == NULL) return -1;
	
	if (pos < 1) return -1;

	if (pos > listSize + 1) return -1;

	if (pos == 1) return this->removeFront();

	if (pos == listSize) return this->removeBack();

	int i, n;
	Node * cursor1, *cursor2;

	if(pos <= listSize / 2){
		cursor1 = head;
		for (i = 0; i < pos-2; i++) cursor1 = cursor1->getNext();
		n = cursor1->getNext()->getValue();
		cursor2 = cursor1->getNext()->getNext();
		cursor2->setPrev(cursor1);
		cursor1->setNext(cursor2);
	} else{
		cursor1 = tail;
		for (i = listSize; i > pos + 1; i--) cursor1 = cursor1->getPrev();	
		n = cursor1->getPrev()->getValue();
		cursor2 = cursor1->getPrev()->getPrev();
		cursor2->setNext(cursor1);
		cursor1->setPrev(cursor2);
	}

	listSize--;
	return n;
}

bool CircularDoublyLinkedList::empty() { return head == NULL; }

int CircularDoublyLinkedList::size() { return listSize; }

void CircularDoublyLinkedList::printList() {
	std::cout << "[ ";
	if (head != NULL){
		Node * cursor = head;
		while (cursor->getNext() != head) {
			std::cout << cursor->getValue() << " ";
			cursor = cursor->getNext();
		}
		std::cout << cursor->getValue() << " ";
	}
	std::cout << "]";
}

void CircularDoublyLinkedList::printListInvert() {
	std::cout << "[ ";
	if (head != NULL){
		Node * cursor = tail;
		while (cursor != head) {
			std::cout << cursor->getValue() << " ";
			cursor = cursor->getPrev();
		}
		std::cout << cursor->getValue() << " ";
	}
	std::cout << "]";
}

int CircularDoublyLinkedList::front() {
    if (head != NULL) return head->getValue();
	return -1;
}

int CircularDoublyLinkedList::back() {
    if (tail != NULL) return tail->getValue();
	return -1;
}

void CircularDoublyLinkedList::removeDuplicate(){
	Node *cursor1 = head, *cursor2, * next;

	while(cursor2 != head && cursor1->getNext() != head){
		cursor2 = cursor1;
		while(cursor2->getNext() != head){
			if(cursor1->getValue() == cursor2->getNext()->getValue()){
				if(cursor2->getNext() == tail) this->removeBack();
				else{
					next = cursor2->getNext()->getNext();
					cursor2->setNext(next);
					next->setPrev(cursor2);
					listSize--;
				}
			} else{
				cursor2 = cursor2->getNext();
			}
		}
		cursor1 = cursor1->getNext();
	}
}

void CircularDoublyLinkedList::mergeSort() { 
	tail->setNext(NULL);
	head = sort(head);
	Node* cursor = head, *cursor1 = head->getNext();
	while(cursor1->getNext() != NULL){
		cursor1->setPrev(cursor);
		cursor = cursor->getNext();
		cursor1 = cursor1->getNext();
	}
	cursor1->setPrev(cursor);
	tail = cursor1;
	tail->setNext(head);
	head->setPrev(tail);	
}

Node *CircularDoublyLinkedList::merge(Node *left,Node *right) {
	Node *merged = new Node(0), *aux = new Node(0);
    
    //merged is equal to aux so in the end merged->getNext() is the head.
    merged = aux;

    while(left != NULL && right != NULL) {

        if(left->getValue() <= right->getValue()) {
            aux->setNext(left);
            left = left->getNext();

        } else {
            aux->setNext(right);
            right = right->getNext();
        }
        aux = aux->getNext();
    }
    
    while(left!=NULL) {
        aux->setNext(left);
        left = left->getNext();
        aux = aux->getNext();
    }
 
    while(right!=NULL) {
        aux->setNext(right);
        right = right->getNext();
        aux = aux->getNext();
    }

    return merged->getNext();
}

Node *CircularDoublyLinkedList::sort(Node *h1){
    if(h1->getNext() == NULL) { return h1; }
 
    Node *mid = h1, *aux = h1->getNext(), *h2;

	while(mid->getNext() != NULL && (aux!=NULL && aux->getNext()!=NULL)) {
        mid = mid->getNext();
        aux = aux->getNext()->getNext();
    }

    h2 = mid->getNext();  
    mid->setNext(NULL);
	
    Node *sortedHead = merge(sort(h1),sort(h2)); 
    return sortedHead;
}

bool CircularDoublyLinkedList::onList(int n){
	if(head == NULL) return false;

	Node * cursor = head;
	for(int i = 0; i < listSize; i++){
		if(n == cursor->getValue()) return true;
		cursor = cursor->getNext();
	}
	return false;
}

void CircularDoublyLinkedList::uni(CircularDoublyLinkedList a, CircularDoublyLinkedList b){
	int i, j;
	CircularDoublyLinkedList listAux;
	Node * cursor1 = a.head, * cursor2 = b.head;
	
	for(i = 0; i < a.listSize; i++){
		listAux.addBack(cursor1->getValue());
		cursor1 = cursor1->getNext();
	}
	for(i = 0; i < b.listSize; i++){
		if(!listAux.onList(cursor2->getValue())) {
			listAux.addBack(cursor2->getValue());
			}
		cursor2 = cursor2->getNext();
	}
	listAux.printList();
}

void CircularDoublyLinkedList::intersec(CircularDoublyLinkedList a, CircularDoublyLinkedList b){
	Node * cursor1 = a.head;
	CircularDoublyLinkedList listAux;
	for(int i = 0; i < a.listSize; i++){
		if(b.onList(cursor1->getValue())) listAux.addFront(cursor1->getValue());
		cursor1 = cursor1->getNext();
	}
	listAux.printList();
}

void CircularDoublyLinkedList::diff(CircularDoublyLinkedList a, CircularDoublyLinkedList b){
	Node * cursor1 = a.head;
	CircularDoublyLinkedList listAux;
	for(int i = 0; i < a.listSize; i++){
		if(!b.onList(cursor1->getValue())) listAux.addFront(cursor1->getValue());
		cursor1 = cursor1->getNext();
	}
	listAux.printList();
}

bool CircularDoublyLinkedList::contained(CircularDoublyLinkedList a, CircularDoublyLinkedList b){
	if(a.listSize > b.listSize) return false;

	Node * cursor1 = a.head;

	for(int i = 0; i < a.listSize; i++){
		if(!b.onList(cursor1->getValue())) return false;
		cursor1 = cursor1->getNext();
	}
	return true;
}