#include "std_lib_facilities.h"
#include "Book.h"
#include "LibrarySystem.h"
#include "Date.h"

int main()

try {

}
catch (Chrono::Date::Invalid) {
	cerr << "Invalid Date" << '\n';
	return 1;
}
catch (Library::Book::Invalid) {
	cerr << "Invalid Book" << '\n';
	return 1;
}
catch (Library::Patron::Invalid) {
	cerr << "Invalid Patron" << '\n';
	return 1;
}
catch (exception& e) {
	cerr << "Exception: " << e.what() << '\n';
	return 1;
}
catch (...) {
	cerr << "Unknown exception" << '\n';
	return 1;
}