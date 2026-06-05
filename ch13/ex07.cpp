#include <Simple_window.h>
#include <Graph.h>

int main()

try {
	using namespace Graph_lib;

	constexpr Point TL{ 100, 100 };
	Simple_window win{ TL, 600, 400, "Chapter 13: Exercise 7" };

	Vector_ref<Rectangle> rcs;
	constexpr int SIZE{ 20 };

	for (int i{}; i < 16; ++i) {
		for (int j{}; j < 16; ++j) {
			rcs.push_back(new Rectangle{ { SIZE * i, SIZE * j }, SIZE, SIZE });
			const int INDEX{ i * 16 + j };
			rcs[INDEX].set_fill_color(INDEX);
			win.attach(rcs[INDEX]);
		}
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