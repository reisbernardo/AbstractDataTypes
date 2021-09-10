#include <iostream>
#include "CircularLinkedQueue.h"

using namespace std;

int main() {    
    CircularLinkedQueue Queue;

    cout << "\n---------------------------------------------------";
    cout << "\n TESTING CIRCULAR LINKED LIST QUEUE DATA STRUCTURE ";
    cout << "\n---------------------------------------------------";

    while(true) {
        int opc, value;
        cout << "\n\n0 - End program;";
        cout << "\n1 - Enqueue value on queue;";
        cout << "\n2 - Dequeue value from queue;";
        cout << "\n3 - Check if queue is empty;";
        cout << "\n4 - Return the value from queue's front;";
        cout << "\n5 - Return the value from queue's back.";
        cout << "\n6 - Print queue;";
        cout << "\n7 - Queue current size;";
        cout << "\n8 - Verify if value is on queue (return value position);" ;
        cout << "\n9 - Sort linked queue (Merge Sort).";
        cout << "\n\nSelect option: ";
        cin >> opc;

        if (opc == 0) {
            break;
        } else if (opc == 1) {
            cout << "\nType new value (int): ";
            cin >> value;
            Queue.enqueue(value);
            cout << "\nValue inserted at queue's back.";

        } else if (opc == 2) {
            value = Queue.dequeue();
            if(value == -1) cout << "\nQueue is empty.";
            else cout << "\nValue " << value << " extracted from queue's front.";

        } else if (opc == 3) {
            if(Queue.empty()) cout << "\nQueue is empty.";
            else cout << "\nQueue is not empty";

        } else if (opc == 4) {
            value = Queue.front();
            if(value == -1) cout << "\nQueue is empty.";
            else cout << "\nQueue's first value is: " << value << ".";

        } else if (opc == 5) {
            value = Queue.back();
            if(value == -1) cout << "\nQueue is empty.";
            else cout << "\nQueue's last value is: " << value << ".";

        } else if (opc == 6) {
            cout << "\nPrinting values from queue: ";
            Queue.printQueue();

        } else if (opc == 7) {
            cout << "\nQueue size is " << Queue.size() << ".";

        } else if (opc == 8) {
            cout << "\nType the value to be verified (int): ";
            cin >> value;
            if(Queue.onQueue(value) == -1) cout << "\nValue not on queue or queue is already empty.";
            else cout << "\nThe value apears in the queue.";
        } else if (opc == 9) {
			Queue.mergeSort();
			cout << "\nOrdered queue: ";
			Queue.printQueue();
		}
    }
    return 0;
}
