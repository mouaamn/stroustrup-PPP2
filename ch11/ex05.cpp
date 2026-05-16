#include "std_lib_facilities.h"

string classify(char c) {
	string s;
	if (isspace(c)) s += "whitespace ";
	if (isalpha(c)) s += "alphabet ";
	if (isdigit(c)) s += "decimal-digit ";
	if (isxdigit(c)) s += "hexidecimal-digit ";
	if (isupper(c)) s += "uppercase ";
	if (islower(c)) s += "lowercase ";
	if (isalnum(c)) s += "alphabet or decimal-digit ";
	if (iscntrl(c)) s += "control-character ";
	if (ispunct(c)) s += "punctuation ";
	if (isprint(c)) s += "printable ";
	if (isgraph(c)) s += "alphabet or decimal-digit or punctuation ";
	return s;
}

int main()

try {
	string word{ "Aref" };
	for (char c : word)
		cout << c << ":\n   " << classify(c) << '\n';
}
catch (exception& e) {
	cerr << "Exception: " << e.what() << '\n';
	return 1;
}
catch (...) {
	cerr << "Unknown exception" << '\n';
	return 1;
}