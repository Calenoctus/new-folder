#include <iostream>

using namespace std;

int main() {
	// A normal integer variable
	int originalValue = 100;

	// A reference is an alias for originalValue.
	int& refValue = originalValue;

	// A pointer stores the address of originalValue.
	int* ptrValue = &originalValue;

	cout << "--- Initial State ---" << endl;
	cout << "originalValue: " << originalValue << endl;
	cout << "refValue: " << refValue << endl;
	cout << "ptrValue points to: " << *ptrValue << endl;

	// Changing the reference changes the original variable.
	refValue = 200;

	cout << "\n--- After setting refValue = 200 ---" << endl;
	cout << "originalValue: " << originalValue << endl;
	cout << "ptrValue points to: " << *ptrValue << endl;

	// Changing the value via the pointer changes the original variable.
	*ptrValue = 300;

	cout << "\n--- After setting *ptrValue = 300 ---" << endl;
	cout << "originalValue: " << originalValue << endl;
	cout << "refValue: " << refValue << endl;

	// A pointer can be changed to point to a different variable.
	int anotherValue = 500;
	ptrValue = &anotherValue;

	cout << "\n--- After pointing ptrValue to anotherValue ---" << endl;
	cout << "originalValue: " << originalValue << endl;
	cout << "ptrValue points to: " << *ptrValue << endl;

	// Assigning anotherValue to refValue would copy its value into originalValue;
	// a reference cannot be changed to refer to another variable.
	return 0;
}
