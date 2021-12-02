#include <iostream>
#include <string>
#include <set>
#include <fstream>
#include <vector>
#include <iterator>
#include <algorithm>

// define character size
#define CHAR_SIZE 128

std::vector<std::string> readFile(std::string filename) {
	int currentLength = 1;

	std::vector<std::string> subwords;

	//Opening file to extract words
	std::ifstream file;
	file.open (filename);
	if (!file.is_open()) return subwords;

	//Put words into a vector of strings
	std::string word;
	while (file >> word)
	{
		subwords.push_back(word);
	}
	file.close();
	return subwords;
}

// C++ implementation of Trie Data Structure
int main() {
	std::vector<std::string> id_words;
	std::string first_word, second_word, current_word, test_word;
	bool pos_check = false;

	id_words = readFile("../../../input/2018/input3.txt");

	for(int i=0; i< id_words.size(); i++) {
		current_word = id_words[i];
		//std::cout << std::endl;
		//std::cout << current_word << std::endl;

		for(int j=i+1; j<id_words.size(); j++) {
			test_word = id_words[j];
			//std::cout << test_word << std::endl;

			for(int k=0; k <= current_word.length(); k++) {
				first_word = current_word;
				second_word = test_word;
				first_word.erase(k,1);
				second_word.erase(k,1);

				if ((first_word.compare(second_word) == 0) & (pos_check == false)) {
					pos_check = true;
					std::cout << first_word << std::endl;
					std::cout << second_word << std::endl;
				}
			}
			pos_check = false;
		}
	}
}