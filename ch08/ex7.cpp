#include "std_lib_facilities.h"

constexpr int SIZE{ 5 };

void read_pairs(vector<string>& name, vector<int>& age) {
	for (int i{}; i < SIZE; ++i) {
		string n;
		int a;
		cout << "Enter a name and an age " << '[' << i + 1 << "]: ";
		cin >> n >> a;
		if (!cin)
			error("Bad input");
		name.push_back(n);
		age.push_back(a);
	}
}

void print_pairs(const vector<string>& name, const vector<int>& age) {
	for (int i{}; i < SIZE; ++i)
		cout << name[i] << ' ' << age[i] << '\n';
}

int main()

try {
	vector<string> name;
	vector<int> age;
	read_pairs(name, age);

	cout << "\nAfter sorting names:\n";
	sort(name);
	print_pairs(name, age);

	vector<string> copy_name{ name };
	for (int i{}; i < SIZE; ++i) {
		for (int j{ i }; j < SIZE; ++j) {
			if (name[i] == copy_name[j]) {
				swap(age[i], age[j]);
				swap(copy_name[i], copy_name[j]);
				break;
			}
		}
	}

	cout << "\nAfter matching ages:\n";
	print_pairs(name, age);
}
catch (exception& e) {
	cerr << "Exception: " << e.what() << '\n';
	return 1;
}
catch (...) {
	cerr << "Unknown exception" << '\n';
	return 1;
}