#include <iostream>
#include <string>
#include <set>
#include <fstream>
#include <vector>
#include <iterator>
#include <algorithm>
#include <array>
#include <map>

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
	while (std::getline(file, word))
	{
		subwords.push_back(word);
	}
	file.close();
	return subwords;
}

// C++ implementation of Trie Data Structure
int main() {
	std::vector<std::string> lines;
	std::string line, line_buffer;
	bool contact=true;

	lines = readFile("../../../input/2018/input9.txt");

	line = lines[0];

	std::cout << "The starting length is: " << line.length() << std::endl;

	//std::cout << line << std::endl;
	while(contact) {
		contact = false;
		for(int i=0; i<line.length(); i++) {
			
//			std::cout << line << std::endl;
			if(int(line[i]) - 32 == int(line[i+1]) || int(line[i]) + 32 == int(line[i+1])) {
				//std::cout << line[i] << ":" << line[i+1] << std::endl;
				line.erase(i,2);
				i--;
				contact = true;
			}
		}
	}
	std::cout << "The new length is: " << line.length() << std::endl;
//	std::cout << line << std::endl;
}

