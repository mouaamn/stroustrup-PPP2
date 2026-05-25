#include "Face.h"

namespace Graph_lib {

	Eyed_face::Eyed_face(Point p, int rr)
		: Circle{ p, rr }
	{
		constexpr int EYE_GAP{ 5 };
		add({ point(0).x + rr / 2 - EYE_GAP, p.y - rr / 2 });
		add({ point(0).x + rr + EYE_GAP, p.y - rr / 2 });
	}

	void Eyed_face::draw_lines() const {
		if (!color().visibility()) return;
		Circle::draw_lines();
		fl_arc(point(1).x, point(1).y, radius() / 2, radius() / 2, 0, 360);
		fl_arc(point(2).x, point(2).y, radius() / 2, radius() / 2, 0, 360);
	}


	void Smiley::draw_lines() const {
		if (!color().visibility()) return;
		Eyed_face::draw_lines();
		fl_arc(point(0).x + radius() / 2, point(0).y + radius() + radius() / 8, radius(), radius() / 2, 0, -180);
	}


	void Frowny::draw_lines() const {
		if (!color().visibility()) return;
		Eyed_face::draw_lines();
		fl_arc(point(0).x + radius() / 2, point(0).y + radius() + radius() / 5, radius(), radius() / 2, 0, 180);
	}


	void Hatted_Smiley::draw_lines() const {
		if (!color().visibility()) return;
		Smiley::draw_lines();
		fl_rect(point(0).x + radius() * 0.78, point(0).y - radius() / 2 + 1, radius() / 2, radius() / 2);
	}


	void Hatted_Frowny::draw_lines() const {
		if (!color().visibility()) return;
		Frowny::draw_lines();
		fl_rect(point(0).x + radius() * 0.78, point(0).y - radius() / 2 + 1, radius() / 2, radius() / 2);
	}
}