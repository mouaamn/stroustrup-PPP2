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

	vector<string> words;
	for (string line; getline(ifs, line);) {
		istringstream iss{ line };
		for (string wo; iss >> wo;)
			words.push_back(wo);
		words.push_back("\n");
	}

	ifs.close();
	ofstream ofs{ file_name };
	if (!ofs)
		error("Couldn't open/create the file for writing");
	for (int i{ static_cast<int>(words.size()) - 2 }; i >= 0; --i) {
		ofs << words[i];
		if (i > 0 && words[i] != "\n")
			if (words[i - 1] != "\n")
				ofs << ' ';
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