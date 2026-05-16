/*
	Sentence:
		Noun Verb "."
		Article Noun Verb "."
		Sentence Conjunction Sentence "."
	Article:
		"the"
	Conjunction:
		"and"
		"or"
		"but"
	Noun:
		"birds"
		"fish"
		"C++"
	Verb:
		"rules"
		"fly"
		"swim"
*/

#include "std_lib_facilities.h"

class Word_stream {
public:
	string get();
	void putback(const string& w);
private:
	bool full{ false };
	string buffer;
};

string Word_stream::get() {
	if (full) {
		full = false;
		return buffer;
	}

	string word;
	cin >> word;
	if (!cin)
		error("Bad input");
	return word;
}

void Word_stream::putback(const string& w) {
	if (full)
		error("putback in already full buffer");

	full = true;
	buffer = w;
}

// had to name it wss instead of ws because it collides with std::ws
Word_stream wss;

bool conjunctionn();
bool noun();
bool verb();

bool sentence() {
	if (!noun())
		return false;

	if (!verb())
		return false;

	string word{ wss.get() };
	if (word == ".")
		return true;
	wss.putback(word);

	if (!conjunctionn())
		return false;
	
	return sentence();
}

// had to name it conjunctionn instead of conjunction because it collides with std::conjunction
bool conjunctionn() {
	string word{ wss.get() };
	if (word == "and" || word == "or" || word == "but")
		return true;
	return false;
}

bool noun() {
	string word{ wss.get() };
	if (word == "the")
		return noun();
	if (word == "birds" || word == "fish" || word == "C++")
		return true;
	return false;
}

bool verb() {
	string word{ wss.get() };
	if (word == "rules" || word == "fly" || word == "swim")
		return true;
	return false;
}

int main()

try {
	
	cout << (sentence() ? "OK" : "not OK") << '\n';
}
catch (exception& e) {
	cerr << "Exception: " << e.what() << '\n';
	return 1;
}
catch (...) {
	cerr << "Unknown exception" << '\n';
	return 1;
}