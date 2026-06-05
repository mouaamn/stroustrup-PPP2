#include <Simple_window.h>
#include <Graph.h>

int main()

try {
	using namespace Graph_lib;

	constexpr Point TL{ 100, 100 };
	Simple_window win{ TL, 600, 400, "Chapter 12: Exercise 7" };

	Rectangle base{ Point{ 200, 150 }, 100, 80 };
	base.set_fill_color(Color::blue);
	base.set_style(Line_style{ Line_style::solid, 3 });
	win.attach(base);

	Rectangle chimney{ Point{ 200 + 65, 150 - 60 }, 20, 50 };
	chimney.set_fill_color(Color::green);
	chimney.set_style(Line_style{ Line_style::solid, 3 });
	win.attach(chimney);

	Closed_polyline roof;
	roof.add(Point{ 200 - 15, 150 });
	roof.add(Point{ 200 + 100 + 15, 150 });
	roof.add(Point{ 200 + 50, 150 - 60 });
	roof.set_fill_color(Color::red);
	roof.set_style(Line_style{ Line_style::solid, 3 });
	win.attach(roof);

	Rectangle door{ Point{ 200 + 40, 150 + 30 }, 20, 50 };
	door.set_fill_color(Color::dark_yellow);
	door.set_style(Line_style{ Line_style::solid, 3 });
	win.attach(door);

	Circle left_window{ Point{ 200 + 19 + 2, 150 + 33 }, 12 };
	left_window.set_fill_color(Color::cyan);
	left_window.set_style(Line_style{ Line_style::solid, 2 });
	win.attach(left_window);

	Rectangle right_window{ Point{ 200 + 68 + 2, 150 + 24 }, 21, 21 };
	right_window.set_fill_color(Color::white);
	right_window.set_style(Line_style{ Line_style::solid, 3 });
	win.attach(right_window);

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