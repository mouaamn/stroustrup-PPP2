#include "std_lib_facilities.h"

class Name_value {
public:
	string name;
	int value;
};

vector<Name_value> names_values;

bool is_name_unique(const string& s) {
	for (const Name_value& nv : names_values)
		if (nv.name == s)
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
		if (!cin)
			error("Bad input");

		if (!(cin) || (name == "NoName" && score == 0))
			break;

		if (!is_name_unique(name))
			error("Redundant name");

		names_values.push_back(Name_value{ name, score });
	}

	for (int i{}; i < names_values.size(); ++i)
		cout << '(' << names_values[i].name << ", " << names_values[i].value << ")" << '\n';

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