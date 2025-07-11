#include <iostream>
#define _CRTDBG_MAP_ALLOC
#include <stdlib.h>
#include <crtdbg.h>


// �����͸� ���� ��� ����
class Node 
{
public:
	int Data;
};

// ���� ����
// �뷮�� �ֻ��� ��� ��ġ �׸��� ����� �迭 ������ ���� �־�� ��
class ArrayStack
{
public:
	int Capacity;
	int Top;
	Node* Nodes;

	~ArrayStack() 
	{
		if (Nodes)
		{
			delete[] Nodes;
		}
	}
};

// ���� ����
void AS_CreateStack(ArrayStack** Stack, int Capacity)
{
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

	// ������ ���� ����ҿ� ����
	(*Stack) = new ArrayStack();

	// �Էµ� Capacity ��ŭ�� ��带 ���� ����ҿ� ����
	(*Stack)->Nodes = new Node[Capacity];

	// Capacity �� Top �ʱ�ȭ -1�� ������� �ǹ���
	(*Stack)->Capacity = Capacity;
	(*Stack)->Top = -1;
}

// ���� ����
void AS_DestoryStack(ArrayStack* Stack)
{
	// ������ ���� ����ҿ��� ����
	// ���� ���� �Ҹ��ڿ��� ���쵵�� å ����� �ڵ� �ٸ��� ����
	delete(Stack);
}

// ��� ���� ����
void AS_Push(ArrayStack* Stack, int Data)
{
	Stack->Top++;
	Stack->Nodes[Stack->Top].Data = Data;
}

// ��� ���� ���� (���ŵǱ��� �ֻ��� ���� ��ȯ�ؾ���)
int AS_Pop(ArrayStack* Stack)
{
	return Stack->Nodes[(Stack->Top)--].Data;
}

bool AS_IsEmpty(ArrayStack* Stack)
{
	return Stack->Top > - 1 ? true : false;
}

int AS_Top(ArrayStack* Stack)
{
	return Stack->Nodes[(Stack->Top)].Data;
}

int AS_GetSize(ArrayStack* Stack)
{
	return (Stack->Top) + 1;
}

bool AS_IsFull(ArrayStack* Stack)
{
	return Stack->Top + 1 == Stack->Capacity;
}

int main()
{
	int i = 0;
	ArrayStack* Stack = nullptr;
	
	AS_CreateStack(&Stack, 10);

	AS_Push(Stack, 3);
	AS_Push(Stack, 5);
	AS_Push(Stack, 7);
	AS_Push(Stack, 9);
	AS_Push(Stack, 12);
	AS_Push(Stack, 12);
	AS_Push(Stack, 12);
	AS_Push(Stack, 12);
	AS_Push(Stack, 12);
	AS_Push(Stack, 12);

	std::cout << "Capacity : " << Stack->Capacity << " Size : " << AS_GetSize(Stack) << " Top : " << AS_Top(Stack) << "\n";
	AS_IsFull(Stack) ? std::cout << "Stack Is Full now\n" : std::cout << "Stack Is not Full\n";
	AS_DestoryStack(Stack);


	return 0;
}