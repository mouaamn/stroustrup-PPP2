#include <Simple_window.h>
#include <Graph.h>

#include "Arc.h"

int main()

try {
	using namespace Graph_lib;

	const Point TL{ 100, 100 };
	Simple_window win{ TL, 600, 400, "Chapter 13: Exercise 1" };

	Arc arc{ { 300, 200 }, 200, 0, 270 };
	win.attach(arc);

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