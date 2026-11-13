#include <iostream>
#include <fstream>
#include <stdexcept>

using namespace std;

// METHOD 1: Using return codes
// Returns true if successful, false if the file could not be opened.
bool readFileWithReturnCode(const string& filename) {
	ifstream file(filename);
	if (!file.is_open()) {
		return false;
	}

	// ... read file ...
	return true;
}

// METHOD 2: Using exceptions
void readFileWithException(const string& filename) {
	ifstream file(filename);
	if (!file.is_open()) {
		throw runtime_error("File not found: " + filename);
	}

	// ... read file ...
}

int main() {
	cout << "--- Testing Return Code Strategy ---" << endl;
	if (!readFileWithReturnCode("data.txt")) {
		cout << "Return Code: Handled error gracefully. Program continues." << endl;
	}

	cout << "\n--- Testing Exception Strategy ---" << endl;
	try {
		readFileWithException("data.txt");
	} catch (const runtime_error& e) {
		cout << "Exception Caught: " << e.what() << endl;
		cout << "Exception Strategy: Forced us to handle the error!" << endl;
	}

	return 0;
}
