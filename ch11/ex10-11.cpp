#include "std_lib_facilities.h"

vector<string> split(const string& s) {
	vector<string> words;
	istringstream iss{ s };
	for (string word; iss >> word;)
		words.push_back(word);
	return words;
}

bool is_char_in(char ch, const string& s) {
	for (const char& c : s)
		if (c == ch)
			return true;
	return false;
}

vector<string> split(const string& s, const string& w) {
	vector<string> words;
	string word;
	for (const char& c : s) {
		if (isspace(c) || is_char_in(c, w)) {
			if (word.size() > 0) {
				words.push_back(word);
				word = "";
			}
		}
		else 
			word += c;
	}
	return words;
}

int main()

try {
	vector<string> vec{ split("A book in, your palm.", ".,!;:") };

	for (const string& s : vec)
		cout << s << '\n';
}
catch (exception& e) {
	cerr << "Exception: " << e.what() << '\n';
	return 1;
}
catch (...) {
	cerr << "Unknown exception" << '\n';
	return 1;
}