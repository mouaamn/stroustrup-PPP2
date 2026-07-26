#ifndef INT
#define INT

#include "std_lib_facilities.h"

namespace DT {

	class Int {
	public:
		Int();
		explicit Int(int value);
		Int(const Int& i);

		Int& operator=(const Int& i);

		int& get();
		int get() const;
	private:
		int value_;
	};

	Int operator+(const Int& l, const Int& r);
	Int operator-(const Int& l, const Int& r);
	Int operator*(const Int& l, const Int& r);
	Int operator/(const Int& l, const Int& r);

	ostream& operator<<(ostream& os, const Int& i);
	istream& operator>>(istream& is, Int& i);
}

#endif