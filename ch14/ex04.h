// Immobile_Circle.h
#ifndef IMMOBILE_CIRCLE
#define IMMOBILE_CIRCLE

#include <Graph.h>

namespace Graph_lib {

	struct Immobile_Circle : Circle {
		using Circle::Circle;
	private:
		using Circle::move;
	};
}

#endif