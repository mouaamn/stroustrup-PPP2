#include "std_lib_facilities.h"

int main()

try {
	char* str{ nullptr };
	size_t sz{};

	for (char c{}; cin >> c && c != '!'; ) {
		++sz;
		char* copy_str{ new char[sz + 1] {} }; // including nullptr
		for (int i{}; i < sz - 1; ++i)
			copy_str[i] = str[i];
		copy_str[sz - 1] = c;
		delete[] str;
		str = copy_str;
	}

	if (str == nullptr) return 0;
	for (; *str; ++str)
		cout << *str;
	cout << '\n';

	
	string string;
	for (char c{}; cin >> c;)
		string.push_back(c);
	cout << string << '\n';
}
catch (exception& e) {
	cerr << "Exception: " << e.what() << '\n';
	return 1;
}
catch (...) {
	cerr << "Unknown exception" << '\n';
	return 1;
}