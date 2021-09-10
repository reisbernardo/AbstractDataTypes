#include <iostream>
#include "Stack.h"

using namespace std;

int main() {    
    cout << "\n--------------------------------------------------";
    cout << "\n TESTING SIMPLE ARRAY BASED STACK DATA STRUCTURE ";
    cout << "\n--------------------------------------------------";
    
    int max;
    cout << "\n\nType stack max size: ";
    cin >> max;

    Stack Stack(max);

    while(true) {
        int opc, value;
        cout << "\n\n0 - End program;";
        cout << "\n1 - Push value on stack;";
        cout << "\n2 - Pop value from stack;";
        cout << "\n3 - Check if stack is empty;";
        cout << "\n4 - Check if stack is full;";
        cout << "\n5 - Return the value from stack's top;";
        cout << "\n6 - Print stack;";
        cout << "\n7 - Stack current size;";
        cout << "\n8 - Verify if value is on stack (return value position);" ;
        cout << "\n9 - Sort stack.";
        cout << "\n\nSelect option: ";
        cin >> opc;

        if (opc == 0) {
            break;
            
        } else if (opc == 1) {
            cout << "\nType new value (int): ";
            cin >> value;
            int n = Stack.push(value);
            if (n == -1) cout << "\nStack is already full.";
            else cout << "\nValue added to stack in position: " << n << ".";

        } else if (opc == 2) {
            value = Stack.pop();
            if(value == -1) cout << "\nStack is empty.";
            else cout << "\nValue " << value << " extracted from stack.";

        } else if (opc == 3) {
            if(Stack.empty()) cout << "\nStack is empty.";
            else cout << "\nStack is not empty";

        } else if (opc == 4) {
            if(Stack.full()) cout << "\nStack is full.";
            else cout << "\nStack is not full";

        }else if (opc == 5) {
            value = Stack.top();
            if(value == -1) cout << "\nStack is empty.";
            else cout << "\nStack's top value is: " << value << ".";

        } else if (opc == 6) {
            cout << "\nPrinting values from stack: ";
            Stack.printStack();

        } else if (opc == 7) {
            cout << "\nStack size is " << Stack.size() << ".";

        } else if (opc == 8) {
            cout << "\nType the value to be verified (int): ";
            cin >> value;
            if(Stack.onStack(value) == -1) cout << "\nValue not on stack or stack is already empty.";
            else cout << "\nThe value apears in the stack.";

        } else if(opc == 9) {
            Stack.sortStack();
            cout << "\nOrdered stack: ";
            Stack.printStack();
        } 
    }
    return 0;
}
