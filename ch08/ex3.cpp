#include "std_lib_facilities.h"

void print(const vector<int>& v, const string& label) {
	cout << label << '\n';
	for (int n : v)
		cout << n << '\n';
}

void fibonacci(int x, int y, vector<int>& v, int n) 
// fills v starting from x and y until n elements;
// pre-condition: x, y, and n are natural.
{
	if (y <= 0 || x <= 0 || n <= 0)
		error("x/y/n is not natural");

	for (; n > 0; --n) {
		const int sum{ x + y };
		v.push_back(sum);
		x = y;
		y = sum;
	}
}

int main()

try {
	vector<int> v;

	fibonacci(1, 2, v, 1);
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