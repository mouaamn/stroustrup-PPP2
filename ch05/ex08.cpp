#include "std_lib_facilities.h"

int get_integer(const string& prompt) {
	cout << prompt;
	int n{};

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
	const int N{ get_integer("Enter the number of values you want to sum: ") };

	if (N < 0)
		error("N is negative");
	
	vector<int> nums;
	for (int i{}; i < N; ++i) {
		const int NUM{ get_integer("integer[" + tostring(i + 1) + "]: ") };
		nums.push_back(NUM);
	}


	int sum{};
	cout << '\n' << "The sum of the " << N << " integers (";
	for (int i{}; i < N; ++i) {
		sum += nums[i];
		cout << nums[i] << (i == N - 1 ? "" : ", ");
	}
	cout << ") is " << sum << '\n';
}
catch (exception& e) {
	cerr << "Exception: " << e.what() << '\n';
	return 1;
}
catch (...) {
	cerr << "Unknown exception" << '\n';
	return 1;
}