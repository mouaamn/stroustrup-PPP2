#ifndef CHRONO
#define CHRONO

namespace Chrono {

	enum class Month {
		jan = 1, feb, mar, apr, may, jun, jul, aug, sep, oct, nov, dec 
	};

	class Date {
	public:
		class Invalid{};

		Date(int year, Month month, int day);
		Date();

		// non-modifying
		int year() const { return year_; } 
		Month month() const { return month_; }
		int day() const { return day_; }
	private:
		int year_;
		Month month_;
		int day_;
	};

	// helpers
	bool is_date(int year, Month month, int day);
	bool leapyear(int year);

	ostream& operator<<(ostream& os, const Date& a);
	istream& operator>>(istream& is, Date& a);
}

#endif