#include <Simple_window.h>
#include <Graph.h>

int main()

try {
	using namespace Graph_lib;

	const Point TL{ 100, 100 };
	Simple_window win{ TL, 600, 400, "Chapter 12: Exercise 9: I got them" };

	Image mouaamn{ Point{ 0, 0 }, "Mouaamn.png" };
	win.attach(mouaamn);

	Text caption{ Point{ 20, 25 }, "Image 1: I got them" };
	caption.set_color(Color::white);
	win.attach(caption);

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