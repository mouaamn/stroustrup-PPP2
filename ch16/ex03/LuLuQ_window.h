#ifndef LULUQ_WINDOW
#define LULUQ_WINDOW

#include <GUI.h>

namespace Graph_lib {

	class LuLuQ_window : public Window {
	public:
		LuLuQ_window(Point xy, int w, int h, const string& title);
	private:
		Button button_;
		Image image_;

		void move_button();
	};
}

#endif