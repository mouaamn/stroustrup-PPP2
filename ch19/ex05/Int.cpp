#include "Int.h"

namespace DT {

	Int::Int()
		: value_{ int{} }
	{}

	Int::Int(int value)
		: value_{ value }
	{}

	Int::Int(const Int& i)
		: value_{ i.value_ }
	{}

	Int& Int::operator=(const Int& i) {
		value_ = i.value_;
		return *this;
	}

	int& Int::get() {
		return value_;
	}

	int Int::get() const {
		return value_;
	}

	Int operator+(const Int& l, const Int& r) {
		return Int{ l.get() + r.get() };
	}

	Int operator-(const Int& l, const Int& r) {
		return Int{ l.get() - r.get() };
	}

	Int operator*(const Int& l, const Int& r) {
		return Int{ l.get() * r.get() };
	}

	Int operator/(const Int& l, const Int& r) {
		if (r.get() == 0)
			error("Division by zero");
		return Int{ l.get() / r.get() };
	}

	ostream& operator<<(ostream& os, const Int& i) {
		return os << i.get();
	}

	istream& operator>>(istream& is, Int& i) {
		return is >> i.get();
	}
}