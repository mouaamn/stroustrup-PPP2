#include "std_lib_facilities.h"

double get_number(const string& prompt) {
	cout << prompt;
	double n{};

	cin >> n;
	if (!cin)
		error("Bad input");

	return n;
}

string tostring(int num) {
	ostringstream oss;
	oss << num;
	return oss.str();
}

int main()

try {
	const int N{ static_cast<int>(get_number("Enter the number of pairs: ")) };


	if (N < 0)
		error("N is negative");
	if (N % 2 != 0)
		error("Invalid pair");

	vector<double> nums;
	for (double i{}; i < N; ++i) {
		const double NUM{ get_number("number[" + tostring(i + 1) + "]: ") };
		nums.push_back(NUM);
	}


	double sum{};
	cout << '\n' << "The sum of the " << N << " numbers (";
	for (int i{}; i < N; ++i) {
		if (nums[i] > 0 && sum > numeric_limits<double>::max() - nums[i])
			error("Sum overflow");
		if (nums[i] < 0 && sum < numeric_limits<double>::min() - nums[i])
			error("Sum underflow");

		sum += nums[i];
		cout << nums[i] << (i == N - 1 ? "" : ", ");
	}
	cout << ") is " << sum << '\n';

	vector<double> differences;
	cout << "The differences of the adjacent pairs [";
	for (int i{ 1 }; i < N; i += 2) {
		// Todo: check for over/under flow, and throw exceptions.

		differences.push_back(nums[i - 1] - nums[i]);
		cout << "(" << nums[i - 1] << ", " << nums[i] << ")" << (i == N - 1 ? "" : ", ");
	}
	cout << "] are ";
	for (int i{}; i < differences.size(); ++i)
		cout << differences[i] << (i == differences.size() - 1 ? "" : ", ");
	cout << '\n';
}
catch (exception& e) {
	cerr << "Exception: " << e.what() << '\n';
	return 1;
}
catch (...) {
	cerr << "Unknown exception" << '\n';
	return 1;
}