#include "std_lib_facilities.h"

template<typename T>
void f(vector<T>& v1, const vector<T>& v2) {
	for (size_t i{}; i < v1.size() && i < v2.size(); ++i)
		v1[i] += v2[i];
}

template<typename T, typename U>
double ff(const vector<T>& vt, const vector<U>& vu) {
	double sum{};
	for (size_t i{}; i < vt.size() && i < vu.size(); ++i)
		sum += vt[i] * vu[i];
	return sum;
}

int main()

try {
	vector<int> v1{ 1, 2 };
	vector<int> v2{ 3, 6 };
	f(v1, v2);
	for (int e : v1)
		cout << e << '\n';

	cout << ff(v1, v2) << '\n';
}
catch (exception& e) {
	cerr << "Exception: " << e.what() << '\n';
	return 1;
}
catch (...) {
	cerr << "Unknown exception" << '\n';
	return 1;
}