#include <cstdlib>
#include <iostream>
#include <cstdlib>
#include "Node.h"
#include "CircularLinkedList.h"

CircularLinkedList::CircularLinkedList() {
	head = NULL;
	tail = NULL;
	listSize = 0;
}

CircularLinkedList::~CircularLinkedList(){
	if (head == NULL && tail == NULL) return;
	tail->setNext(NULL);
	Node* cursor = head, * next;
	while(cursor != NULL) {
		next = cursor->getNext();
		delete cursor;
		cursor = next;
	}
	head = NULL;
	tail = NULL;
	listSize = 0;
}

void CircularLinkedList::addFront(int n) {
	Node * cursor = new Node(n);

	if(head == NULL){
		cursor->setNext(cursor);
		tail = cursor;
	} else{
		cursor->setNext(head);
		tail->setNext(cursor);
	}
	head = cursor;
	listSize++;
}

void CircularLinkedList::addBack(int n) {
	Node * cursor = new Node(n);
	if(head == NULL){
		cursor->setNext(cursor);
		head = cursor;
		tail = head;
	} else{
		tail->setNext(cursor);
		cursor->setNext(head);
		tail = cursor;
	}
	listSize++;
}

int CircularLinkedList::addN(int n, int pos) {
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

	Node * cursor1 = head;
	Node * cursor2 = new Node(n);
	
	for (int i = 1; i < pos - 1; i++) cursor1 = cursor1->getNext();

	cursor2->setNext(cursor1->getNext());
	cursor1->setNext(cursor2);
	
	listSize++;
	return pos;
}

int CircularLinkedList::removeFront(){
	if(head == NULL) return -1;
	int n = head->getValue();
	if(head->getNext() == head) {
		head = NULL;
		tail = NULL;
	} else{
		head = head->getNext();
		tail->setNext(head);
	}
	listSize--;
	return n;
}

int CircularLinkedList::removeBack(){
	if(head == NULL) return -1;

	Node * cursor = head;
	int n;
	if(cursor->getNext() == head){
		n = head->getValue();
		head = NULL;
		tail = NULL;
	} else{
		while(cursor->getNext()->getNext() != head) cursor = cursor->getNext();
		n = cursor->getNext()->getValue();
		tail = cursor;
		tail->setNext(head);
	}

	listSize--;
	return n;
}

int CircularLinkedList::removeN(int pos) {
	if(head == NULL) return -1;
	
	if (pos < 1) return -1;

	if (pos > listSize + 1) return -1;

	if (pos == 1) return this->removeFront();

	if (pos == listSize) return this->removeBack();

	Node * cursor = head;

	for (int i = 0; i < pos-2; i++) cursor = cursor->getNext();

	int n = cursor->getNext()->getValue();

	cursor->setNext(cursor->getNext()->getNext());

	listSize--;
	return n;
}

bool CircularLinkedList::empty() { return head == NULL; }

int CircularLinkedList::size() { return this->listSize; }

void CircularLinkedList::printList() {
	std::cout << "[ ";
	if(head != NULL){
		Node * cursor = head;
		while (cursor->getNext() != head) {
			std::cout << cursor->getValue() << " ";
			cursor = cursor->getNext();
		}
		std::cout << cursor->getValue() << " ";
	}
	std::cout << "]";
}

int CircularLinkedList::front() {
    if (head != NULL) return head->getValue();
	return -1;
}

int CircularLinkedList::back() {
    if (tail != NULL) return tail->getValue();
	return -1;
}

void CircularLinkedList::removeDuplicate(){
	Node *cursor1 = head, *cursor2;

	while(cursor2 != head && cursor1->getNext() != head){
		cursor2 = cursor1;
		while(cursor2->getNext() != head){
			if(cursor1->getValue() == cursor2->getNext()->getValue()){
				if(cursor2->getNext() == tail) this->removeBack();

				else{
					cursor2->setNext(cursor2->getNext()->getNext());
					listSize--;
				}
			} else{
				cursor2 = cursor2->getNext();
			}
		}
		cursor1 = cursor1->getNext();
	}
}

void CircularLinkedList::mergeSort(){
	tail->setNext(NULL);
	head = sort(head);
	Node* cursor = head;
	while(cursor->getNext() != NULL){
		cursor = cursor->getNext();
	}
	tail = cursor;
	tail->setNext(head);
}

Node *CircularLinkedList::merge(Node *left,Node *right) {
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

Node *CircularLinkedList::sort(Node *h1){
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


bool CircularLinkedList::onList(int n){
	if(head == NULL) return false;

	Node * cursor = head;
	for(int i = 0; i < listSize; i++){
		if(n == cursor->getValue()) return true;
		cursor = cursor->getNext();
	}
	return false;
}

void CircularLinkedList::uni(CircularLinkedList a, CircularLinkedList b){
	int i, j;
	CircularLinkedList listAux;
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

void CircularLinkedList::intersec(CircularLinkedList a, CircularLinkedList b){
	Node * cursor1 = a.head;
	CircularLinkedList listAux;
	for(int i = 0; i < a.listSize; i++){
		if(b.onList(cursor1->getValue())) listAux.addFront(cursor1->getValue());
		cursor1 = cursor1->getNext();
	}
	listAux.printList();
}

void CircularLinkedList::diff(CircularLinkedList a, CircularLinkedList b){
	Node * cursor1 = a.head;
	CircularLinkedList listAux;
	for(int i = 0; i < a.listSize; i++){
		if(!b.onList(cursor1->getValue())) listAux.addFront(cursor1->getValue());
		cursor1 = cursor1->getNext();
	}
	listAux.printList();
}

bool CircularLinkedList::contained(CircularLinkedList a, CircularLinkedList b){
	if(a.listSize > b.listSize) return false;

	Node * cursor1 = a.head;

	for(int i = 0; i < a.listSize; i++){
		if(!b.onList(cursor1->getValue())) return false;
		cursor1 = cursor1->getNext();
	}
	return true;
}