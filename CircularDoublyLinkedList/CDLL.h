#include <stdio.h>

typedef struct tagNode
{
	int data;
	struct tagNode* PrevNode;
	struct tagNode* NextNode;
}Node;

Node* CDLL_CreateNode(int NewData);
void CDLL_DestroyNode(Node* Node);
void CDLL_AppendNode(Node** Head, Node* NewNode);
void CDLL_InsertAfter(Node* Current, Node* NewNode);
void CDLL_InsertBefore(Node** Head, Node* Current, Node* NewNode);
void CDLL_RemoveNode(Node** Head, Node* Remove);
void CDLL_DeleteList(Node** Head);
Node* CDLL_GetNodeAt(Node* Head, int Location);
int CDLL_GetNodeCount(Node* Head);
void Print(Node* Head);



