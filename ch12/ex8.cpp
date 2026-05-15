#include <Simple_window.h>
#include <Graph.h>

int main()

try {
	using namespace Graph_lib;

	const Point TL{ 100, 100 };
	Simple_window win{ TL, 600, 400, "Chapter 12: Exercise 8" };

	Circle blue_ring{ Point{ 170, 150 }, 50 };
	blue_ring.set_color(Color::blue);
	blue_ring.set_style(Line_style{ Line_style::solid, 5 });
	win.attach(blue_ring);

	Circle yellow_ring{ Point{ 170 + 60, 150 + 60 }, 50 };
	yellow_ring.set_color(Color::yellow);
	yellow_ring.set_style(Line_style{ Line_style::solid, 5 });
	win.attach(yellow_ring);

	Circle black_ring{ Point{ 170 + 120, 150 }, 50 };
	black_ring.set_color(Color::black);
	black_ring.set_style(Line_style{ Line_style::solid, 5 });
	win.attach(black_ring);

	Circle green_ring{ Point{ 170 + 60 + 120, 150 + 60 }, 50 };
	green_ring.set_color(Color::green);
	green_ring.set_style(Line_style{ Line_style::solid, 5 });
	win.attach(green_ring);

	Circle red_ring{ Point{ 170 + 120 + 120, 150 }, 50 };
	red_ring.set_color(Color::red);
	red_ring.set_style(Line_style{ Line_style::solid, 5 });
	win.attach(red_ring);

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