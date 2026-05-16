#include "std_lib_facilities.h"

bool question(const string& q) {
	cout << q << " (Y, N): ";
	char a;
	cin >> a;

	switch (toupper(a)) {
	case 'Y': return true;
	default: return false;
	}
}

void answer(int num, int answer) {
	if (num == answer)
		cout << "The answer is " << answer << " (correct)" << '\n';
	else
		cout << "The answer is " << answer << " (wrong)" << '\n';
}

int main()

try {
	int num{};
	cout << "Enter a number (1, 100): ";
	cin >> num;

	cout << '\n';

	int low{ 1 }, high{ 100 };
	while (low < high) {
		int mid{ (low + high) / 2 };

		if (question("Is the number less than " + to_string(mid)))
			high = mid - 1;
		else
			low = mid + 1;
	}

	answer(num, low);
}
catch (exception& e) {
	cerr << "Exception: " << e.what() << '\n';
	return 1;
}
catch (...) {
	cerr << "Unknown exception" << '\n';
	return 1;
}