#include "LibrarySystem.h"

namespace Library {

	void LibrarySystem::add_book(const Book& book) {
		if (book_exist(book))
			throw runtime_error{ "Book already exist" };
		books_.push_back(book);
	}

	void LibrarySystem::add_patron(const Patron& patron) {
		if (patron_exist(patron))
			throw runtime_error{ "Patron already exist" };
		patrons_.push_back(patron);
	}

	void LibrarySystem::check_out(const Patron& patron, Book& book) {
		if (!patron_exist(patron))
			throw runtime_error{ "Patron doesn't exist" };
		if (!book_exist(book))
			throw runtime_error{ "Book doesn't exist" };
		if (Library::owes_fee(patron))
			throw runtime_error{ "Patron owes fee" };

		book.check_out();
		Transaction transaction{ book, patron, Chrono::Date{} };
		transactions_.push_back(transaction);
	}

	bool LibrarySystem::book_exist(const Book& book) const {
		if (book.checked_out())
			return false;
		for (const Book& b : books_)
			if (b == book)
				return true;
		return false;
	}

	bool LibrarySystem::patron_exist(const Patron& patron) const {
		for (const Patron& p : patrons_)
			if (p == patron)
				return true;
		return false;
	}

	vector<string> LibrarySystem::patrons_with_fee() const {
		vector<string> names;
		for (const Patron& p : patrons_)
			if (owes_fee(p))
				names.push_back(p.name());
		return names;
	}
}