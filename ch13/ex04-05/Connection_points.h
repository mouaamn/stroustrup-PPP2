#ifndef CONNECTION_POINTS
#define CONNECTION_POINTS

#include <Graph.h>

namespace Graph_lib {

	Point nw(const Rectangle& r);
	Point ne(const Rectangle& r);
	Point n(const Rectangle& r);
	Point sw(const Rectangle& r);
	Point se(const Rectangle& r);
	Point s(const Rectangle& r);

	Point nw(const Circle& c);
	Point ne(const Circle& c);
	Point n(const Circle& c);
	Point sw(const Circle& c);
	Point se(const Circle& c);
	Point s(const Circle& c);

	Point nw(const Ellipse& e);
	Point ne(const Ellipse& e);
	Point n(const Ellipse& e);
	Point sw(const Ellipse& e);
	Point se(const Ellipse& e);
	Point s(const Ellipse& e);
}

#endif