#include "CDLL.h"

int main()
{
	int i = 0;
	int Count = 0;
	Node* List = nullptr;
	Node* NewNode = nullptr;
	Node* Current = nullptr;
	
	// ��� 5�� �߰�
	for (int i = 0; i < 5; i++)
	{
		NewNode = CDLL_CreateNode(i);
		CDLL_AppendNode(&List, NewNode);
	}

	// ����Ʈ ���
	Count = CDLL_GetNodeCount(List);
	for (int i = 0; i < Count; i++)
	{
		Current = CDLL_GetNodeAt(List, i);
		printf("List[%d] : %d\n", i, Current->data);
	}

	// ����Ʈ�� �� ��° ĭ �ڿ� ��� ����
	printf("\nInserting 3000 After[2]...\n\n");

	Current = CDLL_GetNodeAt(List, 2);
	NewNode = CDLL_CreateNode(3000);
	CDLL_InsertAfter(Current, NewNode);

	// ����Ʈ�� �� ��° ĭ ��� ����
	printf("\nRemoving Node at 2...\n");

	Current = CDLL_GetNodeAt(List, 2);
	CDLL_RemoveNode(&List, Current);

	// ����Ʈ ���
	Count = CDLL_GetNodeCount(List);
	for (int i = 0; i < Count; i++)
	{
		Current = CDLL_GetNodeAt(List, i);
		printf("List[%d] : %d\n", i, Current->data);
	}

	// ����Ʈ�� �� ��° ĭ ��� ����
	printf("\nRemoving Node at 3...\n");
	Current = CDLL_GetNodeAt(List, 3);
	CDLL_RemoveNode(&List, Current);
	
	// ����Ʈ ���
	// (��� ������ 2�踸ŭ ������ ���� ȯ������ Ȯ���Ѵ�.)
	Count = CDLL_GetNodeCount(List);
	for (int i = 0; i < Count * 2; i++)
	{
		if (i == 0)
			Current = List;
		else
			Current = Current->NextNode;

		printf("List[%d] : %d\n", i, Current->data);
	}

	//��� ��带 �޸𸮿��� ����
	CDLL_DeleteList(&List);

	return 0;
}
