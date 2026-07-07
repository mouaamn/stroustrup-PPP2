/*
	Which way does the stack grow?
	> Referring to this: https://i.imgur.com/Bh37IiM.png, it grows downward.
	
	Which way does the free store initially grow?
	> Referring to the above image again, it grows upward.

	  Beware that this may not be the case on all machines.
*/

#include "std_lib_facilities.h"

void stack_direction(int a) {
	if (a == 5)
		return;
	cout << "Local variable address in stack " << a << ": " << &a << '\n';
	stack_direction(a + 1);
}

int main()

try {
	stack_direction(1);

	int* a{ new int{ 1 } };
	int* b{ new int{ 2 } };
	cout 
		<< "a address: " << a << '\n'
		<< "b address: " << b << '\n';
}
catch (exception& e) {
	cerr << "Exception: " << e.what() << '\n';
	return 1;
}
catch (...) {
	cerr << "Unknown exception" << '\n';
	return 1;
}