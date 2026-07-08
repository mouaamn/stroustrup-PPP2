/*
	Why did we define two versions of find()? 
	> So that find() works for both const and non-const objects.
*/

#include "std_lib_facilities.h"
#include "Link.h"

int main()

try {
	DT::Link* norse_gods{ new DT::Link{ "Thor"} };
	norse_gods = norse_gods->insert(new DT::Link{ "Odin" });
	norse_gods = norse_gods->insert(new DT::Link{ "Zeus" });
	norse_gods = norse_gods->insert(new DT::Link{ "Freia" });

	DT::Link* greek_gods{ new DT::Link{ "Hera" } };
	greek_gods = norse_gods->insert(new DT::Link{ "Athena" });
	greek_gods = norse_gods->insert(new DT::Link{ "Mars" });
	greek_gods = norse_gods->insert(new DT::Link{ "Poseidon" });

	DT::Link* p{ greek_gods->find("Mars") };
	if (p)
		p->value = "Ares";

	DT::Link* p2{ norse_gods->find("Zeus") };
	if (p2) {
		p2->erase();
		greek_gods = greek_gods->insert(p2);
	}

	DT::print_all(norse_gods);
	DT::print_all(greek_gods);
}
catch (exception& e) {
	cerr << "Exception: " << e.what() << '\n';
	return 1;
}
catch (...) {
	cerr << "Unknown exception" << '\n';
	return 1;
}