#include "std_lib_facilities.h"

double compute(const vector<double>& price, const vector<double>& weight) 
// computes the sum of all price[i] * weight[i];
// pre-condition: the size of both vectors must be equal.
{
	if (price.size() != weight.size())
		error("The size of both vectors aren't equal");

	double result{};
	for (int i{}; i < price.size(); ++i)
		result += price[i] * weight[i];
	return result;
}

int main()

try {
	vector<double> price{ 2, 6 };
	vector<double> weight{ 20, 60 };

	cout << compute(price, weight) << '\n';
}
catch (exception& e) {
	cerr << "Exception: " << e.what() << '\n';
	return 1;
}
catch (...) {
	cerr << "Unknown exception" << '\n';
	return 1;
}