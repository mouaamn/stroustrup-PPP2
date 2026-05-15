#include "std_lib_facilities.h"

vector<int> read_from(istream& is) {
	vector<int> nums;
	for (int n{}; is >> n;)
		nums.push_back(n);
	return nums;
}

struct Number {
	int _num;
	int _quantity;
};

vector<Number> package_occurences(vector<int> nums) 
// repackages numbers into (number, occurences) pairs
// pre-condition: nums.size() > 0
{
	sort(nums);
	nums.push_back(numeric_limits<int>::min());

	vector<Number> new_nums;

	int prev{ nums[0] };
	int count{ 1 };
	for (int i{ 1 }; i < nums.size(); ++i)
		if (nums[i] != prev) {
			new_nums.push_back({ prev, count });
			prev = nums[i];
			count = 1;
		}
		else
			++count;
	return new_nums;
}

int main()

try {
	string file_name;
	cout << "Enter the name of a file: ";
	if (!(cin >> file_name))
		error("Bad input");

	ifstream ifs{ file_name };
	if (!ifs)
		error("Couldn't open the file for reading");

	const vector<Number> RESULT{ 
		package_occurences(read_from(ifs)) 
	};

	cout << '\n';

	for (Number number : RESULT) {
		cout << number._num;
		if (number._quantity > 1)
			cout << '\t' << number._quantity << '\n';
		else
			cout << '\n';
	}
}
catch (exception& e) {
	cerr << "Exception: " << e.what() << '\n';
	return 1;
}
catch (...) {
	cerr << "Unknown exception" << '\n';
	return 1;
}