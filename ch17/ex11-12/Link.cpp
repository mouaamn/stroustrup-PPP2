#include "Link.h"

namespace DT {

	Link::Link(const string& v, Link* p, Link* s)
		: value{ v }, prev{ p }, succ{ s }
	{}

	Link* Link::insert(Link* n) {
		Link* p{ this };
		if (n == nullptr) return p;
		n->succ = p;
		if (p->prev)
			p->prev->succ = n;
		n->prev = p->prev;
		p->prev = n;
		return n;
	}

	Link* Link::add(Link* n) {
		Link* p{ this };
		if (n == nullptr) return p;
		n->prev = p;
		if (p->succ)
			p->succ->prev = n;
		n->succ = p->succ;
		p->succ = n;
		return n;
	}

	Link* Link::erase() {
		Link* p{ this };
		if (p == nullptr) return nullptr;
		if (p->succ)
			p->succ->prev = p->prev;
		if (p->prev)
			p->prev->succ = p->succ;
		return p->succ;
	}

	Link* Link::find(const string& v) {
		Link* p{ this };
		while (p) {
			if (p->value == v)
				return p;
			p = p->succ;
		}
		return nullptr;
	}

	const Link* Link::find(const string& v) const {
		const Link* p{ this };
		while (p) {
			if (p->value == v)
				return p;
			p = p->succ;
		}
		return nullptr;
	}

	Link* Link::advance(int n) const {
		const Link* p{ this };
		if (p == nullptr) return nullptr;
		if (n > 0) {
			while (n--) {
				if (p == nullptr) return nullptr;
				p = p->succ;
			}
		}
		else if (n < 0) {
			while (n++) {
				if (p == nullptr) return nullptr;
				p = p->prev;
			}
		}
		return const_cast<Link*>(p);
	}

	void print_all(Link* p) {
		cout << "{ ";
		while (p) {
			cout << p->value;
			if (p = p->next())
				cout << ", ";
		}
		cout << " }\n";
	}
}