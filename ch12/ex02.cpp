#include <Simple_window.h>
#include <Graph.h>

int main()

try {
	using namespace Graph_lib;

	const Point TL{ 100, 100 };
	Simple_window win{ TL, 600, 400, "Chapter 12: Exercise 2" };

	Rectangle rc{ Point{ 300, 200 }, 100, 30 };
	win.attach(rc);

	Text txt{ Point{ 300 + 28, 200 + 16 }, "Howdy!" };
	win.attach(txt);

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