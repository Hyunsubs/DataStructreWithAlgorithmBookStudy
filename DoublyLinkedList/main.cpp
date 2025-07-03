#include <iostream>


// ���� ��ũ�� ����Ʈ

class Node
{
public:
	int Data;
	Node* Prev;
	Node* Next;

	Node(int NewData) : 
		Data(NewData),
		Prev(nullptr),
		Next(nullptr)
	{
		
	}
};

// ��� ����
Node* DLL_CreateNode(int NewData)
{
	Node* NewNode = new Node(NewData);

	NewNode->Data = NewData;
	NewNode->Prev = nullptr;
	NewNode->Next = nullptr;

	return NewNode;
}

// ��� ����
void DestroyNode(Node* Node)
{
	delete(Node);
}

void DLL_AppendNode(Node** Head, Node* NewNode)
{
	// ��� ��尡 nullptr�̶�� ���ο� ��尡 Head�� ��
	if ((*Head) == nullptr)
	{
		*Head = NewNode;
	}

	else
	{
		// ������ ã�� NewNode�� ����
		Node* Tail = (*Head);
		while (Tail->Next != nullptr)
		{
			Tail = Tail->Next;
		}

		Tail->Next = NewNode;
		NewNode->Prev = Tail; // Singly Linked List�� �ٸ��� ���� ������ ���ο� ������ Prev�� ����
	}
}

// Ư�� ��ġ ��� ��������(������ ���� �ڵ带 �����)
Node* DLL_GetNodeAt(Node* Head, int Location)
{
	Node* Current = Head;
	while (Current != nullptr && (--Location) >= 0)
	{
		Current = Current->Next;
	}
	
	return Current;
}

// Ư�� ��带 ����Ʈ���� ����
void DLL_RemoveNode(Node** Head, Node* Remove)
{
	// ������ ��尡 Head�� ���
	if ((*Head) == Remove)
	{
		// Head�� ���� ��带 ����Ŵ
		*Head = Remove->Next;
		// ���� ��尡 �ִ� ���
		if ((*Head) != nullptr)
		{
			// ���� ��带 ������ ���̱� ������ ���� ����� Prev�� nullptr�� �ž���
			(*Head)->Prev = nullptr;
		}

		// ������ ��尡 ����Ű�� Prev�� Next�� nullptr�� ����
		Remove->Prev = nullptr;
		Remove->Next = nullptr;
	}
	// Head �ܿ� ���
	else
	{
		Node* Temp = Remove;

		if (Remove->Prev != nullptr)
		{
			// ���� ��尡 ����Ű�� Next�� Remove�� ��尡 ���� Next�� �ž��� 
			Remove->Prev->Next = Temp->Next;
		}
		if (Remove->Next != nullptr)
		{
			// ������ ����� ���� ���� Remove�� ��尡 ���� Prev�� �ž���
			Remove->Next->Prev = Temp->Prev;
		}

		// Remove�� ������ �ִ� ���� Prev�� Next�� �ּҸ� nullptr�� �����Ͽ� ���Ἲ ����
		Remove->Prev = nullptr;
		Remove->Next = nullptr;
	}
}

// ��� ����
void DLL_InsertAfter(Node* Current, Node* NewNode)
{
	NewNode->Next = Current->Next;
	NewNode->Prev = Current;

	if (Current->Next != nullptr)
	{
		Current->Next->Prev = NewNode;
		Current->Next = NewNode;
	}
}

// ��� ���� ��ȯ
int DLL_GetNodeCount(Node* Head) 
{
	unsigned int Count = 0;
	Node* Current = Head;

	while (Current != nullptr)
	{
		Current = Current->Next; 
		Count++;
	}

	return Count;
}

// ����Ʈ�� ���� ���
void PrintReverse(Node* Head)
{
	Node* Current = Head;

	while (Current->Next != nullptr)
	{
		Current = Current->Next;
	}

	while (Current->Prev != nullptr)
	{
		std::cout << Current->Data << " ";
		Current = Current->Prev;
	}

	std::cout << Current->Data << " ";
}

int main()
{
	Node* List = nullptr;
	for (int i = 0; i < 20; i++)
	{
		Node* NewNode = nullptr;
		NewNode = DLL_CreateNode(i);
		DLL_AppendNode(&List, NewNode);
	}

	PrintReverse(List);



	return 0;
}