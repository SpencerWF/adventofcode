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

std::vector<int> readFile(std::string filename) {
	int currentLength = 1;

	std::vector<int> nums;

	//Opening file to extract words
	std::ifstream file;
	file.open (filename);
	if (!file.is_open()) return nums;

	//Put words into a vector of strings
	std::string word;
	while (file >> word)
	{
		nums.push_back(std::stoi(word));
	}

	return nums;
}

int recurse(std::vector<int> * nums) {
	int child_nodes = nums->at(0);
	int meta_data = nums->at(1);
	int meta_sum=0;

	nums->erase(nums->begin(),nums->begin()+2);

	for(int i = 0; i<child_nodes; i++) {
		meta_sum += recurse(nums);
	}

	for(int i = 0; i<meta_data; i++) {
		meta_sum += nums->at(0);
		nums->erase(nums->begin(),nums->begin()+1);
	}


	std::cout << "Finished branch, meta sum is: " << meta_sum << std::endl;
	return meta_sum;
}

int main() {
	std::vector<int> nums;
	int meta_sum;

	nums = readFile("../../../input/2018/input15.txt");

	// for(std::vector<int>::iterator it=nums.begin(); it!=nums.end(); ++it) {
	// 	std::cout << *it << " ";
	// }

	meta_sum = recurse(&nums);
	std::cout << std::endl;
}

