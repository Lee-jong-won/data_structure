#include "LinkedListStack.h"


void LLS_CreateStack(LinkedListStack** Stack)
{
	// 스택을 힙 영역에 생성
	(*Stack) = (LinkedListStack*)malloc(sizeof(LinkedListStack));
	(*Stack)->List = NULL;
	(*Stack)->Top = NULL;
}


void LLS_DestroyStack(LinkedListStack* Stack)
{
	while (!LLS_IsEmpty(Stack))
	{
		Node* Popped = LLS_Pop(Stack);
		LLS_DestroyNode(Popped);
	}

	free(Stack);
}


Node* LLS_CreateNode(const char* Data)
{
	Node* newNode = (Node*)malloc(sizeof(Node));
	
	//문자열을 저장하기 위한 공간 할당하기
	newNode->Data = (char*)malloc(sizeof(strlen(Data) + 1));
	newNode->NextNode = NULL;
	strcpy(newNode->Data, Data);

	return newNode;
}

void LLS_DestroyNode(Node* _Node)
{
	free(_Node->Data);
	free(_Node);
}


void LLS_Push(LinkedListStack* Stack, Node* NewNode)
{
	if (Stack->List == NULL)
	{
		Stack->List = NewNode;
	}
	else
	{
		Stack->Top->NextNode = NewNode;
	}

	Stack->Top = NewNode;
}

Node* LLS_Pop(LinkedListStack* Stack)
{
	Node* TopNode = Stack->Top;

	if (Stack->List == Stack->Top)
	{
		Stack->List = NULL;
		Stack->Top = NULL;
	}
	else
	{
		Node* currentTop = Stack->List;

		while (currentTop->NextNode != Stack->Top)
		{
			currentTop = currentTop->NextNode;
		}

		Stack->Top = currentTop;
		Stack->Top->NextNode = NULL;
	}

	return TopNode;
}

Node* LLS_TOP(LinkedListStack* Stack)
{
	return Stack->Top;
}

int LLS_GetSize(LinkedListStack* Stack)
{
	int count = 0;

	Node* currentNode = Stack->List;

	while (currentNode != NULL)
	{
		count++;
		currentNode = currentNode->NextNode;
	}

	return count;
}

int LLS_IsEmpty(LinkedListStack* Stack)
{
	return (Stack->List == NULL);
}
