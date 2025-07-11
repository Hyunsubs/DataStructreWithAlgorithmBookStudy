#define _CRTDBG_MAP_ALLOC
#include <stdlib.h>
#include <crtdbg.h>
#include <iostream>
using namespace std;

class Node
{
public:
	int Data;
	Node* Left;
	Node* Right;

public:
	Node(int Data)
		: Data(Data)
		, Left(nullptr)
		, Right(nullptr)
	{

	}

	~Node()
	{
		if (Left)
		{
			delete(Left);
		}

		if (Right)
		{
			delete(Right);
		}
	}

	int GetData()
	{
		return Data;
	}

	Node* GetLeft() { return Left; }
	Node* GetRight() { return Right; }
};

void PreorderPrintTree(Node* Node)
{
	if (Node == nullptr)
	{
		return;
	}

	// �Ѹ� ��� ���
	cout << Node->GetData();

	// ���� ���� Ʈ�� ���
	PreorderPrintTree(Node->GetLeft());

	// ������ ���� Ʈ�� ���
	PreorderPrintTree(Node->GetRight());
}

void PostorderPrintTree(Node* Node)
{
	if (Node == nullptr)
	{
		return;
	}

	// ���� ���� Ʈ�� ���
	PostorderPrintTree(Node->GetLeft());

	// ������ ���� Ʈ�� ���
	PostorderPrintTree(Node->GetRight());

	// �Ѹ� ��� ���
	cout << Node->GetData();

}

void InorderPrintTree(Node* Node)
{
	if (Node == nullptr)
	{
		return;
	}

	InorderPrintTree(Node->GetLeft());

	cout << Node->GetData();

	InorderPrintTree(Node->GetRight());
}



int main()
{
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

	Node* A = new Node(1);
	Node* B = new Node(2);
	Node* C = new Node(3);
	Node* D = new Node(4);
	Node* E = new Node(5);
	Node* F = new Node(6);
	Node* G = new Node(7);

	// Ʈ���� ��� �߰�
	A->Left = B;
	B->Left = C;
	B->Right = D;

	A->Right = E;
	E->Left = F;
	E->Right = G;

	// Ʈ�� ���
	cout << "Preorder ... \n";
	PreorderPrintTree(A);


	cout << "\nPostorder ... \n";
	PostorderPrintTree(A);

	// Ʈ�� �Ҹ�
	delete(A);

	return 0;
}