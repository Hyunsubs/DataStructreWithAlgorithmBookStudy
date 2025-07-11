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

	// 뿌리 노드 출력
	cout << Node->GetData();

	// 왼쪽 하위 트리 출력
	PreorderPrintTree(Node->GetLeft());

	// 오른쪽 하위 트리 출력
	PreorderPrintTree(Node->GetRight());
}

void PostorderPrintTree(Node* Node)
{
	if (Node == nullptr)
	{
		return;
	}

	// 왼쪽 하위 트리 출력
	PostorderPrintTree(Node->GetLeft());

	// 오른쪽 하위 트리 출력
	PostorderPrintTree(Node->GetRight());

	// 뿌리 노드 출력
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

	// 트리에 노드 추가
	A->Left = B;
	B->Left = C;
	B->Right = D;

	A->Right = E;
	E->Left = F;
	E->Right = G;

	// 트리 출력
	cout << "Preorder ... \n";
	PreorderPrintTree(A);


	cout << "\nPostorder ... \n";
	PostorderPrintTree(A);

	// 트리 소멸
	delete(A);

	return 0;
}