#pragma once
#include <iostream>

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


