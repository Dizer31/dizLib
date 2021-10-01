#pragma once

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
//#define printss(x, y, z) (cout << x << ' ' << y << ' '<< z << ' ')
//#define readss(x, y, z) (cin >> x >> y >> z)
#define printFloat(x, n) cout << setprecision(n+1) << x 
//<-----read & print----->

#define mm(x) (x >= 0 ? x : (-1) * x)
#define ff(x) for (int i = 0; i < (x); i++)
#define fff(x, y) for (int y = 0; y < (x); y++)
#define out return 0
#define clr system("clr")
#define ps system("pause")
#define printArr(x) for (int n : x)prints(n)

void allAscii() { ff(255) { prints((char)i); prints('-'); println(i); } }
