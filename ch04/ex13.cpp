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

void print_vec(const vector<int>& v) {
	for (const int& n : v)
		cout << n << '\n';
}

int main()

try {
	cout << "The following are prime numbers [1, 100]: \n\n";
	print_vec(sieve_ertatosthenes(100));
}
catch (exception& e) {
	cerr << "Exception: " << e.what() << '\n';
	return 1;
}
catch (...) {
	cerr << "Unknown exception" << '\n';
	return 1;
}