#include "std_lib_facilities.h"

int main()

try {
	int num{};
	cout << "Enter an integer: ";
	cin >> num;

	cout << '\n';

	if (num % 2 == 0)
		cout << "The number " << num << " is an even number" << '\n';
	else
		cout << "The number " << num << " is an odd number" << '\n';
}
catch (exception& e) {
	cerr << "Exception: " << e.what() << '\n';
	return 1;
}
catch (...) {
	cerr << "Unknown exception" << '\n';
	return 1;
}