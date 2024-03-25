#include "StackArray.h"

/*

1.stack area의 main function frame에 heap 영역에 존재하는 stackMetaNode의 주소가 저장되어 있다.
2.stackMetaNode에는 스택의 크기, 스택의 주소, 스택의 맨 위 위치가 저장되어 있다.
3.함수의 매개변수와 반환타입

Create / Destroy

(1)Create     Parameter : **StackMetaNode, int  / return : void
새로운 스택을 만드는 경우, 스택 생성 함수를 통해 main function frame에 있는 변수에 stackMedatNode의 주소가 저장 되어야한다.
따라서, 스택 생성 함수에서 main function frame에 존재하는 변수에 접근할 수 있도록
스택 생성 함수의 매개변수를 더블포인터로 선언하고, 이 매개변수에 stackMetaNode의 주소가 저장될 변수의 주소를 인자로 전달한다.  

(2)Destroy    Parameter : **StackMetaNode / return : void
스택을 메모리에서 할당 해제 한 후에, stackMetaNode 역시 메모리에서 할당이 해제되고, main stack frame에서 stackMetaNode를 가리키고 있었던 변수에
nullptr를 할당해주어야 한다. 

(3)Push, Top       Parameter : *StackMetaNode / return : StackElement
Push 함수를 통해, main function frame에 있는 변수에 저장된 stackMetaNode의 주소가 바뀌는 것이 아니라, 이 주소에 접근해서 stackMetaNode에 저장된 stack의 주소로
접근해서 데이터가 삭제되거나 단순히 조회되는 것이므로, Parameter의 타입은 포인터이고, return type은 stack에 저장된 노드 데이터 타입이다.
*/


void AS_CreateStack(ArrayStack** Stack, int Capacity)
{
	// 스택을 자유 저장소에 생성
	(*Stack) = (ArrayStack*)malloc(sizeof(ArrayStack));

	// 입력된 Capacity 만큼의 노드를 자유 저장소에 생성
	(*Stack)->Nodes = (Node*)malloc(sizeof(Node) * Capacity);

	// Capacity 및 Top 초기화
	(*Stack)->Capacity = Capacity;
	(*Stack)->Top = -1;
}

void AS_DestroyStack(ArrayStack** Stack)
{
	// 노드를 자유 저장소에서 해제
	free((*Stack)->Nodes);

	// 스택을 자유 저장소에서 해제
	free(*Stack);
}

int AS_Push(ArrayStack** Stack, ElementType Data)
{
	int status = 0;
	//status 1 : 꽉 찬 상태
	//status 0 : 꽉차지 않은 상태

	// stack이 꽉 차 있는지 확인
	if ( AS_isFull(*Stack) )
	{
		status = 1;
	}
	
	if (status != 1)
	{
		(*Stack)->Top++;
		(*Stack)->Nodes[(*Stack)->Top].data = Data;	
		return 1;
	}
	else
	{
		return -1;
	}
}

ElementType AS_Pop(ArrayStack* Stack)
{
	int status = 0;
	//status 1 : 스택이 빈 상태
	//status 0 : 스택이 비지 않은 상태

	ElementType POP_item = -99;

	// stack 비어 있는지 확인
	if (AS_isEmpty(Stack))
	{
		status = 1;
	}
	
	if (status == 0)
	{
		POP_item = Stack->Nodes[Stack->Top].data;

		//free(Stack->Nodes + Stack->Top);

		--Stack->Top;
	}

	return POP_item;
}

ElementType AS_Top(ArrayStack* Stack)
{
	ElementType Top = -99;
	//status 1 : 스택이 빈 상태
	//status 0 : 스택이 비지 않은 상태

	if(AS_isEmpty(Stack) == 0)
	{	
		Top = Stack->Nodes[Stack->Top].data;
	}

	return Top;
}

int AS_GetSize(ArrayStack* Stack)
{
	return Stack->Top + 1;
}

int AS_isEmpty(ArrayStack* Stack)
{
	if (Stack->Top == -1)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

int AS_isFull(ArrayStack* Stack)
{
	if (Stack->Top == Stack->Capacity)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}