#include "Punct_stream.h"

Punct_stream::Punct_stream(istream& is)
	: source{ is }, sensitive{ true }
{}

bool Punct_stream::is_whitespace(char c) const {
	for (char w : white)
		if (c == w)
			return true;
	return false;
}

Punct_stream& Punct_stream::operator>>(string& s) {

	while (!(buffer >> s)) {
		if (buffer.bad() || !source.good())
			return *this;
		buffer.clear();

		string line;
		getline(source, line);

		for (int i{}; i < line.size(); ++i)
			if (line[i] == '"')
				skip_until(line, i, '"');
			else if (is_whitespace(line[i]))
				line[i] = ' ';
			else if (!sensitive)
				line[i] = tolower(line[i]);

		buffer.str(line);
	}
	return *this;
}

Punct_stream::operator bool() {
	return (buffer && source);
}

void skip_until(string s, int& index, char terminator) {
	while (++index, index < s.size() && s[index] != terminator);
}