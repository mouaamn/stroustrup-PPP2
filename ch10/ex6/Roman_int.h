#ifndef ROMAN_INT
#define ROMAN_INT

#include <map>
#include "std_lib_facilities.h"

namespace Number {

	class Roman_int {
	public:
		Roman_int(string roman_num);
		Roman_int();
		
		// non-modifying
		int as_int() const { return num_; }
		string as_roman() const { return roman_num_; }
	private:
		int num_;
		string roman_num_;
	};

	extern map<char, int> ROMAN_NUMERALS_TBL;

	// helpers
	bool is_roman(string roman_num);
	int roman_to_int(string roman_num);

	ostream& operator<<(ostream& os, const Roman_int& roman_int);
	istream& operator>>(istream& is, Roman_int& roman_int);
}

#endif