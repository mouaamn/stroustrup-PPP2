#include "std_lib_facilities.h"

constexpr char FAHRENHEIT{ 'F' };
constexpr char CELSUIS{ 'C' };

int main()

try {
	ofstream ofs{ "raw_temps.txt" };
	if (!ofs)
		error("Couldn't open/create the file for writing");

	for (int i{}; i < 50; ++i)
		ofs << i << ' ' << 20.3 + i << (i % 2 ? FAHRENHEIT : CELSUIS) << '\n';
}
catch (exception& e) {
	cerr << "Exception: " << e.what() << '\n';
	return 1;
}
catch (...) {
	cerr << "Unknown exception" << '\n';
	return 1;
}