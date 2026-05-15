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

	// they persist
	ofs << scientific << setprecision(8);

	int num{};
	for (int i{ 1 }; ifs >> num; ++i) {
		ofs << setw(20) << num;
		if (i % 4 == 0)
			ofs << '\n';
	}
}
catch (exception& e) {
	cerr << "Exception: " << e.what() << '\n';
	return 1;
}
catch (...) {
	cerr << "Unknown exception" << '\n';
	return 1;
}