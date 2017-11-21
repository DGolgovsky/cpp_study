/*
 * Developed by Dmitry Golgovsky <d.westcoast@aol.com>
 *
 * Description of the program
 *
 */

#include <iostream>

#include <vector>

#include <string>
#include <cmath>

using namespace std;

int main(int argc, char const** argv)
{
    int a = 27;
    int const b = 412;
    int * pa = &a;

    int const c = const_cast<int const &>(a);
    int d = const_cast<int &>(b);
    int const * p1 = const_cast<int const *>(pa);
    int * const * p2 = const_cast<int * const *>(&pa);
    int const ** p3 = const_cast<int const **>(&pa);
    int const * const * p4 = const_cast<int const * const *>(&pa);

    return 0;
}
