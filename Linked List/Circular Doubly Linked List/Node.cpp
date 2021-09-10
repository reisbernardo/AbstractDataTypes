#include <cstdlib>
#include "Node.h"

Node::Node(int i) {
	value =  i;
	next = NULL;
	prev = NULL;
}

int Node::getValue() {
	return value;
}

void Node::setValue(int i) {
	value = i;
}

Node * Node::getNext() {
	return next;
}

void Node::setNext(Node * p) {
	next = p;
}

Node * Node::getPrev() {
	return prev;
}

void Node::setPrev(Node * p) {
	prev = p;
}