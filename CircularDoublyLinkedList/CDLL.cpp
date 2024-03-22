#include "CDLL.h"
#include <stdio.h>
#include <stdlib.h>

Node* CDLL_CreateNode(int NewData)
{
	Node* NewNode = (Node*)malloc(sizeof(Node));

	NewNode->data = NewData;
	NewNode->NextNode = nullptr;
	NewNode->PrevNode = nullptr;

	return NewNode;
}

void CDLL_DestroyNode(Node* Node)
{
	free(Node);
}

void CDLL_AppendNode(Node** Head, Node* NewNode) 
{
	/*
	AppendNode의 동작에 따라 main stack frame의 변수들이 가리키고 있는 노드가 없다가 생긴다.
	이때, 이중 포인터를 매개변수로 사용하지 않으면 main에 있는 변수에 appendnode 함수가 접근할 수 없다. 
	따라서 이중 포인터를 사용한다.
	*/

	if (*Head == nullptr)
	{
		*Head = NewNode;
		(*Head)->NextNode = *Head;
		(*Head)->PrevNode = *Head;
	}
	else
	{
		// 테일과 헤드 사이에 NewNode를 삽입
		Node* Tail = (*Head)->PrevNode;

		Tail->NextNode = NewNode;
		NewNode->PrevNode = Tail;

		NewNode->NextNode = *Head;
		(*Head)->PrevNode = NewNode;
	}
}

void CDLL_InsertAfter(Node* Current, Node* NewNode)
{
	//새 노드와 기존 노드의 다음 노드 연결
	NewNode->NextNode = Current->NextNode;
	Current->NextNode->PrevNode = NewNode;

	//기존 노드와 새 노드 연결
	Current->NextNode = NewNode;
	NewNode->PrevNode = Current;
}

void CDLL_InsertBefore(Node** Head, Node* Current, Node* NewNode)
{
	//Current->prev에 저장된 값이 먼저 변경되면, 헤드가 될 새로운 노드와 tail 노드를 연결할 수 없기 때문에 Current->prev에 저장된 값은 나중에 변경한다.		
	Current->PrevNode->NextNode = NewNode;
	NewNode->PrevNode = Current->PrevNode;

	Current->PrevNode = NewNode;
	NewNode->NextNode = Current;
}

void CDLL_RemoveNode(Node** Head, Node* Remove)
{
	Remove->PrevNode->NextNode = Remove->NextNode;
	Remove->NextNode->PrevNode = Remove->PrevNode;
	
	if (*Head == Remove)
	{
		*Head = Remove->NextNode;
	}


	CDLL_DestroyNode(Remove);
}

void CDLL_DeleteList(Node** Head)
{
	Node* Current = *Head;
	Node* Next = nullptr;

	while (Current)
	{
		Next = Current->NextNode;
		CDLL_DestroyNode(Current);
		Current = Next;

		if (Current == *Head)
			break;
	}

	*Head = nullptr;
}

Node* CDLL_GetNodeAt(Node* Head, int Location)
{
	Node* current = Head;

	while (current->NextNode != nullptr && --Location >= 0) // Location : head로부터 cursor가 몇 번 옮겨지면 찾고자 하는 위치로 cursor가 이동하는지를 나타냄
	{
		current = current->NextNode;
	}

	return current;
}

int CDLL_GetNodeCount(Node* Head)
{
	Node* current = Head;
	int num = 0;

	while (current)
	{
		num++;
		current = current->NextNode;

		if (current == Head)
			break;
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

