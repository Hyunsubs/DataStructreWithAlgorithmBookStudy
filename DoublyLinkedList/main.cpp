#include <iostream>


// 더블 링크드 리스트

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

// 노드 생성
Node* DLL_CreateNode(int NewData)
{
	Node* NewNode = new Node(NewData);

	NewNode->Data = NewData;
	NewNode->Prev = nullptr;
	NewNode->Next = nullptr;

	return NewNode;
}

// 노드 삭제
void DestroyNode(Node* Node)
{
	delete(Node);
}

int main()
{




	return 0;
}