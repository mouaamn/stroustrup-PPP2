#include "std_lib_facilities.h"

constexpr int NOT_A_READING{ -7777 };
constexpr int NOT_A_MONTH{ -8888 };
constexpr int NUM_OF_HOURS{ 24 };
constexpr int NUM_OF_DAYS{ 31 };
constexpr int NUM_OF_MONTHS{ 12 };
const string MONTH_MARKER{ "month" };
const string YEAR_MARKER{ "year" };

void end_of_loop(istream& is, char terminator, string message) {
	if (is.fail()) {
		is.clear();
		char ch;
		if (is >> ch && ch == terminator)
			return;
		error("Bad terminator");
	}
}

const vector<string> MONTHS_TBL{
	"jan", "feb", "mar", "apr", "may", "jun", "jul", "aug", "sep", "oct", "nov", "dec"
};

int month_to_int(string month) {
	for (int i{}; i < MONTHS_TBL.size(); ++i)
		if (month == MONTHS_TBL[i])
			return i;
	error("Non-existing month");
}

string int_to_month(int month) {
	if (month < 0 || month > MONTHS_TBL.size())
		error("Non-existing month");
	return MONTHS_TBL[month];
}

bool is_valid(int hour, int day, double temperature) {
	if (hour < 0 || day < 0)
		return false;
	if (hour > NUM_OF_HOURS || day > NUM_OF_DAYS)
		return false;
	constexpr double IMPLAUSIBLE_MIN{ -200 };
	constexpr double IMPLAUSIBLE_MAX{ 200 };
	if (temperature < IMPLAUSIBLE_MIN || temperature > IMPLAUSIBLE_MAX)
		return false;
	return true;
}

struct Reading {
	int day_;
	int hour_;
	double temperature_;
};

istream& operator>>(istream& is, Reading& reading) {
	char c1;
	if (!(is >> c1) || c1 != '(') {
		is.unget();
		is.clear(ios_base::failbit);
		return is;
	}

	int day;
	int hour;
	double temperature;
	if (!(is >> day >> hour >> temperature))
		error("Bad Reading");
	reading.day_ = day;
	reading.hour_ = hour;
	reading.temperature_ = temperature;

	char c2;
	if (!(is >> c2) || c2 != ')')
		error("Bad Reading");
	return is;
}

struct Day {
	vector<double> hours_{ vector<double>(NUM_OF_HOURS, NOT_A_READING) };
};

struct Month {
	int month_{ NOT_A_MONTH };
	vector<Day> days_{ NUM_OF_DAYS };
};

istream& operator>>(istream& is, Month& month) {
	char c1;
	if (!(is >> c1) || c1 != '{') {
		is.unget();
		is.clear(ios_base::failbit);
		return is;
	}

	string month_marker;
	string m;
	if (!(is >> month_marker >> m) || month_marker != MONTH_MARKER)
		error("Bad Month");
	month.month_ = month_to_int(m);

	for (Reading reading; is >> reading;) {
		if (month.days_[reading.day_].hours_[reading.hour_] != NOT_A_READING)
			error("A Reading duplicate");
		if (!is_valid(reading.hour_, reading.day_, reading.temperature_))
			error("An Invalid Reading");
		month.days_[reading.day_].hours_[reading.hour_] = reading.temperature_;
	}
	end_of_loop(is, '}', "Bad Month");
	return is;
}

struct Year {
	int year_;
	vector<Month> months_{ NUM_OF_MONTHS };
};

istream& operator>>(istream& is, Year& year) {
	char c1;
	if (!(is >> c1) || c1 != '{') {
		is.unget();
		is.clear(ios_base::failbit);
		return is;
	}

	string year_marker;
	int y;
	if (!(is >> year_marker >> y) || year_marker != YEAR_MARKER)
		error("Bad Year");
	year.year_ = y;

	while (true) {
		Month month;
		if (!(is >> month))
			break;
		year.months_[month.month_] = month;
	}
	end_of_loop(is, '}', "Bad Year");
	return is;
}

void print_day(ostream& os, const Day& day, int d) {
	for (int i{}; i < NUM_OF_HOURS; ++i)
		if (day.hours_[i] != NOT_A_READING)
			os << " (" << d << ' ' << i + 1 << ' ' << day.hours_[i] << ')';
}

void print_month(ostream& os, const Month& month) {
	if (month.month_ != NOT_A_MONTH) {
		os << "    { " << MONTH_MARKER << ' ' << int_to_month(month.month_);
		for (int i{}; i < NUM_OF_DAYS; ++i)
			print_day(os, month.days_[i], i);
		os << " }" << '\n';
	}
}

void print_year(ostream& os, const Year& year) {
	os << "{ " << YEAR_MARKER << ' ' << year.year_ << '\n';
	for (const Month& m : year.months_)
		print_month(os, m);
	os << "}" << '\n';
}

int main()

try {
	ifstream ifs{ "file" };
	if (!ifs)
		error("Couldn't open the file for reading");
	ifs.exceptions(ifs.exceptions() | ios_base::badbit);

	vector<Year> years;
	while (true) {
		Year y;
		if (!(ifs >> y))
			break;
		years.push_back(y);
	}

	for (const Year& y : years)
		print_year(cout, y);
}
catch (exception& e) {
	cerr << "Exception: " << e.what() << '\n';
	return 1;
}
catch (...) {
	cerr << "Unknown exception" << '\n';
	return 1;
}