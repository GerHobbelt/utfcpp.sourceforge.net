#include <iostream>
using namespace std;

inline void check_impl (bool condition, const char* file, int line)
 {
   if (!condition) { 
     cout << "Check Failed! File: " << file << " Line: " << line << '\n';
   }
 } 

#define check(c) check_impl(c, __FILE__, __LINE__);

#include "r1_0Beta1/invalidutf8.h"
#include "r1_0Beta1/basic_functionality.h"

int main()
{
//r1_0Beta1/invalidutf8.h
  id_1524459();
  id_1525236();  
  id_1528369();
//r1_0Beta1/basic_functionality.h
  id_1528544();
}
