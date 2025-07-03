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
	// 현재 빈 리스트인 경우
	if ((*Head) == nullptr)
	{
		*Head = NewNode;
		// 환형 구조를 가지고 있지만 노드가 하나만 있어서 모두 자신에게 돌아오도록 설정
		(*Head)->Next = *Head;
		(*Head)->Prev = *Head;
	}
	else
	{
		// 테일과 헤드 사이에 NewNode삽입
		Node* Tail = (*Head)->Prev;

		Tail->Next->Prev = NewNode;
		Tail->Next = NewNode;

		NewNode->Next = (*Head);
		NewNode->Prev = Tail; // 새로운 Tail의 Prev가 기존 Tail을 가리키도록 함
	}
}

void CDLL_InsertAfter(Node* Current, Node* NewNode)
{
	// 노드 삽입

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
