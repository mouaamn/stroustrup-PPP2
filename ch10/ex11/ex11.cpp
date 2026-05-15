#include "std_lib_facilities.h"

int main()

try {
	ifstream ifs{ "file" };
	if (!ifs)
		error("Couldn't open the file for reading");

	int sum{};
	for (int n;;) {
		if (ifs >> n)
			sum += n;

		if (ifs.eof())
			break;

		if (ifs.fail()) {
			ifs.clear();
			for (char c; ifs >> c;)
				if (isdigit(c)) {
					ifs.unget();
					break;
				}
		}
	}

	cout << "The sum is " << sum << '\n';
}
catch (exception& e) {
	cerr << e.what() << '\n';
	return 1;
}
catch (...) {
	cerr << "Unknown reason" << '\n';
	return 1;
}