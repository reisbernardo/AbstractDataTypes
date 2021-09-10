#include <iostream>
#include "LinkedStack.h"

using namespace std;

int main() {    
    LinkedStack Stack;

    cout << "\n-------------------------------------------------";
    cout << "\n TESTING LINKED LIST BASED STACK DATA STRUCTURE ";
    cout << "\n-------------------------------------------------";

    while(true) {
        int opc, value;
        cout << "\n\n0 - End program;";
        cout << "\n1 - Push value on stack;";
        cout << "\n2 - Pop value from stack;";
        cout << "\n3 - Check if stack is empty;";
        cout << "\n4 - Return the value from stack's top;";
        cout << "\n5 - Print stack;";
        cout << "\n6 - Stack current size;";
        cout << "\n7 - Verify if value is on stack (return value position);" ;
        cout << "\n8 - Sort linked stack (Merge Sort).";
        cout << "\n\nSelect option: ";
        cin >> opc;

        if (opc == 0) {
            break;
        } else if (opc == 1) {
            cout << "\nType new value (int): ";
            cin >> value;
            Stack.push(value);
            cout << "\nValue inserted at the top.";

        } else if (opc == 2) {
            value = Stack.pop();
            if(value == -1) cout << "\nStack is empty.";
            else cout << "\nValue " << value << " extracted from stack.";

        } else if (opc == 3) {
            if(Stack.empty()) cout << "\nStack is empty.";
            else cout << "\nStack is not empty";

        } else if (opc == 4) {
            value = Stack.top();
            if(value == -1) cout << "\nStack is empty.";
            else cout << "\nStack's top value is: " << value << ".";

        } else if (opc == 5) {
            cout << "\nPrinting values from stack: ";
            Stack.printStack();

        } else if (opc == 6) {
            cout << "\nStack size is " << Stack.size() << ".";
            
        } else if (opc == 7) {
            cout << "\nType the value to be verified (int): ";
            cin >> value;
            if(Stack.onStack(value) == -1) cout << "\nValue not on stack or stack is already empty.";
            else cout << "\nThe value apears in the stack.";
        } else if (opc == 8) {
			Stack.mergeSort();
			cout << "\nOrdered stack: ";
			Stack.printStack();
		}
    }
    return 0;
}
