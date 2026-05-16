#include "std_lib_facilities.h"

vector<string> reverse_cvector(const vector<string>& v) {
	vector<string> new_v;
	for (int i{ static_cast<int>(v.size()) - 1 }; i >= 0; --i)
		new_v.push_back(v[i]);
	return new_v;
}

void swap(string& a, string& b) {
	string temp{ a };
	a = b;
	b = temp;
}

void reverse_vector(vector<string>& v) {
	for (int i{}; i < v.size() / 2; ++i)
		swap(v[i], v[v.size() - 1 - i]);
}

int main()

try {
	vector<string> v{ "Aref", "Baref", "Caref" };

	//vector<string> new_v{ reverse_cvector(v) };
	//for (string s : new_v)
	//	cout << s << '\n';

	//cout << '\n';

	reverse_vector(v);
	for (string s : v)
		cout << s << '\n';
}
catch (exception& e) {
	cerr << "Exception: " << e.what() << '\n';
	return 1;
}
catch (...) {
	cerr << "Unknown exception" << '\n';
	return 1;
}