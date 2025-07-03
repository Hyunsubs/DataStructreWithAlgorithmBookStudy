#include "CircularDoublyLinkedList.h"

Node* CDLL_CreateNode(int Data)
{
	Node* NewNode = new Node(Data);
	return NewNode;
}

void CDLL_DestoryNode(Node* Node)
{
	delete(Node);
}

void CDLL_AppendNode(Node** Head, Node* NewNode)
{
	// ���� �� ����Ʈ�� ���
	if ((*Head) == nullptr)
	{
		*Head = NewNode;
		// ȯ�� ������ ������ ������ ��尡 �ϳ��� �־ ��� �ڽſ��� ���ƿ����� ����
		(*Head)->Next = *Head;
		(*Head)->Prev = *Head;
	}
	else
	{
		// ���ϰ� ��� ���̿� NewNode����
		Node* Tail = (*Head)->Prev;

		Tail->Next->Prev = NewNode;
		Tail->Next = NewNode;

		NewNode->Next = (*Head);
		NewNode->Prev = Tail; // ���ο� Tail�� Prev�� ���� Tail�� ����Ű���� ��
	}
}

void CDLL_InsertAfter(Node* Current, Node* NewNode)
{
	// ��� ����

	NewNode->Next = Current->Next;
	NewNode->Prev = Current;

	if (Current->Next != nullptr)
	{
		Current->Next->Prev = NewNode;
		Current->Next = NewNode;
	}
}

void RemoveNode(Node** Head, Node* Remove)
{
	if ((*Head) == Remove)
	{
		(*Head)->Prev->Next = Remove->Next;
		(*Head)->Next->Prev = Remove->Prev;

		*Head = Remove->Next;
		
		Remove->Prev = nullptr;
		Remove->Next = nullptr;
	}
	else
	{
		Remove->Prev->Next = Remove->Next;
		Remove->Next->Prev = Remove->Prev;

		Remove->Prev = nullptr;
		Remove->Next = nullptr;
	}
}

Node* CDLL_GetNodeAt(Node* Head, int Location)
{
	Node* Current = Head;

	while (Current != nullptr && (--Location) >= 0)
	{
		Current = Current->Next;
	}

	return Current;
}

int CDLL_GetNodeCount(Node* Head)
{
	unsigned int Count = 0;
	Node* Current = Head;

	while (Current != nullptr)
	{
		Current = Current->Next;
		Count++;

		if (Current == Head)
			break;
	}

	return Count;
}

void PrintNode(Node* _Node)
{
	if (_Node->Prev == nullptr)
	{
		cout << "Prev : NULL";
	}
	else
	{
		cout << "Prev : " << _Node->Prev->Data;
	}

	cout << "Current" << _Node->Data;

	if (_Node->Next == nullptr)
	{
		cout << "Next : nullptr\n";
	}
	else
	{
		cout << "Next : " << _Node->Next->Data << "\n";
	}
}
