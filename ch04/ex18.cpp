#include "std_lib_facilities.h"

void quadratic_equation(double a, double b, double c) {
	const double radicand{ pow(b, 2) - 4 * a * c };

	if (radicand < 0)
		error("Complex root");

	cout 
		<< (-b - sqrt(radicand)) / (2 * a) << '\n'
		<< (-b + sqrt(radicand)) / (2 * a);
}

int main()

try {
	cout << "Enter a, b, and c: ";
	int a{}, b{}, c{};
	cin >> a >> b >> c;
	quadratic_equation(a, b, c);
}
catch (exception& e) {
	cerr << "Exception: " << e.what() << '\n';
	return 1;
}
catch (...) {
	cerr << "Unknown exception" << '\n';
	return 1;
}