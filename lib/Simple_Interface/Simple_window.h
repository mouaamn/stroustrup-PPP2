#ifndef SIMPLE_WINDOW_GUARD
#define SIMPLE_WINDOW_GUARD

#include "GUI.h"

using namespace Graph_lib;

struct Simple_window : Graph_lib::Window {
	Simple_window(Point xy, int w, int h, const string& title);

	void wait_for_button(); // simple event loop
private:
	Button next_button;	// the "Next" button
	bool button_pushed; // implementation detail

	static void cb_next(Address, Address); // callback for next button
	void next(); // action to be done when next_button is pressed
};

#endif