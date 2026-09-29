/*
	What would we have to do if we couldn’t return end() to indicate “not found”?
	> I would return std::optional
*/

#include <optional>
#include "std_lib_facilities.h"

// had to rename it because it collided with std::count
template<typename InIt, typename T>
size_t countt(InIt first, InIt last, const T& val) {
	size_t c{};
	for (; first != last; ++first)
		if (*first == val)
			++c;
	return c;
}

// had to rename it because it collided with std::count_if
template<typename InIt, typename Pred>
size_t countt_if(InIt first, InIt last, Pred pred) {
	size_t c{};
	for (; first != last; ++first)
		if (pred(*first))
			++c;
	return c;
}

template<typename InIt, typename T>
optional<InIt> findd(InIt first, InIt last, const T& val) {
	for (; first != last; ++first)
		if (*first == val)
			return first;
	return {};
}

int main()

try {
	vector<size_t> v{ 1, 3, 3, 3, 5 };
	cout 
		<< countt(v.begin(), v.end(), 3) << '\n'
		<< countt_if(
			v.begin(), 
			v.end(), 
			[](size_t n) { return (n % 2) == 1; }) << '\n';
	auto p{ findd(v.begin(), v.end(), 5) };
	if (p)
		cout << "The number 5 was found" << '\n';
}
catch (exception& e) {
	cerr << "Exception: " << e.what() << '\n';
	return 1;
}
catch (...) {
	cerr << "Unknown exception" << '\n';
	return 1;
}