#include "std_lib_facilities.h"

bool is_palindrome(const string& s) {
	string s_copy;
	for (size_t i{}; i != s.size(); ++i)
		s_copy.push_back(s[s.size() - 1 - i]);
	return s_copy == s;
}

bool is_palindrome(const char* s, int n) {
	char* s_copy{ new char[n] };
	for (int i{}; i < n; ++i)
		s_copy[i] = s[n - i - 1];

	for (int i{}; i < n; ++i)
		if (s_copy[i] != s[i]) {
			return false;
			delete[] s_copy;
		}
	delete[] s_copy;
	return true;
}

bool is_palindrome(const char* first, const char* last) {
	int n{ 1 };
	for (const char* p{ first }; p != last; ++p, ++n);
	char* s_copy{ new char[n] };
	for (int i{}; i < n; ++i)
		*(s_copy + i) = *(last - i);

	for (int i{}; i < n; ++i)
		if (*(s_copy + i) != *(first + i)) {
			delete[] s_copy;
			return false;
		}
	delete[] s_copy;
	return true;
}

int main()

try {
	const char* str{ "anna" };
	cout 
		<< boolalpha 
		<< is_palindrome(str) << '\n'
		<< is_palindrome(str, 4) << '\n'
		<< is_palindrome(str, str + 3) << '\n';
}
catch (exception& e) {
	cerr << "Exception: " << e.what() << '\n';
	return 1;
}
catch (...) {
	cerr << "Unknown exception" << '\n';
	return 1;
}