#include <iostream>

// ��ũ�� ����Ʈ
// ����
// �� ��帶�� ���� ��带 �����Ѿ� �ϱ� ������ �߰������� �޸𸮸� �Ҹ��Ѵ�.
// Ư�� ��ġ�� �ִ� ��忡 �����ϴµ� �ʿ��� ����� �ſ�ũ��
// ����
// ���ο� ����� �߰� ����, ������ ������.
// ���� ����� ���� ��带 �������°Ϳ� ����� �߻����� �ʴ´�.

// ���ó
// ���� ������ ����� �Ͼ���� ��ȸ�� �幰�� �Ͼ�°�


class Node
{
public:
	int data;
	Node* next;

	Node(int NewData)
		: data(NewData)
		, next(nullptr)
	{
	}
	
}; 


Node* SLL_CreateNode(int NewData)
{
	Node* NewNode = new Node(NewData);
	NewNode->next = nullptr;
	return NewNode;
}

void SLL_DestroyNode(Node* Node)
{
	delete Node;
	Node = nullptr;
}

void SLL_AppendNode(Node** Head, Node* NewNode)
{
	// ��� ��尡 nullptr �̶�� ���ο� ��尡 Head�� �ȴ�.
	if ((*Head) == nullptr)
	{
		*Head = NewNode;
	}

	else
	{
		// ������ ã�� NewNode�� �����Ѵ�.
		Node* Tail = (*Head);

		while (Tail->next != nullptr)
		{
			Tail = Tail->next;
		}

		Tail->next = NewNode;
	}
}

Node* SLL_GetNodeAt(Node* Head, int Location)
{
	Node* Current = Head;
	while (Current != nullptr && (--Location) >= 0)
	{
		Current = Current->next;
	}
	return Current;
}

void SLL_RemoveNode(Node** Head, Node* Remove)
{
	if ((*Head) == Remove)
	{
		*Head = Remove->next;
	}

	else
	{
		Node* Current = *Head;
		while (Current != nullptr && Current->next != Remove)
		{
			Current = Current->next;
		}

		if (Current != nullptr)
		{
			Current->next = Remove->next;
		}
	}
}

void SLL_InsertBefore(Node** Head, Node* Current, Node* NewHead)
{
	if ((*Head)->next == Current)
	{
		(*Head)->next = NewHead;
		NewHead->next = Current;
	}
}

void SLL_DestroyAllNodes(Node** List)
{
	Node* Head = *List;
	while (Head != nullptr)
	{
		Node* NewHead = Head->next;
		std::cout << Head->data << " ��� ���� ����\n";
		delete Head;
		Head = NewHead;
	}

	std::cout << "��� ����� ������ �Ϸ�Ǿ����ϴ�.\n";
}

int main()
{

	// ��� ��ȸ �׽�Ʈ
	Node* List = nullptr;
	Node* MyNode = nullptr;

	SLL_AppendNode(&List, SLL_CreateNode(117));
	SLL_AppendNode(&List, SLL_CreateNode(119));


	MyNode = SLL_GetNodeAt(List, 1); // �ι�° ����� �ּҸ� MyNode�� ����.
	SLL_InsertBefore(&List, MyNode, SLL_CreateNode(115));
	MyNode = SLL_GetNodeAt(List, 0); // �ι�° ����� �ּҸ� MyNode�� ����.
	std::cout << MyNode->data << "\n";
	MyNode = SLL_GetNodeAt(List, 1); // �ι�° ����� �ּҸ� MyNode�� ����.
	std::cout << MyNode->data << "\n";
	MyNode = SLL_GetNodeAt(List, 2); // �ι�° ����� �ּҸ� MyNode�� ����.
	std::cout << MyNode->data << "\n";

	SLL_DestroyAllNodes(&List);

	return 0;
}