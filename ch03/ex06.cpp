#include "std_lib_facilities.h"

int main()

try {
	int val1{}, val2{}, val3{};
	cout << "Enter 3 integers: ";
	cin >> val1 >> val2 >> val3;

	if (val1 > val2) {

		int temp{ val1 };
		val1 = val2;
		val2 = temp;

		if (val2 > val3) {

			int temp{ val2 };
			val2 = val3;
			val3 = temp;
		}
	}
	else {

		if (val1 > val3) {

			int temp{ val1 };
			val1 = val3;
			val3 = temp;
		}
	}
	
	cout << '\n' << val1 << ", " << val2 << ", " << val3 << '\n';
}
catch (exception& e) {
	cerr << "Exception: " << e.what() << '\n';
	return 1;
}
catch (...) {
	cerr << "Unknown exception" << '\n';
	return 1;
}