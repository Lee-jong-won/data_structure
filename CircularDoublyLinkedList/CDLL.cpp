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
	AppendNode�� ���ۿ� ���� main stack frame�� �������� ����Ű�� �ִ� ��尡 ���ٰ� �����.
	�̶�, ���� �����͸� �Ű������� ������� ������ main�� �ִ� ������ appendnode �Լ��� ������ �� ����. 
	���� ���� �����͸� ����Ѵ�.
	*/

	if (*Head == nullptr)
	{
		*Head = NewNode;
		(*Head)->NextNode = *Head;
		(*Head)->PrevNode = *Head;
	}
	else
	{
		// ���ϰ� ��� ���̿� NewNode�� ����
		Node* Tail = (*Head)->PrevNode;

		Tail->NextNode = NewNode;
		NewNode->PrevNode = Tail;

		NewNode->NextNode = *Head;
		(*Head)->PrevNode = NewNode;
	}
}

void CDLL_InsertAfter(Node* Current, Node* NewNode)
{
	//�� ���� ���� ����� ���� ��� ����
	NewNode->NextNode = Current->NextNode;
	Current->NextNode->PrevNode = NewNode;

	//���� ���� �� ��� ����
	Current->NextNode = NewNode;
	NewNode->PrevNode = Current;
}

void CDLL_InsertBefore(Node** Head, Node* Current, Node* NewNode)
{
	//Current->prev�� ����� ���� ���� ����Ǹ�, ��尡 �� ���ο� ���� tail ��带 ������ �� ���� ������ Current->prev�� ����� ���� ���߿� �����Ѵ�.		
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

	while (current->NextNode != nullptr && --Location >= 0) // Location : head�κ��� cursor�� �� �� �Ű����� ã���� �ϴ� ��ġ�� cursor�� �̵��ϴ����� ��Ÿ��
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

