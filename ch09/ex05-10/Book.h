#ifndef BOOK
#define BOOK

#include "std_lib_facilities.h"
#include "Date.h"

namespace Library {

	enum class Genre {
		fiction, nonfiction, periodical, biography, children
	};

	class Book {
	public:
		class Invalid{};

		Book(string isbn, string title, string author, Genre genre, Chrono::Date copyright_date);

		// modifying
		void check_in() { checked_out_ = false; };
		void check_out() { checked_out_ = true; };

		// non-modifying
		string isbn() const { return isbn_; };
		string title() const { return title_; }
		string author() const { return author_; }
		Genre genre() const { return genre_; }
		Chrono::Date copyright_date() const { return copyright_date_; };
		bool checked_out() const { return checked_out_; }
	private:
		string isbn_;
		string title_;
		string author_;
		Chrono::Date copyright_date_;
		bool checked_out_{ false };
		Genre genre_;
	};

	// helpers
	bool is_isbn(string isbn);
	bool is_genre(Genre genre);

	bool operator==(const Book& a, const Book& b);
	bool operator!=(const Book& a, const Book& b);

	ostream& operator<<(ostream& os, const Book& a);
}

#endif