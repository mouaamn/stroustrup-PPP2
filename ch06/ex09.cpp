#include "std_lib_facilities.h"

constexpr char EXIT_COMMAND{ ';' };

class Digit_stream {
public:
	char get();
};

char Digit_stream::get() {
	char ch;
	cin >> ch;
	if (!cin)
		error("Bad input");

	switch (ch) {
	case ';':
	case '1': case '2': case '3': case '4':
	case '5': case '6': case '7': case '8':
	case '9':
		return ch;
	default:
		error("Bad digit");
	}
}

int main()

try {
	Digit_stream ds;

	vector<char> v{};
	for (char digit{};;) {
		digit = ds.get();
		if (digit == EXIT_COMMAND)
			break;
		v.push_back(digit);
	}

	cout << '\n';

	int num{};
	int exp{};
	for (int i{ static_cast<int>(v.size()) - 1 }; i >= 0; --i) {
		const int expr{ (v[i] - '0') * static_cast<int>(pow(10, exp++)) };
		num += expr;
		cout << expr << " + ";
	}
	cout << "is " << num << '\n';
}
catch (exception& e) {
	cerr << "Exception: " << e.what() << '\n';
	return 1;
}
catch (...) {
	cerr << "Unknown exception" << '\n';
	return 1;
}