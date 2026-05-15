#include "std_lib_facilities.h"
#include "Rational.h"

int main()

try {

	Number::Rational frac{ 1, 2 };
	cout << static_cast<double>(frac) << '\n';
}
catch (Number::Rational::Invalid) {
	cerr << "Invalid Rational" << '\n';
	return 1;
}
catch (exception& e) {
	cerr << "Exception: " << e.what() << '\n';
	return 1;
}
catch (...) {
	cerr << "Unknown exception" << '\n';
	return 1;
}