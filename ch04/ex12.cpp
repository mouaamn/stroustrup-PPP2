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

int get_integer(const string& prompt) {
	cout << prompt;
	int num{};
	cin >> num;
	return num;
}

int main()

try {
	const int MAX{ get_integer("Enter MAX: ")};
	constexpr int MIN{ 1 };

	cout << "The following are prime numbers [" << MIN << ", " << MAX << "]: \n\n";
	for (int i{ MIN }; i < MAX; ++i)
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