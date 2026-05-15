#include "std_lib_facilities.h"

constexpr char ROCK{ 'r' };
constexpr char PAPER{ 'p' };
constexpr char SCISSORS{ 's' };

char get_answer() {
	cout << "Enter Rock(r)/Paper(p)/Scissors(s): ";
	char c{};
	cin >> c;

	c = tolower(c);

	switch (c) {
	case ROCK: case PAPER: case SCISSORS:
		return c;
	default:
		error("Invalid answer")
	}
}

int get_seed() {
	cout << "Enter a seed: ";
	int seed{};
	cin >> seed;
	return (seed + 10);
}

vector<char> apply_seed(int seed) {
	vector<char> next_value;
	if (seed % 2)
		next_value.push_back(SCISSORS);
	else
		next_value.push_back(ROCK);
	if (seed / 2 > 5)
		next_value.push_back(ROCK);
	else
		next_value.push_back(PAPER);
	if (seed < -1)
		next_value.push_back(SCISSORS);
	else
		next_value.push_back(PAPER);
	return next_value;
}

bool is_player_winner(char player, char machine) {
	return
		(player == machine ? false : false) ||	// tie
		(player == ROCK && machine == SCISSORS ? true : false) ||
		(player == SCISSORS && machine == PAPER ? true : false) ||
		(player == PAPER && machine == ROCK ? true : false);
}

int main()

try {
	const vector<char> NEXT_VALUE{ apply_seed(get_seed()) };

	for (int i{}; i < NEXT_VALUE.size(); ++i) {
		cout << '\n';

		char a{ get_answer() };

		if (is_player_winner(a, NEXT_VALUE[i]))
			cout << "Player wins" << '\n';
		else
			if (a == NEXT_VALUE[i])
				cout << "Tie" << '\n';
			else
				cout << "Machine wins" << '\n';
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