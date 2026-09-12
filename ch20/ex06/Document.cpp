#include "Document.h"

namespace DT {

	Document::Iterator::Iterator(Lines::iterator l, Line::iterator c, Lines::iterator l_e)
		: cur_line{ l }, cur_char{ c }, l_end{ l_e }
	{}

	char& Document::Iterator::operator*() {
		return *cur_char;
	}

	const char& Document::Iterator::operator*() const {
		return *cur_char;
	}

	Document::Iterator& Document::Iterator::operator++() {
		++cur_char;
		if (cur_char == (*cur_line).end() && cur_line != l_end) {
			++cur_line;
			cur_char = (*cur_line).begin();
		}
		return *this;
	}

	bool Document::Iterator::operator==(Iterator& arg) {
		return (arg.cur_line == cur_line && arg.cur_char == cur_char);
	}

	bool Document::Iterator::operator!=(Iterator& arg) {
		return !(arg == *this);
	}

	Document::Iterator  Document::begin() {
		return Iterator{ lines.begin(), (*lines.begin()).begin(), --lines.end() };
	}

	Document::Iterator  Document::end() {
		auto last{ lines.end() };
		--last;
		return Iterator{ last, (*last).end(), last };
	}

	Document::Document() { lines.push_back(Line{}); }

	istream& operator>>(istream& is, Document& d) {
		for (char c; is.get(c);) {
			d.lines.back().push_back(c);
			if (c == '\n')
				d.lines.push_back(Document::Line{});
		}
		return is;
	}

	void erase_line(Document& d, size_t n) {
		if (n < 0 || n > d.lines.size() - 1)
			return;
		auto p{ d.lines.begin() };
		advance(p, n);
		d.lines.erase(p);
	}
}