#include "StackArray.h"

int main()
{
	int i = 0;
	ArrayStack* Stack = NULL;

	AS_CreateStack(&Stack, 4);

	AS_Push(&Stack, 3);
	AS_Push(&Stack, 37);
	AS_Push(&Stack, 11);
	AS_Push(&Stack, 12);

	printf("Capacity : %d, Size : %d, Top: %d\n\n", Stack->Capacity, AS_GetSize(Stack), AS_Top(Stack));

	for (int i = 0; i < 4; i++)
	{
		if (AS_isEmpty(Stack))
			break;
		
		int POP = AS_Pop(Stack);
		if(POP != -99)
			printf("Popped : %d. ", POP);
		else
		{
			printf("StacK is Empty");
		}

		int TOP = AS_Top(Stack);
		if(TOP != -99)
			printf("Currrent Top : %d\n", TOP);
		else
			printf("Stack is Empty.\n");

	}

	// Empty check
	int POP = AS_Pop(Stack);
	if (POP != -99)
		printf("Popped : %d\n", POP);
	else
	{
		printf("StacK is Empty\n");
	}

	// Empty check
	int TOP = AS_Top(Stack);
	if (TOP != -99)
		printf("Currrent Top : %d\n", TOP);
	else
		printf("Stack is Empty.\n");


	//Re-push
	AS_Push(&Stack, 12);


	//Top check
	int TOP2 = AS_Top(Stack);
	if (TOP2 != -99)
		printf("Currrent Top : %d\n", TOP2);
	else
		printf("Stack is Empty.\n");

}