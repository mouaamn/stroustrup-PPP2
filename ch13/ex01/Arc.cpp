#include <Graph.h>
#include "Arc.h"

namespace Graph_lib {

	Arc::Arc(Point p, int radius, int start, int end)
		: radius_{ radius }, start_{ start }, end_{ end }
	{
		add({ p.x - radius / 2, p.y - radius / 2 });
	}

	void Arc::draw_lines() const {
		if (color().visibility())
			fl_arc(point(0).x, point(0).y, radius_, radius_, start_, end_);
	}
}