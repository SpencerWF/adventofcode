#include <iostream>
#include <fstream>
#include <string>

#include "md5.h"

// Default target number of zeros to find at the beginning of the MD5 hash
#define TARGET_ZEROS 6

// Used often enough to justify adding to namespace
using std::cout; using std::endl;

// Function prototype so we can start with main
int starting_zeros(const std::string& text);

int main(int argc, char* argv[]) {
    /**
     * Reads in command line arguments, and tries to find an MD5 hash which has
     * a starting number of zeros equal to the second argument. Uses the first
     * argument for the start of the strings used to create the MD5 hash
     */

    // The number of zeros at the start of a particular MD5 hash, zero for most
    int zero_count = 0;
    // The number added to the end of the first cli argument and used to get a
    // particular MD5 hash
    int end_number = 1;
    // Put default value into the required_zeros used in the do while loop
    int required_zeros = TARGET_ZEROS;
    // String used to create MD5 hashes
    std::string str;

    // There is no point to the code without at least a single argument
    if(argc > 1){
        // If there are more than 2 arguments stop program
        if(argc == 3){
            try{
                // Convert string to number if possible
                required_zeros = std::stoi(argv[2]);
            }
            // Catch invalid argument error and stop program
            catch (const std::invalid_argument& ia) {
                std::cerr << "Invalid argument: " << ia.what() << endl;
            }
        } else if(argc >3) {
            cout << "Too many arguments given\n";
            return EXIT_FAILURE;
        }
    } else {
        cout << "Insufficient arguments given\n";
        return EXIT_FAILURE;
    }

    do {
        // Bring in first argument and add the number to it
        str = argv[1];
        str.append(std::to_string(end_number));

        // Return the number of zeros at the start of the hash
        zero_count = starting_zeros(md5(str));
        end_number++;
    } while(zero_count < required_zeros);

    end_number--;

    cout << required_zeros << " or more starting zeros in MD5 of " << argv[1] << end_number << endl;

    return EXIT_SUCCESS;
}

int starting_zeros(const std::string& text) {
    // Fill cur_char with a null pointer
    char cur_char = '\0';
    uint8_t text_len = text.length();
    int zero_count = 0;

    for(int i=0; i<text_len; i++){
        if(text[i] == '0') {
            zero_count++;
        } else {
            // Break from loop if a non-zero character is found
            break;
        }
    }

    return zero_count;
}