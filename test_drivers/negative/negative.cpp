#include "../../source/utf8.h"
using namespace utf8;

#include <string>
#include <iostream>
#include <fstream>
using namespace std;

const char* TEST_FILE_PATH = "../../test_data/negative/utf8_invalid.txt";

int main()
{
    // Open the test file
    ifstream fs8(TEST_FILE_PATH);
    if (!fs8.is_open()) {
    cout << "Could not open " << TEST_FILE_PATH << endl;
    return 0;
    }

    // Read it line by line
    unsigned int line_count = 0;
    char byte;
    while (!fs8.eof()) {
        string line;
        while ((byte = fs8.get()) != '\n' && !fs8.eof()) 
	    line.push_back(byte);

        line_count++;
	// Print out lines that contain invalid UTF-8
	if (!is_valid(line.begin(), line.end()))
            cout << line_count << ": " << line << '\n';
    }
}
