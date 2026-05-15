#include "std_lib_facilities.h"

int main()

try {
	string number;
	cout << "Enter a spelled-out digit: ";
	cin >> number;

	cout << '\n';

	int digit{};

	if (number == "zero")
		digit = 0;
	else if (number == "one")
		digit = 1;
	else if (number == "two")
		digit = 2;
	else if (number == "three")
		digit = 3;
	else if (number == "four")
		digit = 4;
	else {
		cout << "Not a number that I know" << '\n';
		return 1;
	}

	cout << digit << '\n';
}
catch (exception& e) {
	cerr << "Exception: " << e.what() << '\n';
	return 1;
}
catch (...) {
	cerr << "Unknown exception" << '\n';
	return 1;
}