#ifndef PATRON
#define PATRON

#include "std_lib_facilities.h"

namespace Library {

	class Patron {
	public:
		class Invalid{};

		Patron(string name, string card_number);

		// modifying
		void set_fee(int fee);

		// non-modifying
		string name() const { return name_; }
		string card_number() const { return card_number_; }
		int fee() const { return fee_; }
	private:
		string name_;
		string card_number_;
		int fee_{};
	};

	// helpers
	bool owes_fee(const Patron& p);
	bool is_card_number(string card_number);

	bool operator==(const Patron& a, const Patron& b);
	bool operator!=(const Patron& a, const Patron& b);
}

#endif