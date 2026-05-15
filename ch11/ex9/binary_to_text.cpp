#include "std_lib_facilities.h"

int main()

try {
	ifstream ifs{ "file.bin", ios_base::binary };
	if (!ifs)
		error("Couldn't open the file for reading");

	ofstream ofs{ "file.txt" };
	if (!ofs)
		error("Couldn't open/create the file for writing");

	for (char c; ifs.read(as_bytes(c), sizeof(c));)
		ofs << c;
}
catch (exception& e) {
	cerr << "Exception: " << e.what() << '\n';
	return 1;
}
catch (...) {
	cerr << "Unknown exception" << '\n';
	return 1;
}