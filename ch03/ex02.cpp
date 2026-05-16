#include "std_lib_facilities.h"

int main()

try {
	double miles{};
	cout << "Enter the number of miles: ";
	cin >> miles;

	cout << '\n' << miles << " miles in killo-meters is " << miles * 1.609 << '\n';
}
catch (exception& e) {
	cerr << "Exception: " << e.what() << '\n';
	return 1;
}
catch (...) {
	cerr << "Unknown exception" << '\n';
	return 1;
}