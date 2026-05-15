#include "std_lib_facilities.h"
#include "Punct_stream.h"

int main()

try {
	Punct_stream ps{ cin };
	ps.whitespace(".;,?-'");

	string content;
	for (string word; ps >> word;)
		content += word + ' ';

	cout << content;
}
catch (exception& e) {
	cerr << "Exception: " << e.what() << '\n';
	return 1;
}
catch (...) {
	cerr << "Unknown exception" << '\n';
	return 1;
}