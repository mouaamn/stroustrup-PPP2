#include "std_lib_facilities.h"

void print(const vector<int>& v, const string& label) {
	cout << label << '\n';
	for (int n : v)
		cout << n << '\n';
}

int main()

try {
	const vector<int> v{ 1, 2, 3 };

	print(v, "Elements: ");
}
catch (exception& e) {
	cerr << "Exception: " << e.what() << '\n';
	return 1;
}
catch (...) {
	cerr << "Unknown exception" << '\n';
	return 1;
}