#ifndef LINK
#define LINK

#include "std_lib_facilities.h"

namespace DT {

	class Link {
	public:
		string value;

		Link(const string& v, Link* p = nullptr, Link* s = nullptr);

		Link* insert(Link* n);
		Link* add(Link* n);
		Link* erase();
		Link* find(const string& v);
		const Link* find(const string& v) const;
		Link* advance(int n) const;

		Link* next() const { return succ; }
		Link* previous() const { return prev; }
	private:
		Link* prev;
		Link* succ;
	};

	// helpers
	void print_all(Link* p);
}

#endif