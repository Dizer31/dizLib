#pragma once


//<-----other lib---->
#ifdef stdLib 
#include <iostream>
#include <string>
using namespace std;
#endif

#ifdef mathLib 
#include <cmath>
#endif

#ifdef winLib 
#include <windows.h>
#endif

#ifdef vectorLib 
#include <vector>
#endif
//<-----other lib---->




//<-----DEBUG----->
#ifdef debugMode 
#define DEBUG(x) println(x)
#else 
#define DEBUG(x)
#endif
//<-----DEBUG----->

//<-----read & print----->
#define read(x) (cin >> (x))
#define print(x) (cout << (x))
#define prints(x) (cout << (x) << " ")
#define printt(x) (cout << (x) << "\t")
#define println(x) (cout << (x) << "\n")
#define printFloat(x, n) cout << setprecision(n + 1) << x
//void printFloat(double x, int depth = 3, char separator = '.') { int p = 1; for (int i = 0; i < depth; i++) { p *= 10; } double a = (int)x; cout << a << separator << (int)((x - a) * p); }
//<-----read & print----->

//<-----func----->
#define mm(x) (x >= 0 ? x : (-1) * x)
#define ff(x) for (int i = 0; i < (x); i++)
#define fff(x, y) for (int y = 0; y < (x); y++)
#define out return 0
#define clr system("clr")
#define ps system("pause")
#define Array(x) for (auto n : x)prints(n)
#define allAscii ff(255) { prints((char)i); prints('-'); println(i); } 
#define del(x) delete[] x
//<-----func----->

//<-----data----->
#ifdef datadef && stdLib
#define str string
#endif
#ifdef datadef
#define byte uint8_t
#endif
//<-----data----->
