#ifndef UNIQUE_PTR
#define UNIQUE_PTR

#include "std_lib_facilities.h"

namespace DT {

	template<typename T>
	struct Default_delete {
		void operator()(T* p) {
			delete p;
		}
	};

	template<typename T, typename Deleter = Default_delete<T>>
	class Unique_ptr {
	public:
		Unique_ptr();
		Unique_ptr(T* p);

		// allow move operations
		Unique_ptr(Unique_ptr&& arg);
		Unique_ptr& operator=(Unique_ptr&& arg);

		// disallow copy operations
		Unique_ptr(const Unique_ptr& arg) = delete;
		Unique_ptr& operator=(const Unique_ptr& arg) = delete;

		~Unique_ptr();

		T* operator->();
		T& operator*();

		T* release();
	private:
		T* p_;
		Deleter deleter_;
	};

	template<typename T, typename Deleter>
	Unique_ptr<T, Deleter>::Unique_ptr()
		: p_{ nullptr }
	{}

	template<typename T, typename Deleter>
	Unique_ptr<T, Deleter>::Unique_ptr(T* p)
		: p_{ p }
	{}

	template<typename T, typename Deleter>
	Unique_ptr<T, Deleter>::Unique_ptr(Unique_ptr&& arg)
		: p_{ arg.p_ },
		deleter_{ move(arg.deleter_) }
	{
		arg.p_ = nullptr;
	}

	template<typename T, typename Deleter>
	Unique_ptr<T, Deleter>& Unique_ptr<T, Deleter>::operator=(Unique_ptr&& arg) {
		if (&arg == this) return *this;
		deleter_(p_);
		p_ = arg.p_;
		deleter_ = arg.deleter_;
		arg.p_ = nullptr;
		return *this;
	}

	template<typename T, typename Deleter>
	Unique_ptr<T, Deleter>::~Unique_ptr() {
		deleter_(p_);
	}

	template<typename T, typename Deleter>
	T* Unique_ptr<T, Deleter>::operator->() {
		if (p_ == nullptr)
			error("Accessing a nullptr");
		return p_;
	}

	template<typename T, typename Deleter>
	T& Unique_ptr<T, Deleter>::operator*() {
		if (p_ == nullptr)
			error("Dereferencing a nullptr");
		return *p_;
	}

	template<typename T, typename Deleter>
	T* Unique_ptr<T, Deleter>::release() {
		T* p{ p_ };
		p_ = nullptr;
		return p;
	}
}

#endif