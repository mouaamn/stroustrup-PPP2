#ifndef FACE
#define FACE

#include <Graph.h>

namespace Graph_lib {

	struct Eyed_face : Circle {
		Eyed_face(Point p, int rr);
		void draw_lines() const override;
	};

	struct Smiley : Eyed_face {
		using Eyed_face::Eyed_face;	
		void draw_lines() const override;
	};

	struct Frowny : Eyed_face {
		using Eyed_face::Eyed_face;
		void draw_lines() const override;
	};

	struct Hatted_Smiley : Smiley {
		using Smiley::Smiley;
		void draw_lines() const override;
	};

	struct Hatted_Frowny : Frowny {
		using Frowny::Frowny;
		void draw_lines() const override;
	};
}

#endif