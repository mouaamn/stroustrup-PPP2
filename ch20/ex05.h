#ifndef VECTOR
#define VECTOR

#include "std_lib_facilities.h"

namespace DT {

	template<typename T>
	class vector {
	public:
		using value_type = T;
		using size_type = size_t;
		using iterator = value_type*;
		using const_iterator = const iterator;

		vector();
		explicit vector(size_type n, const value_type val = value_type());
		vector(initializer_list<value_type> ls);

		vector(const vector& arg);
		vector(vector&& arg);

		~vector();

		vector& operator=(const vector& arg);
		vector& operator=(vector&& arg);

		value_type& operator[](size_type i);
		const value_type& operator[](size_type i) const;

		value_type& at(size_type i);
		const value_type& at(size_type i) const;

		void reserve(size_type newalloc);
		void push_back(const value_type& val);
		void resize(size_type newsize, const value_type val = value_type());

		iterator begin();
		const_iterator begin() const;

		iterator end();
		const const_iterator end() const;

		size_type size() const;
		size_type capacity() const;
	private:
		iterator elem;
		size_type sz;
		size_type space;
	};


	template<typename T>
	vector<T>::vector()
		: elem{ nullptr }, sz{ 0 }, space{ 0 }
	{}

	template<typename T>
	vector<T>::vector(size_type n, const value_type val)
		: elem{ new value_type[n] }, sz{ n }, space{ n }
	{
		for (size_type i{}; i < n; ++i)
			elem[i] = val;
	}

	template<typename T>
	vector<T>::vector(initializer_list<value_type> ls)
		: elem{ new value_type[ls.size()] }, sz{ ls.size() }, space{ ls.size() }
	{
		for (size_type i{}; i < ls.size(); ++i)
			elem[i] = *(ls.begin() + i);
	}

	template<typename T>
	vector<T>::vector(const vector& arg)
		: elem{ new value_type[arg.space] }, sz{ arg.sz }, space{ arg.space }
	{
		for (size_type i{}; i < arg.size(); ++i)
			elem[i] = arg[i];
	}

	template<typename T>
	vector<T>::vector(vector&& arg)
		: elem{ arg.elem }, sz{ arg.sz }, space{ arg.space }
	{
		arg.elem = nullptr;
		arg.sz = arg.space = 0;
	}

	template<typename T>
	vector<T>::~vector() {
		delete[] elem;
		sz = space = 0;
	}

	template<typename T>
	vector<T>& vector<T>::operator=(const vector& arg) {
		if (this == &arg) return *this;
		delete[] elem;
		elem = new value_type[arg.space];
		sz = arg.sz;
		space = arg.space;
		for (size_type i{}; i < arg.sz; ++i)
			elem[i] = arg.elem[i];
		return *this;
	}

	template<typename T>
	vector<T>& vector<T>::operator=(vector&& arg) {
		if (this == &arg) return *this;
		delete[] elem;
		elem = arg.elem;
		sz = arg.sz;
		space = arg.space;
		arg.elem = nullptr;
		arg.sz = arg.space = 0;
		return *this;
	}

	template<typename T>
	typename vector<T>::value_type& vector<T>::operator[](size_type i) {
		return elem[i];
	}

	template<typename T>
	const typename vector<T>::value_type& vector<T>::operator[](size_type i) const {
		return elem[i];
	}

	template<typename T>
	typename vector<T>::value_type& vector<T>::at(size_type i) {
		if (i < 0 || i >= sz) throw out_of_range{ "VECTOR, OUT-OF-RANGE ACCESS" };
		return elem[i];
	}

	template<typename T>
	const typename vector<T>::value_type& vector<T>::at(size_type i) const {
		if (i < 0 || i >= sz) throw out_of_range{ "VECTOR, OUT-OF-RANGE ACCESS" };
		return elem[i];
	}

	template<typename T>
	void vector<T>::reserve(size_type newalloc) {
		if (newalloc <= space) return;
		value_type* p{ new value_type[newalloc] };
		for (size_type i{}; i < sz; ++i)
			p[i] = elem[i];
		delete[] elem;
		elem = p;
		space = newalloc;
	}

	template<typename T>
	void  vector<T>::push_back(const value_type& val) {
		if (space == 0)
			reserve(8);
		else if (sz == space)
			reserve(space * 2);
		elem[sz] = val;
		++sz;
	}

	template<typename T>
	void vector<T>::resize(size_type newsize, const value_type val) {
		reserve(newsize);
		for (size_type i{ sz }; i < newsize; ++i)
			elem[i] = val;
		sz = newsize;
	}

	template<typename T>
	typename vector<T>::iterator vector<T>::begin() {
		return elem;
	}

	template<typename T>
	typename vector<T>::const_iterator vector<T>::begin() const {
		return elem;
	}

	template<typename T>
	typename vector<T>::iterator vector<T>::end() {
		return elem + sz;
	}

	template<typename T>
	const typename vector<T>::const_iterator vector<T>::end() const {
		return elem + sz;
	}

	template<typename T>
	typename vector<T>::size_type vector<T>::size() const { return sz; }

	template<typename T>
	typename vector<T>::size_type vector<T>::capacity() const { return space; }

	// helpers
	
	template<typename T>
	ostream& operator<<(ostream& os, const vector<T>& arg) {
		os << "{ ";
		for (typename vector<T>::size_type i{}; i < arg.size(); ++i) {
			os << arg[i];
			if (i != arg.size() - 1)
				os << ", ";
		}
		return os << " }";
	}

	template<typename T>
	istream& operator>>(istream& is, vector<T>& arg) {
		for (typename vector<T>::value_type val; is >> val;)
			arg.push_back(val);
		return is;
	}
}

#endif