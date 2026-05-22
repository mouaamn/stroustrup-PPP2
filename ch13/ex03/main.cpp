#include <Simple_window.h>
#include <Graph.h>

#include "Arrow.h"

int main()

try {
	using namespace Graph_lib;

	const Point TL{ 100, 100 };
	Simple_window win{ TL, 600, 400, "Chapter 13: Exercise 3" };

	Arrow arrow{ { 300, 200 }, { 400, 200 } };
	arrow.move(-220, 100);
	win.attach(arrow);

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