#include <Simple_window.h>
#include <Graph.h>

#include "Striped_rectangle.h"

int main()

try {
	using namespace Graph_lib;

	constexpr Point TL{ 100, 100 };
	Simple_window win{ TL, 600, 400, "Chapter 14: Exercise 5" };

	Striped_rectangle sr{ { 300, 200 }, 100, 80 };
	win.attach(sr);

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