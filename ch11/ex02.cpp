#include "std_lib_facilities.h"

void tolower(string& s) {
	for (char& c : s)
		c = tolower(c);
}

int main()

try {
	string file_name, word;
	cout << "Enter a file name, and a word: ";
	if (!(cin >> file_name >> word))
		error("Bad input");
	tolower(word);

	ifstream ifs{ file_name };
	if (!ifs)
		error("Couldn't open the file for reading");

	string line;
	for (int i{ 1 }; getline(ifs, line); ++i) {
		istringstream iss{ line };
		for (string w; iss >> w;) {
			tolower(w);
			if (w == word) {
				cout << '[' << i << "] " << line << '\n';
				break;
			}
		}
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