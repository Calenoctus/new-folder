#include <iostream>
using namespace std;

// Base class
class Animal {
public:
	// Not virtual: calls are resolved using the pointer's static type.
	virtual void speak() {
		cout << "Animal makes a generic sound." << endl;
	}
};

// Derived class
class Dog : public Animal {
public:
	void speak() {
		cout << "Dog barks: Woof! Woof!" << endl;
	}
};

int main() {
	cout << "--- Without Virtual Keyword ---" << endl;

	Animal* myPet = new Dog();
	myPet->speak(); // Prints the Animal message because speak() is not virtual.

	// Deleting a derived object through a base pointer requires a virtual
	// destructor. This example avoids delete to keep the focus on binding.
	return 0;
}
