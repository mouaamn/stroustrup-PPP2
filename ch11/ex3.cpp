#include "std_lib_facilities.h"

bool is_vowel(char c) {
	switch (tolower(c)) {
	case 'a': case 'e':
	case 'i': case 'o': case 'u':
		return true;
	default:
		return false;
	}
}

int main()

try {
	string file_name;
	cout << "Enter the name of a file: ";
	if (!(cin >> file_name))
		error("Bad input");

	ifstream ifs{ file_name };
	if (!ifs)
		error("Couldn't open the file for reading");

	string new_content;
	for (char c; ifs.get(c);)
		if (!is_vowel(c))
			new_content += c;
	ifs.close();

	ofstream ofs{ file_name };
	if (!ofs)
		error("Couldn't open/create the file for writing");
	ofs << new_content;
}
catch (exception& e) {
	cerr << "Exception: " << e.what() << '\n';
	return 1;
}
catch (...) {
	cerr << "Unknown exception" << '\n';
	return 1;
}