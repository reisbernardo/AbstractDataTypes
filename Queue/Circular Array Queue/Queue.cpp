#include <iostream>
#include <stdlib.h>
#include "Queue.h"

Queue::Queue(int max) {
	queue = new int(max); 
	sizeMax = max;
	queueSize = 0;
	f = -1;
	b = -1;
}

Queue::~Queue() { delete queue; }

int Queue::enqueue(int n) {
	if (full()) {
		return -1;
	}
    
	b = (b + 1) % sizeMax;
	if (f == -1) {
		f = 0;
	}
	queue[b] = n;
	queueSize++;
	return queueSize;
}

int Queue::dequeue() {
	if(empty()){
		f = -1;
		b = -1;
		return -1;
	}
	int n = queue[f];
	f = (f + 1) % sizeMax;
	queueSize--;
	return n;
}

bool Queue::empty() { return queueSize == 0; }

bool Queue::full() { return queueSize == sizeMax; }

int Queue::front(){
	if(empty()) return -1;
	return queue[f]; 
}

int Queue::back(){
	if(empty()) return -1;
	return queue[b];
}

void Queue::printQueue() {
	std::cout << "[ ";

	if (!empty()) {
        int i = f;
        do {
            std::cout << queue[i] << " ";
            i = ++i % size();
		}
        while (i != b);
		std::cout << queue[b] << " ";
    }
	std::cout << "]";
}

int Queue::size(){ return queueSize; }

int Queue::onQueue(int n) {
	int i;
	if(empty()) return -1;
	if(b >= f){
		for(i = f; i < b + 1; i++){
			if(queue[i] == n) return 0;
		}
	} else{
		for(i = f; i < sizeMax; i++){
			if(queue[i] == n) return 0;
		}
		for(i = 0; i < b + 1; i++){
			if(queue[i] == n)  return 0;
		}
	}
	return -1;
}

int compare (const void * a, const void * b){
  return ( *(int*)a - *(int*)b );
}

void Queue::sortQueue(){
	qsort(queue, size(), sizeof(int), compare);
}

