#include "Connection_points.h"

namespace Graph_lib {

	Point nw(const Rectangle& r) { return r.point(0); }
	Point ne(const Rectangle& r) { return { r.point(0).x + r.width(), r.point(0).y }; }
	Point n(const Rectangle& r) { return { r.point(0).x + r.width() / 2, r.point(0).y }; }
	Point sw(const Rectangle& r) { return { r.point(0).x, r.point(0).y + r.height() }; }
	Point se(const Rectangle& r) { return { r.point(0).x + r.width(), r.point(0).y + r.height() }; }
	Point s(const Rectangle& r) { return { r.point(0).x + r.width() / 2, r.point(0).y + r.height() }; }

	Point nw(const Circle& c) { return { c.point(0).x - c.radius(), c.point(0).y - c.radius() }; }
	Point ne(const Circle& c) { return { c.point(0).x + c.radius(), c.point(0).y - c.radius() }; }
	Point n(const Circle& c) { return { c.point(0).x, c.point(0).y - c.radius() }; }
	Point sw(const Circle& c) { return { c.point(0).x - c.radius(), c.point(0).y + c.radius() }; }
	Point se(const Circle& c) { return { c.point(0).x + c.radius(), c.point(0).y + c.radius() }; }
	Point s(const Circle& c) { return { c.point(0).x, c.point(0).y + c.radius() }; }

	Point nw(const Ellipse& e) { return { e.point(0).x - e.major(), e.point(0).y - e.minor() }; }
	Point ne(const Ellipse& e) { return { e.point(0).x + e.major(), e.point(0).y - e.minor() }; }
	Point n(const Ellipse& e) { return { e.point(0).x, e.point(0).y - e.minor() }; }
	Point sw(const Ellipse& e) { return { e.point(0).x - e.major(), e.point(0).y + e.minor()}; }
	Point se(const Ellipse& e) { return { e.point(0).x + e.major(), e.point(0).y + e.minor() }; }
	Point s(const Ellipse& e) { return { e.point(0).x, e.point(0).y + e.minor() }; }
}
