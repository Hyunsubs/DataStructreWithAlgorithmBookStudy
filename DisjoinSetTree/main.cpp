#define _CRTDBG_MAP_ALLOC
#include <iostream>
#include <stdlib.h>
#include <crtdbg.h>
using namespace std;

// �и� ����
// ��尡 �ڽ��� �ƴ°��� �ƴ� �θ� �ƴ� ���·� ������
class Node
{
public:
	Node* Parent;
	int* Data; // ��� ������ �����͸� ��� ���� void*

	Node(int* Data)
		: Data(Data)
		, Parent(nullptr)
	{

	}

	~Node()
	{
		if (Data)
		{
			delete Data;
		}
	}
};

// ���� Ž�� ����
// �θ� ���� ��带 ��� Ÿ�� �ö󰡸� �װ��� ������ ��ǥ�ϴ� ��尡 ��
Node* FindSet(Node* Set)
{
	while (Set->Parent != nullptr)
	{
		Set = Set->Parent;
	}

	return Set;
}

// ������ ����
// �ϳ��� ������ ������ �ִ� ���տ� �ֱ�
// �������� ������ �θ� �ִ°��� �θ�� �����ϸ� ��
void UnionSet(Node* Set1, Node* Set2)
{
	Set2 = FindSet(Set2);
	Set2->Parent = Set1;
}



int main()
{
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

	int* a = new int(1);
	int* b = new int(2);
	int* c = new int(3);
	int* d = new int(4);
	Node* Set1 = new Node(a);
	Node* Set2 = new Node(b);
	Node* Set3 = new Node(c);
	Node* Set4 = new Node(d);


	UnionSet(Set1, Set3);
	UnionSet(Set2, Set4);

	delete Set1;
	delete Set2;



	return 0;
}