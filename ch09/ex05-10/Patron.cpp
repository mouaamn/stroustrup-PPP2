#include "Patron.h"

namespace Library {

	Patron::Patron(string name, string card_number)
		: name_{ name }, card_number_{ card_number }
	{
		if (!is_card_number(card_number))
			throw Invalid{};
	}

	void Patron::set_fee(int fee) {
		fee_ = fee;
	}

	bool owes_fee(const Patron& p) {
		return static_cast<bool>(p.fee());
	}

	bool is_card_number(string card_number) {
		for (int i{}; i < card_number.size(); ++i)
			if (!isdigit(card_number[i]))
				return false;
		return true;
	}

	bool operator==(const Patron& a, const Patron& b) {
		return (a.card_number() == b.card_number());
	}

	bool operator!=(const Patron& a, const Patron& b) {
		return !(a == b);
	}
}