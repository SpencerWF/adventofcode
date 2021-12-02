#include <iostream>
#include <string>
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

	return subwords;
}

// C++ implementation of Trie Data Structure
int main() {
	std::vector<std::string> num_words;
	//std::vector<int> nums;
	std::string current_word;
	double long frequency = 0;

	num_words = readFile("../../../input/2018/input1.txt");

	for(int i = 0; i < num_words.size(); i++) {
		current_word = num_words[i];
		frequency += std::stoi(current_word);
		std::cout << current_word << " : " << frequency << std::endl;
		//frequency += num_words[i];
	}

	std::cout << "Your settled frequency is: " << frequency << std::endl;
}