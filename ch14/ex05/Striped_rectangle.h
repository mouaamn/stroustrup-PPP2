#ifndef STRIPED_RECTANGLE
#define STRIPED_RECTANGLE

#include <Graph.h>

namespace Graph_lib {

	struct Striped_rectangle : Rectangle {
		using Rectangle::Rectangle;
		void draw_lines() const override;
	};
}

#endif