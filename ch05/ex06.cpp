/*
	Estimation:
	If F = 9/5 * C + 32, then C = (F - 32) / (9/5).

	I checked the results of the conversions in my browser, and got different results.
	Thus, the results are unplausible.

	The issue turned out to be integer division (9/5).
	After fixing that, the results matched.
*/

#include "std_lib_facilities.h"

constexpr char FAHRENHEIT{ 'F' };
constexpr char CELSIUS{ 'C' };

double ctof(double c) 
// converts Celsius to Fahrenheit;
// pre-condition: c >= absolute zero.
{
	constexpr double C_ABS_ZERO{ -273.15 };

	if (c < C_ABS_ZERO)
		error("Absolute zero");

	return (9.0 / 5) * c + 32;
}

double ftoc(double f) 
// converts Fahrenheit to Celsius;
// pre-condition: f >= absolute zero.
{
	constexpr double F_ABS_ZERO{ -459.67 };

	if (f < F_ABS_ZERO)
		error("Absolute zero");

	return (f - 32) / (9.0 / 5);
}

int main()

try {
	cout << "Enter a temperature (C, F): ";
	double t{};
	char c{};

	cin >> t >> c;
	if (!cin)
		error("Bad input");

	cout << '\n';

	switch (toupper(c)) {
	case CELSIUS:
		cout << ctof(t) << FAHRENHEIT << '\n';
		break;
	case FAHRENHEIT:
		cout << ftoc(t) << CELSIUS << '\n';
		break;
	default:
		error("Invalid unit");
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