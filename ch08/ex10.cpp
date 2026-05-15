#include "std_lib_facilities.h"

double maxv(const vector<double>& v) 
// returns the largest element;
// pre-condition: v not empty.
{
	if (v.size() == 0)
		error("Empty vector");
	double largest{ v[0] };

	for (int i{ 1 }; i < v.size(); ++i)
		if (v[i] > largest)
			largest = v[i];
	return largest;
}

int main()

try {
	vector<double> v{ 1, 3, 2, 5 };
	cout << maxv(v);
}
catch (exception& e) {
	cerr << "Exception: " << e.what() << '\n';
	return 1;
}
catch (...) {
	cerr << "Unknown exception" << '\n';
	return 1;
}