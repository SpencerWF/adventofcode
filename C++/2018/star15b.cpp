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

std::vector<unsigned> readFile(std::string filename) {
	int currentLength = 1;

	std::vector<unsigned> nums;

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

unsigned recurse(std::vector<unsigned> * nums) {
	unsigned child_nodes = nums->at(0);
	unsigned meta_data = nums->at(1);
	std::vector<unsigned> child_values;
	std::vector<unsigned> select_children;
	unsigned meta_sum=0;

	nums->erase(nums->begin(),nums->begin()+2);

	for(unsigned i = 0; i<child_nodes; i++) {
		child_values.push_back(recurse(nums));
		std::cout << "Value " << child_values.back() << " for child " << i << std::endl;
	}

	// std::cout << "Pre-meta size: " << nums->size() << std::endl;

	for(unsigned i = 0; i<meta_data; i++) {
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
			if(i < child_values.size()){
				std::cout << "child value added " << child_values[select_children[i]] << " for child " << select_children[i] << std::endl;
				meta_sum += child_values[select_children[i]];
			}
		}
	}

	std::cout << "Finished branch, meta sum is: " << meta_sum << std::endl;
	return meta_sum;
}

int main() {
	std::vector<unsigned> nums;
	unsigned meta_sum;

	nums = readFile("advent15.txt");

	// for(std::vector<int>::iterator it=nums.begin(); it!=nums.end(); ++it) {
	// 	std::cout << *it << " ";
	// }

	meta_sum = recurse(&nums);
	std::cout << std::endl;
}

