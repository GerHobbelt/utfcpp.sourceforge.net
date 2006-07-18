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

int main()
{
//r1_0Beta1/invalidutf8.h
  id_1524459();
  
}
