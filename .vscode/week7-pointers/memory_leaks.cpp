#include <iostream>

using namespace std;

// Allocate, use, then free the dynamically allocated integer.
void fixLeak() {
// Allocate memory
int* ptr = new int(42);

cout << "Inside fixed function. Value: " << *ptr << endl;
cout << "Memory allocated at address: " << ptr << endl;

// THE FIX: The 'delete' operator frees the memory back to the operating system.
delete ptr;

// GOOD PRACTICE: Set the pointer to nullptr after deleting it.
// This prevents "dangling pointers" (pointers that point to freed memory).
ptr = nullptr;


cout << "Memory has been successfully freed." << endl;
}

int main() {
cout << "--- Testing the Fix ---" << endl;
fixLeak();
return 0;
}
