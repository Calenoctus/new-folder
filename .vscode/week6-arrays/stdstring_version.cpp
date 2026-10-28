#include <iostream>
#include <string>

int main() {
	// Read a full name, including spaces.
	std::string name;
	std::cout << "Enter your name: ";
	std::getline(std::cin, name);

	std::cout << "Name: " << name << '\n';
	std::cout << "Length: " << name.length() << '\n';

	// Avoid indexing an empty string.
	if (!name.empty()) {
		std::cout << "First character: " << name[0] << '\n';
	} else {
		std::cout << "First character: (none)\n";
	}

	std::string copy = name;
	std::cout << "Copy: " << copy << '\n';

	std::string greeting = "Hello, " + name + "!";
	std::cout << greeting << '\n';

	return 0;
}
