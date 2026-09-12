#ifndef DOCUMENT
#define DOCUMENT

#include "std_lib_facilities.h"

namespace DT {

	struct Document {
		using Line = vector<char>;
		using Lines = list<Line>;

		class Iterator {
		public:
			Iterator(Lines::iterator l, Line::iterator c, Lines::iterator l_e);

			char& operator*();
			const char& operator*() const;

			Iterator& operator++();

			bool operator==(Iterator& arg);
			bool operator!=(Iterator& arg);
		private:
			Lines::iterator cur_line;
			Line::iterator cur_char;
			Lines::iterator l_end;
		};

		Iterator begin();
		Iterator end();

		Document();
		Lines lines;
	};

	// helpers
	istream& operator>>(istream& is, Document& d);

	template<typename It>
	void advance(It& it, ptrdiff_t n) {
		if (n > 0)
			for (; n > 0; --n)
				++it;
		else if (n < 0)
			for (; n < 0; ++n)
				--it;
	}

	void erase_line(Document& d, size_t n);

	template<typename It>
	bool match(It first, It last, const string& s) {
		for (size_t i{}; i < s.length(); ++i, ++first)
			if (*first != s[i])
				return false;
		return true;
	}

	template<typename It>
	void replace(It first, It last, const string& toreplace, const string& replacewith) {
		if (toreplace.size() == 0 || toreplace.size() != replacewith.size())
			throw runtime_error{ "Never LDAR" }; // SORRY I BEEN SO TIRED

		const char first_char{ toreplace.front() };
		for (; first != last && *first != first_char; ++first);
		if (first == last) return;

		auto p{ first };
		size_t i{};
		for (; i < toreplace.size() && p != last; ++i, ++p);
		if (i < toreplace.size()) return;

		if (match(first, p, toreplace))
			for (size_t i{}; i < toreplace.size(); ++i, ++first)
				*first = replacewith[i];
	}
}

#endif