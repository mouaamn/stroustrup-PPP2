#include "std_lib_facilities.h"

void print_until_s(const vector<string>& v, const string& quit) {
	for (const string& s : v) {
		if (s == quit)
			return;
		cout << s << '\n';
	}
}

void print_until_ss(const vector<string>& v, const string& quit) {
	int counter{};
	for (const string& s : v) {
		if (counter >= 2)
			return;
		if (s == quit)
			++counter;
		else
			cout << s << '\n';
	}
}

int main()

try {
	const vector<string> v{ "Mouaamn", "Aref", "Hadiq", "Quit", "Snuffy", "Quit", "Nadia"};
	print_until_ss(v, "Quit");
}
catch (exception& e) {
	cerr << "Exception: " << e.what() << '\n';
	return 1;
}
catch (...) {
	cerr << "Unknown exception" << '\n';
	return 1;
}