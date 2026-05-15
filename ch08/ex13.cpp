/*
	How many separate functions would you use for these tasks? 
	> Just three, and a fourth one that computes a Result by calling them.

	Why?
	> Because every function should do a single logical action.
*/

#include "std_lib_facilities.h"

struct Result {
	vector<int> lengths;
	string shortest;
	string longest;
	string lexi_first;
	string lexi_last;
};

vector<int> get_lengths(const vector<string>& v) {
	vector<int> lengths;
	for (const string& s : v)
		lengths.push_back(s.length());
	return lengths;
}

string shortest(const vector<string>& v)
// returns shortest string;
// pre-condition: v is not empty.
{
	if (v.size() == 0)
		error("empty vector");

	string shortest{ v[0] };
	for (int i{ 1 }; i < v.size(); ++i)
		if (v[i].length() < shortest.length())
			shortest = v[i];
	return shortest;
}

string longest(const vector<string>& v)
// returns longest string;
// pre-condition: v is not empty.
{
	if (v.size() == 0)
		error("empty vector");

	string longest{ v[0] };
	for (int i{ 1 }; i < v.size(); ++i)
		if (v[i].length() > longest.length())
			longest = v[i];
	return longest;
}

Result calculate(const vector<string>& v) {
	vector<string> copy_v{ v };
	sort(copy_v);

	return Result{ 
		get_lengths(v), shortest(v), longest(v), 
		copy_v[0], copy_v[copy_v.size() - 1] 
	};
}

int main()

try {
	const vector<string> v{ "Mouaamn", "Hadiq", "Aref" };

	Result result{ calculate(v) };
	cout
		<< "Not Applicable`" << '\n'
		<< "Longest: " << result.longest << '\n'
		<< "Shortest: " << result.shortest << '\n'
		<< "Lexi first: " << result.lexi_first << '\n'
		<< "Lexi last: " << result.lexi_last << '\n';
}
catch (exception& e) {
	cerr << "Exception: " << e.what() << '\n';
	return 1;
}
catch (...) {
	cerr << "Unknown exception" << '\n';
	return 1;
}