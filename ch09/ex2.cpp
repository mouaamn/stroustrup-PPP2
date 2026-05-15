#include "std_lib_facilities.h"

class Name_pairs {
public:
	void read_names();
	void read_ages();
	void print();
	void sort();
private:
	vector<string> names_;
	vector<double> ages_;
};

void Name_pairs::read_names() {
	cout << "Enter a series of names (`exist` to terminate): ";
	for (string n; cin >> n;) {
		if (n == "exist")
			return;
		names_.push_back(n);
	}
	error("Bad input");
}

void Name_pairs::read_ages() {
	for (int i{}; i < names_.size(); ++i) {
		int a{};
		cout << "Enter an age for [" << i + 1 << "]; " << names_[i] << ": ";
		cin >> a;
		if (!cin)
			error("Bad input");
		ages_.push_back(a);
	}
}

void Name_pairs::print() {
	for (int i{}; i < names_.size(); ++i)
		cout << '(' << names_[i] << ", " << ages_[i] << ')' << '\n';
}

void Name_pairs::sort() {
	vector<string> copy_name{ names_ };

	::sort(names_);

	for (int i{}; i < names_.size(); ++i) {
		for (int j{ i }; j < names_.size(); ++j) {
			if (names_[i] == copy_name[j]) {
				swap(ages_[i], ages_[j]);
				swap(copy_name[i], copy_name[j]);
				break;
			}
		}
	}
}

int main()

try {
	Name_pairs np;

	np.read_names();
	np.read_ages();

	cout << '\n';
	
	np.sort();
	np.print();
}
catch (exception& e) {
	cerr << "Exception: " << e.what() << '\n';
	return 1;
}
catch (...) {
	cerr << "Unknown exception" << '\n';
	return 1;
}