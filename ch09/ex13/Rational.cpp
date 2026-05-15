#include "Rational.h"

namespace Number {

	Rational::Rational(int numerator, int denominator)
		: numerator_{ numerator }, denominator_{ denominator }
	{
		if (denominator == 0)
			throw Invalid{};
	}

	const Rational& default_rational() {
		static const Rational RATIONALL{ 1, 1 };
		return RATIONALL;
	}

	Rational::Rational()
		: numerator_{ default_rational().numerator() },
		denominator_{ default_rational().denominator() }
	{}

	Rational operator+(const Rational& a, const Rational& b) {
		return Rational{ 
			(a.numerator() * b.denominator()) + (b.numerator() * a.denominator()), 
			a.denominator() * b.denominator()
		};
	}

	Rational operator-(const Rational& a, const Rational& b) {
		return Rational{
			(a.numerator() * b.denominator()) - (b.numerator() * a.denominator()),
			a.denominator() * b.denominator()
		};
	}

	Rational operator*(const Rational& a, const Rational& b) {
		return Rational{
			a.numerator() * b.numerator(),
			a.denominator() * b.denominator()
		};
	}

	Rational operator/(const Rational& a, const Rational& b) {
		return Rational{
			a.numerator() * b.denominator(),
			a.denominator() * b.numerator()
		};
	}

	bool operator==(const Rational& a, const Rational& b) {
		return (a.numerator() == b.numerator() && a.denominator() == b.denominator());
	}

	bool operator!=(const Rational& a, const Rational& b) {
		return !(a == b);
	}
}