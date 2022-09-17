//bst.cpp

#include "bst.h"
#include <stdlib.h>
#include <assert.h>
#include <stdio.h>

void new_tree(tree* tree_Pointer, int _max_Size)
{
    if(tree_Pointer == nullptr || _max_Size <= 0)
    {
        assert(nullptr);
    }

    tree_Pointer->data = (int*)malloc(sizeof(int) * _max_Size);
    tree_Pointer->max_Size = _max_Size;

    for(int i = 0; i < _max_Size; i++)
    {
        tree_Pointer->data[i] = -1;
    }

}

void tree_expansion(tree* tree_Pointer, int* object)
{
    if(tree_Pointer == nullptr || object == nullptr)
    {
        assert(nullptr);
    }

    int object_size = tree_Pointer->max_Size;
    new_tree(tree_Pointer, tree_Pointer->max_Size * 2);

    for(int i = 0; i < object_size; i++)
    {
        tree_Pointer->data[i] = object[i];
    }

}

void insert(tree* tree_Pointer, int _data)
{
    if(!tree_Pointer)
    {
        assert(nullptr);
    }

    if(tree_Pointer->data[1] == -1)
    {
        tree_Pointer->data[1] = _data;
    } 
    else
    {

        int cursor = 1;
        while (true)
        {
            // 이동 방향 결정.
            if (tree_Pointer->data[cursor] > _data)
            {
                cursor = cursor * 2;
            }
            else if (tree_Pointer->data[cursor] < _data)
            {
                cursor = 2 * cursor + 1;
            }
            else
            {
                assert(nullptr);
            }

            // 데이터 삽입.
            if (cursor > tree_Pointer->max_Size)
            {
                tree_expansion(tree_Pointer, tree_Pointer->data);
            }

            if (tree_Pointer->data[cursor] == -1)
            {
                tree_Pointer->data[cursor] = _data;
                break;
            }
        }
    }

    tree_Pointer->_Count++;
}

int find(tree* tree_Pointer, int item)
{
    if(tree_Pointer == nullptr)
    {
        assert(nullptr);
    }

    int index = 0;

    for(int i = 0; i < tree_Pointer->max_Size; i++)
    {
        if(tree_Pointer->data[i] == item)
        {
            index = i;
            break;
        }
    }

    if(index == 0)
    {
        return 0;
    }
    else
    {
        
        return index;
    }
    
}

void delete(tree* tree_Pointer, int item)
{
    int index = find(tree_Pointer, item);

    //1.삭제할 데이터를 못 찾은 경우.
    if(index == 0)
    {
        printf("delete is failed");
    }
    
    //2.삭제할 데이터를 찾은 경우.
    else
    {
        int child_num = check_child(tree_Pointer, index);

        //1.leaf node 삭제
        if(child_num == 0)
        {
            tree_Pointer->data[index] = -1;
        }
        //2.자식이 1개 있는 node 삭제
        else if(child_num == 1)
        {
            int child_sort = 2 * index;

            if(tree_Pointer->data[child_sort] == -1)
            {
                child_sort = 2 * index + 1;
            }

            tree_redefine(tree_Pointer, child_sort, index);            
        }
        //3.자식이 2개 있는 node 삭제
        else
        {
            int delete_index = 2 * index + 1;

            while(1)
            {
                if(tree_Pointer->data[2 * delete_index] == -1)
                {
                    break;
                }
                delete_index = 2 * delete_index;
            }

            tree_Pointer->data[index] = tree_Pointer->data[delete_index];
            tree_Pointer->data[delete_index] = -1;
        }
        
    }
    
}

int check_child(tree* tree_Pointer, int index)
{
    //데이터가 존재하지 않은 영역을 가리키는 0이 input으로 들어오거나, input 으로 들어온 index 
    //값이 트리에 있는 데이터 수 보다 많은 경우 예외처리
    if(index == 0 || tree_Pointer->_Count < index)
    {
        assert(nullptr);
    }

    if(2 * index <= tree_Pointer->_Count && 2 * index + 1 <= tree_Pointer->_Count)
    {
        return 2;
    }
    else if( (2 * index <= tree_Pointer->_Count) != ( 2 * index + 1 <= tree_Pointer->_Count )   )
    {
        return 1;
    }
    else
    {
        return 0;
    }
    
    
}

int is_Left_Child(tree* tree_Pointer, int index)
{
    if(index <= 0)
    {
        assert(nullptr);
    }

    if(index == 1)
    {
        return 0;
    }
    else
    {
        if( index % 2 == 0)
        {
            return 1;
        }
        else
        {
            return 0;
        }
        
    }    
}

int is_Right_Child(tree* tree_Pointer, int index)
{
    if (index <= 0)
    {
        assert(nullptr);
    }

    if (index == 1)
    {
        return 0;
    }
    else
    {
        if (index % 2 != 0)
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }
}

void tree_redefine(tree* tree_Pointer, int from, int to)
{
    tree_Pointer->data[to] = tree_Pointer->data[from];
    tree_Pointer->data[from] = -1;

    if(tree_Pointer->data[2 * temp] != -1)
    {
        tree_redefine(tree_Pointer, 2 * from, 2 * to);
    }
    if(tree_Pointer->data[2 * temp + 1] != -1)
    {
        tree_redefine(tree_Pointer, 2 * from + 1, 2 * to + 1);
    }
}