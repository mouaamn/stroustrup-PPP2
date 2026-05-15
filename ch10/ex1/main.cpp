#include "std_lib_facilities.h"

int main()

try {
	ifstream ifs{ "file" };
	if (!ifs)
		error("Couldn't open the file for reading");

	int sum{};
	for (int i; ifs >> i;)
		sum += i;

	cout << "The sum is " << sum << '\n';
}
catch (exception& e) {
	cerr << "Exception: " << e.what() << '\n';
	return 1;
}
catch (...) {
	cerr << "Unknown exception" << '\n';
	return 1;
}