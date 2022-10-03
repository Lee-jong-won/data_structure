#include "postfix.h"
#include "stdio.h"

int main()
{
    char input[] = "(a+b*c)/d+e+f";
    char output[100];

    postfix(input, output);
    printf("%s", output);
}