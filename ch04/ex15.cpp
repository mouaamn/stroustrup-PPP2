/*
	Note: I had to comment out the include directive to std_lib_facilities.h,
	because it caused some weird errors in this program.
*/

//#include "std_lib_facilities.h"
#include <iostream>
#include <vector>
using namespace std; // bad BTW

vector<int> sieve_ertatosthenes(int n) {
	vector<bool> is_prime(n, true);
	is_prime[0] = is_prime[1] = false;

	for (int p{ 2 }; p < n; ++p)
		if (is_prime[p])
			for (int i{ p + p }; i < n; i += p)
				is_prime[i] = false;

	vector<int> r;
	for (int i{ 2 }; i < n; ++i)
		if (is_prime[i])
			r.push_back(i);

	return r;
}

void print_vec(const vector<int>& v, int max) {
	for (int i{}; i < max; ++i)
		cout << v[i] << '\n';
}

int get_integer(const string& prompt) {
	cout << prompt;
	int num{};
	cin >> num;
	return num;
}

int main()

try {
	// MAX now means how many primes
	const int MAX{ get_integer("Enter how many primes: ") };
	constexpr int MIN{ 1 };

	print_vec(sieve_ertatosthenes(MAX * 10), MAX);
}
catch (exception& e) {
	cerr << "Exception: " << e.what() << '\n';
	return 1;
}
catch (...) {
	cerr << "Unknown exception" << '\n';
	return 1;
}