#include <iostream>
using namespace std;
// ��ũ�� ����Ʈ ��� ����
// ������ ���� �뷮�� ������ ���� �ʾƵ� �ȴٴ� ��

class Node
{
public:
	char* Data;
	Node* NextNode;

	Node(const char* Data)
		: Data(new char[sizeof(Data) + 1])
		, NextNode(nullptr)
	{
		strcpy_s(this->Data, sizeof(Data), Data);
	}

	~Node()
	{
		if (Data)
		{
			delete[] Data;
			Data = nullptr;
		}

		if (NextNode)
		{
			NextNode = nullptr;
		}
	}
};

class LinkedListStack
{
public:
	Node* List;
	Node* Top;

	LinkedListStack()
		: List(nullptr)
		, Top(nullptr)
	{
	}
};

void LLS_CreateStack(LinkedListStack** Stack)
{
	// ������ ���� ����ҿ� ����
	(*Stack) = new LinkedListStack();
}


void LLS_DestroyStack(LinkedListStack* Stack)
{
	Node* Current = Stack->List;
	while (Current != nullptr)
	{
		Node* Temp = Current;
		Current = Current->NextNode;
		delete(Temp);
	}

	Stack->Top = nullptr;
}

void LLS_Push(LinkedListStack* Stack, Node* NewNode)
{
	if (Stack->List == nullptr)
	{
		Stack->List = NewNode;
	}
	else
	{
		// ������ Top ���� �� ��带 ��´�.
		Stack->Top->NextNode = NewNode;
	}

	// ������ Top �ʵ忡 �� ����� �ּҸ� ����Ѵ�.
	Stack->Top = NewNode;
}

Node* LLS_Pop(LinkedListStack* Stack)
{
	// LLS_Pop() �Լ��� ��ȯ�� �ֻ��� ��� ����
	Node* TopNode = Stack->Top;

	if (Stack->List == Stack->Top)
	{
		Stack->List = nullptr;
		Stack->Top = nullptr;
	}

	else
	{
		// Top �Ʒ��� �ִ� ��带 ���ο� CurrentTop�� ����
		Node* CurrentTop = Stack->List;

		while (CurrentTop != nullptr && CurrentTop->NextNode != Stack->Top)
		{
			CurrentTop = CurrentTop->NextNode;
		}

		// CurrentTop�� Top�� ����
		if (CurrentTop)
		{
			Stack->Top = CurrentTop;
			CurrentTop->NextNode = nullptr;
		}
	}

	return TopNode;
}


int main()
{

	int i = 0;
	int Count = 0;
	Node* Popped;

	LinkedListStack* Stack;

	LLS_CreateStack(&Stack);

	LLS_Push(Stack, new Node("ASC"));
	LLS_Push(Stack, new Node("AVC"));
	LLS_Push(Stack, new Node("KOSD"));

	Popped = LLS_Pop(Stack);
	cout << Popped->Data << "\n";


	Popped = LLS_Pop(Stack);
	cout << Popped->Data << "\n";

	Popped = LLS_Pop(Stack);
	cout << Popped->Data << "\n";
	
	return 0;
}