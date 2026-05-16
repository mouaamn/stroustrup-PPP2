#include "std_lib_facilities.h"

int main()

try {
	vector<double> temps;
	for (double t{}; cin >> t;)
		temps.push_back(t);

	sort(temps);

	double sum{};
	for (double d : temps)
		sum += d;

	cout << '\n';

	cout << "The mean is " << sum / temps.size() << '\n';

	if (temps.size() % 2)
		cout << "The median is " << temps[temps.size() / 2] << '\n';
	else
		cout << "The median is " << (temps[temps.size() / 2 - 1] + temps[temps.size() / 2]) / 2 << '\n';
}
catch (exception& e) {
	cerr << "Exception: " << e.what() << '\n';
	return 1;
}
catch (...) {
	cerr << "Unknown exception" << '\n';
	return 1;
}