#include <stdio.h>

typedef struct tagNode
{
	int data;
	struct tagNode* PrevNode;
	struct tagNode* NextNode;
}Node;

Node* DLL_CreateNode(int NewData);
void DLL_DestroyNode(Node* Node);
void DLL_AppendNode(Node** Head, Node* NewNode);
void DLL_InsertAfter(Node* Current, Node* NewNode);
void DLL_InsertBefore(Node** Head, Node* Current, Node* NewNode);
void DLL_RemoveNode(Node** Head, Node* Remove);
void DLL_DeleteList(Node** Head);
Node* DLL_GetNodeAt(Node* Head, int Location);
int DLL_GetNodeCount(Node* Head);
void PrintReverse(Node* Head);
void Print(Node* Head);

