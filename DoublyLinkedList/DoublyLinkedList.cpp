#include "DoublyLinkedList.h"
#include <stdio.h>
#include <stdlib.h>

Node* DLL_CreateNode(int NewData)
{
	Node* newNode = (Node*)malloc(sizeof(Node));
	newNode->data = NewData;
	newNode->NextNode = nullptr;
	newNode->PrevNode = nullptr;

	return newNode;
}

void DLL_DestroyNode(Node* Node)
{
	free(Node);
}

void DLL_AppendNode(Node** Head, Node* NewNode)
{
	if ((*Head) == nullptr)
		(*Head) = NewNode;
	else
	{
		Node* tailNode = *Head;
		
		while (tailNode->NextNode)
		{
			tailNode = tailNode->NextNode;
		}

		tailNode->NextNode = NewNode;
		NewNode->PrevNode = tailNode;
	}
}

void DLL_InsertAfter(Node* Current, Node* NewNode)
{
	if (Current->NextNode != nullptr) //Current가 tail이 아닌 경우
	{
		NewNode->NextNode = Current->NextNode;
		Current->NextNode->PrevNode = NewNode;

		Current->NextNode = NewNode;
		NewNode->PrevNode = Current;
	}
	else // Current가 tail 인 경우
	{
		Current->NextNode = NewNode;
		NewNode->PrevNode = Current;
	}
}

void DLL_InsertBefore(Node** Head, Node* Current, Node* NewNode)
{
	if (Current == *Head)
	{
		NewNode->NextNode = Current;
		Current->PrevNode = NewNode;
		*Head = NewNode;
	}
	else
	{
		Current->PrevNode->NextNode = NewNode;
		NewNode->PrevNode = Current->PrevNode;

		Current->PrevNode = NewNode;
		NewNode->NextNode = Current;
	}
}

void DLL_RemoveNode(Node** Head, Node* Remove)
{
	Node* current = *Head;

	if ( Remove == *Head )
	{
		*Head = Remove->NextNode;
		(*Head)->PrevNode = nullptr;
	}
	else
	{
		Node* current = *Head;

		while (current->NextNode != Remove)
		{
			current = current->NextNode;
		}

        if (Remove->NextNode != nullptr) // Remove가 tail이 아닌 경우
		{
			current->NextNode = Remove->NextNode;
			Remove->NextNode->PrevNode = current;
		}
		else // Remove가 tail인 경우
		{
			current->NextNode = nullptr;
		}

	}

	DLL_DestroyNode(Remove);
}

void DLL_DeleteList(Node** Head)
{
	Node* Current = *Head;
	Node* Next = nullptr;

	while (Current)
	{
		Next = Current->NextNode;
		DLL_DestroyNode(Current);
		Current = Next;
	}

	*Head = nullptr;
}

Node* DLL_GetNodeAt(Node* Head, int Location)
{
	Node* current = Head;

	while (current->NextNode != nullptr && --Location >= 0) // Location : head로부터 cursor가 몇 번 옮겨지면 찾고자 하는 위치로 cursor가 이동하는지를 나타냄
	{
		current = current->NextNode;
	}

	return current;
}

int DLL_GetNodeCount(Node* Head)
{
	Node* current = Head;
	int num = 0;

	while (current)
	{
		num++;
		current = current->NextNode;
	}
	
	return num;
}

void PrintReverse(Node* Head)
{
	if (Head == nullptr)
		return;
	
	Node* tail = Head;
	Node* Current = nullptr;
	int num = 1;

	while (tail->NextNode)
	{
		tail = tail->NextNode;
		num++;
	}
	Current = tail;

	while (Current)
	{
		printf("List[%d] : %d\n", num - 1, Current->data);
		Current = Current->PrevNode;
		num--;
	}	
}

void Print(Node* Head)
{
	if (Head == nullptr)
		return;
	
	Node* Current = Head;
	int idx = 0;

	while (Current)
	{
		printf("List[%d] : %d\n", idx, Current->data);
		Current = Current->NextNode;
		idx++;
	}
}
