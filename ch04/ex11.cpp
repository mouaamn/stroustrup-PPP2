#include "std_lib_facilities.h"

// inefficient?
bool is_prime(int n) {
	if (n <= 1)
		return false;

	for (int i{ 2 }; i < n; ++i)
		if (n % i == 0)
			return false;
	return true;
}

int main()

try {
	cout << "The following are prime numbers [1, 100]: \n\n";
	for (int i{ 1 }; i < 100; ++i)
		if (is_prime(i))
			cout << i << '\n';
}
catch (exception& e) {
	cerr << "Exception: " << e.what() << '\n';
	return 1;
}
catch (...) {
	cerr << "Unknown exception" << '\n';
	return 1;
}