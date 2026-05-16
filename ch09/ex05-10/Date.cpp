#include "std_lib_facilities.h"
#include "Date.h"

namespace Chrono {

	Date::Date(int year, Month month, int day)
		: year_{ year }, month_{ month }, day_{ day }
	{
		if (!is_date(year, month, day))
			throw Invalid{};
	}

	const Date& default_date() {
		static const Date DATE{ 2001, Month::jan, 1 };
		return DATE;
	}

	Date::Date()
		: year_{ default_date().year() },
		month_{ default_date().month() },
		day_{ default_date().day() }
	{}

	bool is_date(int year, Month month, int day) {
		if (year <= 0 || day <= 0)
			return false;
		if (month < Month::jan || month > Month::dec)
			return false;

		int days_of_month{ 31 };

		switch (month) {
		case Month::feb:
			days_of_month = (leapyear(year) ? 29 : 28);
			break;
		case Month::apr:
		case Month::jun:
		case Month::sep:
		case Month::nov:
			days_of_month = 30;
			break;
		}

		return (day <= days_of_month);
	}

	bool leapyear(int year) {
		return (year % 4 == 0);
	}

	ostream& operator<<(ostream& os, const Date& a) {
		return (os << '(' << a.year() << ", " << static_cast<int>(a.month()) << ", " << a.day() << ')');
	}

	istream& operator>>(istream& is, Date& a) {
		int day, int month, int year;
		char c1, c2, c3, c4;
		is >> c1 >> day >> c2 >> month >> c3 >> year >> c4;
		if (!is)
			return is;
		if (c1 != '(' || c2 != ',' || c3 != ',' || c4 != ')') {
			is.clear(ios_base::failbit);
			return is;
		}
		a = Date{ year, static_cast<Month>(month), day };
		return is;
	}
}