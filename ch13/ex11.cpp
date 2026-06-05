#include <Simple_window.h>
#include <Graph.h>

int main()

try {
	using namespace Graph_lib;

	constexpr Point TL{ 100, 100 };
	Simple_window win{ TL, 800, 600, "Chapter 13: Exercise 11" };

	Ellipse e{ { 400, 300 }, 300, 200 };
	win.attach(e);

	Axis x{ Axis::x, { e.center().x - 400, e.center().y }, 400 * 2, 400 / 5 };
	Axis y{ Axis::y, { e.center().x, e.center().y + 300 }, 300 * 2, 300 / 5 };
	win.attach(x);
	win.attach(y);

	Mark mark_focus1{ e.focus1(), 'A' };
	Mark mark_focus2{ e.focus2(), 'B' };
	win.attach(mark_focus1);
	win.attach(mark_focus2);

	Point point{ 500, 110 };
	Mark mark_point{ point, 'P' };
	win.attach(mark_point);

	Lines lines{ { e.focus1(), point }, { point, e.focus2() } };
	win.attach(lines);

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