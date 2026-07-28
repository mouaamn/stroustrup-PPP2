#ifndef COUNTED_PTR
#define COUNTED_PTR

#include "std_lib_facilities.h"

namespace DT {

	template<typename T>
	class Counted_ptr {
	public:
		Counted_ptr();
		explicit Counted_ptr(const T& val);

		Counted_ptr(const Counted_ptr& arg);
		Counted_ptr& operator=(const Counted_ptr& arg);

		~Counted_ptr();

		T& operator*();
		T* operator->();
	private:
		T* p_;
		ptrdiff_t* use_count_;
	};

	template<typename T>
	Counted_ptr<T>::Counted_ptr()
		: p_{ new T{} },
		use_count_{ new ptrdiff_t{ 1 } }
	{}

	template<typename T>
	Counted_ptr<T>::Counted_ptr(const T& val)
		: p_{ new T{ val } },
		use_count_{ new ptrdiff_t{ 1 } }
	{}

	template<typename T>
	Counted_ptr<T>::Counted_ptr(const Counted_ptr& arg)
		: p_{ arg.p_ },
		use_count_{ arg.use_count_ }
	{
		++(*use_count_);
	}

	template<typename T>
	Counted_ptr<T>& Counted_ptr<T>::operator=(const Counted_ptr& arg) {
		if (&arg == this) return *this;
		if (--(*use_count_) <= 0) {
			delete p_;
			delete use_count_;
		}
		p_ = arg.p_;
		use_count_ = arg.use_count_;
		++(*use_count_);
		return *this;
	}

	template<typename T>
	Counted_ptr<T>::~Counted_ptr() {
		if (--(*use_count_) <= 0) {
			delete p_;
			delete use_count_;
		}
	}

	template<typename T>
	T& Counted_ptr<T>::operator*() {
		return *p_;
	}

	template<typename T>
	T* Counted_ptr<T>::operator->() {
		return p_;
	}
}

#endif