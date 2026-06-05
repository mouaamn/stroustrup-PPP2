#include <Simple_window.h>
#include <Graph.h>

int main() 

try {
	using namespace Graph_lib;

	constexpr Point TL{ 100, 100 };
	Simple_window win{ TL, 600, 400, "Chapter 12: Exercise 1" };

	Rectangle rc{ Point{ 300, 200 }, 50, 50 };
	rc.set_color(Color::blue);
	win.attach(rc);

	Polygon poly;
	poly.add(Point{ 300, 200 - 10 });
	poly.add(Point{ 300 + 50, 200 - 10 });
	poly.add(Point{ 300 + 50, 200 - 10 - 50 });
	poly.add(Point{ 300, 200 - 10 - 50 });
	poly.set_color(Color::red);
	win.attach(poly);

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