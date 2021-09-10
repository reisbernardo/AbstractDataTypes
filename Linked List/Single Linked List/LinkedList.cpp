#include <cstdlib>
#include <iostream>
#include "Node.h"
#include "LinkedList.h"

LinkedList::LinkedList() {
	head = NULL;
	listSize = 0;
}

LinkedList::~LinkedList(){
	Node* cursor = head, * next;
	while(cursor != NULL) {
		next = cursor->getNext();
		delete cursor;
		cursor = next;
	}
	head = NULL;
	listSize = 0;
}

void LinkedList::addFront(int n) {
	Node * cursor = new Node(n);
	cursor->setNext(head);
	head = cursor;
	listSize++;
}

void LinkedList::addBack(int n) {
	if(head == NULL) return this->addFront(n);
	Node * cursor = head, * c = new Node(n);

	while(cursor->getNext() != NULL) cursor = cursor->getNext();

	cursor->setNext(c);
	listSize++;
}

int LinkedList::addN(int n, int pos) {
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

	Node * cursor2 = new Node(n), * cursor1 = head;
	for (int i = 1; i < pos - 1; i++) cursor1 = cursor1->getNext();

	cursor2->setNext(cursor1->getNext());
	cursor1->setNext(cursor2);
	
	listSize++;
	return pos;
}

int LinkedList::removeFront(){
	if(head == NULL) return -1;
	int n = head->getValue();
	if(head->getNext() == NULL) head = NULL;

	else head = head->getNext();

	listSize--;
	return n;
}

int LinkedList::removeBack(){
	if(head == NULL) return -1;
	
	int n;

	if(head->getNext() == NULL) {
		n = head->getValue();
		head = NULL;
	} else{
		Node * cursor = head;
		for (int i = 0; i < listSize-2; i++) cursor = cursor->getNext();
		
		n = cursor->getNext()->getValue();
		cursor->setNext(cursor->getNext()->getNext());
	}
	listSize--;
	return n;
}

int LinkedList::removeN(int pos) {
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

bool LinkedList::empty() {return head == NULL;}

int LinkedList::size() {return listSize;}

void LinkedList::printList() {
	Node * cursor = head;
	std::cout << "[ ";
	while (cursor != NULL) {
		std::cout << cursor->getValue() << " ";
		cursor = cursor->getNext();
	}
	std::cout << "]";
}

int LinkedList::front() {
    if (head != NULL) return head->getValue();
	return -1;
}

int LinkedList::back() {
    if (head != NULL) {
		Node * cursor = head;
		for (int i = 1; i < listSize; i++) cursor = cursor->getNext();
		return cursor->getValue();
	}
	return -1;
}

void LinkedList::removeDuplicate(){
	Node *cursor1 = head, *cursor2;

	while(cursor2 != NULL && cursor1->getNext() != NULL){
		cursor2 = cursor1;
		while(cursor2->getNext() != NULL){
			if(cursor1->getValue() == cursor2->getNext()->getValue()){
				cursor2->setNext(cursor2->getNext()->getNext());
				listSize--;
			} else{
				cursor2 = cursor2->getNext();
			}
		}
		cursor1 = cursor1->getNext();
	}
}

void LinkedList::mergeSort(){ head = sort(head); }

Node *LinkedList::merge(Node *left,Node *right) {
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

Node *LinkedList::sort(Node *h1){
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

bool LinkedList::onList(int n){
	if(head == NULL) return false;

	Node * cursor = head;
	for(int i = 0; i < listSize; i++){
		if(n == cursor->getValue()) return true;
		cursor = cursor->getNext();
	}
	return false;
}

void LinkedList::uni(LinkedList a, LinkedList b){
	int i, j;
	LinkedList listAux;
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

void LinkedList::intersec(LinkedList a, LinkedList b){
	Node * cursor1 = a.head;
	LinkedList listAux;
	for(int i = 0; i < a.listSize; i++){
		if(b.onList(cursor1->getValue())) listAux.addFront(cursor1->getValue());
		cursor1 = cursor1->getNext();
	}
	listAux.printList();
}

void LinkedList::diff(LinkedList a, LinkedList b){
	Node * cursor1 = a.head;
	LinkedList listAux;
	for(int i = 0; i < a.listSize; i++){
		if(!b.onList(cursor1->getValue())) listAux.addFront(cursor1->getValue());
		cursor1 = cursor1->getNext();
	}
	listAux.printList();
}

bool LinkedList::contained(LinkedList a, LinkedList b){
	if(a.listSize > b.listSize) return false;

	Node * cursor1 = a.head;

	for(int i = 0; i < a.listSize; i++){
		if(!b.onList(cursor1->getValue())) return false;
		cursor1 = cursor1->getNext();
	}
	return true;
}