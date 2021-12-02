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
	char worker_step='.';
	int free_time=0;
};


worker assign_work(worker elf, int step, int second) {
	elf.worker_step = step;
	elf.free_time = step - 4 + second;
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
	std::string available_steps;
	int pos=0;
	std::map<char, std::string> steps;
	bool finished=false;
	std::array<worker, 5> workers;

	lines = readFile("../../../input/2018/input13.txt");

	available_steps.clear();

	steps = extract_steps(lines);

	for(int i = int('A'); i < int('Z')+1; i++) {
		std::cout << "Step " << char(i) << " must be after steps " << steps[char(i)] << std::endl;
	}
	int i;
	for(i = 0; !finished; i++){
		finished = true;
		for(int j = 0; j<workers.size(); j++) {
			if(i>=workers[j].free_time && workers[j].worker_step!='.') {
				for(int k = int('A'); k<int('Z')+1; k++) {
					if(!(steps[char(k)].find_first_of(workers[j].worker_step)==-1)) {
						pos = steps[char(k)].find_first_of(workers[j].worker_step);
						steps[char(k)].erase(pos,1);
					}
				}
				std::cout << "Worker has completed step " << workers[j].worker_step << " at second " << i << std::endl;
				for(int l = int('A'); l < int('Z')+1; l++) {
					std::cout << "Step " << char(l) << " must be after steps " << steps[char(l)] << std::endl;
				}
				workers[j].free_time = 0;
				workers[j].worker_step='.';
			}
		}
		for(int j = int('A'); j < int('Z')+1; j++) {
			if(steps[char(j)].empty()) {
				for(int k = 0; k<workers.size(); k++) {
					if(workers[k].worker_step=='.') {
						workers[k] = assign_work(workers[k], j, i);
						std::cout << "Worker has been assigned step " << workers[k].worker_step << " which will be completed at second " << workers[k].free_time << std::endl;
						steps[char(j)] = '.';
						break;
					}
				}
			}
			else if (!(steps[char(j)]==".")){
				finished = false;
			}
			for(int k = 0; k<workers.size(); k++) {
				if(workers[k].worker_step!='.') {
					finished = false;
				}
			}
		}
	}

	std::cout << "Final second is: " << i-1 << std::endl;
}

