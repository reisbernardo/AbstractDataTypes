#include <cstdlib>
#include <iostream>
#include <sstream>
#include "Node.h"
#include "DoublyLinkedList.h"

using namespace std;

DoublyLinkedList::DoublyLinkedList() {
	head = NULL;
	tail = NULL;
	listSize = 0;
}

DoublyLinkedList::~DoublyLinkedList(){
	if (head == NULL && tail == NULL) return;
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

void DoublyLinkedList::addFront(int i) {
	Node * cursor = new Node(i);
	if(head != NULL) head->setPrev(cursor);
	cursor->setNext(head);
	cursor->setPrev(NULL);
	head = cursor;
	if (tail == NULL) tail = cursor;
	listSize++;
}

void DoublyLinkedList::addBack(int n) {
	if(head == NULL) return this->addFront(n);
	Node * cursor = new Node(n);
	tail->setNext(cursor);
	cursor->setPrev(tail);
	tail = cursor;
	listSize++;
}

int DoublyLinkedList::addN(int n, int pos) {
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


int DoublyLinkedList::removeFront(){
	if(head == NULL) return -1;
	int n = head->getValue();
	if(head->getNext() == NULL){
		head = NULL;
		tail = NULL;
	} else{
		head = head->getNext();
		head->setPrev(NULL);
	}
	listSize--;
	return n;
}

int DoublyLinkedList::removeBack(){
	if(head == NULL) return -1;
	int n = tail->getValue();
	if(head->getNext() == NULL) {
		n = head->getValue();
		head = NULL;
		tail = NULL;
	} else{
		tail = tail->getPrev();
		tail->setNext(NULL);
	}
	listSize--;
	return n;
}

int DoublyLinkedList::removeN(int pos) {
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

bool DoublyLinkedList::empty() { return head == NULL; }

int DoublyLinkedList::size() { return listSize; }

void DoublyLinkedList::printList() {
	Node * cursor = head;
	cout << "[ ";
	while (cursor != NULL) {
		cout << cursor->getValue() << " ";
		cursor = cursor->getNext();
	}
	cout << "]";
}

void DoublyLinkedList::printListInvert() {
	Node * cursor = tail;
	cout << "[ ";
	while (cursor != NULL) {
		cout << cursor->getValue() << " ";
		cursor = cursor->getPrev();
	}
	cout << "]";
}

int DoublyLinkedList::front() {
    if (head != NULL) return head->getValue();
	return -1;
}

int DoublyLinkedList::back() {
    if (tail != NULL) return tail->getValue();
	return -1;
}

void DoublyLinkedList::removeDuplicate(){
	Node *cursor1 = head, *cursor2, * next;

	while(cursor2 != NULL && cursor1->getNext() != NULL){
		cursor2 = cursor1;
		while(cursor2->getNext() != NULL){
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

void DoublyLinkedList::mergeSort() { 
	head = sort(head);
	Node* cursor = head, *cursor1 = head->getNext();
	while(cursor1->getNext() != NULL){
		cursor1->setPrev(cursor);
		cursor = cursor->getNext();
		cursor1 = cursor1->getNext();
	}
	cursor1->setPrev(cursor);
	head->setPrev(NULL);
	tail = cursor1;	
}

Node *DoublyLinkedList::merge(Node *left,Node *right) {
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


Node *DoublyLinkedList::sort(Node *h1){
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

bool DoublyLinkedList::onList(int n){
	if(head == NULL) return false;

	Node * cursor = head;
	for(int i = 0; i < listSize; i++){
		if(n == cursor->getValue()) return true;
		cursor = cursor->getNext();
	}
	return false;
}

void DoublyLinkedList::uni(DoublyLinkedList a, DoublyLinkedList b){
	int i, j;
	DoublyLinkedList listAux;
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

void DoublyLinkedList::intersec(DoublyLinkedList a, DoublyLinkedList b){
	Node * cursor1 = a.head;
	DoublyLinkedList listAux;
	for(int i = 0; i < a.listSize; i++){
		if(b.onList(cursor1->getValue())) listAux.addFront(cursor1->getValue());
		cursor1 = cursor1->getNext();
	}
	listAux.printList();
}

void DoublyLinkedList::diff(DoublyLinkedList a, DoublyLinkedList b){
	Node * cursor1 = a.head;
	DoublyLinkedList listAux;
	for(int i = 0; i < a.listSize; i++){
		if(!b.onList(cursor1->getValue())) listAux.addFront(cursor1->getValue());
		cursor1 = cursor1->getNext();
	}
	listAux.printList();
}

bool DoublyLinkedList::contained(DoublyLinkedList a, DoublyLinkedList b){
	if(a.listSize > b.listSize) return false;

	Node * cursor1 = a.head;

	for(int i = 0; i < a.listSize; i++){
		if(!b.onList(cursor1->getValue())) return false;
		cursor1 = cursor1->getNext();
	}
	return true;
}