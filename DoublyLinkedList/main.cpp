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

int main()
{




	return 0;
}