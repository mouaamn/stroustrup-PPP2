#include "std_lib_facilities.h"

const vector<string> SPELLED_DIGITS{
		"zero",
		"one",
		"two",
		"three",
		"four",
		"five",
		"six",
		"seven",
		"eight",
		"nine"
};

string tolower(string s) {
	for (char& c : s)
		c = tolower(c);
	return s;
}

int get_digit() {
	int digit;
	cin >> digit;

	if (cin) {
		if (!(digit >= 0 && digit <= 9))
			error("Out of range digit");
		return digit;
	}
	else {
		cin.clear();
		string digit_word;
		cin >> digit_word;

		for (int i{}; i < SPELLED_DIGITS.size(); ++i)
			if (SPELLED_DIGITS[i] == tolower(digit_word))
				return i;
		error("Out of range spelled out digit");
	}
}

int main()

try {
	cout << "Enter two digits and an operation: ";
	int lval{ get_digit() }, rval{ get_digit() };
	char op{};
	cin >> op;

	cout << '\n';

	switch (op) {
	case '+':
		cout << "The sum of " << lval << " and " << rval << " is " << lval + rval;
		break;
	case '-':
		cout << "The difference of " << lval << " and " << rval << " is " << lval - rval;
		break;
	case '*':
		cout << "The product of " << lval << " and " << rval << " is " << lval * rval;
		break;
	case '/':
		cout << "The ratio of " << lval << " and " << rval << " is " << lval / rval; // division by zero is handled by exceptions
		break;
	default:
		error("Bad input");
	}

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