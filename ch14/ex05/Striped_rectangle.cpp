#include "Striped_rectangle.h"

namespace Graph_lib {

	void Striped_rectangle::draw_lines() const {
		if (!color().visibility())
			return;
		
		fl_color(color().as_int());
		fl_rect(point(0).x, point(0).y, width(), height());

		for (int i{ 1 }; i < 6; ++i)
			fl_line(point(0).x, point(0).y + height() * 1 / 6 * i, point(0).x + width(), point(0).y + height() * 1 / 6 * i);
	}
}