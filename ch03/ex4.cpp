#include "std_lib_facilities.h"

int main()

try {
	int val1{}, val2{};
	cout << "Enter two integers: ";
	cin >> val1 >> val2;

	cout << '\n';

	if (val1 > val2)
		cout
		<< val1 << " is greater than " << val2 << '\n'
		<< val2 << " is less than " << val1 << '\n';
	else if (val2 > val1)
		cout
		<< val2 << " is greater than " << val1 << '\n'
		<< val1 << " is less than " << val2 << '\n';
	else
		cout
		<< val1 << " and " << val2 << " are equal" << '\n';

	cout
		<< "The sum is " << val1 + val2 << '\n'
		<< "The difference is " << abs(val1 - val2) << '\n'
		<< "The product is " << val1 * val2 << '\n'
		<< "The ratio is " << val1 / val2 << '\n';	// division by zero is handled by exceptions
}
catch (exception& e) {
	cerr << "Exception: " << e.what() << '\n';
	return 1;
}
catch (...) {
	cerr << "Unknown exception" << '\n';
	return 1;
}