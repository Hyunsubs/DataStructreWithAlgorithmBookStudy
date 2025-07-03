#include "CircularDoublyLinkedList.h"

// ȯ�� ��ũ�� ����Ʈ(Circular Linked List)
// �׸��� ��ȭ�� �����ϴ� ��κ��ν�ó�� �Ӹ��� ������ ���� �ִ� ������
// �� Head->Prev = Tail  Tail->Next = Head�� ����� �ִ� ������ �ǹ���

// �̷��� �����ϸ� AppendNode ������ �ſ� ������ �� �� ����
// Reverse�� ��带 Ž���ϴ°͵� ������




int main()
{
	int i = 0;
	int Count = 0;
	Node* List = nullptr;
	Node* NewNode = nullptr;
	Node* Current = nullptr;

	// ��� 5�� �߰� 
	for (int i = 0; i < 5; i++)
	{
		NewNode = CDLL_CreateNode(i);
		CDLL_AppendNode(&List, NewNode);
	}

	// ����Ʈ ���
	Count = CDLL_GetNodeCount(List);

	for (int i = 0; i < Count; i++)
	{
		Current = CDLL_GetNodeAt(List, i);
		cout << "List [" << i << "] : " << Current->Data << "\n";
	}

	// ����Ʈ�� �� ��° ĭ �ڿ� ��� ����
	cout << "\nInserting 3000 After [2] .. \n\n";

	Current = CDLL_GetNodeAt(List, 2);
	NewNode = CDLL_CreateNode(3000);
	CDLL_InsertAfter(Current, NewNode);

}