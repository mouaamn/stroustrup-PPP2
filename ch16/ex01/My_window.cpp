#include "My_window.h"

namespace Graph_lib {

	My_window::My_window(Point xy, int w, int h, const string& title)
		: Simple_window{ xy, w, h, title },
		quit_button_{ Point{ w - 70, 20 }, 70, 20, "quit", [](Address, Address pw) { reference_to<My_window>(pw).hide(); } }
	{
		attach(quit_button_);
	}
}