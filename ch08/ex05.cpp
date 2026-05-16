#include "std_lib_facilities.h"

vector<int> reverse_cvector(const vector<int>& v) {
	vector<int> new_v;
	for (int i{ static_cast<int>(v.size()) - 1 }; i >= 0; --i)
		new_v.push_back(v[i]);
	return new_v;
}

void swap(int& a, int& b) {
	int temp{ a };
	a = b;
	b = temp;
}

void reverse_vector(vector<int>& v) {
	for (int i{}; i < v.size() / 2; ++i)
		swap(v[i], v[v.size() - 1 - i]);
}

int main()

try {
	vector<int> v{ 1, 2, 3, 4 };

	//vector<int> new_v{ reverse_cvector(v) };
	//for (int n : new_v)
	//	cout << n << '\n';

	//cout << '\n';

	reverse_vector(v);
	for (int n : v)
		cout << n << '\n';
}
catch (exception& e) {
	cerr << "Exception: " << e.what() << '\n';
	return 1;
}
catch (...) {
	cerr << "Unknown exception" << '\n';
	return 1;
}