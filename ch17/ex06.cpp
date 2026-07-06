/*
	Approximately how much memory did you manage to allocate before failing?
	> Approximately, 22,000 MB, which's about 22 GB (aka, 69% of my memory) 
	  before the OS started what I assume, recycling (might be wrong).

	  See: https://i.imgur.com/w5bXchN.png
*/

#include "std_lib_facilities.h"

int main()

try {
	constexpr size_t N_BYTES{ 1048576 }; // one MB
	for (size_t n{}; ; n += N_BYTES) {
		new char[N_BYTES];
		std::cout << "Current (tried) allocated bytes: " << n << '\n';
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