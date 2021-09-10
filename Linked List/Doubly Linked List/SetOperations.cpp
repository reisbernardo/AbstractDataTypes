#include <iostream>
#include "DoublyLinkedList.h"

using namespace std;

int main() {
	DoublyLinkedList A, B;
	int opc, opca, na, nb;
	char opcb;

	cout << "\n----------------------------------------------";
    cout << "\n TESTING SET OPERATIONS ON DOUBLY LINKED LIST ";
    cout << "\n----------------------------------------------\n";

    while (true){
		cout << "\nType value from list A (type -1 to stop): ";
		cin >> na;
		if(na == -1) break;
		A.addFront(na);
	}
	cout << "\nList A values: ";
	A.printList();
	cout << endl;
	while (true){
		cout << "\nType value from list B (type -1 to stop): ";
		cin >> nb;
		if(nb == -1) break;
		B.addFront(nb);
	}
	cout << "\nList B values: ";
	B.printList();

	while (true) {
		cout << "\n\n0 - End program;";
		cout << "\n1 - Union (C = A U B);";
		cout << "\n2 - Intersection (C = A n B);";
		cout << "\n3 - Difference (C = A - B);";
		cout << "\n4 - Inclusion (A c B);";
		cout << "\n5 - Print lists (A or B).";
		cout << "\n\nSelect option: ";
		cin >> opc;

		if (opc == 0) {
			break;
		} else if (opc == 1) {
			cout << "\nLists A and B union is: ";
			A.uni(A, B);
		} else if (opc == 2) {
			cout << "\nLists A and B intersection is: ";
			A.intersec(A, B);
		} else if(opc == 3) {
			cout << "\nSelect the difference operation you want:\n";
			cout << "1 - A - B\n";
			cout << "2 - B - A\n";
			cout << "Select option: ";
			cin >> opca;
			if(opca == 1) {
				cout << "\nLists A and B difference is: ";
				A.diff(A, B);
			}
			else if (opca == 2) {
				cout << "\nLists B and A difference is: ";
				A.diff(B, A);
			}
			else cout << "Invalid option.";
		} else if (opc == 4) {
			cout << "\nSelect the inclusion operation you want:\n";
			cout << "1 - A c B\n";
			cout << "2 - B c A\n";
			cout << "Select option: ";
			cin >> opca;
			if(opca == 1) {
				if(A.contained(A, B)) cout << "\nList A is included in list B";
				else cout << "\nList A is not included in list B";
			}
			else if(opca == 2) {
				if(A.contained(B, A)) cout << "\nList B is included in list A";
				else cout << "\nList B is not included in list A";
			}
			else cout << "Invalid option.";
        } else if (opc == 5) {
			cout << "\nWhich list do you want to print:\n";
			cout << "1 - A\n";
			cout << "2 - B\n";
			cout << "Select option: ";
			cin >> opcb;
			if(opcb == 'A' || opcb == '1') {
				cout << "\nPrinting values from list A: ";
				A.printList();
			}
			else if (opcb == 'B' || opcb == '2') {
				cout << "\nPrinting values from list B:";
				B.printList();
			}
			else cout << "Invalid option.";
        }
	}
	return 0;
}
