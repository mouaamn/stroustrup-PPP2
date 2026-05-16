#ifndef LIBRARYSYSTEM
#define LIBRARYSYSTEM

#include "Patron.h"
#include "Book.h"
#include "Date.h"

namespace Library {

	struct Transaction {
		Book book;
		Patron patron;
		Chrono::Date date;
	};

	class LibrarySystem {
	public:
		// modifying
		void add_book(const Book& book);
		void add_patron(const Patron& patron);
		void check_out(const Patron& patron, Book& book);

		// non-modifying
		bool book_exist(const Book& book) const;
		bool patron_exist(const Patron& patron) const;
		vector<string> patrons_with_fee() const;
	private:
		vector<Book> books_;
		vector<Patron> patrons_;
		vector<Transaction> transactions_;
	};
}

#endif