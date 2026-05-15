#include <Simple_window.h>
#include <Graph.h>

int main()

try {
	using namespace Graph_lib;

	const Point TL{ 100, 100 };
	Simple_window win{ TL, 600, 400, "Chapter 12: Exercise 3" };

	constexpr int HIGHT{ 150 }, WIDTH{ 90 };

	Open_polyline m;
	m.add(Point{ 100, 300 });
	m.add(Point{ 100, 300 - HIGHT });
	m.add(Point{ 100 + WIDTH, 300 - 30 });
	m.add(Point{ 100 + WIDTH + WIDTH, 300 - HIGHT });
	m.add(Point{ 100 + WIDTH + WIDTH, 300 });
	m.set_style(Line_style{ Line_style::solid, 5 });
	win.attach(m);

	constexpr int SEPARATION_AMOUNT{ 20 };

	Open_polyline o;
	o.add(Point{ 300 + SEPARATION_AMOUNT, 300 });
	o.add(Point{ 300 + SEPARATION_AMOUNT, 300 - HIGHT });
	o.add(Point{ 300 + SEPARATION_AMOUNT + WIDTH + WIDTH, 300 - HIGHT });
	o.add(Point{ 300 + SEPARATION_AMOUNT + WIDTH + WIDTH, 300 });
	o.add(Point{ 300 + SEPARATION_AMOUNT, 300 });
	o.set_style(Line_style{ Line_style::solid, 5 });
	win.attach(o);
	
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