#include <iostream>
using namespace std;

// Bad design: public data can be changed without validation.
class BadBankAccount {
public:
	double balance;

	BadBankAccount() : balance(0.0) {}
};

// Good design: private data is accessed through controlled methods.
class GoodBankAccount {
private:
	double balance;

public:
	GoodBankAccount() : balance(0.0) {}

	void deposit(double amount) {
		if (amount > 0) {
			balance += amount;
		}
	}

	double getBalance() const {
		return balance;
	}
};

int main() {
	cout << "--- Testing BAD Design ---" << endl;
	BadBankAccount badAccount;
	badAccount.balance = -5000; // No validation prevents this.
	cout << "Bad Account Balance: " << badAccount.balance << endl;

	cout << "\n--- Testing GOOD Design ---" << endl;
	GoodBankAccount goodAccount;
	// goodAccount.balance = -5000; // Error: balance is private.
	goodAccount.deposit(1000);
	cout << "Good Account Balance: " << goodAccount.getBalance() << endl;

	return 0;
}
