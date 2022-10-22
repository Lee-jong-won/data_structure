#include "SAT.h"

#include <iostream>

using std::wcout;

int main()
{
    SAT_problem my_sat;
    my_sat.to_postfix(L"(a∧b)∨(c∧d)");

    wcout << my_sat.postfix[2];

    return 0;
}