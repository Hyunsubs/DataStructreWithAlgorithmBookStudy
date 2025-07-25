#pragma once
#include <iostream>

class Node
{
public:
	char* Data;
	Node* NextNode;

	Node(const char* Data)
		: Data(new char[strlen(Data) + 1])
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
	// 스택을 자유 저장소에 생성
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
		// 스택의 Top 위에 새 노드를 얹는다.
		Stack->Top->NextNode = NewNode;
	}

	// 스택의 Top 필드에 새 노드의 주소를 등록한다.
	Stack->Top = NewNode;
}

bool LLS_IsEmpty(LinkedListStack* Stack)
{
	return Stack->List == nullptr;
}


Node* LLS_Pop(LinkedListStack* Stack)
{
	// LLS_Pop() 함수가 반환할 최상위 노드 저장
	Node* TopNode = Stack->Top;

	if (Stack->List == Stack->Top)
	{
		Stack->List = nullptr;
		Stack->Top = nullptr;
	}

	else
	{
		// Top 아래에 있던 노드를 새로운 CurrentTop에 저장
		Node* CurrentTop = Stack->List;

		while (CurrentTop != nullptr && CurrentTop->NextNode != Stack->Top)
		{
			CurrentTop = CurrentTop->NextNode;
		}

		// CurrentTop을 Top에 저장
		if (CurrentTop)
		{
			Stack->Top = CurrentTop;
			CurrentTop->NextNode = nullptr;
		}
	}

	return TopNode;
}


