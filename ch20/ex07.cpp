#include "std_lib_facilities.h"

int main()

try {
	vector<string> v{ "banana", "watermelon", "apple" };

	string str;
	for (auto a : v)
		if (a > str)
			str = a;

	cout << str << '\n';
}
catch (exception& e) {
	cerr << "Exception: " << e.what() << '\n';
	return 1;
}
catch (...) {
	cerr << "Unknown exception" << '\n';
	return 1;
}