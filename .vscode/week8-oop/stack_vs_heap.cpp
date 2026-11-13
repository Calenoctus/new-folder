// ============================================================
// ACTIVITY 2: STACK VS HEAP OBJECTS
// Learning Outcome: Analyse stack vs heap allocation
// ============================================================

#include <iostream>
#include <string>
using namespace std;

class Car {
public:
	string model;

	// Constructor
	Car(string m) {
		model = m;
		cout << "Car created: " << model << endl;
	}

	// Destructor: Runs automatically when an object is destroyed
	~Car() {
		cout << "Car destroyed: " << model << endl;
	}
};

int main() {
	cout << "--- Creating Stack Object ---" << endl;
	// STACK ALLOCATION: Memory is managed automatically.
	// Note: No 'new' keyword.
	Car stackCar("Toyota");

	cout << "\n--- Creating Heap Object ---" << endl;
	// HEAP ALLOCATION: Memory is managed manually using 'new'.
	// A pointer (*) holds the memory address.
	Car* heapCar = new Car("Honda");

	// Access the heap object's members with the arrow operator (->).
	cout << "Heap car model: " << heapCar->model << endl;

	cout << "\n--- End of main function ---" << endl;

	// Manually delete the heap object to avoid a memory leak.
	// This triggers the destructor for the Honda.
	delete heapCar;

	// The stack object (Toyota) is destroyed automatically when it
	// goes out of scope, just before main returns.
	return 0;
}
