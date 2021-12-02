#include <iostream>
#include <string>
#include <set>
#include <fstream>
#include <vector>
#include <iterator>
#include <algorithm>
#include <array>
#include <map>

#include <iostream>
#include <string>
#include <regex>
#include <fstream>
 
using namespace std;
 
char alphabet[] = { 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z' };
 
int lengths[sizeof(alphabet)] = { 0 };
 
string InputPath = "/home/spencerwf/programs/adventcalender/advent9.txt";
 
void read() {
    string storage;
    ifstream input(InputPath);
    getline(input, storage);
    while (true) {
        for (int k = 0; k < sizeof(alphabet); k++) {
            string tmpStorage = storage;
            tmpStorage.erase(remove(tmpStorage.begin(), tmpStorage.end(), tolower(alphabet[k])), tmpStorage.end());
            tmpStorage.erase(remove(tmpStorage.begin(), tmpStorage.end(), toupper(alphabet[k])), tmpStorage.end());
            cout << "tmpStorage without " << alphabet[k] << " has length of " << tmpStorage.length() << endl;
            //Repeat for each character
			for(int i=0; i<tmpStorage.length(); i++) {
				if(int(tmpStorage[i]) - 32 == int(tmpStorage[i+1]) || int(tmpStorage[i]) + 32 == int(tmpStorage[i+1])) {
					//std::cout << line[i] << ":" << line[i+1] << std::endl;
					tmpStorage.erase(i,2);
					i--;
					// contact = true;
				}
			}
            // for (int pos = 0; pos < tmpStorage.length(); pos++) {
            //     if (islower(tmpStorage[pos]) && isupper(tmpStorage[pos + 1]) && tmpStorage[pos] == tolower(tmpStorage[pos + 1])) {
            //         //Erase combination of elements, subtract one from 'pos' to catch new combinations
            //         tmpStorage.erase(tmpStorage.begin() + pos, tmpStorage.begin() + (pos + 2));
            //         pos--;
            //     }
            //     if (isupper(tmpStorage[pos]) && islower(tmpStorage[pos + 1]) && tmpStorage[pos] == toupper(tmpStorage[pos + 1])) {
            //         //Erase combination of elements, subtract one from 'pos' to catch new combinations
            //         tmpStorage.erase(tmpStorage.begin() + pos, tmpStorage.begin() + (pos + 2));
            //         pos--;
            //     }
            // }
            //Add length to array
            lengths[k] = tmpStorage.length();
        }
        break;
    }
    cout << *min_element(begin(lengths), end(lengths)) << endl;
}
 
int main() {
    read();
}
