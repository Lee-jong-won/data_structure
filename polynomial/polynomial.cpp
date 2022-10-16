#include <stdlib.h>

typedef struct poly{
    int degree;
    float* coef;

    poly(int _degree)
    : degree(_degree)
    {
        coef = new float[_degree + 1];
    }
} polynomial;

polynomial* padd(polynomial* poly1, polynomial* poly2)
{
    int cursor = 0;
    polynomial* new_poly = nullptr;

    if(poly1->degree <= poly2->degree)
    {
        new_poly = new poly(poly2->degree);
    }    
    else
    {
        new_poly = new poly(poly1->degree);
    }
    
    while(cursor <= poly1->degree && cursor <= poly2->degree)
    {
        new_poly->coef[cursor] = poly1->coef[cursor] + poly2->coef[cursor];
        cursor++;
    }

    while(cursor <= poly1->degree)
    {
        new_poly->coef[cursor] = poly1->coef[cursor];
    }

    while(cursor <= poly2->degree)
    {
        new_poly->coef[cursor] = poly2->coef[cursor];
    }

    return new_poly;
}

