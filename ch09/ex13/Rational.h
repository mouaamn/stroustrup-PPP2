#ifndef RATIONAL
#define RATIONAL

namespace Number {

	class Rational {
	public:
		class Invalid {};

		Rational(int numerator, int denominator);
		Rational();

		// non-modifying
		int numerator() const { return numerator_; };
		int denominator() const { return denominator_; }
		operator double() const { return static_cast<double>(numerator_) / denominator_; };
	private:
		int numerator_;
		int denominator_;
	};

	// helpers
	Rational operator+(const Rational& a, const Rational& b);
	Rational operator-(const Rational& a, const Rational& b);

	Rational operator*(const Rational& a, const Rational& b);
	Rational operator/(const Rational& a, const Rational& b);

	bool operator==(const Rational& a, const Rational& b);
	bool operator!=(const Rational& a, const Rational& b);
}

#endif