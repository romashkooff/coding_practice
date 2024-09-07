#include <iostream>
#include <string>
#include <fstream>

void text_statistics(std::fstream& input)
{
	std::string longest_word;
	std::string shortest_word;

	while (!input.eof()) {
		std::string word;
		input >> word;

		if (input.bad()) {
			std::cout << "Pri cteni souboru nastala nejaka chyba" << std::endl;
			return;
		}

		if (input.fail()) {
			break;
		}
		if (word.length() > longest_word.length()) {
			longest_word = word;
		}
		if (shortest_word.empty() || word.length() < shortest_word.length()) {
			shortest_word = word;
		}
	}
	std::cout << "Longest word: " << longest_word << std::endl;
	std::cout << "Shortest word: " << shortest_word << std::endl;
}

int main() {
	std::fstream file("vstup.txt", std::ios::in);

	text_statistics(file);
}