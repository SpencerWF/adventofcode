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
	std::vector<int> nums;
	std::string current_word;
	int frequency = 0, select = 0, i = 0;
	bool repeat = true;

	num_words = readFile("../../../input/2018/input1.txt");

	while(repeat) {
		current_word = num_words[i];
		frequency += std::stoi(current_word);
		// std::cout << frequency << std::endl;
		
		if(!nums.empty()){
			for(int j = 0; j < nums.size(); j++) {
				if(nums[j] == frequency) {
					repeat = false;
					select = frequency;
					break;
				}
				
			}
		}

		nums.push_back(frequency);

		i++;
		if (!(i < num_words.size())) {
			i = 0;
			std::cout << "One loop" << std::endl;
			// break;
		}
	}

	std::cout << "Your repeated frequency is: " << select << std::endl;
}