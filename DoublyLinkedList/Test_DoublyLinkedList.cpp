#include "DoublyLinkedList.h"

int main()
{
	int i = 0;
	int Count = 0;
	Node* List = NULL;
	Node* NewNode = NULL;
	Node* Current = NULL;
	
	// ��� 5�� �߰�
	for (int i = 0; i < 5; i++)
	{
		NewNode = DLL_CreateNode(i);
		DLL_AppendNode(&List, NewNode);
	}

	// ����Ʈ ���
	Print(List);

	// ����Ʈ�� �� ��° ĭ �ڿ� ��� ����
	printf("\nInserting 3000 after 2.....\"\n");
	Current = DLL_GetNodeAt(List, 2);
	NewNode = DLL_CreateNode(3000);
	DLL_InsertAfter(Current, NewNode);

	// ����Ʈ ���
	Print(List);

	// ����Ʈ�� �� ��° ĭ �տ� ��� ����
	printf("\nInserting 4000 before 2.....\"\n");	
	Current = DLL_GetNodeAt(List, 2);
	NewNode = DLL_CreateNode(4000);
	DLL_InsertBefore(&List, Current, NewNode);

	// ����Ʈ ���
	Print(List);

	// ����Ʈ�� �� ��° ĭ ����
	printf("\nRemoving fourth item.....\"\n");
	Current = DLL_GetNodeAt(List, 3);
	DLL_RemoveNode(&List, Current);

	
	// ����Ʈ ���
	Print(List);

	// ����Ʈ�� ù ��° ĭ ����
	printf("\nRemoving first item.....\"\n");
	Current = DLL_GetNodeAt(List, 0);
	DLL_RemoveNode(&List, Current);

	// ����Ʈ ���
	Print(List);

	// ����Ʈ �Ųٷ� ���
	printf("\nReverse printing.....\"\n");
	PrintReverse(List);

	// ����Ʈ ����
	printf("\nDelete List.....\"\n");
	printf("List num:%d Before deleting\n", DLL_GetNodeCount(List));
	
	DLL_DeleteList(&List);
	
	printf("List num:%d After deleting\n", DLL_GetNodeCount(List));

	return 0;

}