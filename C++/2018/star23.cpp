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

struct pot {
	int pos;
	bool state=false;	
};

std::vector<pot> extract_pots(std::string line) {
	int pos_hash;
	std::vector<pot> pots;
	pot current_pot;
	// std::map<int, bool> pots;

	for(int i=0; i<line.length(); i++) {
		if(line[i] == '#') {
			pos_hash = i;
			line.erase(0,pos_hash);
			break;
		}
	}

	for(int i=0; i<line.length(); i++) {
		if(line[i] == '#') {
			current_pot.pos = i;
			current_pot.state = true;
			pots.push_back(current_pot);
		}
		else {
			current_pot.pos = i;
			current_pot.state = false;
			pots.push_back(current_pot);
		}
	}

	return pots;
}

std::vector<std::array<bool, 5>> extract_rules(std::vector<std::string> lines) {
	lines.erase(lines.begin(), lines.begin()+2);
	std::vector<std::array<bool, 5>> rules;
	std::array<bool, 5> rule;
	std::string line;

	for(int i=0; i<lines.size(); i++) {
		line = lines[i];
		if(line[line.length()-1] == '#') {
			for(int j=0; j<5; j++) {
				if(line[j] == '#') {
					rule[j] = true;
				}
				else{
					rule[j] = false;
				}
			}
			rules.push_back(rule);
		}
	}
	return rules;
}

int main() {
	int start_pos=0, end_pos=0, add_count;
	int generations = 20, pot_plants = 0, value=0;
	std::vector<std::string> lines;
	// std::vector<bool> pots, pots_buffer;
	std::vector<std::array<bool, 5>> rules;
	std::array<bool, 5> rule, ref_pots;
	std::string hundreds;
	int buffer;
	bool new_state = false, rule_app=false;
	// std::map<int, bool> pots, pots_buffer;
	std::vector<pot> pots, pots_buffer;
	pot current_pot;


	lines = readFile("../../../input/2018/input23.txt");

	pots = extract_pots(lines[0]);
	rules = extract_rules(lines);

	end_pos = pots.size();

	std::cout << "0: ";
	for(int i=0; i<pots.size(); i++) {
		if(pots[i].state==true) {
			std::cout << "#";
		}
		else {
			std::cout << ".";
		}
	}
	std::cout << std::endl;

	for(int i=1; i<generations+1; i++) {
		// pots_buffer = pots;

		for(std::vector<pot>::iterator it=pots.begin(); it!=pots.end(); ++it) {
			if(it->state) {
				start_pos = it->pos;
				// std::cout << it->state << " value is true at position " << start_pos << std::endl;
				current_pot.pos = start_pos-1;
				current_pot.state = false;
				pots.insert(pots.begin(), current_pot);
				current_pot.pos--;
				pots.insert(pots.begin(), current_pot);
				current_pot.pos--;
				pots.insert(pots.begin(), current_pot);
				current_pot.pos--;
				pots.insert(pots.begin(), current_pot);
				// start_pos -= 2;
				break;
			}
			else {
				pots.erase(pots.begin());
				--it;
			}
		}

		for(std::vector<pot>::reverse_iterator rit=pots.rbegin(); rit!=pots.rend(); ++rit) {
			if(rit->state) {
				end_pos = rit->pos;
				// std::cout << rit->state << " value is true at position " << end_pos << std::endl;
				current_pot.pos = end_pos+1;
				current_pot.state = false;
				pots.push_back(current_pot);
				current_pot.pos++;
				pots.push_back(current_pot);
				current_pot.pos++;
				pots.push_back(current_pot);
				current_pot.pos++;
				pots.push_back(current_pot);
				// end_pos += 2;
				break;
			}
			else {
				pots.erase(pots.end());
			}
		}

		
		// pots = pots_buffer;

		// for

		for(std::vector<pot>::iterator it=pots.begin()+2; it!=pots.end()-2; ++it) {
			for(int k=0; k<rules.size(); k++) {
				rule = rules[k];
				for(int l=0; l<5; l++){
					if(rule[l] != (it+l-2)->state) {
						break;
					}
					else if(l==4) {
						// std::cout << rule[l] << " is equal to " << it->pos << std::endl;
						// write->state = true;
						current_pot.pos = it->pos;
						current_pot.state = true;
						pots_buffer.push_back(current_pot);
						rule_app = true;
					}
				}
				// pots_buffer[it->first] = rule_app;
			}
			if(!rule_app){
				// write->state = false;
				current_pot.pos = it->pos;
				current_pot.state = false;
				pots_buffer.push_back(current_pot);
			}
			rule_app = false;
			// ++write;
		}

		pots = pots_buffer;
		pots_buffer.clear();
		std::cout << i << ": ";
		for(std::vector<pot>::iterator it=pots.begin(); it!=pots.end(); ++it) {
			if(!it->pos) {
				std::cout << "(";
				if(it->state) {
					std::cout << "#";
				}
				else {
					std::cout << ".";
				}
				std::cout << ")";
			}
			// else if(it->pos%5==0) {
			// 	std::cout << "'";
			// 	if(it->state) {
			// 		std::cout << "#";
			// 	}
			// 	else {
			// 		std::cout << ".";
			// 	}
			// 	std::cout << "'";
			// }
			else if(it->state) {
				std::cout << "#";
			}
			else {
				std::cout << ".";
			}
		}
		std::cout << std::endl;
	}

	for(std::vector<pot>::iterator it=pots.begin(); it!=pots.end(); ++it) {
		if(it->state) {
			value += it->pos;
			std::cout << it->pos << " ";
		}
	}
	std::cout << "Value is: " << value << std::endl;
	std::cout << std::endl;
}
