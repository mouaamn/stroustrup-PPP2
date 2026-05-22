#ifndef ARC
#define ARC

namespace Graph_lib {

	class Arc : public Shape {
	public:
		Arc(Point p, int radius, int start, int end);

		void draw_lines() const override;
	private:
		int radius_;
		int start_, end_;
	};
}

#endif