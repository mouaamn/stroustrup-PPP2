#include <Simple_window.h>
#include <Graph.h>

struct Arc : Shape {
	Arc(Point p, int radius, int start, int end)
		: radius_{ radius }, start_{ start }, end_{ end }
	{
		add({ p.x - radius / 2, p.y - radius / 2 });
	}

	void draw_lines() const override {
		if (color().visibility())
			fl_arc(point(0).x, point(0).y, radius_, radius_, start_, end_);
	}

	Point center() const { return point(0); }
	int radius() const { return radius_; }
	int start() const { return start_; }
	int end() const { return end_; }
private:
	int radius_;
	int start_, end_;
};

int main()

try {
	using namespace Graph_lib;

	const Point TL{ 100, 100 };
	Simple_window win{ TL, 600, 400, "Chapter 13: Exercise 1" };

	Arc arc{ { 300, 200 }, 200, 0, 180 + 90 };
	win.attach(arc);

	win.wait_for_button();
}
catch (exception& e) {
	cerr << "Exception: " << e.what() << '\n';
	return 1;
}
catch (...) {
	cerr << "Unknown exception" << '\n';
	return 1;
}