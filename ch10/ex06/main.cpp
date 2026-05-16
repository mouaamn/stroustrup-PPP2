#include "std_lib_facilities.h"
#include "Roman_int.h"

int main()

try {
	Number::Roman_int rn;
	cout << "Enter a roman-numeral: ";
	if (!(cin >> rn))
		error("Couldn't read into Roman_int");
	cout << "Roman " << rn << " equals " << rn.as_int() << '\n';
}
catch (exception& e) {
	cerr << "Exception: " << e.what() << '\n';
	return 1;
}
catch (...) {
	cerr << "Unknown exception" << '\n';
	return 1;
}