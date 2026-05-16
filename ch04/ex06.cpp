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

int main()

try {
	cout << "Enter a digit: ";
	int digit{};
	cin >> digit;

	cout << '\n';

	if (cin) {
		if (!(digit >= 0 && digit <= 9))
			error("Out of range digit");
		cout << "The digit " << digit << " is spelled out as " << SPELLED_DIGITS[digit] << '\n';
	}
	else {
		cin.clear();
		string digit_word;
		cin >> digit_word;

		for (int i{}; i < SPELLED_DIGITS.size(); ++i)
			if (SPELLED_DIGITS[i] == digit_word) {
				cout << "The spelled out " << digit_word << " is " << i << " numerically" << '\n';
				return 0;
			}
		error("Out of range spelled out digit");
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