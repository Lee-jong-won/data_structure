#include "DoublyLinkedList.h"

int main()
{
	int i = 0;
	int Count = 0;
	Node* List = NULL;
	Node* NewNode = NULL;
	Node* Current = NULL;
	
	// 노드 5개 추가
	for (int i = 0; i < 5; i++)
	{
		NewNode = DLL_CreateNode(i);
		DLL_AppendNode(&List, NewNode);
	}

	// 리스트 출력
	Print(List);

	// 리스트의 세 번째 칸 뒤에 노드 삽입
	printf("\nInserting 3000 after 2.....\"\n");
	Current = DLL_GetNodeAt(List, 2);
	NewNode = DLL_CreateNode(3000);
	DLL_InsertAfter(Current, NewNode);

	// 리스트 출력
	Print(List);

	// 리스트의 세 번째 칸 앞에 노드 삽입
	printf("\nInserting 4000 before 2.....\"\n");	
	Current = DLL_GetNodeAt(List, 2);
	NewNode = DLL_CreateNode(4000);
	DLL_InsertBefore(&List, Current, NewNode);

	// 리스트 출력
	Print(List);

	// 리스트의 네 번째 칸 삭제
	printf("\nRemoving fourth item.....\"\n");
	Current = DLL_GetNodeAt(List, 3);
	DLL_RemoveNode(&List, Current);

	
	// 리스트 출력
	Print(List);

	// 리스트의 첫 번째 칸 삭제
	printf("\nRemoving first item.....\"\n");
	Current = DLL_GetNodeAt(List, 0);
	DLL_RemoveNode(&List, Current);

	// 리스트 출력
	Print(List);

	// 리스트 거꾸로 출력
	printf("\nReverse printing.....\"\n");
	PrintReverse(List);

	// 리스트 삭제
	printf("\nDelete List.....\"\n");
	printf("List num:%d Before deleting\n", DLL_GetNodeCount(List));
	
	DLL_DeleteList(&List);
	
	printf("List num:%d After deleting\n", DLL_GetNodeCount(List));

	return 0;

}