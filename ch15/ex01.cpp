/*
	Which implementation of fac() do you prefer, and why?
	> Probably, the recusrive one, because it's an elegant solution. Tho, both overflow.
*/

#include <Simple_window.h>
#include <Graph.h>

int recursive_fac(int n) { return n > 1 ? n * recursive_fac(n - 1) : 1; }
int iterative_fac(int n) {
	int result{ 1 };
	for (; n > 1; --n)
		result *= n;
	return result;
}

int main()

try {
	using namespace Graph_lib;

	constexpr Point TL{ 100, 100 };
	Simple_window win{ TL, 600, 400, "Chapter 15: Exercise 1" };

	for (int i{}; i < 20; ++i)
		std::cout << recursive_fac(i) << (recursive_fac(i) / std::pow(10, 7) > 1 ? "\t" : "\t\t") << iterative_fac(i) << '\n';

	win.wait_for_button();
}
catch (exception& e) {
	cerr << "Exception: " << e.what() << '\n';
	return 1;
}
catch (...) {
	cerr << "Unknown exception" << '\n';
	return 1;
}
