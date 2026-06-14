#ifndef MY_WINDOW
#define MY_WINDOW

#include <Simple_window.h>

namespace Graph_lib {

	class My_window : public Simple_window {
	public:
		My_window(Point xy, int w, int h, const string& title);
	private:
		Button quit_button_;
	};
}

#endif