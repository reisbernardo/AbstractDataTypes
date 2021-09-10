#include <iostream>
#include "Stack.h"

Stack::~Stack() { delete stack; }

Stack::Stack(int max) {
    stack = new int(max);
    t = -1; 
    sizeMax = max;
}

int Stack::push(int n) {
    if(full()) return -1;
    stack[++t] = n;
    return t + 1;
}

int Stack::pop() {
    if (empty()) return -1;
    return stack[t--] ;
}

bool Stack::empty() { return t == -1; }

bool Stack::full() { return t == sizeMax - 1; }

int Stack::top() {
    if(empty()) return -1; 
    return stack[t];
}

void Stack::printStack() {
    std::cout << "[ ";
	if (!empty()) {
		int i = 0;
		while(i < t + 1) std::cout << stack[i++] << " ";
	}
	std::cout << "]";
}

int Stack::size() { return t + 1; }

int Stack::onStack(int n) {
	int i = 0;
	if(empty()) return -1;
	while(i < t + 1){
        if(stack[i++] == n) return 0;
    }
    return -1;
}

int compare (const void * a, const void * b){
  return ( *(int*)a - *(int*)b );
}

void Stack::sortStack(){
	qsort(stack, size(), sizeof(int), compare);
}
