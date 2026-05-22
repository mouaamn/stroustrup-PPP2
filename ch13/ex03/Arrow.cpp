#include <cmath>
#include "Arrow.h"

namespace Graph_lib {

	Arrow::Arrow(Point p1, Point p2) {
		add(p1);
		add(p2);

		double dx{ static_cast<double>(p2.x - p1.x) };
		double dy{ static_cast<double>(p2.y - p1.y) };

		double magnitude{ std::sqrt(dx * dx + dy * dy) };

		dx /= magnitude;
		dy /= magnitude;

		double size = 15;

		double px = -dy;
		double py = dx;

		Point w1 = { p2.x - static_cast<int>(size * (0.866 * dx + 0.5 * px)),
					 p2.y - static_cast<int>(size * (0.866 * dy + 0.5 * py)) };

		Point w2 = { p2.x - static_cast<int>(size * (0.866 * dx - 0.5 * px)),
					 p2.y - static_cast<int>(size * (0.866 * dy - 0.5 * py)) };

		add(w1);
		add(p2);
		add(w2);
	}
}