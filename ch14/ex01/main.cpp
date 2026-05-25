#include <Simple_window.h>
#include <Graph.h>

#include "Face.h"

int main()

try {
	using namespace Graph_lib;

	const Point TL{ 100, 100 };
	Simple_window win{ TL, 600, 400, "Chapter 14: Exercise 1" };

	Hatted_Smiley hatted_smiley{ { 200, 200 }, 50 };
	Hatted_Frowny hatted_frowny{ { 300, 200 }, 50 };
	Eyed_face eyed_face{ { 200, 300 }, 50 };
	Smiley smiley{ { 300, 300 }, 50 };
	Frowny frowny{ { 400, 300 }, 50 };
	win.attach(hatted_frowny);
	win.attach(hatted_smiley);
	win.attach(eyed_face);
	win.attach(smiley);
	win.attach(frowny);

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