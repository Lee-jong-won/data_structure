#include "StackArray.h"

/*

1.stack area�� main function frame�� heap ������ �����ϴ� stackMetaNode�� �ּҰ� ����Ǿ� �ִ�.
2.stackMetaNode���� ������ ũ��, ������ �ּ�, ������ �� �� ��ġ�� ����Ǿ� �ִ�.
3.�Լ��� �Ű������� ��ȯŸ��

Create / Destroy

(1)Create     Parameter : **StackMetaNode, int  / return : void
���ο� ������ ����� ���, ���� ���� �Լ��� ���� main function frame�� �ִ� ������ stackMedatNode�� �ּҰ� ���� �Ǿ���Ѵ�.
����, ���� ���� �Լ����� main function frame�� �����ϴ� ������ ������ �� �ֵ���
���� ���� �Լ��� �Ű������� ���������ͷ� �����ϰ�, �� �Ű������� stackMetaNode�� �ּҰ� ����� ������ �ּҸ� ���ڷ� �����Ѵ�.  

(2)Destroy    Parameter : **StackMetaNode / return : void
������ �޸𸮿��� �Ҵ� ���� �� �Ŀ�, stackMetaNode ���� �޸𸮿��� �Ҵ��� �����ǰ�, main stack frame���� stackMetaNode�� ����Ű�� �־��� ������
nullptr�� �Ҵ����־�� �Ѵ�. 

(3)Push, Top       Parameter : *StackMetaNode / return : StackElement
Push �Լ��� ����, main function frame�� �ִ� ������ ����� stackMetaNode�� �ּҰ� �ٲ�� ���� �ƴ϶�, �� �ּҿ� �����ؼ� stackMetaNode�� ����� stack�� �ּҷ�
�����ؼ� �����Ͱ� �����ǰų� �ܼ��� ��ȸ�Ǵ� ���̹Ƿ�, Parameter�� Ÿ���� �������̰�, return type�� stack�� ����� ��� ������ Ÿ���̴�.
*/


void AS_CreateStack(ArrayStack** Stack, int Capacity)
{
	// ������ ���� ����ҿ� ����
	(*Stack) = (ArrayStack*)malloc(sizeof(ArrayStack));

	// �Էµ� Capacity ��ŭ�� ��带 ���� ����ҿ� ����
	(*Stack)->Nodes = (Node*)malloc(sizeof(Node) * Capacity);

	// Capacity �� Top �ʱ�ȭ
	(*Stack)->Capacity = Capacity;
	(*Stack)->Top = -1;
}

void AS_DestroyStack(ArrayStack** Stack)
{
	// ��带 ���� ����ҿ��� ����
	free((*Stack)->Nodes);

	// ������ ���� ����ҿ��� ����
	free(*Stack);
}

int AS_Push(ArrayStack** Stack, ElementType Data)
{
	int status = 0;
	//status 1 : �� �� ����
	//status 0 : ������ ���� ����

	// stack�� �� �� �ִ��� Ȯ��
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
	//status 1 : ������ �� ����
	//status 0 : ������ ���� ���� ����

	ElementType POP_item = -99;

	// stack ��� �ִ��� Ȯ��
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
	//status 1 : ������ �� ����
	//status 0 : ������ ���� ���� ����

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