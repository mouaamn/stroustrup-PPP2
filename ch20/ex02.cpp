#include "std_lib_facilities.h"

double* get_from_jack(int* count) {
	*count = 3;
	return new double[3] { 1, 2, 3 };
}

vector<double>* get_from_jill() {
	return new vector<double>{ 1, 3, 5 };
}

double high(double* begin, double* end) {
	double highest{ *begin };
	for (double* p{ begin }; p != end; ++p)
		if (*p > highest)
			highest = *p;
	return highest;
}

int main()

try {
	int jack_count{};
	double* jack_data{ get_from_jack(&jack_count) };

	vector<double>* jill_data{ get_from_jill() };
	auto& v = *jill_data;

	cout 
		<< high(jack_data, jack_data + jack_count) << '\n'
		<< high(&v[0], &v[0] + v.size()) << '\n';

	delete jack_data;
	delete jill_data;
}
catch (exception& e) {
	cerr << "Exception: " << e.what() << '\n';
	return 1;
}
catch (...) {
	cerr << "Unknown exception" << '\n';
	return 1;
}