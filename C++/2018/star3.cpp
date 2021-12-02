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
	std::vector<char> letters;
	std::string current_word;
	std::set<char> unique_letters;
	int frequency = 0, two_count = 0, three_count = 0;
	bool two_buffer = false, three_buffer = false;
	bool repeat = true;

	id_words = readFile("../../../input/2018/input3.txt");

	for(int i = 0; i < id_words.size(); i++) {
		two_buffer = false;
		three_buffer = false;
		current_word = id_words[i];
		std::cout << "The current word is: " << current_word << std::endl;

		unique_letters.clear();
		for(int m = 0; m < current_word.length(); m++) {
			unique_letters.insert(current_word[m]);
		}


		for (std::set<char>::iterator it=unique_letters.begin(); it!=unique_letters.end(); it++) {

			frequency = 0;

			for(int k = 0; k < current_word.length(); k++) {
				if(current_word[k] == *it) {
					frequency++;
				}
			}

			if(frequency == 2) {
				two_buffer = true;
			}
			else if(frequency == 3) {
				three_buffer = true;
			}
		}

		if(two_buffer) {
			two_count++;
			std::cout << "The count for 2: " << two_count << std::endl;
		}
		if(three_buffer) {
			std::cout << "The count for 3: " << three_count << std::endl;			
			three_count++;
		}



	}

	std::cout << "Your checksum is: " << two_count*three_count << std::endl;
}