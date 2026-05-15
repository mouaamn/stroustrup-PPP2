#include "std_lib_facilities.h"

int get_integer(const string& prompt) {
	cout << prompt;
	int num{};
	cin >> num;

	if (!cin)
		error("Bad input");

	return num;
}

vector<int> fibonacci_series(int max) 
// gets fibonacci series of MAX numbers;
// pre-condition: max is natural.
{
	if (max <= 0)
		error("Max is not natural");

	vector<int> series;
	series.push_back(1);
	if (max == 1)
		return series;
	series.push_back(2);
	if (max == 2)
		return series;

	for (int i{ 1 }; (i + 1) < max; ++i)
		series.push_back(series[i - 1] + series[i]);

	return series;
}

int main()

try {
	const int MAX{ get_integer("Enter MAX: ") };

	const vector<int> series{ fibonacci_series(MAX) };
	for (int n : series)
		cout << n << '\n';
}
catch (exception& e) {
	cerr << "Exception: " << e.what() << '\n';
	return 1;
}
catch (...) {
	cerr << "Unknown exception" << '\n';
	return 1;
}