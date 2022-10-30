#include "SAT.h"
#include <cwchar>
#include <iostream>
#include <string.h>

using std::wcout;
using std::endl;

int main()
{
    SAT_problem my_sat;

    my_sat.make_tree(L"(a∧b)∨(c∨d)");    
    my_sat.print();

    return 0;
}