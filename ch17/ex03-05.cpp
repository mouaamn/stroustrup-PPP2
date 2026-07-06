/*
	Note: I had to comment out the include directive to std_lib_facilities.h,
	because it caused naming collision.
*/

//#include "std_lib_facilities.h"
#include <iostream>

char to_lower(char c) {
	switch (c) {
	case 'A': return 'a';
	case 'B': return 'b';
	case 'C': return 'c';
	case 'D': return 'd';
	case 'E': return 'e';
	case 'F': return 'f';
	case 'G': return 'g';
	case 'H': return 'h';
	case 'I': return 'i';
	case 'J': return 'j';
	case 'K': return 'k';
	case 'L': return 'l';
	case 'M': return 'm';
	case 'N': return 'n';
	case 'O': return 'o';
	case 'P': return 'p';
	case 'Q': return 'q';
	case 'R': return 'r';
	case 'S': return 's';
	case 'T': return 't';
	case 'U': return 'u';
	case 'V': return 'v';
	case 'W': return 'w';
	case 'X': return 'x';
	case 'Y': return 'y';
	case 'Z': return 'z';
	default:
		return c;
	}
}

void to_lower(char* s) {
	if (s == nullptr) return;
	for (; *s; ++s)
		*s = to_lower(*s);
}

void print_str(std::ostream& os, char* s) {
	if (s == nullptr) return;
	for (; *s; ++s)
		os << *s;
	os << '\n';
}

size_t str_size(const char* s) {
	if (s == nullptr) return 0;
	size_t sz{};
	for (; *s; ++s)
		++sz;
	return sz;
}

// Note: I had to change its name
char* strdup_(const char* s) {
	if (s == nullptr) return nullptr;
	size_t sz{ str_size(s) };
	char* a{ new char[sz + 1] };
	for (size_t i{}; i < sz; ++i)
		a[i] = s[i];
	a[sz] = '\0';
	return a;
}

char* findx(const char* s, const char* x) {
	if (s == nullptr) return nullptr;
	if (x == nullptr) return nullptr;

	size_t x_sz{ str_size(x) };
	size_t s_sz{ str_size(s) };
	if (s_sz < x_sz) return nullptr;

	for (size_t i{}; i + x_sz <= s_sz; ++i) {
		bool is_equal{ true };
		for (size_t j{}; j < x_sz; ++j)
			if (s[i + j] != x[j]) {
				is_equal = false;
				break;
			}
		if (is_equal)
			return const_cast<char*>(s + i);
	}

	return nullptr;
}

int main()

try {
	char* str{ new char[] { "Hello, World!" } };
	to_lower(str);
	print_str(std::cout, str);

	char* another_str{ strdup_(str) };
	print_str(std::cout, another_str);

	char* poetry{ 
		new char[] {
			"Tower over me, O mountains, or rise higher still,"			"\n"
			"For I am in love with the steep and the rugged hill,"		"\n"
			"And the greater the challenge - I am greater still,"		"\n"
			"My ambition is the ambition of kings, my soul"				"\n"
		}
	};
	char* p{ findx(poetry, "And") };
	print_str(std::cout, p);
}
catch (std::exception& e) {
	std::cerr << "Exception: " << e.what() << '\n';
	return 1;
}
catch (...) {
	std::cerr << "Unknown exception" << '\n';
	return 1;
}