#include "std_lib_facilities.h"
#include "Number.h"

int main()

try {
	DT::Number<int> ni{ 2 };
	DT::Number<double> nd;
	cout << '>';
	cin >> nd;
	if (!cin)
		error("Bad input for Number");
	cout 
		<< nd << '%' << ni << '='
		<< nd % ni << '\n';
}
catch (exception& e) {
	cerr << "Exception: " << e.what() << '\n';
	return 1;
}
catch (...) {
	cerr << "Unknown exception" << '\n';
	return 1;
}