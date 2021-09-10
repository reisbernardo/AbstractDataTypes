#include <iostream>
#include "Queue.h"

using namespace std;

int main() {    
    cout << "\n---------------------------------------------------";
    cout << "\n TESTING CIRCULAR ARRAY BASED QUEUE DATA STRUCTURE ";
    cout << "\n---------------------------------------------------";
    
    int max;
    cout << "\n\nType queue max size: ";
    cin >> max;

    Queue Queue(max);

    while(true) {
        int opc, value;
        cout << "\n\n0  - End program;";
        cout << "\n1  - Enqueue value on queue;";
        cout << "\n2  - Dequeue value from queue;";
        cout << "\n3  - Check if queue is empty;";
        cout << "\n4  - Check if queue is full;";
        cout << "\n5  - Return the value from queue's front;";
        cout << "\n6  - Return the value from queue's back.";
        cout << "\n7  - Print queue;";
        cout << "\n8  - Queue current size;";
        cout << "\n8  - Verify if value is on queue (return value position);" ;
        cout << "\n10 - Sort queue.";
        cout << "\n\nSelect option: ";
        cin >> opc;

        if (opc == 0) {
            break;
            
        } else if (opc == 1) {
            cout << "\nType new value (int): ";
            cin >> value;
            int n = Queue.enqueue(value);
            if (n == -1) cout << "\nQueue is already full.";
            else cout << "\nValue added to queue in position: " << n << ".";

        } else if (opc == 2) {
            value = Queue.dequeue();
            if(value == -1) cout << "\nQueue is empty.";
            else cout << "\nValue " << value << " extracted from queue.";

        } else if (opc == 3) {
            if(Queue.empty()) cout << "\nQueue is empty.";
            else cout << "\nQueue is not empty";

        } else if (opc == 4) {
            if(Queue.full()) cout << "\nQueue is full.";
            else cout << "\nQueue is not full";

        } else if (opc == 5) {
            value = Queue.front();
            if(value == -1) cout << "\nQueue is empty.";
            else cout << "\nQueue's first value is: " << value << ".";

        } else if (opc == 6) {
            value = Queue.back();
            if(value == -1) cout << "\nQueue is empty.";
            else cout << "\nQueue's last value is: " << value << ".";

        } else if (opc == 7) {
            cout << "\nPrinting values from queue: ";
            Queue.printQueue();

        } else if (opc == 8) {
            cout << "\nQueue size is " << Queue.size() << ".";

        } else if (opc == 9) {
            cout << "\nType the value to be verified (int): ";
            cin >> value;
            if(Queue.onQueue(value) == -1) cout << "\nValue not on queue or queue is already empty.";
            else cout << "\nThe value apears in the queue.";
        } else if(opc == 10) {
            Queue.sortQueue();
            cout << "\nOrdered queue: ";
            Queue.printQueue();
        }
    }
    return 0;
}
