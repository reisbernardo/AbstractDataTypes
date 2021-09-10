#include <cstdlib>
#include <iostream>
#include "Node.h"

Node::Node(int i) {
	value =  i;
	next = NULL;
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
