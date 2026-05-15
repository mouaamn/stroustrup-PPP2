// Note: I did not quite understand this EX

#include "std_lib_facilities.h"

int main()

try {
	vector<double> dists;
	for (double d{}; cin >> d;)
		dists.push_back(d);

	sort(dists);

	double sum{};
	for (double d : dists)
		sum += d;

	cout << '\n';

	cout
		<< "The total distance is " << sum << '\n'
		<< "The smallest distance is " << dists[0] << '\n'
		<< "The greatest distance is " << dists[dists.size() - 1] << '\n'
		<< "The means is " << sum / dists.size() << '\n';
}
catch (exception& e) {
	cerr << "Exception: " << e.what() << '\n';
	return 1;
}
catch (...) {
	cerr << "Unknown exception" << '\n';
	return 1;
}