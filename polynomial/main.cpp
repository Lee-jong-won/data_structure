#include "polynomial.cpp"
#include <stdio.h>

int main()
{
    polynomial* poly1 = new poly(4);
    poly1->coef[0] = 3;
    poly1->coef[1] = 0;
    poly1->coef[2] = 2;
    poly1->coef[3] = 4;
    poly1->coef[4] = 5;

    polynomial* poly2 = new poly(3);
    poly2->coef[0] = 2;
    poly2->coef[1] = 1;
    poly2->coef[2] = 4;
    poly2->coef[3] = 2;

    polynomial* poly3 = padd(poly1, poly2);

    int cursor = 0;
    while(cursor <= poly3->degree)
    {
        if(poly3->coef[cursor] != 0)
        {
            printf("degree:%d, coef:%f", cursor, poly3->coef[cursor]);
        }
        cursor++;
    }

    return 0;
}