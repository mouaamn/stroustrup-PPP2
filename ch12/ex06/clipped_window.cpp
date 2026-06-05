/*
	What happens when you draw a Window that doesn’t fit on your screen?
	> It gets clipped
*/

#include <Simple_window.h>
#include <Graph.h>

int main()

try {
	using namespace Graph_lib;

	constexpr Point TL{ 100, 100 };
	Simple_window win{ TL, 600, 3000, "Chapter 12: Exercise 6: clipped_window" };

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