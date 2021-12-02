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

std::vector<unsigned int> readFile(std::string filename) {
	int currentLength = 1;

	std::vector<unsigned int> nums;

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

// int recurse(std::vector<int> * nums) {
// 	int child_nodes = nums->at(0);
// 	int meta_data = nums->at(1);
// 	int meta_sum=0;

// 	nums->erase(nums->begin(),nums->begin()+2);

// 	for(int i = 0; i<child_nodes; i++) {
// 		meta_sum += recurse(nums);
// 	}


// 	for(int i = 0; i<meta_data; i++) {
// 		meta_sum += nums->at(0);
// 		nums->erase(nums->begin(),nums->begin()+1);
// 	}


// 	std::cout << "Finished branch, meta sum is: " << meta_sum << std::endl;
// 	return meta_sum;
// }

unsigned int recurse(std::vector<unsigned int> * nums) {
	unsigned int child_nodes = nums->at(0);
	unsigned int meta_data = nums->at(1);
	std::vector<unsigned int> child_values;
	std::vector<unsigned int> select_children;
	unsigned int meta_sum=0;

	nums->erase(nums->begin(),nums->begin()+2);

	for(int i = 0; i<child_nodes; i++) {
		child_values.push_back(recurse(nums));
		std::cout << "Value " << child_values.back() << " for child " << i << std::endl;
	}

	// std::cout << "Pre-meta size: " << nums->size() << std::endl;

	for(int i = 0; i<meta_data; i++) {
		if(child_nodes) {

			select_children.push_back(nums->at(0) - 1);
		}
		else {
			meta_sum += nums->at(0);
		}
		nums->erase(nums->begin(),nums->begin()+1);
	}

	if(child_nodes) {
		for(int i=0; i<select_children.size(); i++) {
			if(select_children[i] < child_values.size()){
				std::cout << "child value added " << child_values[select_children[i]] << " for child " << select_children[i] << std::endl;
				meta_sum += child_values[select_children[i]];
			}
		}
	}
	std::cout << "Finished branch, meta sum is: " << meta_sum << std::endl;
	return meta_sum;
}

int main() {
	std::vector<unsigned int> nums;
	unsigned int meta_sum;

	nums = readFile("../../../input/2018/input15.txt");

	meta_sum = recurse(&nums);
	std::cout << std::endl;
}

