/*
	Expression:
		Term
		Expression "+" Term
		Expression "-" Term
	Term:
		Primary
		Term "*" Primary
		Term "/" Primary
	Factorial:
		Number "!"
	Primary:
		Number
		"(" Expression ")"
		"{" Expression "}"
	Number:
		floating-point-literal
*/

#include "std_lib_facilities.h"

class Token {
public:
	char kind;
	double value;
};

class Token_stream {
public:
	Token get();
	void putback(Token t);
private:
	bool full{ false };
	Token buffer;
};

Token Token_stream::get() {
	if (full) {
		full = false;
		return buffer;
	}

	char ch;
	cin >> ch;

	switch (ch) {
	case 'q':
	case ';':
	case '(': case ')': case '{': case '}':
	case '!': case '+': case '-': case '*': case '/':
		return Token{ ch };
	case '.':
	case '0': case '1': case '2': case '3': case '4':
	case '6': case '5': case '7': case '8': case '9': {
		cin.putback(ch);
		double num;
		cin >> num;
		return Token{ '8', num };
	}
	default:
		error("Bad token");
	}
}

void Token_stream::putback(Token t) {
	if (full)
		error("putback in already full buffer");
	buffer = t;
	full = true;
}

Token_stream ts;

double term();
double primary();
double factorial();

double expression() {
	double left{ term() };
	Token t{ ts.get() };

	while (true) {
		switch (t.kind) {
		case '+':
			left += term();
			t = ts.get();
			break;
		case '-':
			left -= term();
			t = ts.get();
			break;
		default:
			ts.putback(t);
			return left;
		}
	}
}

double term() {
	double left{ factorial() };
	Token t{ ts.get() };

	while (true) {
		switch (t.kind) {
		case '*':
			left *= factorial();
			t = ts.get();
			break;
		case '/': {
			double right{ factorial() };
			if (right == 0)
				error("Division by zero");
			left /= right;
			t = ts.get();
			break;
		}
		default:
			ts.putback(t);
			return left;
		}
	}
}

double factorial() {
	double left{ primary() };
	Token t{ ts.get() };

	while (true) {
		switch (t.kind) {
		case '!':
			if (left < 0)
				error("Negative factorial");
			if (left == 0)
				left = 1;
			for (int i{ static_cast<int>(left) - 1 }; i > 0; --i)
				left *= i;
			t = ts.get();
			break;
		default:
			ts.putback(t);
			return left;
		}
	}
}

double primary() {
	Token t{ ts.get() };

	switch (t.kind) {
	case '(': {
		double d{ expression() };
		t = ts.get();
		if (t.kind != ')')
			error(") expected");
		return d;
	}
	case '{': {
		double d{ expression() };
		t = ts.get();
		if (t.kind != '}')
			error("} expected");
		return d;
	}
	case '8':
		return t.value;
	}
}

int main()

try {

	for (double val{}; cin;) {
		Token t{ ts.get() };

		if (t.kind == 'q')
			return 0;
		if (t.kind == ';')
			cout << "= " << val << '\n';
		else
			ts.putback(t);

		val = expression();
	}
}
catch (exception& e) {
	cerr << "Exception: " << e.what() << '\n';
	return 1;
}
catch (...) {
	cerr << "Unknown exception" << '\n';
	return 1;
}