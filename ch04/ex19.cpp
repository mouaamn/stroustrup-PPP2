#include "std_lib_facilities.h"

vector<string> names;
vector<int> scores;

bool is_name_unique(const string& s) {
	for (const string& name : names)
		if (name == s)
			return false;
	return true;
}

int main()

try {
	cout << "Enter name-value pairs: ";
	for (;;) {
		string name;
		int score;
		cin >> name >> score;

		if (!(cin) || (name == "NoName" && score == 0))
			break;

		if (!is_name_unique(name))
			error("Redundant name");

		names.push_back(name);
		scores.push_back(score);
	}

	for (int i{}; i < names.size(); ++i)
		cout << '(' << names[i] << ", " << scores[i] << ")" << '\n';

	cout << '\n';
}
catch (exception& e) {
	cerr << "Exception: " << e.what() << '\n';
	return 1;
}
catch (...) {
	cerr << "Unknown exception" << '\n';
	return 1;
}