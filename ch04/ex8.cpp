// Note: I did not quite understand this EX either

#include "std_lib_facilities.h"

int get_grain_square(int total_grain) {
	constexpr int SQUARES{ 64 };

	if (total_grain <= 0)
		error("Invalid total_grain");

	if (total_grain == 1)
		return 1;

	int grains{ 1 };
	for (int i{ 2 }; i < SQUARES; ++i) {
		grains *= 2;
		if (grains >= total_grain)
			return i;
	}

	error("Out of range SQUARES");
}

int main()

try {
	constexpr int ONE_K{ 1000 };
	constexpr int ONE_M{ 1000000 };
	constexpr int ONE_B{ 1000000000 };

	cout 
		<< get_grain_square(ONE_K) << " squares to get atleast " << ONE_K << " grains" << '\n'
		<< get_grain_square(ONE_M) << " squares to get atleast " << ONE_M << " grains" << '\n'
		<< get_grain_square(ONE_B) << " squares to get atleast " << ONE_B << " grains" << '\n';
}
catch (exception& e) {
	cerr << "Exception: " << e.what() << '\n';
	return 1;
}
catch (...) {
	cerr << "Unknown exception" << '\n';
	return 1;
}