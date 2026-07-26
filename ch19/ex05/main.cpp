#include "std_lib_facilities.h"
#include "Int.h"

int main()

try {
	DT::Int i{ 1 }, i2;
	cout << '>';
	cin >> i2;
	if (!cin)
		error("Bad input for Int");
	cout << i + i2 << '\n';
}
catch (exception& e) {
	cerr << "Exception: " << e.what() << '\n';
	return 1;
}
catch (...) {
	cerr << "Unknown exception" << '\n';
	return 1;
}