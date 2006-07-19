#include "../../../source/utf8.h"
using namespace utf8;

/// [ 1524459 ] utf8::is_valid does not report some illegal code positions
void id_1524459()
{
// Single UTF-16 surrogates: 
unsigned char ud800[] = {0xed, 0xa0, 0x80};
check (!is_valid(ud800, ud800 + 3));

unsigned char udb7f[] = {0xed, 0xad, 0xbf};
check (!is_valid(udb7f, udb7f + 3));
  
unsigned char udb80[] = {0xed, 0xae, 0x80};
check (!is_valid(udb80, udb80 + 3));
  
unsigned char udbff[] = {0xed, 0xaf, 0xbf};
check (!is_valid(udbff, udbff + 3));

unsigned char udc00[] = {0xed, 0xb0, 0x80};
check (!is_valid(udc00, udc00 + 3));

unsigned char udf80[] = {0xed, 0xbe, 0x80};
check (!is_valid(udf80, udf80 + 3));

unsigned char udfff[] = {0xed, 0xbf, 0xbf};
check (!is_valid(udfff, udfff + 3));

// Paired UTF-16 surrogates: 
unsigned char ud800_dc00[] = {0xed, 0xa0, 0x80, 0xed, 0xb0, 0x80};
check (!is_valid(ud800_dc00, ud800_dc00 + 6));

unsigned char ud800_dfff[] = {0xed, 0xa0, 0x80, 0xed, 0xbf, 0xbf};
check (!is_valid(ud800_dfff, ud800_dfff + 6));

unsigned char udb7f_dc00[] = {0xed, 0xad, 0xbf, 0xed, 0xb0, 0x80};
check (!is_valid(udb7f_dc00, udb7f_dc00 + 6));

unsigned char udb7f_dfff[] = {0xed, 0xad, 0xbf, 0xed, 0xbf, 0xbf};
check (!is_valid(udb7f_dfff, udb7f_dfff + 6));

unsigned char udb80_dc00[] = {0xed, 0xae, 0x80, 0xed, 0xb0, 0x80};
check (!is_valid(udb80_dc00, udb80_dc00 + 6));

unsigned char udb80_dfff[] = {0xed, 0xae, 0x80, 0xed, 0xbf, 0xbf};
check (!is_valid(udb80_dfff, udb80_dfff + 6));

unsigned char udbff_dc00[] = {0xed, 0xaf, 0xbf, 0xed, 0xb0, 0x80};
check (!is_valid(udbff_dc00, udbff_dc00 + 6));

unsigned char udbff_dfff[] = {0xed, 0xaf, 0xbf, 0xed, 0xbf, 0xbf};
check (!is_valid(udbff_dfff, udbff_dfff + 6));

// Other illegal code positions 
unsigned char ufffe[] = {0xef, 0xbf, 0xbe};
check (!is_valid(ufffe, ufffe + 3));

unsigned char uffff[] = {0xef, 0xbf, 0xbf};
check (!is_valid(uffff, uffff + 3));
}
