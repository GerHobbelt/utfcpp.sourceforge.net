#include <iconv.h>
#include "../../source/utf8.h"
#include "timer.h"
#include <fstream>
#include <algorithm>
using namespace std;

using namespace utf8;

int main(int argc, char** argv)
{
    if (argc != 2) {
        cout << "\nUsage: iconvtest filename\n";
        return 0;
    }
    const char* test_file_path = argv[1];
    // Open the test file (UTF-8 encoded text)
    ifstream fs8(test_file_path, ios::binary);
    if (!fs8.is_open()) {
    cout << "Could not open " << test_file_path << endl;
    return 0;
    }
    // get length
    fs8.seekg(0, ios::end);
    int length = fs8.tellg();
    fs8.seekg(0, ios::beg);

    // allocate the buffer (no vector - we are benchmarking conversions, not STL
    char* buf = new char[length];
    fs8.close();
    // the UTF-16 result will not be larger than this (I hope :) )
    unsigned short* utf16buf = new unsigned short[length];
    // fill the data
    fs8.read(buf, length);

    {
        memset (utf16buf, 0 , length * sizeof(unsigned short));
        // utf-8 cpp:
        cout << "utf8::utf8to16: ";
        timer t(cout);
        utf8::utf8to16(buf, buf + length, utf16buf);
    }

    {
        memset (utf16buf, 0 , length * sizeof(unsigned short));
        // utf-8 cpp:
        cout << "unchecked::utf8to16: ";
        timer t(cout);
        utf8::unchecked::utf8to16(buf, buf + length, utf16buf);
    }

    // the UTF-16 result will not be larger than this (I hope :) )
    unsigned short* utf16iconvbuf = new unsigned short[length];
    {
        memset (utf16iconvbuf, 0 , length * sizeof(unsigned short));
        // iconv
        cout << "iconv: ";

        iconv_t cd = iconv_open("UTF-16LE", "UTF-8");
        if (cd == iconv_t(-1)) {
            cout << "Error openning the iconv stream";
            return 0;
        } 
        char* inbuf = buf;
        size_t in_bytes_left = length;
        char* outbuf = (char*)utf16iconvbuf;
        size_t out_bytes_left = length * sizeof (unsigned char);
        {
            timer t(cout);
            iconv(cd, &inbuf, &in_bytes_left, &outbuf, &out_bytes_left);
        }
        iconv_close(cd);
    }

    // just check the correctness while we are here:
    if (!equal(utf16buf, utf16buf + length, utf16iconvbuf)) 
        cout << "Different result!!!";
    

    
    delete [] buf;
    delete [] utf16buf;
}
