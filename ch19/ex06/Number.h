#ifndef NUMBER
#define NUMBER

#include "std_lib_facilities.h"

namespace DT {

	template<typename T> // requires Number<T>()
	class Number {
	public:
		Number();
		explicit Number(const T& value);
		Number(const Number& n);

		Number& operator=(const Number& n);

		T& get();
		const T& get() const;
	private:
		T value_;
	};

	template<typename T>
	Number<T>::Number()
		: value_{ T() }
	{}

	template<typename T>
	Number<T>::Number(const T& value)
		: value_{ value }
	{}

	template<typename T>
	Number<T>::Number(const Number& n)
		: value_{ n.value_ }
	{}

	template<typename T>
	Number<T>& Number<T>::operator=(const Number& n) {
		value_ = n.value_;
		return *this;
	}

	template<typename T>
	T& Number<T>::get() {
		return value_;
	}

	template<typename T>
	const T& Number<T>::get() const {
		return value_;
	}

	// helpers
	template<typename T, typename U>
	Number<common_type_t<T, U>> operator+(const Number<T>& l, const Number<U>& r) {
		return Number<common_type_t<T, U>>{ l.get() + r.get() };
	}

	template<typename T, typename U>
	Number<common_type_t<T, U>> operator-(const Number<T>& l, const Number<U>& r) {
		return Number<common_type_t<T, U>>{ l.get() - r.get() };
	}

	template<typename T, typename U>
	Number<common_type_t<T, U>> operator*(const Number<T>& l, const Number<U>& r) {
		return Number<common_type_t<T, U>>{ l.get() * r.get() };
	}

	template<typename T, typename U>
	Number<common_type_t<T, U>> operator/(const Number<T>& l, const Number<U>& r) {
		if (r.get() == 0)
			error("Division by zero");
		return Number<common_type_t<T, U>>{ l.get() / r.get() };
	}

	template<typename T, typename U>
	Number<common_type_t<T, U>> operator%(const Number<T>& l, const Number<U>& r) {
		if (r.get() == 0)
			error("Division by zero");
		return Number<common_type_t<T, U>>{ fmod(l.get(), r.get()) };
	}

	template<typename T>
	ostream& operator<<(ostream& os, const Number<T>& n) {
		return os << n.get();
	}

	template<typename T>
	istream& operator>>(istream& is, Number<T>& n) {
		return is >> n.get();
	}
}

#endif
