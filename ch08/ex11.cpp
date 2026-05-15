/*
	Either return a struct containing the results or pass them back 
	through reference arguments. Which of the two ways of returning several 
	result values do you prefer and why?
	> I prefer returnning a struct that has all the results, 
	  because it's best suited and it clearly expresses our intent.
*/

#include "std_lib_facilities.h"

struct Result {
	double max{};
	double min{};
	double mean{};
	double median{};
};

double maxv(const vector<double>& v)
// returns the largest element;
// pre-condition: v not empty.
{
	if (v.size() == 0)
		error("Empty vector");
	double largest{ v[0] };

	for (int i{ 1 }; i < v.size(); ++i)
		if (v[i] > largest)
			largest = v[i];
	return largest;
}

double minv(const vector<double>& v)
// returns the smallest element;
// pre-condition: v not empty.
{
	if (v.size() == 0)
		error("Empty vector");
	double smallest{ v[0] };

	for (int i{ 1 }; i < v.size(); ++i)
		if (v[i] < smallest)
			smallest = v[i];
	return smallest;
}

double average(const vector<double>& v) 
// returns the average;
// pre-condition: v not empty.
{
	if (v.size() == 0)
		error("Empty vector");

	double sum{};
	for (double d : v)
		sum += d;
	return sum / v.size();
}

double median(const vector<double>& v) 
// returns the median;
// pre-condition: v not empty.
{
	if (v.size() == 0)
		error("Empty vector");

	vector<double> copy_v{ v };
	sort(copy_v);

	if (copy_v.size() % 2 == 1)
		return copy_v[copy_v.size() / 2];
	else
		return (copy_v[copy_v.size() / 2 - 1] + copy_v[copy_v.size() / 2]) / 2;
}

Result calculate(const vector<double>& v) {
	return Result{ maxv(v), minv(v), average(v), median(v) };
}

int main()

try {
	const vector<double> v{ 1, 3, 2, 5 };
	
	Result result{ calculate(v) };
	cout
		<< "Maximum: " << result.max << '\n'
		<< "Minimum: " << result.min << '\n'
		<< "Average: " << result.mean << '\n'
		<< "Median: " << result.median << '\n';
}
catch (exception& e) {
	cerr << "Exception: " << e.what() << '\n';
	return 1;
}
catch (...) {
	cerr << "Unknown exception" << '\n';
	return 1;
}