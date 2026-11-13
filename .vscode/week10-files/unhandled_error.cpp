#include <iostream>
#include <fstream>
using namespace std;

int main() {
	// This file does not exist, and the stream state is not checked.
	ifstream myFile("missing_file.txt");

	string data;

	cout << "Attempting to read from missing file..." << endl;
	myFile >> data;

	// The failed extraction leaves data empty; the program does not crash.
	cout << "Data read: " << data << endl;
	cout << "Program continued running without crashing." << endl;

	return 0;
}
