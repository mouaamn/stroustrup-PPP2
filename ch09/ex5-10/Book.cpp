#include "Book.h"

namespace Library {

	Book::Book(string isbn, string title, string author, Genre genre, Chrono::Date copyright_date)
		: isbn_{ isbn }, title_{ title }, author_{ author }, genre_{ genre }, copyright_date_{copyright_date}
	{
		if (!is_isbn(isbn) || !is_genre(genre))
			throw Invalid{};
	}

	bool is_isbn(string isbn) {
		for (int i{}; i < isbn.size(); ++i)
			if (!isdigit(isbn[i]) && isbn[i] != '-')
				return false;
		return true;
	}

	bool is_genre(Genre genre) {
		return !(genre < Genre::fiction || genre > Genre::children);
	}

	bool operator==(const Book& a, const Book& b) {
		return (a.isbn() == b.isbn());
	}

	bool operator!=(const Book& a, const Book& b) {
		return !(a == b);
	}

	ostream& operator<<(ostream& os, const Book& a) {
		return os
			<< "Title:\t" << a.title() << '\n'
			<< "Author:\t" << a.author() << '\n'
			<< "ISBN:\t" << a.isbn();
	}
}