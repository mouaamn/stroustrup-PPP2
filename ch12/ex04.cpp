#include <Simple_window.h>
#include <Graph.h>

int main()

try {
	using namespace Graph_lib;

	const Point TL{ 100, 100 };
	Simple_window win{ TL, 600, 400, "Chapter 12: Exercise 4" };

	vector<Rectangle> rcs;

	for (int i{}; i < 3; ++i)
		for (int j{}; j < 3; ++j) {
			Rectangle rc{ Point{ 50 + (50 * j), 50 + (50 * i) }, 50, 50 };
			rcs.push_back(rc);
		}

	for (int i{}; i < rcs.size(); ++i) {
		if ((i + 1) % 2)
			rcs[i].set_color(Color::red);
		else
			rcs[i].set_color(Color::blue);
		win.attach(rcs[i]);
	}

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