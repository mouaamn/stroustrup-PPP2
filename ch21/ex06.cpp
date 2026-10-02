/*
	Discuss the differences between the two implementations.
	> In the first, the function object had to take objects and use '.,'
	  but in the second had to take pointers use '->.'
*/

#include "std_lib_facilities.h"

struct Fruit {
	string name;
	int count;
	double price;
};

struct Fruit_comparsion {
	bool operator()(const Fruit* a, const Fruit* b) const {
		return a->name < b->name;
	}
};

int main()

try {
	set<Fruit*, Fruit_comparsion> inventory;
	inventory.insert(new Fruit{ "Banana", 4, 6 });
	inventory.insert(new Fruit{ "Apple", 4, 8 });

	for (auto a : inventory)
		cout << a->name << '\t' << a->count << '\t' << a->price << '\n';
}
catch (exception& e) {
	cerr << "Exception: " << e.what() << '\n';
	return 1;
}
catch (...) {
	cerr << "Unknown exception" << '\n';
	return 1;
}
