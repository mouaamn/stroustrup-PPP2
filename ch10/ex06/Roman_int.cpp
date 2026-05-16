#include <map>
#include "Roman_int.h"

namespace Number {

	Roman_int::Roman_int(string roman_num)
		: num_{ roman_to_int(roman_num) }, roman_num_{ roman_num }
	{}

	Roman_int::Roman_int()
		: num_{ 0 }, roman_num_{ "" }
	{}

	map<char, int> ROMAN_NUMERALS_TBL{
		{ 'I', 1 },
		{ 'V', 5 },
		{ 'X', 10 },
		{ 'L', 50 },
		{ 'C', 100 },
		{ 'D', 500 },
		{ 'M', 1000 },
	};

	bool is_roman(string roman_num) {
		for (int i{}; i < roman_num.size(); ++i) {
			if (ROMAN_NUMERALS_TBL.find(roman_num[i]) == ROMAN_NUMERALS_TBL.end())
				return false;

			for (int j{ i + 1 }; j < roman_num.size(); ++j)
				if (ROMAN_NUMERALS_TBL[roman_num[j]] > ROMAN_NUMERALS_TBL[roman_num[i]])
					return false;
		}
		return true;
	}

	int roman_to_int(string roman_num) {
		if (!is_roman(roman_num))
			error("Not roman");

		int result{};
		for (char sy : roman_num)
			result += ROMAN_NUMERALS_TBL[sy];
		return result;
	}

	ostream& operator<<(ostream& os, const Roman_int& roman_int) {
		return os << roman_int.as_roman();
	}

	istream& operator>>(istream& is, Roman_int& roman_int) {
		string roman_num;
		if (!(is >> roman_num) || !is_roman(roman_num))
			error("Bad roman-numeral");
		roman_int = Roman_int{ roman_num };
		return is;
	}
}