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

struct worker {
	char worker_step;
	int free_time;
};


worker assign_work(worker elf, char step) {
	elf.worker_step = step;
	elf.free_time = int(step) - 4;
	return elf;
}

std::map<char, std::string> extract_steps(std::vector<std::string> lines) {
	std::map<char, std::string> steps;
	std::string current_line, empty_str, step_string;
	char current_step, current_requirement;
	int pos=0;

	empty_str.clear();

	for(int i=0; i<lines.size(); i++) {
		current_line = lines[i];
		// std::cout << current_line << std::endl;
		current_step = current_line[36];
		current_requirement = char(current_line[5]);
		step_string = current_line[5];
		
		if(!steps.count(current_step)) {
			steps.emplace(current_step, step_string);
		}
		else{
			if(steps[current_step].empty()) {
				steps[current_step] = step_string;
			}
			else{
				int j=0;
				for(std::string::iterator it=steps[current_step].begin(); it!=steps[current_step].end(); ++it) {
					if(int(*it) > int(step_string[0]) && it==steps[current_step].begin()) {
						steps[current_step].insert(j,1,step_string[0]);
					}
					else if((int(*it) < int(step_string[0])) && ((it+1)==steps[current_step].end())) {
						steps[current_step].push_back(step_string[0]);
					}
					else if(int(*it) < int(step_string[0]) && int(step_string[0]) < int(*(it+1))) {
						steps[current_step].insert(j+1,1,step_string[0]);
					}
					j++;
				}
			}
		}
		if(!steps.count(current_requirement)) {
			steps.emplace(current_requirement, empty_str);
		}
	}
	return steps;
}

int main() {
	std::vector<std::string> lines;
	std::string step_string;
	int pos=0;
	std::map<char, std::string> steps;
	bool finished;
	std::array<worker, 5> workers;

	

	lines = readFile("../../../input/2018/input13.txt");

	step_string.clear();

	steps = extract_steps(lines);

	for(int i = int('A'); i < int('Z')+1; i++) {
		std::cout << "Step " << char(i) << " must be after steps " << steps[char(i)] << std::endl;
	}

	do {
		finished = false;
		for(int i = int('A'); i < int('Z')+1; i++) {
			//std::cout << "Step " << char(i) << " must be after steps " << steps[char(i)] << std::endl;
			if(steps[char(i)].empty()) {
				step_string.push_back(char(i));
				for(int j = int('A'); j<int('Z')+1; j++) {
					if(!(steps[char(j)].find_first_of(char(i))==-1)) {
						pos = steps[char(j)].find_first_of(char(i));
						steps[char(j)].erase(pos,1);
					}
				}
				steps[char(i)]=".";
				finished = true;
				break;
			}
			else if (!(steps[char(i)]==".")){
				finished = true;
			}
		}
	} while(finished);

	std::cout << "Final step order is: " << step_string << std::endl;
}

