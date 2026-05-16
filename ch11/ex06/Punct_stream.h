#ifndef PUNCT_STREAM
#define PUNCT_STREAM

#include "std_lib_facilities.h"

class Punct_stream {
public:
	Punct_stream(istream& is);

	// modifying
	void whitespace(string s) { white = s; }
	void add_white(char c) { white += c; }
	void case_sensitive(bool b) { sensitive = b; }

	// non-modifying
	bool is_case_sensitive() const { return sensitive; }
	bool is_whitespace(char c) const;

	Punct_stream& operator>>(string& s);
	operator bool();
private:
	istream& source;
	istringstream buffer;
	string white;
	bool sensitive;
};

void skip_until(string s, int& index, char terminator);

#endif