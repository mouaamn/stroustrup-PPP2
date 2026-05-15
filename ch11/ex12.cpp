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

	vector<char> chars;
	for (char ch; ifs.get(ch);)
		chars.push_back(ch);

	ifs.close();
	ofstream ofs{ file_name };
	if (!ofs)
		error("Couldn't open/create the file for writing");

	for (int i{ static_cast<int>(chars.size()) - 1 }; i >= 0; --i)
		ofs << chars[i];
}
catch (exception& e) {
	cerr << "Exception: " << e.what() << '\n';
	return 1;
}
catch (...) {
	cerr << "Unknown exception" << '\n';
	return 1;
}