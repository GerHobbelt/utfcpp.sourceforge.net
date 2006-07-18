#include "../../../source/utf8.h"
using namespace utf8;

/// [ 1524459 ] utf8::is_valid does not report some illegal code positions
void id_1524459()
{

unsigned char ud800[] = {0xed, 0xa0, 0x80};
check (!is_valid(ud800, ud800 + 3));


  
}
