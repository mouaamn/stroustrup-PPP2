/*
	Can we declare a non-reference function argument const 
	(e.g., void f(const int);)?
	> Yes, but it's dumb.

	What might that mean?
	> It means a copy of the argument but the copy is constant.

	Why might we want to do that?
	> I would never want to do that.

	Why don’t people do that often?
	> Because it's dumb, duh.
*/

#include "std_lib_facilities.h"

void foo(const int) {}

int main()

try {

}
catch (exception& e) {
	cerr << "Exception: " << e.what() << '\n';
	return 1;
}
catch (...) {
	cerr << "Unknown exception" << '\n';
	return 1;
}