#include <iostream>
#include <string>
#include <set>
#include <fstream>
#include <vector>
#include <iterator>
#include <algorithm>
#include <array>
#include <map>

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
	std::vector<int> lengths;
	bool contact=true;
	int shortest_length=100000;
	char shortest_letter;

	lines = readFile("../../../input/2018/input9.txt");
	line = lines[0];

	std::cout << "The starting length is: " << line.length() << std::endl;

	//std::cout << line << std::endl;
	for(int j=int('a'); j<int('z')+1; j++) {
		line_buffer = line;
		for(int i=0; i<line_buffer.length(); i++) {
			if(int(line_buffer[i]) == j || int(line_buffer[i]) == j - 32) {
				line_buffer.erase(i,1);
				i--;
			}
		}

		std::cout << "The mid length is: " << line_buffer.length() << std::endl;
		while(contact) {
			contact = false;
			for(int i=0; i<line_buffer.length(); i++) {
				if(int(line_buffer[i]) - 32 == int(line_buffer[i+1]) || int(line_buffer[i]) + 32 == int(line_buffer[i+1])) {
					//std::cout << line[i] << ":" << line[i+1] << std::endl;
					line_buffer.erase(i,2);
					i--;
					contact = true;
				}
			}
		}
		contact = true;
		lengths.push_back(line_buffer.length());
		std::cout << "The new length is: " << line_buffer.length() << std::endl;
	}

	for(int i=0; i<lengths.size(); i++) {
		if(lengths[i] < shortest_length) {
			shortest_length = lengths[i];
			shortest_letter = char(i+65);
		}
	}

	std::cout << "Shortest letter is: " << shortest_letter << std::endl;
	std::cout << "Shortest length is: " << shortest_length << std::endl;
}

