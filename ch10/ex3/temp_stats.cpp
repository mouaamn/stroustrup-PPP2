#include "std_lib_facilities.h"

struct Reading {
	int hour_;
	double temperature_;
};

istream& operator>>(istream& is, Reading& reading) {
	int hour;
	double temperature;
	if (!(is >> hour >> temperature))
		return is;

	reading.hour_ = hour;
	reading.temperature_ = temperature;
	return is;
}

double mean(const vector<double>& temps)
// computes the mean
// pre-condition: temps not empty
{
	if (temps.size() <= 0)
		error("Empty readings");
	double sum{};
	for (double t : temps)
		sum += t;
	return sum / temps.size();
}

double median(vector<double> temps)
// computes the median
// pre-condition: temps not empty
{
	if (temps.size() <= 0)
		error("Empty readings");
	sort(temps);
	if (temps.size() % 2)
		return temps[temps.size() / 2];
	else
		return (temps[temps.size() / 2 - 1] + temps[temps.size() / 2]) / 2;
}

struct Result {
	double mean_;
	double median_;
};

Result calculate(istream& is) {
	vector<double> temperatures;
	for (Reading r; is >> r;)
		temperatures.push_back(r.temperature_);
	return Result{ mean(temperatures), median(temperatures) };
}

int main()

try {
	ifstream ifs{ "raw_temps.txt" };
	ifs.exceptions(ios_base::badbit);
	if (!ifs)
		error("Couldn't open the file for reading");

	Result result{ calculate(ifs) };
	cout
		<< "The mean is " << result.mean_ << '\n'
		<< "The median is " << result.median_ << '\n';
}
catch (exception& e) {
	cerr << "Exception: " << e.what() << '\n';
	return 1;
}
catch (...) {
	cerr << "Unknown exception" << '\n';
	return 1;
}