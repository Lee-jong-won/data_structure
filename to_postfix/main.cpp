#include "postfix.h"
#include "stdio.h"

int main()
{
    char input[] = "m*n+(p-q)+r";
    char output[100];

    postfix(input, output);
    printf("%s", output);
}