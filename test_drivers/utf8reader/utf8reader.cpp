#include "../../source/utf8.h"
using namespace utf8;

#include <string>
#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

int main(int argc, char** argv)
{
    if (argc != 2) {
        cout << "\nUsage: utfreader filename\n";
        return 0;
    }
    const char* TEST_FILE_PATH = argv[1];
    // Open the test file
    ifstream fs8(TEST_FILE_PATH);
    if (!fs8.is_open()) {
    cout << "Could not open " << TEST_FILE_PATH << endl;
    return 0;
    }

    // Create a file to write utf-16 text
    string utf16_file_name = TEST_FILE_PATH;
    utf16_file_name += "utf16.txt";
    ofstream fs16(utf16_file_name.c_str(), ios_base::out | ios_base::binary);
    if (!fs16.is_open()) {
        cout << "Could not open utf16.txt" << endl;
        return 0;
    }  
    const unsigned short utf16_bom = 0xfeff;
    fs16.write(reinterpret_cast<const char*>(&utf16_bom), sizeof(unsigned short));

    // Read it line by line
    unsigned int line_count = 0;
    char byte;
    while (!fs8.eof()) {
        string line;
        while ((byte = static_cast<char>(fs8.get())) != '\n' && !fs8.eof()) 
            line.push_back(byte);

        line_count++;
	// Play around with each line and convert it to utf16
        string::iterator line_start = line.begin();
        string::iterator line_end   = line.end();
        line_end = find_invalid(line_start, line_end);
        if (line_end != line.end()) 
            cout << "Line " << line_count << ": Invalid utf-8 at byte " << line.end() - line_end << '\n';

        // Convert it to utf-16 and write to the file
        vector<unsigned short> utf16_line;
        utf8to16(line_start, line_end, back_inserter(utf16_line));
        utf16_line.push_back('\n');
        fs16.write(reinterpret_cast<const char*>(&utf16_line[0]), utf16_line.size() * sizeof (unsigned short));

    }
}
