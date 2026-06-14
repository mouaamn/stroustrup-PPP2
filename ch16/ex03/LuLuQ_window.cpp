#include "LuLuQ_window.h"

namespace Graph_lib {

	LuLuQ_window::LuLuQ_window(Point xy, int w, int h, const string& title)
		: Window{ xy, w, h, title },
		button_{ {50, 50}, 100, 79, "",
		[](Address, Address pw) { reference_to<LuLuQ_window>(pw).move_button(); } },
		image_{ {50, 50}, "LULUQ.jpg", Suffix::jpg }
	{
		attach(button_);
		attach(image_);
	}

	void LuLuQ_window::move_button() {
		int x{ randint(0, x_max()) / 2 };
		int y{ randint(0, y_max()) / 2 };

		if ((button_.loc.x + x) > x_max())
			x *= -1;
		if ((button_.loc.y + y) > y_max())
			y *= -1;

		button_.move(x, y);
		image_.move(x, y);
	}
}