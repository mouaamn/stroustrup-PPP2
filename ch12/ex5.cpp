#include <Simple_window.h>
#include <Graph.h>

int main()

try {
	using namespace Graph_lib;

	const Point TL{ 100, 100 };
	Simple_window win{ TL, 2560, 1600, "Chapter 12: Exercise 5"};

	Rectangle rc{ 
		Point{ 10, 10 }, 
		static_cast<int>(0.66 * win.x_max()), 
		static_cast<int>(0.75 * win.y_max())
	};
	rc.set_style(Line_style{ Line_style::solid, 24 });
	rc.set_color(Color::red);
	win.attach(rc);

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