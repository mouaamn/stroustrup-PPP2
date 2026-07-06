/*
	How many bytes are there in an int? In a double? In a bool?
	> On most machines, it's 4 bytes in an int, 8 in a double, and 1 in a bool.
*/

#include "std_lib_facilities.h"

int main()

try {
	cout
		<< "int -> " << sizeof(int) << '\n'
		<< "double -> " << sizeof(double) << '\n'
		<< "bool -> " << sizeof(bool) << '\n';
}
catch (exception& e) {
	cerr << "Exception: " << e.what() << '\n';
	return 1;
}
catch (...) {
	cerr << "Unknown exception" << '\n';
	return 1;
}