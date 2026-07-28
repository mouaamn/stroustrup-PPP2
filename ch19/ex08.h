#ifndef ALLOCATOR
#define ALLOCATOR

#include <cstdlib>

namespace DT {

	template<typename T>
	struct Allocator {
		Allocator();

		T* allocate(size_t s);
		void deallocate(T* p, size_t s);
		void construct(T* p, const T& val);
		void destroy(T* p);
	};

	template<typename T>
	Allocator<T>::Allocator() {}

	template<typename T>
	T* Allocator<T>::allocate(size_t s) {
		return static_cast<T*>(malloc(sizeof(T) * s));
	}

	template<typename T>
	void Allocator<T>::deallocate(T* p, size_t) {
		free(p);
	}

	template<typename T>
	void Allocator<T>::construct(T* p, const T& val) {
		if (p == nullptr) return;
		new (p) T{ val }; // placement new
	}

	template<typename T>
	void Allocator<T>::destroy(T* p) {
		if (p == nullptr) return;
		p->~T(); // explicit destructor call
	}
}

#endif