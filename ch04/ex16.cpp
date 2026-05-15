#include "std_lib_facilities.h"

int find_mode(vector<int> v) {
	if (v.size() == 0)
		error("Empty set");

	sort(v);

	int mode{ v[0] };
	int count{ 1 };

	int max_mode{};
	int max_count{};

	for (int i{ 1 }; i < v.size(); ++i)
		if (v[i] == mode)
			++count;
		else {
			if (count > max_count) {
				max_mode = mode;
				max_count = count;
				count = 1;
				mode = v[1];
			}
		}

	return max_mode;
}

int main()

try {
	vector<int> v;
	for (int i{}; cin >> i;)
		v.push_back(i);

	cout << '\n' << "The mode is " << find_mode(v) << '\n';
}
catch (exception& e) {
	cerr << "Exception: " << e.what() << '\n';
	return 1;
}
catch (...) {
	cerr << "Unknown exception" << '\n';
	return 1;
}