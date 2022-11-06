#include "SAT.h"
#include <cwchar>
#include <iostream>
#include <string.h>
#include <stdlib.h>
#include <math.h>

using std::cout;
using std::endl;

int main()
{
    SAT_problem my_sat;
    int* lg_arry;
    int main_num;
    bool flag; 

    my_sat.make_tree(L"(a∧b)∨(￢c∧d)");    
    
    
    lg_arry = (int*)malloc(sizeof(int) * my_sat.size);
    for(int i = 0; i < my_sat.size; i++)
    {
        lg_arry[i] = 0;
    }

    
    for(main_num = 0; main_num < (int)pow(2, my_sat.size); main_num++)
    {
        int idx = my_sat.size-1;
        for(int k = main_num; k != 0; k/=2)
        {
            lg_arry[idx] = k%2;
            idx--;
        }

        for(int i = 0; i < my_sat.size; i++)
        {
            if(lg_arry[i] == 1)
            {
                my_sat.leaf[i]->data = logical::TRUE;
                my_sat.leaf[i]->value = true;
            }
            else
            {
                my_sat.leaf[i]->data = logical::FALSE; 
                my_sat.leaf[i]->value = false;
            }
        }   

        my_sat.postOrderEval(my_sat.root);

        if(my_sat.root->value)
        {
            flag = true;
            cout << "combination is as followed" << endl;

            for(int i = 0; i < my_sat.size; i++)
            {
                if(my_sat.leaf[i]->value == true)
                {
                    printf("p[%d]:true\n", i);
                }
                else
                {
                    printf("p[%d]:false\n", i);
                }
            }

            cout << endl << endl;
        }

    }

    if(!flag)
    {
        cout << "No satisfiable combination\n";
    }
    

    return 0;
}