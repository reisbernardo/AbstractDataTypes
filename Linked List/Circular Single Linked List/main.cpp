#include <iostream>
#include "CircularLinkedList.h"

using namespace std;

int main() {
	CircularLinkedList List;
	int opc, opca, opcb, value;

	cout << "\n---------------------------------------";
    cout << "\n TESTING SIMPLE CIRCULARLY LINKED LIST ";
    cout << "\n---------------------------------------";
	
	while (true) {
		cout << "\n\n0  - End program;";
		cout << "\n1  - Insert value at front;";
		cout << "\n2  - Insert value at back;";
		cout << "\n3  - Insert value at position N;";
		cout << "\n4  - Remove first value;";
		cout << "\n5  - Remove last value;";
		cout << "\n6  - Remove value at position N;";
		cout << "\n7  - Check if list is empty;";
		cout << "\n8  - Current list size;";
		cout << "\n9  - Print List";
		cout << "\n10 - Print first list's first value;";
		cout << "\n11 - Print first list's last value;";
		cout << "\n12 - Remove duplicate values;";
		cout << "\n13 - Sort list (Merge Sort).";
		cout << "\n\nSelect option: ";
		cin >> opc;
		
		if (opc == 0) {
			break;

		} else if (opc == 1) {
			cout << "\nType the new value (int): ";
			cin >> opca;
			List.addFront(opca);
			cout << "\nValue inserted at the front.";

		} else if (opc == 2) {
			cout << "\nType the new value (int): ";
			cin >> opca;
			List.addBack(opca);
			cout << "\nValue inserted at the end.";

		} else if(opc == 3) {
			cout << "\nType the new value (int): ";
			cin >> opca;
			cout << "\nPosition to insert: ";
			cin >> opcb;
			value = List.addN(opca, opcb);
			if(value != -1) cout << "\nValue inserted at position: " << value << ".";
			else cout << "\nInvalid position.";

		} else if (opc == 4) {
			value = List.removeFront();
			if(value != -1) cout << "\nValue removed from list start: " << value << ".";
			else cout << "\nList is empty.";

		} else if (opc == 5) {
			value = List.removeBack();
			if(value != -1) cout << "\nValue removed from list end: " << value << ".";
			else cout << "\nList is empty.";

		} else if (opc == 6) {
			cout << "\nPosition to remove: ";
			cin >> opca;
			value = List.removeN(opca);
			if(value != -1) cout << "\nValue " << value << " removed.";
			else cout << "\nList is empty.";

		} else if (opc == 7) {
            if (List.empty()) cout << "\nList is empty.";
            else cout << "\nList is not empty";

        } else if (opc == 8) {
			cout << "\nList size: " << List.size() << ".";

		} else if (opc == 9) {
			cout << "\nPrinting values from list: ";
			List.printList();

		} else if (opc == 10){
		    value = List.front();
		    if (value != -1){
		        cout << "\nQueue's first value is: " << value << ".";
		    }else
		        cout << "\nList is empty.";

		} else if (opc == 11){
		    value = List.back();
		    if (value != -1){
		        cout << "\nQueue's last value is: " << value << ".";
		    }else
		        cout << "\nList is empty.";

		}  else if (opc == 12) {
			List.removeDuplicate();
			cout << "\nDuplicate values removed.";

		} else if (opc == 13) {
			List.mergeSort();
			cout << "\nOrdered list: ";
			List.printList();
		}
	}
	return 0;
}