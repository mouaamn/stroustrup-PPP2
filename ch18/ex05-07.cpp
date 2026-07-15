/*
	Compare the effort involved in this exercise with 
	the effort involved for exercises 5 and 6.
	> Yea so using standard types like std::string requires 
	  way less effort than directly using built-in types like C-style strings.
*/

#include "std_lib_facilities.h"

string cat_dot(const string& s1, const string& s2, const string& sep = ".") {
	return s1 + sep + s2;
}

char* cat_dot(const char* s1, const char* s2, const char* sep = ".") {
	size_t sz{};
	for (size_t i{}; *(s1 + i); ++i) ++sz;
	for (size_t i{}; *(s2 + i); ++i) ++sz;
	for (size_t i{}; *(sep + i); ++i) ++sz;

	char* str{ new char[sz + 1] {} };
	for (; *s1; ++s1, ++str) 
		*str = *s1;
	for (; *sep; ++sep, ++str)
		*str = *sep;
	for (; *s2; ++s2, ++str) 
		*str = *s2;

	*str = '\0';

	return str - sz;
}

int main()

try {
	char* str{ cat_dot("MN", "MO", ".") };
	for (const char* p{ str }; *p; ++p)
		cout << *p << '\n';
	delete[] str;
}
catch (exception& e) {
	cerr << "Exception: " << e.what() << '\n';
	return 1;
}
catch (...) {
	cerr << "Unknown exception" << '\n';
	return 1;
}