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

struct guard {
	std::vector<int> sleep_time, wake_time;
	int total;
	int fav_minute=0;
	int fav_count=0;
};

int month_to_day(int month) {
	switch(month){
		case 1:
			return 0;
			break;

		case 2:
			return 31;
			break;

		case 3:
			return 59;
			break;

		case 4:
			return 90;
			break;

		case 5:
			return 120;
			break;

		case 6:
			return 151;
			break;

		case 7:
			return 181;
			break;

		case 8:
			return 212;
			break;

		case 9:
			return 243;
			break;

		case 10:
			return 273;
			break;

		case 11:
			return 304;
			break;

		case 12:
			return 334;
			break;
	}
}

bool minuteSort(std::string first, std::string second) {
	int month1 = std::stoi(first.substr(0,6));
	int month2 = std::stoi(second.substr(0,6));
	return month1 < month2;
}

// C++ implementation of Trie Data Structure
int main() {
	std::vector<std::string> lines;
	//std::vector<guard> guards;
	std::string current_line;
	guard current_guard;
	int month, day, hour, total_minute, night_minute, pos_start, pos_end;
	int sleep_total = 0, current_ID=0;
	std::array<int, 60> minutes_list;
	int minute=0, dude=0;
	std::map<int, guard> guards;

	for(int i=0; i<minutes_list.size(); i++) {
		minutes_list[i] = 0;
	}

	lines = readFile("../../../input/2018/input6.txt");

	for(int i=0; i<lines.size(); i++) {
		current_line = lines[i];

		month = std::stoi(current_line.substr(6,2));
		day = std::stoi(current_line.substr(9,2));
		hour = std::stoi(current_line.substr(12,2));
		total_minute = std::stoi(current_line.substr(15,2));

		night_minute = total_minute;

		total_minute += 60*(hour+ 24*(day-1 + month_to_day(month)));

		//std::cout << total_minute << std::endl;

		// current_line.insert(0, std::to_string(night_minute));
		// current_line.insert(0, " ");
		// current_line.insert(0, std::to_string(total_minute));

		current_line.replace(0,11, std::to_string(total_minute));
		current_line.replace(7,6, std::to_string(night_minute));

		lines[i] = current_line;
		
	}

	std::sort(lines.begin(), lines.end(), minuteSort);
	current_ID = 0;
	for(int i=0; i<lines.size(); i++) {
		current_line = lines[i];
		std::cout << current_line << std::endl;
		if(!(current_line.find_first_of("#")==-1)) {
			

			pos_start = current_line.find_first_of("#");
			pos_end = current_line.find_first_of("b");
			current_ID = std::stoi(current_line.substr(pos_start + 1,pos_end-pos_start-1));

			if(!guards.count(current_ID)) {
				current_guard.sleep_time.clear();
				current_guard.wake_time.clear();
				current_guard.total = 0;
				guards.emplace(current_ID, current_guard);
			}
			current_guard = guards[current_ID];
			std::cout << "current total: " << guards[current_ID].total << std::endl;
		}
		else if(!(current_line.find_first_of("l")==-1)) {
			pos_start = 6;
			pos_end = current_line.find_first_of("f");
			current_guard.sleep_time.push_back(std::stoi(current_line.substr(pos_start + 1,pos_end-pos_start-1)));
		}
		else if(!(current_line.find_first_of("w")==-1)) {
			pos_start = 6;
			pos_end = current_line.find_first_of("w");
			current_guard.wake_time.push_back(std::stoi(current_line.substr(pos_start + 1,pos_end-pos_start-1)));
			current_guard.total += current_guard.wake_time.back() - current_guard.sleep_time.back();
			guards[current_ID] = current_guard;
		}
	}
	// for(std::map<int,guard>::iterator it=guards.begin(); it!=guards.end(); ++it) {
	// 	std::cout << it->first << " Guard minutes slept: " << it->second.total << std::endl;
	// 	if(it->second.total > sleep_total) {
	// 		sleep_total = it->second.total;
	// 		current_ID = it->first;
	// 	}
	// }

	for(std::map<int,guard>::iterator it=guards.begin(); it!=guards.end(); ++it) {
		current_ID = it->first;
		for(int i=0; i<guards[current_ID].sleep_time.size(); i++) {
			for(int j=guards[current_ID].sleep_time[i]; j<guards[current_ID].wake_time[i]; j++) {
				minutes_list[j]++;
			}
		}

		for(int i=0; i<minutes_list.size(); i++) {

			if(minutes_list[i]>minutes_list[guards[current_ID].fav_minute]) {
				guards[current_ID].fav_minute = i;
				guards[current_ID].fav_count = minutes_list[i];
			}
		}

		for(int i=0; i<minutes_list.size(); i++) {
		minutes_list[i] = 0;
		}
	}
	for(std::map<int,guard>::iterator it=guards.begin(); it!=guards.end(); ++it) {
		current_ID = it->first;
		std::cout << current_ID << " slept in this minute: " << guards[current_ID].fav_minute << " this many times: " << guards[current_ID].fav_count << std::endl;
		if(guards[current_ID].fav_count > minute) {
			minute = guards[current_ID].fav_count;
			dude = current_ID;
		}
	}
	std::cout << "Sleepiest guard is: " << dude << std::endl;
	std::cout << "Who slept the most during minute " << guards[current_ID].fav_minute << std::endl;
	std::cout << "The value is: " << current_ID * (guards[current_ID].fav_minute) << std::endl;
}

