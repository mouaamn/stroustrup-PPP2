#include "std_lib_facilities.h"

int main()

try {
	cout << "Enter two numbers followed by an operation: ";
	double lval{}, rval{}; char op{};
	cin >> lval >> rval >> op;

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