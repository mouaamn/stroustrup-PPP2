/*
	Simple claculator

	This program implements a basic expression calculator.


	Calculation:
		Statement
		Quit
		Print
		Help
		Statement Calculation
	Print:
		"\n"
		";"
	Quit:
		"quit"
	Help:
		"help"
	Statement:
		Declaration
		Expression
	Declaration:
		"let" Name "=" Expression
		"let" const Name "=" Expression
	Expression:
		Term
		Expression "+" Term
		Expression "-" Term
	Term:
		Primary
		Term "*" Primary
		Term "/" Primary
	Primary:
		Name
		Assignment
		Number
		"(" Expression ")"
		"-" Primary
		"+" Primary
	Number:
		floating-point-literal
	Name:
		^[a-zA-Z_][a-zA-Z0-9_]*$	// regular expressions (regex)
	Assignment:
		Name "=" Expression

	Input comes from cin through the Token_stream ts.
*/

#include "std_lib_facilities.h"

//--------------------------------------------------------------------

constexpr char NUMBER{ '8' };
constexpr char QUIT{ 'q' };
constexpr char PRINT{ ';' };
constexpr char HELP{ 'h' };
constexpr char NAME{ 'a' };
constexpr char LET{ 'l' };
constexpr char CONST{ 'c' };
const string DECL_KEY{ "let" };
const string CONST_KEY{ "const" };
const string HELP_KEY{ "help" };
const string QUIT_KEY{ "quit" };
const string PROMPT{ "> " };
const string RESULT{ "= " };

//--------------------------------------------------------------------

class Token {
public:
	char kind{};
	double value{};
	string name{};
	
	Token() {}

	Token(char k)
		: kind{ k }
	{}

	Token(char k, double val)
		: kind{ k }, value{ val }
	{}

	Token(char k, const string& n)
		: kind{ k }, name{ n }
	{}
};

class Variable {
public:
	string name;
	double value;
	bool constant;
};

class Token_stream {
public:
	Token get();
	void putback(Token t);
	void ignore(char c);
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
	while (cin.get(ch) && isspace(ch))
		if (ch == '\n')
			break;
	if (!cin)
		error("Bad input");

	switch (ch) {
	case '\n':
		return Token{ PRINT };
	case PRINT:
	case '=':
	case '(':
	case ')':
	case '+':
	case '-':
	case '*':
	case '/':
	case '%':
		return Token{ ch };
	case '.':	// a floating-point-literal can start with a dot	
	case '0': case '1': case '2': case '3': case '4':
	case '5': case '6': case '7': case '8': case '9': {
		cin.putback(ch);
		double num;
		cin >> num;
		return Token{ NUMBER, num };
	}
	default:
		if (isalpha(ch) || ch == '_') {	// a NAME starts with an alphabet or underscore
			cin.putback(ch);
			string s;
			while (cin.get(ch) && (isalpha(ch) || isdigit(ch) || ch == '_'))
				s += ch;
			cin.putback(ch);
			if (s == DECL_KEY)
				return Token{ LET };
			if (s == CONST_KEY)
				return Token{ CONST };
			if (s == HELP_KEY)
				return Token{ HELP };
			if (s == QUIT_KEY)
				return Token{ QUIT };
			return Token{ NAME, s };
		}
		error("Bad token");
	}
}

void Token_stream::ignore(char c) {

	if (full && buffer.kind == c) {
		full = false;
		return;
	}
	full = false;

	for (char ch; cin >> ch;)
		if (ch == c)
			return;
}

void Token_stream::putback(Token t) {
	if (full)
		error("putback in already full buffer");
	buffer = t;
	full = true;
}


class Symbol_table {
public:
	double get(const string& s);
	double set(const string& s, double d);
	bool is_declared(const string& s);
	double declare(const string& s, double d, bool b);
private:
	vector<Variable> var_table;
};

double Symbol_table::get(const string& s) {
	for (const Variable& v : var_table)
		if (v.name == s)
			return v.value;
	error("Undefined variable: ", s);
}

double Symbol_table::set(const string& s, double d) {
	for (Variable& v : var_table)
		if (v.name == s) {
			if (v.constant)
				error("Constant variable: ", s);
			v.value = d;
			return d;
		}
	error("Undefined variable: ", s);
}

bool Symbol_table::is_declared(const string& s) {
	for (const Variable& v : var_table)
		if (v.name == s)
			return true;
	return false;
}

double Symbol_table::declare(const string& s, double d, bool b) {
	if (is_declared(s))
		error("Declared twice: ", s);
	var_table.push_back(Variable{ s, d, b });
	return d;
}

//--------------------------------------------------------------------
// globals
Token_stream ts;
Symbol_table st{};

//--------------------------------------------------------------------

double expression();

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
	case NUMBER:
		return t.value;
	case NAME: {
		Token t2{ ts.get() };
		if (t2.kind != '=') {
			ts.putback(t2);
			return st.get(t.name);
		}
		return st.set(t.name, expression());
	}
	case '-':
		return -primary();
	case '+':
		return primary();
	default:
		error("Primary expected");
	}
}

double term() {
	double left{ primary() };
	Token t{ ts.get() };

	while (true) {
		switch (t.kind) {
		case '*':
			left *= primary();
			t = ts.get();
			break;
		case '/': {
			double right{ primary() };
			if (right == 0)
				error("Division by zero");
			left /= right;
			t = ts.get();
			break;
		}
		case '%': {
			double right{ primary() };
			if (right == 0)
				error("Division by zero");
			left = fmod(left, right);
			t = ts.get();
			break;
		}
		default:
			ts.putback(t);
			return left;
		}
	}
}

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

double declaration() {
	Token t{ ts.get() };

	bool constant{ false };

	if (t.kind == CONST) {
		constant = true;
		t = ts.get();
	}

	if (t.kind != NAME)
		error("Name expected");
	const string var_name{ t.name };

	t = ts.get();
	if (t.kind != '=')
		error("= expected");

	return st.declare(var_name, expression(), constant);
}

double statement() {
	Token t{ ts.get() };
	switch (t.kind) {
	case LET:
		return declaration();
	default:
		ts.putback(t);
		return expression();
	}
}

void clean_up_mess() {
	ts.ignore(';');
}

void help() {
	cout
		<< "--------HELP--------" << '\n'
		<< "Supported operators:\n    + - * / %" << '\n'
		<< "Variable declaration:\n    let Name = Expression;\n    let const Name = Expression;" << '\n'
		<< "To print result:\n    press 'enter' or end an expression with ';'" << '\n'
		<< "To quit:\n    type 'quit'" << '\n'
		<< "--------------------" << '\n';
}

void calculate() {

	while (cin)

		try {
			cout << PROMPT;

			Token t{ ts.get() };
			while (t.kind == PRINT) t = ts.get();	// removes repeated PRINT
			if (t.kind == QUIT)
				return;
			if (t.kind == HELP) {
				help();
				continue;
			}
			ts.putback(t);

			cout << RESULT << statement() << '\n';
		}
		catch (exception& e) {
			cerr << e.what() << '\n';
			clean_up_mess();
		}
}

//--------------------------------------------------------------------

int main()

try {
	// predefined names
	st.declare("PI", 3.1415926535897932384626433832795, true);
	st.declare("e", 2.7182818284590452353602874713527, true);

	calculate();
}
catch (exception& e) {
	cerr << "Exception: " << e.what() << '\n';
	return 1;
}
catch (...) {
	cerr << "Unknown exception" << '\n';
	return 1;
}