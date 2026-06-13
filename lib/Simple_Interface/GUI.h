#ifndef GUI_GUARD
#define GUI_GUARD

//#include<vector>
//#include<string>
#include "Point.h"
#include "fltk.h"
#include "Window.h"
#include "Graph.h"

namespace Graph_lib {

	typedef void* Address;
	typedef void(*Callback)(Address, Address); // FLTK's required function type for all callbacks

	template<class W> W& reference_to(Address pw)
		// treat an address as a reference to a W
	{
		return *static_cast<W*>(pw);
	}

	class Widget {
		// Widget is a handle to a Fl_widget - it is *not* a Fl_widget
		// We try to keep our interface classes at arm's length from FLTK
	public:
		Widget(Point xy, int w, int h, const string& s, Callback cb);

		virtual void move(int dx, int dy);
		virtual void hide();
		virtual void show();
		virtual void attach(Window&) = 0;

		Point loc;
		int width;
		int height;
		string label;
		Callback do_it;
	protected:
		Window* own;	// every Widget belongs to a Window
		Fl_Widget* pw;	// connection to the FLTK Widget
	};

	struct Button : Widget {
		Button(Point xy, int w, int h, const string& label, Callback cb);
		void attach(Window&);
	};

	struct In_box : Widget {
		In_box(Point xy, int w, int h, const string& s)
			: Widget{ xy, w, h, s, 0 }
		{}
		int get_int();
		string get_string();

		void attach(Window& win);
	};

	struct Out_box : Widget {
		Out_box(Point xy, int w, int h, const string& s)
			: Widget{ xy, w, h, s, 0 }
		{}
		void put(int);
		void put(const string&);

		void attach(Window& win);
	};

	struct Menu : Widget {
		enum Kind { horizontal, vertical };

		Menu(Point xy, int w, int h, Kind kk, const string& label);

		Vector_ref<Button> selection;
		Kind k;
		int offset;

		int attach(Button& b);		// attach Button to Menu
		int attach(Button* p);		// attach new Button to Menu

		void show()					// show all buttons 
		{
			for (int i = 0; i < selection.size(); ++i)
				selection[i].show();
		}
		void hide();				// hide all buttons
		void move(int dx, int dy);	// move all buttons

		void attach(Window& win);
	};
}

#endif