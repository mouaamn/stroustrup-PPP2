#include "std_lib_facilities.h"

void write_to(istream& is, ostream& os) {
	while (is) {
		string line;
		getline(is, line);
		os << line << '\n';
	}
}

int main()

try {
	string file1_name, file2_name;
	cout << "Enter the name of two files: ";
	if (!(cin >> file1_name >> file2_name))
		error("Bad input");

	ifstream file1{ file1_name }, file2{ file2_name };
	if (!file1 || !file2)
		error("Couldn't open the file(s) for reading");

	ofstream ofile{ "output.txt" };
	if (!ofile)
		error("Couldn't open/create the file for writing");

	write_to(file1, ofile);
	write_to(file2, ofile);
}
catch (exception& e) {
	cerr << "Exception: " << e.what() << '\n';
	return 1;
}
catch (...) {
	cerr << "Unknown exception" << '\n';
	return 1;
}