#include "std_lib_facilities.h"

int main()

try {
	string file_name;
	cout << "Enter the name of a file: ";
	if (!(cin >> file_name))
		error("Bad input");
	ifstream ifs{ file_name };
	if (!ifs)
		error("Couldn't open the file for reading");

	ofstream ofs{ "output" };
	if (!ofs)
		error("Couldn't open/create the file for writing");

	for (char c; ifs.get(c);)
		ofs << static_cast<char>(tolower(c));
}
catch (exception& e) {
	cerr << "Exception: " << e.what() << '\n';
	return 1;
}
catch (...) {
	cerr << "Unknown exception" << '\n';
	return 1;
}