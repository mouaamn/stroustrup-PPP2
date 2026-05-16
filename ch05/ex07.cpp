/*
	How do you know that your results are plausible? 
	> By estimation; by solving quadratic equations by-hand, 
	  and comparing them with what the program produces.
	
	  For example, given a = 2, b = 4, and c  = -2. 
	  Solution: https://archive.org/details/meth_20260206
	  If the output equals my solution then the result is plausible.
	
	Can you check that they are correct? 
	> Yea, duh.
*/

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
	if (!cin)
		error("Bad input");

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